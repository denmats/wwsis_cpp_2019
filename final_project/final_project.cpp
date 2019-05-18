#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

string nazwa_pliku_do_odczytu, nazwa_pliku_do_zapisu, line, tmp, trigger;
bool errorOpenFile = true;
string p2,comment;
int m, n, prog, adjust;
int counter = 1;
char userChoice;
int **tab;
int **tab1;
int **tab2;
int **tabNegatyw;
int **tabProg;

bool Wczytaj(string nazwa_pliku_do_odczytu);
int getSize(string line);
bool Zapisz(string nazwa_pliku_do_zapisu);
void Negatyw();
void Progowanie(int p);
void garbageCollector();

int main()
{
    cout << "Witaj w programie obrobki obrazow. Podaj nazwe obrazow do wczytania: ";
    cin >> nazwa_pliku_do_odczytu;

    if(!Wczytaj(nazwa_pliku_do_odczytu))
    {
    cout<<"Something wrong with this file or the file does not exist"<<endl;
    exit(0);
    }
    else cout<<"Obraz wczytano pomyslne"<<endl;

    while(true)
    {
        cout<<endl;
        cout << "Wybierz numer operacji do wykonania: "<<endl;
        cout << "1. Negatyw" <<endl;
        cout << "2. Progowanie" <<endl;
        cout << "Q. Zakoncz" <<endl;

        cin>> userChoice;
        cout<<"Wybrano: "<<userChoice<<endl;
        cout<<endl;

        switch(userChoice)
            {
            case '1':
                Negatyw();
                cout<<"Podaj nazwe pliku do zapisu ";
                cin>>nazwa_pliku_do_zapisu;
                if(Zapisz(nazwa_pliku_do_zapisu))
                {
                    cout<<"Obraz zapisano do pliku "<<nazwa_pliku_do_zapisu<<endl;
                };
                break;

            case '2':
                cout<<"Podaj wartosc progowania od 0 do " << adjust<<": ";
                cin>>prog;
                Progowanie(prog);
                cout<<"Podaj nazwe pliku do zapisu ";
                cin>>nazwa_pliku_do_zapisu;
                if(Zapisz(nazwa_pliku_do_zapisu))
                {
                    cout<<"Obraz zapisano do pliku "<<nazwa_pliku_do_zapisu<<endl;
                };
                break;
            case 'Q':
            case 'q':
                exit(0);
            default:
                cout<<"Zrobiles zly wybor. Sprobuj ponownie"<<endl;
                break;
            }
        }
    garbageCollector(); //clean memory
    return 0;
}



bool Wczytaj(string nazwa_pliku_do_odczytu)
{
    ifstream dane;
    dane.open(nazwa_pliku_do_odczytu.c_str());
    if(!dane.good())
    {
        errorOpenFile = false;
        cout<<"The file isn't opened"<<endl;
        return errorOpenFile;
    }
    else
    {
        ofstream dane1;
        dane1.open("tmp.pgm");

        //Read and write to variables the first four lines
        //Then rest of lines write to new file "tmp.pgm"
        //**program solves two options: one - with comment, other - without comment
        while(getline(dane, line))
        {
            switch(counter)
            {
            case 1:
                p2 = line;
                break;
            case 2:
                if(line.substr(0,1)!="#"){
                    comment = "";
                    tmp = line;
                }else comment = line;
                break;
            case 3:
                if(comment !=""){
                    tmp = line;
                }else adjust = atoi(line.c_str());
                break;
            case 4:
                if(comment != ""){
                    adjust = atoi(line.c_str());
                }else dane1 << line <<endl;
                break;
            default:
                dane1 << line <<endl;
            }
            counter++;
        }

        //Pull out dimension of picture
        getSize(tmp);

        //Take data from file tmp.pgm to array "tab[m][n]"
        //The data includes only array of numbers without the first four line
        ifstream dane2;
        dane2.open("tmp.pgm");
        if(!dane2.good())
        {
            errorOpenFile = false;
            cout << "The file isn't opened!" << endl;
            return errorOpenFile;
        }
        else
        {
            tab = new int *[n];
            for(int i = 0; i < n; i++)
            {
                tab[i] = new int[m];
            }

            for(int i = 0; i < n; i ++)
            {
                for(int j = 0; j < m; j++)
                {
                    dane2 >> tab[i][j];
                }
            }
        }

        dane2.close();
        dane1.close();
        dane.close();
    }
    return errorOpenFile;
}

getSize(string line){
        string delimeter = " ";
        m = atoi(tmp.c_str());
        string tmp1s = tmp.substr(tmp.find(delimeter),(tmp.length()-1));
        n = atoi(tmp1s.c_str());
}



bool Zapisz(string nazwa_pliku_do_zapisu)
{
    ofstream dane4;
    dane4.open(nazwa_pliku_do_zapisu.c_str());
    dane4 << p2 <<endl;
    if(comment != ""){
        dane4 << comment <<endl;
    }
    dane4 << tmp << endl;
    dane4 << adjust <<endl;

    if(trigger == "Negotyw")
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                dane4 << tabNegatyw[i][j]<<" ";
            }
            dane4<<endl;
        }
    }
    else if(trigger == "Prog")
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                dane4 << tabProg[i][j]<<" ";
            }
            dane4<<endl;
        }
    }
    dane4.close();
    return true;
}

void Negatyw()
{
    ifstream dane3;
    dane3.open("tmp.pgm");
    if(!dane3.good())
    {
        cout << "The file isn't opened!" << endl;
        exit(0);
    }
    else
    {
        tab1 = new int *[n];
        for(int i = 0; i < n; i++)
        {
            tab1[i] = new int[m];
        }

        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < m; j++)
            {
                dane3 >> tab1[i][j];
            }
        }

        //Calculation Negative
        //int tabNegatyw[n][m];
        tabNegatyw = new int *[n];
        for(int i = 0; i < n; i++)
        {
            tabNegatyw[i] = new int [m];
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                tabNegatyw[i][j] = adjust - tab1[i][j];
            }
        }

        trigger = "Negotyw";
    }
    dane3.close();
    cout<<"Negatyw wykonano"<<endl;
}

void Progowanie(int p)
{
    cout<<"Wartosc progowania wynosi: "<<prog<<endl;

    ifstream dane5;
    dane5.open("tmp.pgm");
    if(!dane5.good())
    {
        cout << "The file isn't opened!" << endl;
        exit(0);
    }
    else
    {
        tab2 = new int *[n];
        for(int i = 0; i < n; i++)
        {
            tab2[i] = new int[m];
        }

        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < m; j++)
            {
                dane5 >> tab2[i][j];
            }
        }

        //Calculation 'Progowanie'
        tabProg = new int *[n];
        for(int i = 0; i < n; i++)
        {
            tabProg[i] = new int [m];
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(tab2[i][j] <= prog)
                {
                    tabProg[i][j] = 0;
                }
                else
                {
                    tabProg[i][j] = prog;
                }
            }
        }

        trigger = "Prog";
    }
    dane5.close();
    cout<<"Progowanie wykonano"<<endl;
}

void garbageCollector()
{
    for(int i = 0; i < n; i++)
    {
        delete[] tab[i] ;
    }
    delete[] tab;
    tab = NULL;

    for(int i = 0; i < n; i++)
    {
        delete[] tab1[i] ;
    }
    delete[] tab1;
    tab1 = NULL;

    for(int i = 0; i < n; i++)
    {
        delete[] tab2[i] ;
    }
    delete[] tab2;
    tab2 = NULL;

    for(int i = 0; i < n; i++)
    {
        delete[] tabNegatyw[i] ;
    }
    delete[] tabNegatyw;
    tabNegatyw = NULL;

    for(int i = 0; i < n; i++)
    {
        delete[] tabProg[i] ;
    }
    delete[] tabProg;
    tabProg = NULL;
}




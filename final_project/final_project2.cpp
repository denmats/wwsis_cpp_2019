#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

string nazwa_pliku_do_odczytu, nazwa_pliku_do_zapisu, line,trigger;
bool errorOpenFile = true;
string p2,comment;
int m, n, prog, adjust;
char userChoice;

int **tab;
int **tabNegatyw;
int **tabProg;

bool Wczytaj(string nazwa_pliku_do_odczytu);
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
        return errorOpenFile;
    }
    else
    {
        dane>>p2;
        dane.ignore();
        getline(dane,line);
        comment=line;
        dane>>m>>n>>adjust;

        tab = new int*[n];
        for(int i=0; i<n; i++)
        {
            tab[i] = new int[m];
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                dane>>tab[i][j];
            }
        }
        dane.close();
    }
    return errorOpenFile;
}

bool Zapisz(string nazwa_pliku_do_zapisu)
{
    ofstream dane1;
    dane1.open(nazwa_pliku_do_zapisu.c_str());
    if(!dane1.good())
    {
        errorOpenFile = false;
        return errorOpenFile;
    }
    else
    {
        dane1<<p2<<endl;
        if(comment.substr(0,1)=="#")
        {
            dane1<<comment<<endl;
        }
        dane1<<m<<" ";
        dane1<<n<<endl;
        dane1<<adjust<<endl;
        if(trigger == "negatyw")
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    dane1<<tabNegatyw[i][j]<<" ";
                }
                dane1<<endl;
            }
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    dane1<<tabProg[i][j]<<" ";
                }
                dane1<<endl;
            }
        }
    }
    dane1.close();
    return errorOpenFile;
}

void Negatyw()
{
    tabNegatyw = new int *[n];
    for(int i=0; i<n; i++)
    {
        tabNegatyw[i] = new int[m];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            tabNegatyw[i][j] = adjust - tab[i][j];
        }
    }
    trigger = "negatyw";
}

void Progowanie(int p)
{
    tabProg = new int *[n];
    for(int i=0; i<n; i++)
    {
        tabProg[i] = new int[m];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(tab[i][j] <= prog)
            {
                tabProg[i][j] = 0;
            }
            else
            {
                tabProg[i][j] = prog;
            }
        }
    }
    trigger="prog";
}

void garbageCollector()
{
    for(int i = 0; i < n; i++)
    {
        delete[] tab[i] ;
    }
    delete[] tab;
    tab = NULL;

    for(int i=0; i<n; i++)
    {
        delete [] tabNegatyw[i];
    }
    delete[] tabNegatyw;
    tabNegatyw = NULL;

    for(int i=0; i<n; i++)
    {
        delete[] tabProg[i];
    }
    delete[] tabProg;
    tabProg = NULL;
}

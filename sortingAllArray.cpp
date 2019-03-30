#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int tab [15][18];
int start,finish,type_of_sorting;

int check_range()
{
    cout << "Give the start number of random range: " << endl;
    cin >> start;
    cout << "Give the end number of random range: " << endl;
    cin >> finish;

    if(start > finish)
    {
        int buf = start;
        start = finish;
        finish = buf;
    }
}

int fillTabWith300RandNum(int a, int b)
{
    for (int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 18; j++)
        {
            {
                tab[i][j] = rand()%(finish-start+1)+start;
            }
        }
    }
}

int ascendRowOnlySorting()
{
    for (int m = 0; m < 1; m++)
    {
        for (int i = 0; i < 270; i++)
        {

            for(int j=i; j< 270; j++)
            {
                int tmp = tab[m][i];
                if(tab[m][j]< tmp)
                {
                    tab[m][i] = tab[m][j];
                    tab[m][j] = tmp;
                }
            }
        }
        cout << ""<<endl;
        cout << "--------------"<<endl;
    }
}

int descendRowOnlySorting()
{
    for (int m = 0; m < 1; m++)
    {
        for (int i = 0; i < 270; i++)
        {
            for(int j=i; j< 270; j++)
            {
                int tmp = tab[m][i];
                if(tab[m][j] > tmp)
                {
                    tab[m][i] = tab[m][j];
                    tab[m][j] = tmp;
                }
            }
        }
        cout << ""<<endl;
        cout << "--------------"<<endl;
    }
}

void display_table()
{
    cout << " " <<endl;
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            cout << tab[i][j] << " ";
        }
        cout << " " << endl;
    }
    cout << " " <<endl;
}


int main()
{
    srand(time(NULL));
    cout << "Give the range of numbers to generate random 300 numbers" << endl;
    cout << "------------" << endl;

    check_range();

    fillTabWith300RandNum(start,finish);

    cout << "Non-sorting table with random numbers from "<<start<< " to "<<finish<<":"<<endl;
    display_table();

    while(true)
    {
        cout << "What kind of sorting use: ascend or descend?" << endl;
        cout << "1. Ascend"<< endl;
        cout << "2. Descend" << endl;
        cout << "3. exit" << endl;
        cout << "Make your choice:  ";
        cin >> type_of_sorting;

        switch(type_of_sorting)
        {
        case 1:
            //Ascend sorting
            ascendRowOnlySorting();
            display_table();
            break;

        case 2:
            //Descend sorting
            descendRowOnlySorting();
            display_table();
            break;

        case 3:
            exit(0);

        default:
            cout << "Make your choice from 1,2 or 3." << endl;
            break;
        }
    }

    return 0;
}

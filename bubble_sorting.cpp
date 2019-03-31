#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int tab [15][18];
int start,finish,type_of_sorting;

void check_range()
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

void fillTabWith300RandNum(int a, int b)
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

void ascendBubbleSorting()
{
    for(int row = 0; row < 15; row++)
    {
        for(int col = 0; col < 18; col++)
        {
            for (int i = 0; i < 15; i++)
            {
                for(int j=0; j < 18; j++)
                {
                    int tmp = tab[row][col];
                    if(tab[i][j]> tmp)
                    {
                        tab[row][col] = tab[i][j];
                        tab[i][j] = tmp;
                    }
                }
            }
        }
    }
}

void descendBubbleSorting()
{
    for(int row = 0; row < 15; row++)
    {
        for(int col = 0; col < 18; col++)
        {
            for (int i = 0; i < 15; i++)
            {
                for(int j=0; j < 18; j++)
                {
                    int tmp = tab[row][col];
                    if(tab[i][j] < tmp)
                    {
                        tab[row][col] = tab[i][j];
                        tab[i][j] = tmp;
                    }
                }
            }
        }
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
                ascendBubbleSorting();
                display_table();
                break;

            case 2:
                //Descend sorting
                descendBubbleSorting();
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


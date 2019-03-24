#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int tab [300];
int start,finish,type_of_sorting;

int main()
{
    srand(time(NULL));
    cout << "Give the range of numbers to generate random 300 numbers" << endl;
    cout << "Give the start number of random range: " << endl;
    cin >> start;
    cout << "Give the end number of random range: " << endl;
    cin >> finish;
    cout << "------------" << endl;

    if(start > finish){
        int buf = start;
        start = finish;
        finish = buf;
    }

    for (int i = 0; i < 300; i++)
    {
        tab[i] = rand()%(finish-start+1)+start;
    }
    cout << ""<<endl;

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
            for (int i = 0; i < 300; i++)
            {
                for (int j = i; j < 300; j++)
                {
                    int tmp = tab [i];
                    if (tab[j] < tmp)
                    {
                        tab[i] = tab[j];
                        tab[j] = tmp;
                    }
                }
            }

            cout << "Ascend sorting" << endl;
            for (int i = 0; i < 300; i++)
            {
                cout << tab[i] << endl;
            }
            break;

        case 2:
            for (int i = 0; i < 300; i++)
            {
                for (int j = i; j < 300; j++)
                {
                    int tmp = tab [i];
                    if (tab[j] > tmp)
                    {
                        tab[i] = tab[j];
                        tab[j] = tmp;
                    }
                }
            }

            cout << "Descend sorting" << endl;
            for (int i = 0; i < 300; i++)
            {
                cout << tab[i] << endl;
            }
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



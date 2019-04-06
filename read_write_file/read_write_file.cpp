#include <iostream>
#include <fstream>

using namespace std;

int tab[640][480];
double tab1[1000][1000];
int m, n, maxNum, minNum;
double avg;

//Get and write Maximum, Minimum and Average of each row in tab1
void getMaxMinAvg(int m, int n){
    for(int i = 0; i < m; i++ )
    {
        avg = 0;
        maxNum = tab[i][0];
        minNum = tab[i][0];
        for(int j = 0; j < n; j++)
        {
            if(maxNum < tab[i][j])
            {
                maxNum = tab[i][j];
            }
            else if(minNum > tab[i][j])
            {
                minNum = tab[i][j];
            }
            avg += tab[i][j];
        }
        tab1[i][0] = i+1;
        tab1[i][1] = maxNum;
        tab1[i][2] = minNum;
        tab1[i][3] = avg/n;
    }
}

int main()
{
    //Read file dane.txt
    ifstream  dane;
    dane.open("dane.txt");
    if(!dane.good())
    {
        cout << "The file isn't opened!" << endl;
        return 0;
    }
    dane >> m >> n;

    for(int i = 0; i < m; i ++)
    {
        for(int j = 0; j < n; j++)
        {
            dane >> tab[i][j];
        }
    }
    dane.close();

    //Get and write Maximum, Minimum and Average of each row in tab1
    getMaxMinAvg(m,n);

    //Write in file dane1.txt number of row, max, min and avg
    ofstream dane1;
    dane1.open("dane1.txt");
    if(!dane1.good())
    {
        cout << "The file isn't opened!" << endl;
        return 0;
    }

    dane1 << "Row " << "Max  " << "Min  " << "Average  " << endl;
    for(int i = 0; i < 640; i ++)
    {
        for(int j = 0; j < 4; j++)
        {
            dane1 << tab1[i][j] <<"        ";
        }
        dane1 << endl;
    }
    dane1.close();

    cout << endl;
    cout << "File dane1.txt with max, min and average numbers of each row is ready" << endl;

    return 0;
}

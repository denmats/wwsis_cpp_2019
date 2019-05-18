#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct RGB
{
    int r;
    int g;
    int b;
};

RGB tab[4][4];
int m,n,adjust;
string p2,comment;


int main()
{
    ifstream dane;
    dane.open("3.ppm");
    if(!dane.good())
    {
        cout<<"not ok"<<endl;
        exit(0);
    }
    //Solving problem of trying to read file with comment
    //and without comment (3.ppm or 33.ppm)
    dane>>p2;
    dane>>comment;
    if(comment == "#")
    {
        dane>>comment;
        comment = "# "+comment;
    }else if(comment != " "){
        m = atoi(comment.c_str());
        dane>>n>>adjust;
    }else dane>>m>>n>>adjust;

    if(comment.substr(0,1) == "#"){
        dane>>m>>n>>adjust;
    }


    //This output on the screen might be redirect
    //to file
    cout<<p2<<endl;
    if(comment.substr(0,1) == "#"){
        cout<<comment<<endl;
    }
    cout<<m<<" "<<n<<endl;
    cout<<adjust<<endl;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            dane>>tab[i][j].r>>tab[i][j].g>>tab[i][j].b;
        }
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<" "<<tab[i][j].r<<" "<<tab[i][j].g<<" "<<tab[i][j].b<<" ";
        }
        cout<<endl;
    }
    dane.close();
    return 0;
}





#include <iostream>
#include <stdlib.h>

using namespace std;
int a,b,c,d, choice, maximum, minimum;

int getMax(int a,int b,int c, int d);

int getMin(int a,int b,int c, int d);

double getAvg(int a,int b,int c, int d);

double getCalculation(int a,int b,int c, int d);

double getAvgWeights(int a,int b,int c, int d);


int main()
{
cout<<"Podaj a: "; cin >> a;
cout<<"Podaj b: "; cin >> b;
cout<<"Podaj c: "; cin >> c;
cout<<"Podaj d: "; cin >> d;

while(true){
    cout<< "Menu" <<endl;
    cout<< "1. Wyswietl maksumalna wartosc wprowadzonych liczb" <<endl;
    cout<< "2. Wyswietl minimalna wartosc wprowadzonych liczb" <<endl;
    cout<< "3. Policzy srednia" <<endl;
    cout<< "4. Obliczy (a+b)/(c+d)" <<endl;
    cout<< "5. Obliczy srednia wazona z wagami 0.1, 0.2, 0.3, 0.4 odpowiednio dla a,b,c,d" <<endl;
    cout<< "6: Exit" <<endl;

    cout << "Wybierz punkt z menu: ";
    cin >> choice;
    cout<<endl;

    switch(choice){
    case 1:
        cout << getMax( a,b,c,d) << endl;
        break;
    case 2:
        cout << getMin(a,b,c,d) <<endl;
        break;
    case 3:
        cout << getAvg(a,b,c,d)<<endl;
        break;
    case 4:
        cout << getCalculation(a,b,c,d)<<endl;
        break;
    case 5:
        cout << getAvgWeights(a,b,c,d)<< endl;
        break;
    case 6:
        exit(0);
    default:
        cout<<"Wybierz jeden punkt z menu"<<endl;
        break;
    }

}

    return 0;
}

int getMax(int a,int b,int c, int d){
    int tab[4];
    tab[0] = a;
    tab[1] = b;
    tab[2] = c;
    tab[3] = d;

    maximum = a;
    for(int i = 0; i < 4; i++){
        if(tab[i]>maximum){
            maximum = tab[i];
        }
    }

    return maximum;
}

int getMin(int a,int b,int c, int d){
    int tab[4];
    tab[0] = a;
    tab[1] = b;
    tab[2] = c;
    tab[3] = d;

    minimum = a;
    for(int i = 0; i < 4; i++){
        if(tab[i]<minimum){
            minimum = tab[i];
        }
    }

    return minimum;
}

double getAvg(int a, int b, int c, int d){
 return (a+b+c+d)/4;
}

double getCalculation(int a,int b,int c, int d){
return ((double)(a+b)/(double)(c+d));
}

double getAvgWeights(int a,int b,int c, int d){
 return (((double)a*0.1 +(double)b*0.2 +(double)c*0.3 +(double)d*0.4)/(0.1+0.2+0.3+0.4));
}



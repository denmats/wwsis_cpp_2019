#include <iostream>

using namespace std;

double a, b, c, d;
int cykli;

int main()
{
    cout << "Program PRZECIECIE ZERO" << endl;
    cout << " "<< endl;
    cout << "Podaj ilosc cikli ktore program mial wykonac: " << endl;
    cin >> cykli;
    cout << " "<< endl;

    for (int i = 0; i < cykli; i++)
    {
        int ilosc_cykli = 0;
        cout << "Podaj cztere liczby dla ktorych program policzy przeciecia przez zero: " << endl;
        cout << "Podaj a:" << endl;
        cin >> a;

        cout << "Podaj b:" << endl;
        cin >> b;

        cout << "Podaj c:" << endl;
        cin >> c;

        cout << "Podaj d:" << endl;
        cin >> d;

        cout << "------------" << endl;

       if ((a*b < 0))
       {
           cout << "a= " << a << " b= " << b << endl;
           ilosc_cykli ++;
       }

       if ((b*c < 0))
       {
           cout << "b= " << b << " c= " << c << endl;
           ilosc_cykli ++;
       }

       if ((c*d < 0))
       {
           cout << "c= " << c << " d= " << d << endl;
           ilosc_cykli ++;
       }

       cout <<  "Ilosc cykli = " << ilosc_cykli << endl;
       cout << "" << endl;
    }
    return 0;
}

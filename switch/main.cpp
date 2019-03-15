#include <iostream>
#include <stdlib.h>

using namespace std;

double checkFor9 (double x)
{
    if (x == 9)
    {
        exit(0);
    }
}

double a, b, c, d, x;
int wybor;


int main()
{
    cout << "Program using 'case'" << endl;
    cout << "To leave program enter 9" << endl;

    while(true)
    {
        cout << endl;
        cout << "------------------" << endl;
        cout << "Podaj a: "<< endl;
        cin >> a;
        checkFor9(a);

        cout << "Podaj b: "<< endl;
        cin >> b;
        checkFor9(b);

        cout << "Podaj c: "<< endl;
        cin >> c;
        checkFor9(c);

        cout << "Podaj d: "<< endl;
        cin >> d;
        checkFor9(d);

        cout << "Menu" << endl;
        cout << "1. Dodaj liczby" << endl;
        cout << "2. Pomnoz przez siebie" << endl;
        cout << "3. Odejmuj a od b" << endl;
        cout << "4. Podziel a+b przez c" << endl;
        cout << "5. Policz srednia" << endl;
        cout << "------------------" << endl;


        cout << "Podaj numer z menu: " << endl;
        cin >> wybor;
        checkFor9(wybor);

        switch(wybor)
        {
        case 1:
        {
            cout << "Dodanie liczby a+b+c+d = " << a+b+c+d << endl;
            break;
        }
        case 2:
        {
            cout << "Mnozenie liczb a*b*c*d = " << a*b*c*d << endl;
            break;
        }
        case 3:
        {
            cout << "Odejmowanie a od b = " << a-b << endl;
            break;
        }
        case 4:
        {
            if( c == 0)
            {
                cout << "Nie wolno dzielic przez zero" << endl;
            }else
            {
               cout << "Dzelenie a+b przez c = " << (a+b)/c << endl;
            }

            break;
        }
        case 5:
        {
            cout << "Srednia = " << (a+b+c+d)/4 << endl;
            break;
        }

        default:
        {
            cout << "Nie ma takiego punktu w menu. Wybierz prawidlowa liczba" << endl;
        }
        }
    }

    return 0;
}


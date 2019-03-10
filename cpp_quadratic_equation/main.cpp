#include <iostream>
#include <math.h>

using namespace std;

double find_x1 (double a, double b, double delta)
{
    double x1 = (-b - sqrt(delta))/(2 * a);
    return x1;
}

double find_x2 (double a, double b, double delta)
{
    double x2 = (-b + sqrt(delta))/(2 * a);
    return x2;
}

double find_x0 (double a, double b, double delta)
{
    double x0 = -b/(2 * a);
    return x0;
}

double check_input (double x)
{
    while (true)
    {
        if (cin >> x)
        {
            // valid number
            return x;
        }
        else
        {
            // not a valid number
            cout << "Invalid Input! Please input a numerical value." << endl;
            cin.clear();
            while (cin.get() != '\n') ; // empty loop
        }
    }
}

double isTheQuadratic (double x)
{
    while (true)
    {
        if (cin >> x && x != 0)
        {
            return x;
        }
        else
        {
            // not a valid number
            cout << "Invalid Input! Please input a numerical value." << endl;
            cout << "The first element of quadratic equation can't be zero" << endl;
            cin.clear();
            while (cin.get() != '\n') ; // empty loop
        }
    }
}

int main()
{
    double a, b, c, delta, x1, x2 = 0;
    int times = 1;

    cout << "Quadratic equation: y = ax2 + bx + c" << endl;
    cout << "The program will run 5 times"<< endl;
    cout << "" <<endl;

    while(times <= 5)
    {
        cout << "The program is starting  "<< times << " time" << endl;

        cout << "Give a: " << endl;
        a = isTheQuadratic(a);
        //cout << "a= " << a << endl;

        cin.clear();
        cout << "Give b: " << endl;
        b = check_input(b);
        //cout << "b= " << b << endl;

        cin.clear();
        cout << "Give c: " << endl;
        c = check_input(c);
        //cout << "c= " << c << endl;

        delta = b*b - 4 * a * c;

        if(delta < 0)
        {
            cout << "No solving" << endl;
        }
        else if(delta > 0)
        {
            cout << "The equation has two solving: x1 = "
                 << find_x1(a, b, delta)
                 << "  x2 =  "
                 << find_x2(a, b, delta)
                 <<endl;
        }
        else
        {
            cout << "The equation has one solving: x =  " << find_x0(a, b, delta) << endl;
        }

        cout << "" <<endl;
        cout << "-----------------------------------------------------" << endl;
        cout << ""<< endl;

        times++;
    }
}


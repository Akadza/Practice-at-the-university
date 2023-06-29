#include <iostream>
#include <iomanip>
#define EPS pow(10, -5)

using namespace std;

class diff {
    // (y + 2y - x)y' = 1; y(2) = 0 -> x0 = 2, y0 = 0;
    // Диапазон [2, 12];
    double func(double x, double y) { return 1.0 / (3 * y - x); }
    double func1(double x, double y) { return 1.0 / 9 * pow(y, 2) - 6 * x * y + pow(x, 2) + 3; }
    
public:
    void m_euler(double x, double y, double h = 0.5, double end = 10) {
        double xn = x, yn = y;
        cout << "x = " << setw(5) << x << " y = " << y << endl;
        while (abs(x - end) > EPS) 
        {
            xn += h;
            yn += h * func(x, y);
            x = xn, y = yn;
            cout << "x = " << setw(5) << x << " y = " << y << "\n";
        }
    }
    

    public:
       void m_euler_mod(double x, double y, double h = 0.5, int end = 10) {
           double xn = x, yn = y, halfX, halfY;
           cout << "x = " << setw(5) << x << " y = " << y << endl;
           while (abs(xn - end) > EPS)
           {
               halfX = xn + h / 2;
               halfY = yn + h * func(xn, yn);
               yn += h * func(halfX, halfY);
               xn += h;
               cout << "x = " << setw(5) << xn << " y = " << yn << "\n";
           }
       }

    public:
        void m_euler_improve(double x, double y, double h = 0.5, int end = 10) {
            double xn = x, yn = y, halfX, halfY;
            cout << "x = " << setw(5) << x << " y = " << y << endl;
            while (abs(xn - end) > EPS)
            {
                halfY = yn + h * func(xn, yn);
                xn += h;
                yn += h * ((func(x, yn) + func(xn, halfY)) / 2);
                cout << "x = " << setw(5) << xn << " y = " << yn << "\n";
                x = xn;
            }
        }

    public:
         void m_runge_kutt(double x, double y, double h = 0.5, int end = 10) {
            double xn = x, yn = y;
            double k1, k2, k3, k4;
            cout << "x = " << setw(5) << x << " y = " << y << endl;
            while (abs(xn - end) > EPS)
            {
                k1 = h * func(xn, yn);
                k2 = h * func(xn + h / 2, yn + h / 2 * k1);
                k3 = h * func(xn + h / 2, yn + h / 2 * k2);
                k4 = h * func(xn + h, yn + h * k3);
                cout << k1 << " " << k2 << " " << k3 << " " << k4 << "\n";
                xn += h;
                yn += (k1 + 2 * k2 + 2 * k3 + k4)/6;
                cout << "x = " << setw(5) << xn << " y = " << yn << "\n";
            }
        }
};

int main()
{
    diff diffMethod;    
    const double x = 2, y = 0;
    const double h = 0.5, end = 6;
    const int precision = 10;
    //diffMethod.m_euler(x, y, h, end);
    //diffMethod.m_euler_mod(x, y, h, end);
    //diffMethod.m_euler_improve(x, y, h, end);
    diffMethod.m_runge_kutt(x, y, h, end);

    return 0;
}
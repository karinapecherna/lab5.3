#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


double f(const double x);

int main() {
    double tp, tk, z;
    int n;

    
    cout << "tp = "; cin >> tp;
    cout << "tk = "; cin >> tk;
    cout << "n = "; cin >> n;

    
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(5) << "t" << " |"
        << setw(10) << "f(t)" << " |"
        << endl;
    cout << "-------------------------------------------------" << endl;

   
    double dt = (tk - tp) / (n - 1);  

    for (int i = 0; i < n; i++) {
        double t = tp + i * dt;  
        z = f(2 * t) + pow(f(t), 2) * (pow(t, 2) + 1); 
        cout << "|" << setw(7) << setprecision(2) << t << " |"
            << setw(10) << setprecision(5) << z << " |" << endl; 
    }

    cout << "-------------------------------------------------" << endl;

    return 0;
}

double f(const double x) {
    if (abs(x) >= 1) {
        return ((sin(2 * x)) + 1) / sin(x) + (cos(x) * cos(x));
    }
    else {
        double S = 0;
        int n = 0;
        double a = 1;
        S = a;
        do {
            n++;
            double R = (pow(x, 4 * n + 2)) / (((2 * n + 1) - 2) * ((2 * n + 1) - 1) * (2 * n + 1));
            a *= R;
            S += a;
        } while (n < 7);
        return S;
    }
}

#include <bits/stdc++.h>
using namespace std;

// Constants
const double R = 0.08206; // Gas constant in atm·L/(K·gmmol)

// get Z value using Z = PV/RT
double Z(double P, double V, double T)
{
    return (P * V) / (R * T);
}
// Virial equation of state
double virialEquation(double V, double T, double P, double B, double C)
{
    return Z(P, V, T) - (B / V) - (C / (V * V)) - 1.0;
}

// This function returns the value of the intersection point of the line passing through(a,fa) and (b,fb)
// If f( of this point is +ve) then b = this point
// else a = this point
double pointOfIntersectionOfLineOnXAxis(double a, double b, double fa, double fb)
{
    return a - (fa * ((b - a) / (fb - fa)));
}

// Regula Falsi method to find root
double regulaFalsi(double T, double P, double B, double C, double a, double b, double epsilon, int maxIterations)
{
    double fa = virialEquation(a, T, P, B, C);
    double fb = virialEquation(b, T, P, B, C);

    // either fa or fb should return -ve value if a root is present in the interval [a,b]
    if (fa * fb >= 0.0)
    {
        cout << "Initial interval does not bracket the root." << endl;
        return -1.0; // Return an error value
    }

    int prevC = INT_MIN;

    for (int i = 0; i < maxIterations; ++i)
    {
        int c = pointOfIntersectionOfLineOnXAxis(a, b, fa, fb);
        double fc = virialEquation(c, T, P, B, C);

        if (abs(c - prevC) < epsilon)
        {
            return c;
        }

        if (fc > 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }

        prevC = c;
    }

    cout << "Maximum iterations reached without convergence." << endl;
    return -1.0; // Return an error value
}

int main()
{
    double T = 460.0;           // Temperature in K
    double P = 15.0;            // Pressure in atm
    double B = -265.0;          // cm^3/gmmol
    double C = 30250.0;         // cm^6/gmmol^2
    double a = 0.001;           // Initial interval left endpoint (cm^3/gmmol)
    double b = 50.0;            // Initial interval right endpoint (cm^3/gmmol)
    double epsilon = 1e-6;      // Convergence criteria
    int maxIterations = 100000; // Maximum number of iterations

    double molarVolume = regulaFalsi(T, P, B, C, a, b, epsilon, maxIterations);

    if (molarVolume != -1.0)
    {
        cout << "Molar Volume: " << molarVolume << " cm^3/gmmol" << endl;
    }
    else
    {
        cout << "Failed to find molar volume." << endl;
    }

    return 0;
}

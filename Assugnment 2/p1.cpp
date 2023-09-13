#include <bits/stdc++.h>
using namespace std;

// Z= 1 + (B/V) + (C/(V^2))
// PV/RT= 1 + (B/V) + (C/(V^2))

double func(double V)
{
    double T = 460.0;
    double P = 15;
    double R = 0.082;
    double B = -265;
    double C = 30250;
    return (R * T / P) * (1 + B / V + (C / (pow(V, 2))));
}

int main()
{
    double maxItr = 1000;
    double tolX = 1e-6;

    double V = 0.5;
    double VOld = 0.5;

    for (int i = 1; i <= maxItr; i++)
    {
        V = func(VOld); // finding new V

        double err = abs(V - VOld); // error calculation

        if (err < tolX) // checking if error is less than tolerance
        {
            break;
        }
        VOld = V;
    }
    cout << "The value of V corrected upto 6 decimal places = " << V << endl;
    return 0;
}
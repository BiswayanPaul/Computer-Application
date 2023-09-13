#include <bits/stdc++.h>
using namespace std;
// f(x) = cos(x)-x*exp(x)
// f'(x) = -sin(x) - {exp(x) + x*exp(x)}
double func(double x)
{
    return cos(x) - (x * exp(x));
}
double diff(double x)
{
    return -sin(x) - (exp(x) + (x * exp(x)));
}
int main()
{
    double x0 = 0; // initial guess
    double newsign = func(x0) / abs(func(x0));
    double oldsign = func(x0) / abs(func(x0));
    while ((oldsign * newsign) > 0)
    {
        oldsign = newsign;
        x0 += .1;
        newsign = func(x0) / abs(func(x0));
    }
    double maxItr = 1000;
    double tolX = 1e-6;
    double x = x0;
    double xOld = x0;
    for (int i = 1; i <= maxItr; i++)
    {  
        double f = func(x);         // returns f(x)
        double df = diff(x);        // returns f'(x)
        x = xOld - (f / df);        // finding new x
        double err = abs(x - xOld); // error calculation
        if (err < tolX)             // checking if error is less than tolerance
        {
            break;
        }
        xOld = x;
    }
    cout << "The value of x corrected upto 6 decimal places = " << x << endl;
    cout << "The corresponding value of f(x) = " << cos(x) - (x * exp(x)) << endl;
    return 0;
}
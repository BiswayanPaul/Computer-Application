#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// f(x)  = cos(x)-x*exp(x)
// f'(x) = -sin(x) - {exp(x) + x*exp(x)}



int main()
{
    float x0 = 2;
    float maxItr = 50;
    float tolX = 1e-5;

    float x = x0;
    float xOld = x0;
    float itr = 0;
    for (float i = 1; i <= maxItr; i++)
    {

        //using sin cos and exp function here... 


        float f = cos(x) - (x * exp(x));
        float df = -sin(x) - (exp(x) + (x * exp(x)));

        x = xOld - (f / df);

        float err = abs(x - xOld);
        xOld = x;
        itr = i;
        if (err < tolX)
        {
            break;
        }
    }

    cout << "Ite needed: " << itr << endl
         << "Value of x is: " << setprecision(10) << x << endl;
    return 0;
}
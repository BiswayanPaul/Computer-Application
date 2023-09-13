#include <bits/stdc++.h>
using namespace std;
int main()
{
    float x = 0.1;
    float prevans = 0;
    float ans = 0;
    for (int i = 1; i <= 100; i++)
    {
        prevans = ans;
        if (i % 2 == 0)
        {
            ans = ans - float(pow(x, i) / i);
        }
        else
        {
            ans = ans + float(pow(x, i) / i);
        }
        if (abs(ans - prevans) < 1e-5)
        {
            break;
        }
    }
    // Correcting the answer upto 5 Decimal places by explicit type casting
    ans = ((int)(ans / (1e-5))) * (1e-5);
    cout << "The value of ln(1+0.1) corrected up to 5 decimal places is = " << ans;
    return 0;
}

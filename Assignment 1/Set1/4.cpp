#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return n * fact(n - 1);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, x;
    cin >> n >> x;
    float ans = 1;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            ans = ans + float((pow(x, i) / fact(i)));
        }
        else
        {
            ans = ans - float((pow(x, i) / fact(i)));
        }
    }

    cout << setprecision(5) << ans;

    return 0;
}
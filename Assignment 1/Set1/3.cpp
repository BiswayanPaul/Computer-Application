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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    float ans = 0;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        ans = ans + (1 / float(fact(i)));
    }
    cout << setprecision(5) << ans;

    return 0;
}

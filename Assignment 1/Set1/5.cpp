#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    float x = 0.1;
    int n;
    cin >> n;

    float ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = ans - float(pow(x, i) / i);
    }

    cout << setprecision(5) << ans;
    return 0;
}
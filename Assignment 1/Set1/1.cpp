#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 1+1/4+1/9+1/16

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    float n;
    cin >> n;
    float ans = 0;
    float res = 0;
    for (float i = 1; i <= n; i++)
    {
        res = 1 / (i * i);
        ans += res;
    }

    cout << setprecision(6) << ans;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 1-1/4+1/9-1/16

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    float n;
    cin >> n;
    float ans = 1.000;
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            ans -= float(1 / float(i * i));
        }
        else
        {
            ans += float(1 / float(i * i));
        }
    }

    cout << setprecision(5) << ans;
    return 0;
}
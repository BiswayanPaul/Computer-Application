#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    ll nextTerm = 0;
    ll t1 = 0;
    ll t2 = 1;
    ll temp = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || i == 1)
        {
            cout << i << " ";
            continue;
        }

        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        cout << t2 << " ";

        if ((i + 1) % 5 == 0 && i != 0)
        {
            cout << endl;
        }
    }

    return 0;
}
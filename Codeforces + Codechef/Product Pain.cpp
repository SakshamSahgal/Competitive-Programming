#include <iostream>
#define ll long long
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll maxi = a[i], minn = a[i];
        set<ll> set;
        for (ll j = i; j < n; j++)
        {
            set.insert(a[j]);
            maxi = max(maxi, a[j]);
            minn = min(minn, a[j]);
            if (j - i < 2)
            {
                continue;
            }
            ll value = 0;
            auto position = set.lower_bound((maxi + minn) / 2);
            if (position != set.end())
            {
                value = max(value, (maxi - (*position)) * ((*position) - minn));
            }
            if (position != set.begin())
            {
                position--;
                value = max(value, (maxi - (*position)) * ((*position) - minn));
            }
            res += value;
        }

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}

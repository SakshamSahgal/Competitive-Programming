#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

//template begins
#define int long long int
typedef unsigned int ull;
typedef unsigned int ll;
typedef long double lld;
#define ios                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pb push_back
#define max3(a, b, c) max(max((a), (b)), (c))
#define max4(a, b, c, d) max(max((a), (b)), max((c), (d)))
#define min3(a, b, c) min(min((a), (b)), (c))
#define min4(a, b, c, d) min(min((a), (b)), min((c), (d)))
#define all(v) v.begin(), v.end()
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define cinv(v, n)              \
    for (int i = 0; i < n; ++i) \
    {                           \
        cin >> v[i];            \
    }
#define vll vector<int>
#define rep(x, start, end) for (auto x = (start) - ((start) > (end)); x != (end) - ((start) > (end)); ((start) < (end) ? x++ : x--))
#define endl "\n"
void google(int t)
{
    cout << "Case #" << t << ": ";
}
const long double pi = 3.14159265358979323846264338;
vector<int> sieve(int n)
{
    int *arr = new int[n + 1]();
    vector<int> vect;
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (int j = 2 * i; j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
    find_by_order() - Returns an iterator to the k-th largest element (counting from zero)
    order_of_key()  - The number of items in a set that are strictly smaller than our item
    Rest same as set
*/

//debugging statements

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x) ;
#endif
void _print(int t)
{
    cerr << t;
}
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
const int N = 5000;
bool check_prime(int n)
{
    for (int i = 2; i < min(N, n); i++)
        if (n % i == 0)
            return 0;
    return 1;
}
//template ends
vll divisors(ll n)
{
    vll div;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            div.pb(i);
            if (n / i != i)
                div.pb(n / i);
        }
    }
    return div;
}
void solve()
{
    ll n;
    cin >> n;
    ll a[n];

    ll sum = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }

    vll div = divisors(sum);

    ll ans = n;

    if (div.size() <= 2)
    {
        cout << n << endl;
        return;
    }

    for (auto x : div)
    {

        ll req = sum / x;
        bool b = false;

        ll s = 0;
        ll thick = 0;

        ll mx = 0;

        for (int i = 0; i < n; ++i)
        {
            s += a[i];
            thick++;

            if (s == req)
            {
                mx = max(thick, mx);
                s = 0;
                thick = 0;
            }
            else if (s > req)
            {
                b = true;
                break;
            }
        }

        if (!b)
        {
            ans = min(ans, mx);
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios;
    int Tests = 1;
    cin >> Tests;

    for (int z = 1; z <= Tests; ++z)
    {
        // google(z);
        solve();
        //cout << fixed << setprecision(10);
    }
}

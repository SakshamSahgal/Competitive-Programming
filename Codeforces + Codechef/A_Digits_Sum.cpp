#include <iostream>
#include <algorithm>
#include <vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int t;
    cin >> t;
    while (t)
    {
        lli n;
        cin >> n;
        if (n >= 1 && n <= 8)
            cout << 0 << "\n";
        else
            cout << (n - 9) / 10 + 1 << "\n";
        t--;
    }

    return 0;
}
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool solve(string a, string b,int n,int m)
{
    int freq[26] = {0};
    // int n = a.length();
    // int m = b.length();
    string c = a + b;
    int len_c = n + m;


    for (int i = 0; i < len_c; i++)
    {
        freq[c[i] - 'a']++;
    }


    bool has_odd_freq = false;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] % 2 == 1)
        {
            if (has_odd_freq)
            {
                return false;
            }
            has_odd_freq = true;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin>>n>> m;

        string x, y;
        cin>> x >> y;


        if (solve(x, y,n,m))
        {
            cout << "YEs"<<endl;;
        }
        else
        {
            cout << "NO"<<endl;
        }
    }

    return 0;
}

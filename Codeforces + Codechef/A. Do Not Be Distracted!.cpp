#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    usi t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        char x[n];
        for(int i=0; i<n; i++)
            cin>>x[i];
        vector<int> freq;
        vector <char> element;
        n = unique(x,x+n) - x;
        bool found=0;
        for(int i=0; i<n; i++)
        {
            found=0;
            for(int j=0; j<element.size(); j++)
            {
                if(x[i] == element[j])
                {
                    found=1;
                    freq[j]++;
                    if(freq[j] > 1)
                    {
                        cout<<"NO\n";
                        goto u;
                    }
                    break;
                }

            }
            if(found == 0)
            {
                element.push_back(x[i]);
                freq.push_back(1);
            }
        }

        cout<<"YES\n";

        u:
        t--;
    }

    return 0;
}


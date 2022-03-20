#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        string s,h;
        cin>>s>>h;

        if(h.length() < s.length())
        {
            cout<<"NO\n";
            goto k;
        }
        else
        {
            map<char,lli> fs;

            for(int i=0; i<s.length(); i++)
                fs[s[i]]++;


            for(int l=0; l<h.length(); l++)
            {
                int r=l+s.length()-1;

                if(r < h.length())
                {
                    map<char,lli> fh;

                    for(int i=l; i<=r; i++)
                        fh[h[i]]++;

                    bool no=0;

                    for(auto i:fs)
                    {
                        if(fh[i.first] != i.second)
                        {
                            no = 1;
                            break;
                        }
                    }

                    if(no == 0)
                    {
                        cout<<"YES\n";
                        goto k;
                    }
                }



            }
            cout<<"NO\n";
        }
k:
        t--;
    }
    return 0;
}

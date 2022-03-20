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
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;



int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        bool pass=0;
        set<string> f;
        map<string,vector<lli>> index;
        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;
            index[s].push_back(i);
            if(s.length() == 1)
                pass = 1;
            else if(s.length() == 2 && s[0] == s[1])
                pass = 1;
            else if(s.length() == 3 && s[0] == s[2])
                pass = 1;
            else
                f.insert(s);
        }

        if(pass == 1)
            cout<<"YES\n";
        else
        {


            for(auto i:f)
            {
                string temp = i;
                reverse(temp.begin(),temp.end());
                auto ptr = f.find(temp);
                if(ptr != f.end())
                {
                    if(index[temp][index[temp].size()-1] > index[i][0])
                    {
                        cout<<"YES\n";
                        goto k;
                    }
                }

                if(i.length() == 3 && i[0] != i[1])
                {
                    string x;
                    x += i[1];
                    x += i[0];
                    //cout<<"at - "<<i<<" searching for = "<<x<<"\n";
                    auto ptr = f.find(x);
                    if(ptr != f.end())
                    {
                        if(index[x][index[x].size()-1] > index[i][0])
                        {
                            cout<<"YES\n";
                            goto k;
                        }
                    }
                }
                if(i.length() == 3 && i[1] != i[2])
                {
                    string x;
                    x += i[2];
                    x += i[1];
                    //cout<<"at - "<<i<<" searching for = "<<x<<"\n";
                    auto ptr = f.find(x);
                    if(ptr != f.end())
                    {
                        if(index[x][0] < index[i][index[i].size()-1])
                        {
                            cout<<"YES\n";
                            goto k;
                        }
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


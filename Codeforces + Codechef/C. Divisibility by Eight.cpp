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


bool check_divisibility(string a)
{
    if(a.length() == 2)
    {
        lli temp = ((a[0] - '0')*10) + (a[1]-'0');
        if(temp%8 == 0)
            return 1;
        else
            return 0;
    }
    else
    {
        lli temp = ((a[0] - '0')*100) + (a[1]-'0')*10 + (a[2]-'0');
        if(temp%8 == 0)
            return 1;
        else
            return 0;
    }
}

int main()
{
    GO_FAST
    string s;
    cin>>s;

    bool one_found=0;
    string found;

    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '0' || s[i] == '8')
        {
            found = s[i];
            one_found = 1;
            break;
        }
    }

    if(one_found == 0)
    {
        if(s.length() >= 2)
        {
            bool two_found = 0;
            for(int i=0; i<s.length(); i++)
            {
                for(int j=i+1; j<s.length(); j++)
                {
                    string temp;
                    temp += s[i];
                    temp += s[j];
                    if(check_divisibility(temp))
                    {
                        two_found = 1;
                        found = temp;
                        goto k;
                    }
                }
            }
k:
            if(two_found == 0)
            {
                if(s.length() >= 3)
                {
                    bool three_found = 0;
                    for(int i=0; i<s.length(); i++)
                    {
                        for(int j=i+1; j<s.length(); j++)
                        {
                            for(int k=j+1; k<s.length(); k++)
                            {
                                string temp;
                                temp += s[i];
                                temp += s[j];
                                temp += s[k];
                                if(check_divisibility(temp))
                                {
                                    three_found = 1;
                                    found = temp;
                                    goto o;
                                }
                            }
                        }
                    }

o:
                    if(three_found == 0)
                        cout<<"NO\n";
                    else
                        cout<<"YES\n"<<found<<"\n";
                }
                else
                    cout<<"NO\n";
            }
            else
                cout<<"YES\n"<<found<<"\n";
        }
        else
            cout<<"NO\n";

    }
    else
        cout<<"YES\n"<<found<<"\n";

    return 0;
}


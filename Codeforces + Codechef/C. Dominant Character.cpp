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

bool check(lli x,lli n)
{
    if(x >=0 && x<n)
        return 1;
    else
        return 0;
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        string s;
        cin>>s;

        if( n>=2 )
        {
            lli tf = s.find("aa");
           // cout<<"for 2 = "<<tf<<"\n";
            if( check(tf,n) == 1 )
                cout<<2<<"\n";
            else
            {
                if( n >= 3 )
                {
                    lli thf1 = s.find("aba");
                    lli thf2 = s.find("aca");

                  //  cout<<"for 3 = "<<thf1<<" "<<thf2<<" \n";

                    if( check(thf1,n) == 1 || check(thf2,n) == 1 )
                        cout<<3<<"\n";
                    else
                    {
                        if( n>= 4)
                        {
                            lli ff1 = s.find("abca");
                            lli ff2 = s.find("acba");

                         //    cout<<"for 4 = "<<ff1<<" "<<ff2<<" \n";

                            if( check(ff1,n) == 1 || check(ff2,n) == 1 )
                                cout<<4<<"\n";
                            else
                            {
                                if(n>= 7)
                                {
                                    lli sf1 = s.find("abbacca");
                                    lli sf2 = s.find("accabba");

                               //     cout<<"for 7 = "<<sf1<<" "<<sf2<<" \n";

                                    if( check(sf1,n) == 1 || check(sf2,n) == 1 )
                                        cout<<7<<"\n";
                                    else
                                        cout<<-1<<"\n";

                                }
                                else
                                    cout<<-1<<"\n";
                            }
                        }
                        else
                            cout<<-1<<"\n";
                    }
                }
                else
                    cout<<"-1\n";
            }
        }
        else
            cout<<-1<<"\n";

        t--;
    }
    return 0;
}

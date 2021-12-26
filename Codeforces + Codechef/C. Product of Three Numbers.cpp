#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;


void set_printer(set<int> s)
{
    cout<<"\n-------------------\n";
    for(auto i=s.begin(); i!=s.end(); i++)
        cout<<*i<<" ";
    cout<<"\n-------------------\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        lli n;
        cin>>n;
        if(n<24)
            cout<<"NO\n";
        else
        {
            lli a=-1,b=-1,c=-1;
            set<lli> s;
            for(lli i=2; i*i <= n; i++)
            {
                if(n%i == 0)
                {
                    s.insert(i);
                    s.insert(n/i);
                    break;
                }
            }

            //set_printer(s);

            if(s.size() < 2)
                cout<<"NO\n";
            else
            {
                a = *(s.begin());
                int x = n/a;

                for(lli i=2;i*i<=x;i++)
                    {
                        if(x%i == 0 && i != a)
                        {
                            b = i;
                            break;
                        }

                    }

                if(b  == -1)
                    cout<<"NO\n";
                else
                {
                    c = n/(a*b);
                    if(n%(a*b) != 0 || c == a || c == b)
                        cout<<"NO\n";
                    else
                        cout<<"YES\n"<<a<<" "<<b<<" "<<c<<"\n";
                }
            }



        }

    }


    return 0;
}

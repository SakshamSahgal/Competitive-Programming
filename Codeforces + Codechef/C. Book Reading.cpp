#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi q;
cin>>q;
while(q--)
    {
    ulli n,m;
    cin>>n>>m;
    if(n == m)
        cout<<m%10<<"\n";
    else if(n>m)
        {
            ulli s=0;
            if(n>(10*m))
                {
                   if(m%2 == 1)
                    {
                        if(m%5 != 0)
                            {
                            s+= (n/(10*m))*45;
                            for(ulli i=(n-n%(10*m)+m);i<=n;i+=m)
                                {
                                //cout<<i%10<<"\n";
                                s += i%10;
                                }

                            cout<<s<<"\n";
                            }
                        else
                            {
                             s+= (n/(10*m))*25;
                            for(ulli i=(n-n%(10*m)+m);i<=n;i+=m)
                                {
                                //cout<<i%10<<"\n";
                                s += i%10;
                                }
                             cout<<s<<"\n";
                            }
                    }
                else
                    {
                            if(m%10 != 0)
                                {
                                  s+= (n/(10*m))*40;
                                for(ulli i=(n-n%(10*m)+m);i<=n;i+=m)
                                {
                                //cout<<i%10<<"\n";
                                s += i%10;
                                }

                            cout<<s<<"\n";
                                }
                            else
                                cout<<"0\n";


                    }

                }
            else
                {
                    for(ulli i=m;i<=n;i+=m)
                        {
                        //cout<<i%10<<"\n";
                            s += i%10;
                        }

                            cout<<s<<"\n";

                }


        }
        else
            cout<<"0\n";


    }


return 0;
}

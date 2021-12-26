#include<iostream>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
unsigned int t;
cin>>t;
while(t--)
    {
    int c1,c2,c3,a1,a2,a3,a4,a5;
    cin>>c1>>c2>>c3;
    cin>>a1>>a2>>a3>>a4>>a5;
    c1-=a1;
    c2-=a2;
    c3-=a3;
    if(c1<0 || c2<0 || c3<0)
        cout<<"NO\n";
    else
        {

                        a4-=c1;
                        a5-=c2;

                     if(a4<0)
                        a4 = 0;
                     if(a5<0)
                        a5 = 0;

                    if( (a4+a5)<=c3)
                        {
                        cout<<"YES\n";
                        goto x;
                        }
                    else
                        {
                       cout<<"NO\n";
                        goto x;
                        }



        }
    x:
   a1=a1;
    }
return 0;
}

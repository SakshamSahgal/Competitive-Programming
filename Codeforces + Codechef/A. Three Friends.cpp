#include<iostream>
#include<algorithm>
using namespace std;
#include<cmath>
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
unsigned short int q;
cin>>q;
while(q--)
    {
    unsigned long int a,b,c;
    cin>>a>>b>>c;

    if(a==b && b==c)
    cout<<"0\n";

    else if(a==b && c != b)
        {
        if(c>a)
            {
            c--;
            if((c-a)>=1)
                a++;
            cout<<(c-a)*2<<"\n";
            }

        else
            {
            c++;
            if((a-c)>=1)
                a--;
            cout<<(a-c)*2<<"\n";
            }
        }
    else if(b==c && a!=b)
        {
            if(a<b)
                {
                a++;
                if((b-a)>=1)
                    b--;
                cout<<(b-a)*2<<"\n";
                }

            else
                {
                a--;
                if((a-b)>=1)
                    b++;
                cout<<(a-b)*2<<"\n";
                }

        }
    else if(a==c && b!=a)
        {
            if(b>a)
                {
                b--;
                if((b-a)>=1)
                    a++;
                cout<<(b-a)*2<<"\n";
                }

            else
                {
                b++;
                if((a-b)>=1)
                    a--;
                cout<<(a-b)*2<<"\n";
                }

        }

    else if(a!=b && b!=c)
        {
        int d[3];
        d[0] = a;
        d[1] = b;
        d[2] = c;
        sort(d,d+3);
        d[0]++;
        d[2]--;
        cout<<( abs(d[0]- d[1]) + abs(d[1] - d[2]) + abs(d[0] - d[2]) )<<"\n";
        }



    }



return 0;
}

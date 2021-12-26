#include<iostream>
#include<algorithm>
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
    int n;
    cin>>n;
    char s[2*n+1];
    for(int i=1;i<=2*n;i++)
        cin>>s[i];
    int q;
    cin>>q;
    int c=0;
    for(int i=1; i<=q; i++)
    {
        int t,a,b;
        char temp;
        cin>>t>>a>>b;
        if(t==1)
        {
            if(c%2 == 1)
            {
                if((a+n)>(2*n))
                    a-=n;
                else
                    a+=n;

                 if((b+n)>(2*n))
                    b-=n;
                else
                    b+=n;
                temp = s[a];
                s[a] = s[b];
                s[b] = temp;
               // cout<<"swapping index "<<a<<" "<<b<<"\n";
            }
            else
            {
                temp = s[a];
                s[a] = s[b];
                s[b] = temp;
                //cout<<"swapping index "<<a<<" "<<b<<"\n";
            }
        }
        else
            c++;

    }
   //cout<<"c = "<<c<<"\n";
    if(c%2 == 1)
    {

     for(int i=n+1;i<=2*n;i++)
            cout<<s[i];
     for(int i=1;i<=n;i++)
            cout<<s[i];


    //cout<<"thios";


        cout<<"\n";
    }
    else
       {
           for(int i=1;i<=n;i++)
            cout<<s[i];

           for(int i=n+1;i<=2*n;i++)
            cout<<s[i];



           cout<<"\n";
       }
    return 0;
}


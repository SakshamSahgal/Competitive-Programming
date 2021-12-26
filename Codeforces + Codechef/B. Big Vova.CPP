#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

lli Eular_GCD(lli a,lli b)
{
    lli temp;
x:
    if(a == 0 || b == 0)
    {
        return max(a,b);
    }
    else
    {
        temp = a;
        a = b;
        b = temp%b;
        goto x;
    }
}


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
        int a[n];
        int maxi=0;
        int index=0;
        vector <int> b;
        int GCDX;

        for(int i=0; i<n; i++)
            cin>>a[i];


        if(n!= 1)
        {


            sort(a,a+n,greater<int>());
            b.push_back(a[0]);
            int gcd = a[0];
            a[0] = 0;
g:
            maxi = 0;
            for(int j=0; j<n; j++)
            {
                if(a[j] != 0)
                {

                    GCDX = Eular_GCD(gcd,a[j]);
                    //cout<<"checking for j = "<<j<<"GCD = of "<<gcd<<" "<<a[j]<<" = "<<GCDX<<"\n";
                    if ( GCDX > maxi )
                    {
                        maxi = GCDX;
                        index = j;
                    }
                }
            }
            //cout<<"maxi = "<<maxi<<" index = "<<index<<"\n";



            if(maxi != 1 )
            {
                b.push_back(a[index]);
                gcd = maxi;
                a[index] = 0;
            }
            else
            {
                for(int i=0; i<n; i++)
                {
                    if(a[i]!=0)
                        b.push_back(a[i]);
                }
            }

           // for(int i=0; i<b.size(); i++)
               // cout<<b[i]<<" ";

            //cout<<"\n";

            if(b.size() < n )
                goto g;

            //cout<<"\n--------------\n";
            for(int i=0; i<b.size(); i++)
                cout<<b[i]<<" ";
            cout<<"\n";



        }
        else
            cout<<a[0]<<"\n";

     t--;
    }

    return 0;
}


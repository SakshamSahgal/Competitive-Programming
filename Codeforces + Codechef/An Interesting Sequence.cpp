#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int Eular_GCD(int a,int b)
{
    int temp;
    if(a!=0 && b!=0)
    {
x:
        if(a == 0)
            return b;
        else if(b == 0)
            return a;
        else
        {
            temp = a;
            a = b;
            b = temp%b;
            goto x;
        }
    }
    else
        return max(a,b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        // int k;
        // cin>>k;
        lli sum=0;
        lli a;
        lli b;
        bool allone=0;
        for(int k=1,j=1; k<=30; k++)
        {
            allone=1;
            cout<<"\nK = "<<k<<" : \n";
            sum=0;
             //series
            for(lli i=1; i<=(2*k); i++)
                {
                a = k + (i*i);
                b = k + (i+1)*(i+1);
                cout<<a<<" ";
                }
             cout<<b<<"\n";
            for(lli i=1; i<=(2*k); i++)
            {
                a = k + (i*i);
                b = k + (i+1)*(i+1);
                sum+=Eular_GCD(a,b);
                if(i!=(2*k))
                {
                    if(Eular_GCD(a,b) != 1)
                        allone=0;
                }
               cout<<Eular_GCD(a,b)<<" ";
            }
            // cout<<"\nsum = "<<sum<<"\n";

            // cout<<"("<<k<<","<<sum<<")\n";
            // cout<<k<<"\n";
            if(allone == 1)
           {
            //cout<<j<<"\n";
            //cout<<sum<<"\n";
           // cout<<"("<<j<<","<<k<<")\n";
            //cout<<"("<<k<<","<<sum<<")\n";
           // cout<<"("<<j<<","<<k<<")\n";
            j++;
           }

        }



        t--;
    }

    return 0;
}


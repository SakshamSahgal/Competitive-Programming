#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
struct A
{
    lli value;
    lli index;
    lli no_available_before_this;
};

void Printer(struct A x[],int n)
{
    cout<<"\nValue = ";
    for(int i=0; i<n; i++)
        cout<<x[i].value<<" ";

    cout<<"\nIndex = ";
    for(int i=0; i<n; i++)
        cout<<x[i].index<<" ";

    cout<<"\nno before= ";
    for(int i=0; i<n; i++)
        cout<<x[i].no_available_before_this<<" ";
    cout<<"\n";
}


int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    lli n,q;
    cin>>n>>q;
    lli x,y;
    A a[n];
    for(lli i=0; i<n; i++)
    {
        cin>>x;
        a[i].value = x;
        a[i].index = i+1;
        a[i].no_available_before_this = a[i].value-a[i].index;
    }
    Printer(a,n);

    while(q)
    {
        lli k;
        cin>>k;
        bool found=0;
        for(int i=0; i<n; i++)
        {
            found=0;
            if(k<=a[i].no_available_before_this)
            {
                if(k<a[i].no_available_before_this)
                {
                    if(i == 0)
                        cout<<k<<"\n";
                    else
                    {
                         //cout<<a[i].no_available_before_this - k<<"\n";
                    }

                }
                else
                    cout<<a[i].value-1<<"\n";

                found = 1;
                break;
            }

        }


        if(found == 0)
            cout<<k+n<<"\n";

        q--;
    }





    return 0;
}

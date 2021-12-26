#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n,k;
    string t;
    cin>>n>>k;
    cin>>t;

    bool found = 0;
    if(n == 1)
    {
        for(int i=1; i<=k; i++)
            cout<<t;
    }
    else
    {
        string y = t;
        int index=0;
        for(int j=1; j<n; j++)
        {

            if(y[0] == t[j])
            {
                //cout<<"checking for j = "<<j<<"\n";
                found = 1;
                for(int i=0,k=j; i<(n-j); i++,k++)
                {

                    if(y[i] != t[k])
                    {
                        //cout<<"break at ="<<k<<"\n";
                        found = 0;
                        break;
                    }
                }

                if(found == 1)
                {
                    //cout<<"found at j = "<<j<<"\n";
                    index = j;
                    break;
                }
            }
        }
        if(found == 0)
        {
            for(int i=1; i<=k; i++)
                cout<<t;
        }
        else
        {
            cout<<t;
            for(int i=1; i<=(k-1); i++)
            {
                for(int j=n-index; j<n; j++)
                    cout<<t[j];
            }

        }

    }
    return 0;
}

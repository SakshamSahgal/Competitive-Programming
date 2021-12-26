#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void array_printer(int a[],int n)
{
for(int i=0;i<n;i++)
    cout<<a[i];
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
        int n;
        cin>>n;
        int b[n];
        int a[n];
        int c[n];

        string s;
        cin>>s;

        for(int i=0;i<n;i++)
            a[i] = s[i]-48;

        for(int i=0; i<n; i++)
        {
            if(i == 0)
            {
                b[i] = 1;
            }
            else
            {
                if(a[i] == 0)
                {
                    if(c[i-1] != 1)
                        b[i] = 1;
                    else
                        b[i] = 0;
                }
                else
                {
                    if(c[i-1] != 2)
                        b[i] = 1;
                    else
                        b[i] = 0;
                }
            }
            c[i] = a[i]+b[i];
        }

        //array_printer(a,n);
        array_printer(b,n);
        //array_printer(c,n);
        cout<<"\n";
        t--;
    }
    return 0;
}



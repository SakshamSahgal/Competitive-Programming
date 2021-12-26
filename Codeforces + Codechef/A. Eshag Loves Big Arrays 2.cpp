#include<iostream>
#include<algorithm>
#include<vector>
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
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        int a[n];

        for(int i=0; i<n; i++)
            cin>>a[i];

        double avg;
        int c=0;
        for(int i=0; i<n; i++)
        {
            if(a[i] != -1)
            {
                for(int j=0; j<n; j++)
                {
                    if(a[j] != -1)
                    {
                        if(i!=j)
                        {
                            avg = (a[i] + a[j])/2.0;
                            if(a[i] > avg)
                                {
                                    a[i] = -1;
                                    c++;
                                    break;
                                }
                            if(a[j] > avg)
                            {
                                a[j] = -1;
                                c++;
                            }
                        }
                    }
                }

            }

        }

        cout<<c<<"\n";
        t--;
    }

    return 0;
}

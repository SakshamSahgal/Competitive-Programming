#include<iostream>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
int t,n;
long int k,temp;
cin>>t;
while(t--)
    {
    cin>>n>>k;
    int countit=1;
    long int q[n];
    for(int i=0;i<n;i++)
        {
        cin>>q[i];
        }
    for(int i=0;i<n-1;i++)
        {
            if((q[i]-k)>=0)
                {
                temp = q[i];
                q[i+1] += (q[i]-k);
                q[i] = 0;
                countit++;
                }
            else
                {
                goto a;
                }
        }
    temp = q[n-1];
    while(temp >= k)
        {
            countit++;
            temp = temp - k;
        }
        a:
    cout<<countit<<"\n";
    }

return 0;
}

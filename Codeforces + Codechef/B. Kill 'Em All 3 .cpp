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
int q;
cin>>q;
while(q)
    {
    int n,r;
    cin>>n>>r;
    int a[n];
    int freq[100001] = {0};
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            freq[a[i]]++;
        }
    if(n == 1)
    cout<<1<<"\n";
    else
        {
            int counter = 0;
            sort(a,a+n);
           // for(int i=0;i<n;i++)
              //  cout<<a[i]<<" ";
          // cout<<"\n";
            for(int i=n-1;i>=0;i-= freq[a[i]] )
                {
                    counter++;
                   // if(i<0)
                        //break;
                  //cout<<"checking  = "<<a[i]<<"\n";
                    if( ( i - freq[a[i]] ) >=0 )
                        {
                          if( ( a[i - freq[a[i]]] - r*counter ) <= 0 )
                                break;
                          else
                            {
                                if(i == 1)
                                    {
                                     counter++;
                                     break;
                                    }
                            }
                        }
                    else
                        break;
                }
        cout<<max(1,counter)<<"\n";
        }

    q--;
    }
return 0;
}

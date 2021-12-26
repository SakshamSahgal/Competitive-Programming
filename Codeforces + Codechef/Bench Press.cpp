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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
lli t;
cin>>t;
while(t)
    {
    lli n,w,wr;
    cin>>n>>w>>wr;
    lli x[n];
    lli freq[100001] = {0};
    for(int i=0;i<n;i++)
        {
            cin>>x[i];
            freq[x[i]]+=1;
        }


    if(wr>=w)
        cout<<"YES\n";
    else
        {
            w = w-wr;
           for(lli i=1;i<=100000;i++)
           {
             if(freq[i] >= 2)
                {

                 if(freq[i]%2 == 0)
                    {
                    w-= i*freq[i];
                    //freq[i] = 0;
                    }

                 else
                    {
                        w-=i*(freq[i]-1);
                        //freq[i] = 1;
                    }

                if(w<=0)
                    break;
                //cout<<"AAiya\n";
                }
           }
            //cout<<"sum = "<<sum<<"\n";

            if(w<=0)
                cout<<"YES\n";
            else
                cout<<"NO\n";

        }
    t--;
    }

return 0;
}


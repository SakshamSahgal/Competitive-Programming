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
usi t;
cin>>t;
while(t)
    {
    usi n;
    int m,k;
    cin>>n>>m>>k;
    int h[n];

    for(usi i=0;i<n;i++)
            cin>>h[i];

    for(usi i=0;i<(n-1);i++)
        {
        //cout<<"I = "<<i<<"\n";
        if( h[i] > h[i+1] )
            {
               // cout<<"h[i] > h[i+1] found ...\n";
                m += (h[i] - h[i+1]);
                //cout<<"m+="<<(h[i] - h[i+1])<<"\n";
                h[i] = h[i+1];

                if(h[i] >= k)
                    {
                    m+=k;
                    //cout<<"m+="<<k<<".....\n";
                    h[i]-=k;
                    }
                else
                    {
                    m +=h[i];
                    //cout<<"m+="<<h[i]<<".....\n";
                    h[i]=0;
                    }
            }
        else
            {
                //cout<<"h[i] <= h[i+1] found ...\n";
                if( (h[i+1] - h[i]) > k  )
                    {
                        //cout<<"( h[i+1] - h[i] ) > k found ......\n";
                        if( m >= ( h[i+1]- h[i] - k ) )
                            {
                                 m -= (h[i+1]- h[i] - k);
                                //cout<<"m -= " <<(h[i+1]- h[i] - k)<<"\n";
                                 h[i] +=(h[i+1]- h[i] - k);
                            }
                        else
                            {
                            cout<<"NO\n";
                            goto x;
                            }

                    }
                else
                    {
                        if(h[i] >=  (k + h[i] - h[i+1]) )
                            {
                            m+= k + h[i] - h[i+1];
                            //cout<<"m+="<<(k + h[i] - h[i+1])<<".....\n";
                            h[i] -= k + h[i] - h[i+1];
                            }
                        else
                            {
                            m+= h[i];
                            h[i] = 0;
                            }

                    }
            }
        //cout<<"h[i] = "<<h[i]<<" m = "<<m<<"\n";
        }
    cout<<"YES\n";
    x:
    t--;
    }

return 0;
}

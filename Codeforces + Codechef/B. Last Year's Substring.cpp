#include<iostream>
#define usi unsigned short int
using namespace std;
void printer(char h[],int n)
{
cout<<"\n-------\n";
for(usi i=0;i<n;i++)
cout<<h[i]<<" ";
cout<<"\n-------\n";
}

bool comparer(char h[])
{
if(h[0] == '2' && h[1] == '0' && h[2] == '2' && h[3] == '0')
    return 1;
else
    return 0;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t--)
    {
    usi n=0;
    cin>>n;
    string s;
    cin>>s;
    if(n==4 && s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0')
        {
            cout<<"YES\n";
            goto y;
        }
    else
        {
            usi l=0;
            for(usi i=0;i<n;i++)
            {
            for(usi j=i;j<n;j++)
                {
                l=0;
                if((n-j+i-1) == 4)
                    {
                    char h[(n-j+i-1)];
                        for(usi k=0;k<n;k++)
                        {
                        if(k<i || k>j)
                            {
                            h[l] = s[k];
                            l++;
                            }

                        }
                        //printer(h,(n-j+i-1));
                        if(comparer(h) == 1)
                        {
                        cout<<"YES\n";
                        goto y;
                        }
                    }


                }
        //cout<<"\n===============\n";
            }


        }



    cout<<"NO\n";
    y:
    n=n;
    }
}

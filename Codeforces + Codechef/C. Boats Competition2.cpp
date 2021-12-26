#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
void reset(usi n,usi temp[],usi w[])
{
for(usi i=0;i<n;i++)
    w[i] = temp[i];
}
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
    cin>>n;
    usi w[n];
    usi temp[n];
    int maxi = 0;
    int index;
    int second_maxi = 0;
    for(usi i=0;i<n;i++)
        {
        cin>>w[i];
        temp[i] = w[i];
        if(w[i]>maxi)
            {
            maxi = w[i];
            index = i;
            }
        }
    for(usi i=0;i<n;i++)
        {
            if(w[i]>second_maxi && i != index)
                second_maxi = w[i];
        }
    //cout<<"maxi = "<<maxi<<"second maxi = "<<second_maxi<<"\n";
    if(n==1)
        cout<<0<<"\n";
    else
    {
    usi no_of_pair[maxi+second_maxi];
    int p=0;
        for(usi s=1,k=0;s<=(maxi+second_maxi);s++,k++)
        {
            p=0;
           //cout<<"for s = "<<s<<"\n";
            for(usi i=0;i<n;i++)
            {
                if(w[i]!=0)
                    {
                         for(usi j=0;j<n;j++)
                            {
                                if(i!=j && w[j]!=0)
                                    {
                                        //cout<<w[i]<<"+"<<w[j]<<"="<<w[i]+w[j]<<"\n";
                                        if( (w[i]+w[j]) == s)
                                            {
                                                w[i] = 0;
                                                w[j] = 0;
                                               // cout<<"i = "<<i<<"j = "<<j<<"\n";
                                                p++;
                                                break;
                                            }

                                    }
                            }
               // cout<<"\n";
                    }
            }
                reset(n,temp,w);
                no_of_pair[k] = p;
            }
            /*
            cout<<"\n";
            for(usi i=0;i<(maxi+second_maxi);i++)
                cout<<" "<<no_of_pair[i];
             cout<<"\n"; */
         cout<<*max_element(no_of_pair,no_of_pair+(maxi+second_maxi))<<"\n";
    }
    t--;
    }



return 0;
}

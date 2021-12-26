#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void array_printer(int a[],int b[],int d[],int n)
{
    cout<<"\n--------------------\n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    for(int i=0; i<n; i++)
        cout<<b[i]<<" ";
    cout<<"\n";
    for(int i=0; i<n; i++)
        cout<<d[i]<<" ";
    cout<<"\n--------------------\n";
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
        int a[n];
        int b[n];
        int diff[n];
        vector<pair<int,int>> m;
        lli sum=0;
        for(int i=0; i<n; i++)
            cin>>a[i];

        for(int i=0; i<n; i++)
            cin>>b[i];

        for(int i=0; i<n; i++)
        {
            if( a[i] > b[i])
                diff[i] = b[i] - a[i];
            else
                diff[i] = b[i] - a[i];

            sum+= b[i] - a[i];
        }

        //array_printer(a,b,diff,n);

        if(sum !=0)
            cout<<"-1\n";
        else
        {
            for(int i=0; i<n; i++)
            {
                if(diff[i]<0)
                {
                    for(int j=0; j<n; j++)
                    {
                        if(i!=j && diff[j] > 0)
                        {
                            if(diff[j] >= abs(diff[i]))
                            {
                                for(int k=0; k<abs(diff[i]); k++)
                                    m.push_back({i+1,j+1});

                                diff[j] += diff[i];
                                diff[i] = 0;
                                break;
                            }
                            else
                            {
                                diff[i] += diff[j];
                                for(int k=0; k<diff[j]; k++)
                                    m.push_back({i+1,j+1});
                                diff[j] = 0;
                            }
                        }

                        if(diff[i] == 0)
                            break;
                    }
                    //array_printer(a,b,diff,n);
                }
            }

            cout<<m.size()<<"\n";

            for(int i=0; i<m.size(); i++)
                cout<<m[i].first<<" "<<m[i].second<<"\n";
        }
        t--;
    }

    return 0;
}


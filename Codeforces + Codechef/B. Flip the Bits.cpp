#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void bracker_printer(vector<pair<int,int>> x,int n)
{
    char temp[n];
    for(auto i = x.begin(); i!=x.end(); i++)
    {
        temp[i->first] = '[';
        temp[i->second] = ']';
    }
    cout<<"\n";
    for(int i=0; i<n; i++)
    {
        if(temp[i] != '[' && temp[i] != ']')
            cout<<"-";
        else
            cout<<temp[i];
    }
    cout<<"\n";
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
        string a,b;
        cin>>a;
        cin>>b;
        vector<pair<int,int>> index;
        int prefix_z[n];
        int prefix_o[n];
        int sum_z=0;
        int sum_o=0;

        for(int i=0; i<n; i++)
        {
            if(a[i] == '0')
                sum_z++;
            else
                sum_o++;

            prefix_z[i] = sum_z;
            prefix_o[i] = sum_o;

            if(prefix_o[i] == prefix_z[i])
            {
                if(index.size() == 0)
                    index.push_back({0,i});
                else
                    index.push_back({index[index.size()-1].second+1,i});
            }
        }
       // cout<<"index size = "<<index.size()<<"\n";
        //bracker_printer(index,n);

        if(index.size() == 0)
        {
            if(a == b)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }

        else
        {

            for(auto i = index.begin(); i!=index.end(); i++)
            {
                if(a[i->first] != b[i->first])
                {
                    for(int j = i->first ; j<= i->second; j++)
                    {
                        if(a[j] == b[j])
                        {
                            cout<<"NO\n";
                            goto k;
                        }
                    }
                }
                else
                {
                    for(int j = i->first ; j<= i->second; j++)
                    {
                        if(a[j] != b[j])
                        {
                            cout<<"NO\n";
                            goto k;
                        }
                    }
                }

                if( i == (index.end()-1) )
                {
                    if(i->second != (n-1))
                    {
                        for(int j=i->second+1;j<n;j++)
                        {
                            if(a[j] != b[j])
                                {
                                cout<<"NO\n";
                                goto k;
                                }
                        }
                    }
                }
            }
            cout<<"YES\n";
        }
k:
        t--;
    }

    return 0;
}


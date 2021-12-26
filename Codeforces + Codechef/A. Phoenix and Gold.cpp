#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;


void printer(vector <int> v)
{
cout<<"\n----------\n";
for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
cout<<"\n----------\n";
}

bool checker(vector <int> v,int x)
{
    lli sum=0;

    for(int i=0; i<v.size(); i++)
    {
        sum+=v[i];
        if(sum == x)
            return 0;
    }
    return 1;
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
        int n,x;
        cin>>n>>x;
        int w[n];
        lli sum=0;
        lli maxi=0;
        lli maxi_index=0;
        for(int i=0; i<n; i++)
        {
            cin>>w[i];
            sum+=w[i];
            if(w[i]>maxi)
            {
                maxi = w[i];
                maxi_index = i;
            }

        }

        if(n == 1)
        {
            if(x == w[0])
                cout<<"NO\n";
            else
            {
                cout<<"YES\n";
                cout<<w[0]<<"\n";
            }
        }
        else
        {
            if(x>sum)
            {
                cout<<" YES\n";
                for(int i=0; i<n; i++)
                    cout<<w[i]<<" ";
                cout<<"\n";
            }
            else if(x == sum)
                cout<<"NO\n";
            else
            {
                if(x<maxi)
                {
                    cout<<"YES\n";
                    cout<<maxi<<" ";
                    for(int i=0; i<n; i++)
                    {
                        if(i != maxi_index)
                            cout<<w[i]<<" ";
                    }
                    cout<<"\n";
                }
                else
                {
                    vector <int> temp;
                    temp.clear();

                    for(int i=0; i<n; i++)
                    {
                        if(x!=w[i])
                        {
                            temp.push_back(w[i]);

                            for(int j=0; j<n; j++)
                            {
                                if(j!=i)
                                {
                                    temp.push_back(w[j]);
                                }
                            }

                            goto h;
                        }
                    }

                    h:
                    for(int k=1; k<=n-1; k++)
                    {

                        if(checker(temp,x) == 1)
                        {
                            cout<<"YES\n";
                            for(int i=0; i<n; i++)
                                cout<<temp[i]<<" ";

                            cout<<"\n";
                            goto o;
                        }
                        else
                        {
                            auto ptr = temp.begin();
                            int q = temp[1];
                            temp.erase(ptr+1);
                            temp.push_back(q);
                          // printer(temp);
                        }

                    }

                    cout<<"NO\n";
                    goto o;

                }


            }

        }

o:
        t--;
    }

    return 0;
}

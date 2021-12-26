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
    int n;
    cin>>n;
    int sum=0;
    vector<int> z;
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        sum+=x;

        if(x == 0)
            z.push_back(x);
        else
            v.push_back(x);
    }

    cout<<"sum = "<<sum<<"\n";

    if( z.size() != 0)
    {
        if(sum%3 != 0)
        {
            sort(v.begin(),v.end());

            int temp = sum%3;
            bool found=0;

                for(int i=0; i<n; i++)
                {
                    if( v[i] >= temp && (v[i]-temp)%3 == 0)
                    {
                        found = 1;
                        auto x = v.begin() + i;
                        v.erase(x);
                        break;
                    }
                }

                if(found == 0)
                    cout<<"-1\n";
                else
                {
                    sort(v.begin(),v.end(),greater<int>());
                    for(int i=0; i<v.size(); i++)
                        cout<<v[i];
                    for(int i=0; i<z.size(); i++)
                        cout<<z[i];
                    cout<<"\n";
                }

        }
        else
        {
            sort(v.begin(),v.end(),greater<int>());
            for(int i=0; i<v.size(); i++)
                cout<<v[i];
            for(int i=0; i<z.size(); i++)
                cout<<z[i];
            cout<<"\n";
        }
    }
    else
        cout<<"-1\n";
    return 0;
}


#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
bool my_comparator(pair<int,int> a,pair<int,int> b)
{
    return a.first>b.first;
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>> a;
    lli sum=0;
    int maxi;
    int x;
    int max_index;
    vector<int> index;
    bool all_Equal=1;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        a.push_back(make_pair(x,i+1));
        if(i>0 && all_Equal == 1)
        {
            if(a[i] != a[i-1])
                all_Equal = 0;
        }

    }

    if(all_Equal == 0)
    {
        sort(a.begin(),a.end(),my_comparator);
        /*
        for(int i=0; i<n; i++)
            cout<<a[i].first<<" ";
        cout<<"\n";
        for(int i=0; i<n; i++)
            cout<<a[i].second<<" ";
        cout<<"\n"; */

        for(int i=0; i<n; i++)
        {
            cout<<"--- i = "<<i<<"-----\n";
            if(i==0)
            {
                maxi = a[1].first;
                max_index = 1;
            }

            else
            {
                maxi = a[0].first;
                max_index = 0;
            }


            sum=0;
            for(int j=0; j<n; j++)
            {

                if(j!=i && j!= max_index)
                {
                    cout<<"j = "<<j<<"\n";
                    sum+=a[j].first;
                    if(sum>maxi)
                        break;
                }
            }
            //cout<<sum<<"\n";
            if(sum == maxi)
            {
                index.push_back(a[i].second);
                // index+=' ';
                //cout<<a[i].second<<"\n";
            }

        }
        cout<<index.size()<<"\n";
        if(index.size() != 0)
            for(int i=0; i<index.size(); i++)
                cout<<index[i]<<" ";

    }
    else
    {
        if(n == 3)
        {
            cout<<"3\n";
            cout<<1<<" "<<2<<" "<<3;
        }
        else
            cout<<0<<"\n";
    }
    /*
    for(int i=0; i<n; i++)
        cout<<a[i].first<<" ";
    cout<<"\n";
    for(int i=0; i<n; i++)
        cout<<a[i].second<<" ";
    cout<<"\n";
    */


    return 0;
}

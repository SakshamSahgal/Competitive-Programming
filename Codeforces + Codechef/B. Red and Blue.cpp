#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
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
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        vector<pair<int,int>> r;
        vector<pair<int,int>> b;
        lli sum=0;
        int x;
        int maxx = INT_MIN;
        int max_prefix_upto1=0;
        for(int i=0; i<n; i++) //a input
        {
            cin>>x;
            sum+=x;
            if(sum > maxx)
            {
                maxx = sum;
                max_prefix_upto1 = i;
            }
            r.push_back({x,sum});
        }
        int m;
        cin>>m;

        sum=0;
        maxx = INT_MIN;
        int max_prefix_upto2=0;
        for(int i=0; i<m; i++) //b input
        {
            cin>>x;
            sum+=x;
            if(sum > maxx)
            {
                maxx = sum;
                max_prefix_upto2 = i;
            }
            b.push_back({x,sum});
        }

        {

        }


        vector<pair<int,int>> a;

        {
            sum=0;
            maxx = INT_MIN;
            for(int i=0; i<=max_prefix_upto1; i++) //putting r upto max prefix
            {
                sum+=r[i].first;
                if(sum>maxx)
                    maxx = sum;
                a.push_back({r[i].first,sum});
            }

            for(int i=0; i<=max_prefix_upto2; i++) //putting b upto max prefix
            {
                sum+=b[i].first;
                if(sum>maxx)
                    maxx = sum;
                a.push_back({b[i].first,sum});
            }

            for(int i = max_prefix_upto1+1; i<n; i++) //putting r left
            {
                sum+=r[i].first;
                if(sum>maxx)
                    maxx = sum;
                a.push_back({r[i].first,sum});
            }

            for(int i = max_prefix_upto2+1; i<m; i++) //putting b left
            {
                sum+=b[i].first;
                if(sum>maxx)
                    maxx = sum;
                a.push_back({b[i].first,sum});
            }
        }

        int max1 = max(0,maxx);

        {
            sum=0;
            maxx = INT_MIN;
            for(int i=0; i<=max_prefix_upto2; i++) //putting b upto max prefix
            {
                sum+=b[i].first;
                if(sum>maxx)
                    maxx = sum;
                a.push_back({b[i].first,sum});
            }

            for(int i=0; i<=max_prefix_upto1; i++) //putting r upto max prefix
            {
                sum+=r[i].first;
                if(sum>maxx)
                    maxx = sum;
                a.push_back({r[i].first,sum});
            }



            for(int i = max_prefix_upto2+1; i<m; i++) //putting b left
            {
                sum+=b[i].first;
                if(sum>maxx)
                    maxx = sum;
                a.push_back({b[i].first,sum});
            }

                        for(int i = max_prefix_upto1+1; i<n; i++) //putting r left
            {
                sum+=r[i].first;
                if(sum>maxx)
                    maxx = sum;
                a.push_back({r[i].first,sum});
            }
        }

        int max2 = max(0,maxx);

        cout<<max(max1,max2)<<"\n";
        t--;
    }

    return 0;
}

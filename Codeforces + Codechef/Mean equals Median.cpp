#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;


lli min_moves(lli *a,lli n,lli x)
{
    lli mini = 0;
    lli med_i = n/2 - 1*(!(n%2));

    for(int i=n-1; i>=med_i; i--)
    {
        if(x > a[i])
            mini += (x - a[i]);
    }
    return mini; // median ko x banane me min itne moves lagenge
}

bool is_possible(lli moves,lli x,lli n,lli *a)
{
    lli min_req = min_moves(a,n,x);
    if(min_req <= moves)
        return 1;
    else
        return 0;
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        lli sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            sum += a[i];
        }

        sort(a,a+n);

        if(sum%n == 0)
        {
            lli x = sum/n;
            lli low = 0;
            lli high = 1e9;
            lli mid;
            lli ans = INT_MAX;
            while(low <= high)
            {
                mid = ( low + high )/2;
                lli moves = mid*n;
                //cout<<"Trying = "<<moves<<" ";
                if(is_possible(moves,x + mid,n,a))
                {
                   // cout<<"Possible \n";
                    ans = moves;
                    high = mid - 1;
                }
                else
                {
                   // cout<<"Not possible\n";
                    low = mid + 1;
                }
                //cout<<"low = "<<low<<" high = "<<high<<"\n";
            }

            cout<<ans<<"\n";
        }
        else
        {
            lli num = sum;
            lli deno = n;

            lli y = deno - num%deno;
            lli z = (num + y)/deno;
            lli low = 0;
            lli high = 1e9;

            lli mid;
            lli ans;
            while(low <= high)
            {
                mid = (low+high)/2;
                lli moves = y + mid*deno;
                //cout<<"Trying = "<<moves<<" ";
                if(is_possible(moves,z+mid,n,a) )
                {
                    //cout<<"Possible \n";
                    high = mid - 1;
                    ans = moves;
                }
                else
                {
                    //cout<<"Not possible\n";
                    low = mid + 1;
                }
            }

            cout<<ans<<"\n";
        }




        t--;
    }
    return 0;
}

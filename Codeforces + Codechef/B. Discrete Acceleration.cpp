#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

//remember to use endl instead of \n for interactive problems.


void vector_printer( vector<ld> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,l;
        cin>>n>>l;
        vector<ld> a(n,0);
        vector<ld> a_t(n,0);
        vector<ld> b_t(n,0);
        for(int i=0;i<n;i++)
            cin>>a[i];

        for(int i=0;i<n;i++)
        {
            if(i == 0)
                a_t[i] = a[i];
            else
                a_t[i] = a_t[i-1] + (a[i] - a[i-1])/(1.0*(i+1));
        }

        for(int i=n-1;i>=0;i--)
        {
            if(i == n-1)
                b_t[i] = l - a[i];
            else
                b_t[i] = b_t[i+1] + (a[i+1] - a[i])/(1.0*(n-i));
        }


        vector_printer(a_t);
        vector_printer(b_t);

        lli st=0;
        lli ed=l;
        lli low = l;
        lli high = 0;
        while(st<=ed)
        {
            lli mid = (st+ed)/2;
            ld a_time;
            ld b_time;
            auto ptr_a = upper_bound(a.begin(),a.end(),mid);
            auto ptr_b = lower_bound(a.begin(),a.end(),mid);
            lli id_a = ptr_a - a.begin();
            lli id_b = ptr_b - a.begin();

            if(id_a == 0)
                a_time = mid;
            else
                a_time = a_t[id_a - 1] + ((ld)mid - a[(id_a-1)])/(1.0*(id_a+1));

            if(id_b == n)
                b_time = mid;
            else
                b_time = b_t[id_b] + (a[id_b] - (ld)mid)/((1.0)*(n-id_b+1));

            cout<<"mid = "<<mid<<"a = "<<a_time<<" b = "<<b_time<<"\n";
            if(a_time < b_time) //do not intersect
                st = mid+1;
            else //intersect
            {
                high = mid;
                ed = mid-1;
            }

        }




        while(st<=ed)
        {
            lli mid = (st+ed)/2;
            ld a_time;
            ld b_time;
            auto ptr_a = upper_bound(a.begin(),a.end(),mid);
            auto ptr_b = lower_bound(a.begin(),a.end(),mid);
            lli id_a = ptr_a - a.begin();
            lli id_b = ptr_b - a.begin();

            if(id_a == 0)
                a_time = mid;
            else
                a_time = a_t[id_a - 1] + ((ld)mid - a[(id_a-1)])/(1.0*(id_a+1));

            if(id_b == n)
                b_time = mid;
            else
                b_time = b_t[id_b] + (a[id_b] - (ld)mid)/((1.0)*(n-id_b+1));

            cout<<"mid = "<<mid<<"a = "<<a_time<<" b = "<<b_time<<"\n";
            if(a_time < b_time) //do not intersect
            {
                st = mid+1;
                low = mid;
            }
            else //intersect
                ed = mid-1;
        }

        cout<<low<<" "<<high<<"\n";

        t--;
    }
    return 0;
}


#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;


class Segiment_Tree
{
    lli *seg;
    lli sz;
public:
    Segiment_Tree(lli n)
    {
        sz = 4*n;
        seg = new lli[sz];
        memset(seg,-1,4*n*sizeof(lli));
    }

    void Build_min(lli ind,lli low,lli high,lli a[])
    {
        if(low == high)
        {
            seg[ind] = a[low];
            return;
        }
        else
        {
            lli mid = (low+high)/2;
            Build_min(2*ind + 1,low,mid,a);
            Build_min(2*ind + 2,mid+1,high,a);
            seg[ind] = min(seg[(2*ind+1)],seg[(2*ind + 2)]);
        }
    }


    void Build_max(lli ind,lli low,lli high,lli a[])
    {
        if(low == high)
        {
            seg[ind] = a[low];
            return;
        }
        else
        {
            lli mid = (low+high)/2;
            Build_max(2*ind + 1,low,mid,a);
            Build_max(2*ind + 2,mid+1,high,a);
            seg[ind] = max(seg[2*ind+1],seg[2*ind + 2]);
        }
    }

    lli Querry_min(lli ind,lli low,lli high,lli l,lli r)
    {
        if(r < low || l > high) // no overlap
            return inf;
        else if( l <= low && r >= high) //complete overlap
            return seg[ind];
        else
        {
            lli mid = (low + high)/2;
            lli left = Querry_min(2*ind + 1,low,mid,l,r);
            lli right = Querry_min(2*ind + 2,mid+1,high,l,r);
            return min(left,right);
        }
    }

    lli Querry_max(lli ind,lli low,lli high,lli l,lli r)
    {
        if(r < low || l > high) // no overlap
            return -inf;
        else if( l <= low && r >= high) //complete overlap
            return seg[ind];
        else
        {
            lli mid = (low + high)/2;
            lli left = Querry_max(2*ind + 1,low,mid,l,r);
            lli right = Querry_max(2*ind + 2,mid+1,high,l,r);
            return max(left,right);
        }
    }

    void Point_Update_min(lli ind,lli low,lli high,lli i,lli val) //ind - > index of the seg tree you are currently at , i -> index of the array you want to update
    {
        if(low == high)
        {
            seg[ind] = val;
            return;
        }
        else
        {
            lli mid = (low+high)/2;
            if(i<=mid)
                Point_Update_min((2*ind+1),low,mid,i,val);
            else
                Point_Update_min((2*ind+2),mid+1,high,i,val);
            seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
        }
    }

    void Point_Update_max(lli ind,lli low,lli high,lli i,lli val) //ind - > index of the seg tree you are currently at , i -> index of the array you want to update
    {
        if(low == high)
        {
            seg[ind] = val;
            return;
        }
        else
        {
            lli mid = (low+high)/2;
            if(i<=mid)
                Point_Update_min((2*ind+1),low,mid,i,val);
            else
                Point_Update_min((2*ind+2),mid+1,high,i,val);
            seg[ind] = max(seg[2*ind+1],seg[2*ind+2]);
        }
    }

    void print_segiment_tree(lli n)
    {
        line_printer(20);
        cout<<"\nSEG TREE - > \n";
        for(int i=0; i<4*n; i++)
            cout<<seg[i]<<" ";
        line_printer(20);
    }
};

lli sum_btw(lli ps[],lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli t;
    cin>>t;
    lli counter = 1;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        lli ps[n] = {0}; //stores prefix-sum of a array
        lli b[n]; //[ b[i] = (n-i)*a[i] ]
        lli ps2[n] = {0}; //stores the prefix sum of b array
        lli ans=0;
        vector<pll> v;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(i == 0)
                ps[i] = a[i];
            else
                ps[i] = ps[i-1] + a[i];
        }

        Segiment_Tree st(n);
        st.Build_min(0,0,n-1,ps);

        for(lli i=n-1; i>=0; i--)
            b[i] = (n-i)*a[i];

        for(int i=0; i<n; i++)
        {
            if(i == 0)
                ps2[i] = b[i];
            else
                ps2[i] = ps2[i-1] + b[i];
        }


        for(int i=0;i<n; i++)
        {
            if(a[i] >= 0)
            {
                lli l=i;
                lli h=n-1;
                lli mx=i; //max r for this particular l
                while(l<=h)
                {
                    lli mid = (l+h)/2;
                    lli pmn = st.Querry_min(0,0,n-1,i,mid); //min ps in range [i,mid]
                    if(i != 0)
                        pmn -= ps[i-1];

                    if(pmn >= 0)
                    {
                        mx = mid;
                        l = mid+1;
                    }
                    else
                        h = mid-1;
                }
                //cout<<"can go "<<i<<" "<<mx<<"\n";
                v.push_back({i,mx});
            }
        }

        for(auto i:v)
        {
            lli l = i.first;
            lli r = i.second;
            lli sss = sum_btw(ps2,l,r);
            ans += (sss - (n-r-1)*(sum_btw(ps,l,r)));
        }

        cout<<"Case #"<<counter<<": "<<ans<<"\n";
        counter++;
        t--;
    }
    return 0;
}


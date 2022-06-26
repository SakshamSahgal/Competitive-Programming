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
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

lli dist(lli f, lli t,lli n)
{
    if (f < t)
        return (t - f);
    else
        return(n + t - f);
}

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

int main()
{
    // GO_FAST
    // freopen("input.txt", "r", stdin);
    // freopen("myout.txt", "w", stdout);
    lli n, x;
    cin >> n >> x;
    x--;
    lli a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Segiment_Tree st(n);
    st.Build_min(0, 0, n - 1, a);
    //st.print_segiment_tree(n);
    lli to_sub;
    for (int i = x - 1; i >= 0; i--)
    {
        //     lli xc = (a[i] + 1);
        //     li hona = dist(i, x, n) + (a[i]) * n;
        //     cout << " abh - " << a[i] << " hona = " << dist(i, x, n) << " xc = " << xc << "\n";

        lli mini_in_btw = st.Querry_min(0, 0, n - 1, i + 1, x);
        lli mini_else;

        if (x == n - 1)
            mini_else = st.Querry_min(0, 0, n - 1, 0, i);
        else
            mini_else = min(st.Querry_min(0, 0, n - 1, 0, i), st.Querry_min(0, 0, n - 1, min(n - 1, x + 1), n - 1));

        lli abhi = a[i];
        if (mini_in_btw >= a[i] + 1 && mini_else >= a[i])
        {
            to_sub = a[i] + 1;
            for (int j = i + 1; j <= x; j++)
                a[j] -= to_sub;
            to_sub--;
            for (int j = 0; j < i; j++)
                a[j] -= to_sub;
            for (int j = x + 1; j < n; j++)
                a[j] -= to_sub;
            //cout<<"Found at "<<i<<"\n";
            a[i] = dist(i,x,n) + abhi*n;
            goto l;
        }
    }

    for(lli i=n-1;i>x;i--)
    {
        lli mini_in_btw = st.Querry_min(0, 0, n - 1, x+1, i);
        lli mini_else;
        lli abhi = a[i];

        if(i == n-1)
            mini_else = st.Querry_min(0, 0, n - 1,0,x);
        else
            mini_else = min(st.Querry_min(0, 0, n - 1,0,x),st.Querry_min(0, 0, n - 1,min(n-1,i+1),n-1));

        if(mini_else >= a[i] + 1 && mini_in_btw >= a[i])
        {
            to_sub = a[i];
            for (int j = x+1; j <= i; j++)
                a[j] -= to_sub;
            to_sub++;
            for (int j = 0; j <= x; j++)
                a[j] -= to_sub;
            for (int j = i + 1; j < n; j++)
                a[j] -= to_sub;
            //cout<<"Found at "<<i<<"\n";
            a[i] = dist(i,x,n) + abhi*n;
            goto l;
        } 
    }

    to_sub = a[x];
    for(int i=0;i<n;i++)
     a[i] -= to_sub; 
    
    a[x] = n*to_sub;
    l:
    
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
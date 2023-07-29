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

class segmentTreeSum
{
    vector<lli> tree;
public :

    segmentTreeSum(lli n)
    {
        tree.resize(4*n,-1);
    }

    void build(lli ind,lli low,lli high,vector<lli> &a) //nlogn
    {
        if(low == high)
            tree[ind] = a[low];
        else
        {
            lli mid = (low+high)/2;
            build(2*ind + 1,low,mid,a);
            build(2*ind + 2,mid+1,high,a);
            tree[ind] = (tree[2*ind+1]+tree[2*ind + 2]);
        }
    }

    lli sum(lli ind,lli low,lli high,lli l,lli r) //logn //ind -> index of the seg tree you are currently at , low,high=> range of array indexes that the node holds , l,r=> range that you want the ans for
    {
        if(r < low || l > high) // no overlap
            return 0;
        else if( l <= low && r >= high) //completly inside querry overlap
            return tree[ind];
        else
        {
            lli mid = (low + high)/2;
            lli left = sum(2*ind + 1,low,mid,l,r);
            lli right = sum(2*ind + 2,mid+1,high,l,r);
            return (left+right);
        }
    }

    void update(lli ind,lli low,lli high,lli i,lli val,vector<lli> &a) //ind - > index of the seg tree you are currently at , i -> index of the array you want to update //logn
    {
        if(low == high)
            tree[ind] = val,a[i] = val;
        else
        {
            lli mid = (low+high)/2;
            if(i<=mid)
                update(2*ind+1,low,mid,i,val,a);
            else
                update(2*ind+2,mid+1,high,i,val,a);
            tree[ind] = (tree[2*ind+1]+tree[2*ind+2]);
        }
    }
};

/*

6
1 3 2 0 4 5

*/

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n;
    cin>>n;
    vector<lli> a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    segmentTreeSum st(n);
    st.build(0,0,n-1,a); //
    line_printer(20);
    cout<<"\nSum in range index from 1 to 4 is = "<<st.sum(0,0,n-1,1,4)<<"\n";
    cout<<"\nSum in range index from 0 to 2 is = "<<st.sum(0,0,n-1,0,2)<<"\n";
    cout<<"\nSum in range index from 2 to 1 is = "<<st.sum(0,0,n-1,2,1)<<"\n";

    cout<<"Updating Point min (changing third index to 4)\n";
    st.update(0,0,n-1,3,4,a); //changing third index to 4
    cout<<"\nSum in range index from 1 to 4 is = "<<st.sum(0,0,n-1,1,4)<<"\n";
    cout<<"\nSum in range index from 0 to 2 is = "<<st.sum(0,0,n-1,0,2)<<"\n";
    cout<<"\nSum in range index from 2 to 1 is = "<<st.sum(0,0,n-1,2,1)<<"\n";
    return 0;
}


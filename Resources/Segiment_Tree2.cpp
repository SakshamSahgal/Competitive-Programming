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
    /*

    1
    6
    1 3 2 0 4 5

    */

    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        Segiment_Tree st(n);
        st.Build_min(0,0,n-1,a);
        st.print_segiment_tree(n);

        line_printer(20);
        cout<<"\nMin in range index from 1 to 4 is = "<<st.Querry_min(0,0,n-1,1,4)<<"\n";
        cout<<"\nMin in range index from 0 to 2 is = "<<st.Querry_min(0,0,n-1,0,2)<<"\n";

        cout<<"Updating Point min (changing third index to 4)\n";
        st.Point_Update_min(0,0,n-1,3,4); //changing third index to 4
        a[3] = 4;
        st.print_segiment_tree(n);
        cout<<"\nMin in range index from 1 to 4 is = "<<st.Querry_min(0,0,n-1,1,4)<<"\n";
        line_printer(20);
        Segiment_Tree st2(n);
        st2.Build_max(0,0,n-1,a);
        st2.print_segiment_tree(n);
        cout<<"\nMax in range index from 3 to 3 is = "<<st2.Querry_max(0,0,n-1,3,3)<<"\n";
        cout<<"\nMax in range index from 0 to 2 is = "<<st2.Querry_max(0,0,n-1,0,2)<<"\n";
        line_printer(20);
        t--;
    }
    return 0;
}


#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
const int N = 1e5;
class Segiment_Tree
{
public:
    int n;
    int t[2*N] = {0};


    void Input_array(int its_size)
    {
        n = its_size;
        for(int i=0; i<n; i++)
            cin>>t[n+i];
    }

    void build()
    {
        for(int i=n-1; i>0; i--)
        {
            cout<<"t["<<i<<"] = "<<"t["<<2*i<<"] + t["<<2*i+1<<"]\n";
            t[i] = t[2*i] + t[2*i + 1];
        }
    }

    void modify(int p, int value)    // set value at position p
    {
        for (t[p += n] = value; p /= 2; )
        {
            t[p] = t[p * 2] + t[p * 2 + 1];
        }
    }

    void print_tree_array()
    {
        cout<<"\n---------------------\n";
        for(int i=1; i<(2*n); i++)
        {

            if((i&(i-1)) == 0)
                cout<<"\n";

            cout<<t[i]<<" ";

        }
        cout<<"\n---------------------\n";
    }

    int find_sum(int l, int r)    // sum on interval [l, r)
    {
        r++;
        int res = 0;
        // if l is odd then right child
        // if l is even then left child
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l&1) res += t[l++];
            if (r&1) res += t[--r];
        }
        return res;
    }
};



int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        Segiment_Tree tree;
        int n;
        cin>>n;
        tree.Input_array(n);
        tree.build();
        tree.print_tree_array();
        cout<<tree.find_sum(0,3)<<"\n";
        tree.modify(2,5);
        cout<<tree.find_sum(0,3)<<"\n";
        t--;
    }
    return 0;
}



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

//remember to use endl instead of \n for interactive problems.

template<typename Z>
void Vec_2d_printer(vector<vector<Z>> x)
{
    cout<<"\n--------------------\n";
    for(auto i:x)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n--------------------\n";
}

class Sparce_Table
{
public :
    vector<vector<lli>> table;
    vector<vector<lli>> table_index;
    lli rows;
    lli col;
    void Build_Table(lli a[],lli n) //n is size of array
    {
        rows = ((lli)(log2(n)) + 1);
        col = n;
        vector<lli> temp(col,0);

        for(int i=0; i<rows; i++)
        {
            table.push_back(temp);
            table_index.push_back(temp);
        }

        for(lli i=0; i<rows; i++)
        {
            for(lli j = 0; j <= n - pow(2,i) ; j++)
            {
                if(i == 0)
                {
                    table[i][j] = a[j];
                    table_index[i][j] = j;
                }
                else
                {
                    lli a = table[i-1][j];
                    lli ai = table_index[i-1][j];
                    lli b = table[i-1][(j+powl(2,i-1))];
                    lli bi = table_index[i-1][(j+powl(2,i-1))];
                    if(a < b)
                    {
                        table[i][j] = a;
                        table_index[i][j] = ai;
                    }
                    else
                    {
                        table[i][j] = b;
                        table_index[i][j] = bi;
                    }
                }
            }
        }
    }

    void Print_table()
    {
        Vec_2d_printer(table);
        Vec_2d_printer(table_index);
    }

    lli range_minimum(lli l,lli r) //l to r inclusive
    {
        lli length_of_segiment = r-l+1;
        lli row_to_search = (lli)log2(length_of_segiment);
        return min( table[row_to_search][l], table[row_to_search][(lli)(r-powl(2,row_to_search)+1)]);
    }

    lli range_minimum_id(lli l,lli r) //l to r inclusive (gives the first index of minimum no(in case minimum no appears many times))
    {
        lli length_of_segiment = r-l+1;
        lli row_to_search = (lli)log2(length_of_segiment);
        if(   table[row_to_search][l] < table[row_to_search][(lli)(r-powl(2,row_to_search)+1)] )
            return table_index[row_to_search][l];
        else
            return table_index[row_to_search][(lli)(r-powl(2,row_to_search)+1)];
    }
};


int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    lli a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    Sparce_Table st;
    st.Build_Table(a,n);
    st.Print_table();
    lli l,r;
    cin>>l>>r;
    cout<<"Min between index l and r (inclusive) is = "<<st.range_minimum(l,r)<<"\n";
    cout<<"Min id between index l and r  (inclusive) is = "<<st.range_minimum_id(l,r)<<"\n";
    return 0;
}

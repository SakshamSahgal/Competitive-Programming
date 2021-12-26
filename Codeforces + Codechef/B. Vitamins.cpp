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

void matrix_printer(int r,int c,int *x)
{
    cout<<"\n";
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
            cout<<*((x+i*c)+j)<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    int table[n][4];
    map<lli,int> single_a;  //cost,index
    map<lli,int> single_b;
    map<lli,int> single_c;
    int cond_a=0,cond_b=0,cond_c=0;
    map<lli,int> doule_ab; //cost,index
    map<lli,int> doule_bc; //cost,index
    map<lli,int> doule_ca; //cost,index

    map<lli,int> abc; //cost,index

    for(int i=0; i<n; i++)
    {
        lli c;
        cin>>c;
        table[i][0] = c;
        string s;
        cin>>s;
        if(s.length() == 1)
        {
            if(s[0] == 'A')
            {
                single_a[c] = i;
                table[i][1] = 1;
                table[i][2] = 0;
                table[i][3] = 0;
            }
            else if(s[0] == 'B')
            {
                single_b[c] = i;
                table[i][1] = 0;
                table[i][2] = 1;
                table[i][3] = 0;
            }
            else
            {
                single_c[c] = i;
                table[i][1] = 0;
                table[i][2] = 0;
                table[i][3] = 1;
            }
        }
        else if(s.length() == 2)
        {
            if( (s[0] == 'A' || s[0] == 'B') && (s[1] == 'A' || s[1] == 'B') )
            {
                table[i][1] = 1;
                table[i][2] = 1;
                table[i][3] = 0;
                doule_ab[c] = i;
            }
            else if( (s[0] == 'B' || s[0] == 'C') && (s[1] == 'B' || s[1] == 'C') )
            {
                table[i][1] = 0;
                table[i][2] = 1;
                table[i][3] = 1;
                doule_bc[c] = i;
            }
            else
            {
                table[i][1] = 1;
                table[i][2] = 0;
                table[i][3] = 1;
                doule_ca[c] = i;
            }
        }
        else
        {
            table[i][1] = 1;
            table[i][2] = 1;
            table[i][3] = 1;
            abc[c] = i;
        }

        cond_a = cond_a||(table[i][1]);
        cond_b = cond_b||(table[i][2]);
        cond_c = cond_c||(table[i][3]);
    }

   // matrix_printer(n,4,(int*) table);


    if(cond_a&cond_b&cond_c)
    {
        int min_of_all_three = INT_MAX;
        if(abc.size() > 0)
            min_of_all_three = (abc.begin())->first;

        int min_of_single=INT_MAX;

        if(single_a.size() > 0 && single_b.size() > 0 && single_c.size() > 0)
            min_of_single = ((single_a.begin())->first) + ((single_b.begin())->first) + ((single_c.begin())->first);


        lli min_of_ab = INT_MAX;
        lli min_of_bc = INT_MAX;
        lli min_of_ca = INT_MAX;

        for(auto i:doule_ab)
        {
            for(int j=0; j<n; j++)
            {
                if(j != i.second)
                {
                    if(table[j][3] == 1)
                        min_of_ab = min((i.first+table[j][0]),min_of_ab);
                }
            }
        }

        for(auto i:doule_bc)
        {
            for(int j=0; j<n; j++)
            {
                if(j != i.second)
                {
                    if(table[j][1] == 1)
                        min_of_bc = min((i.first+table[j][0]),min_of_bc);
                }
            }
        }

        for(auto i:doule_ca)
        {
            for(int j=0; j<n; j++)
            {
                if(j != i.second)
                {
                    if(table[j][2] == 1)
                        min_of_ca = min((i.first+table[j][0]),min_of_ca);
                }
            }
        }

        int min_of_double = min(min(min_of_ab,min_of_bc),min_of_ca);

        cout<<min(min_of_double,min(min_of_all_three,min_of_single));
    }
    else
        cout<<"-1\n";

    return 0;
}

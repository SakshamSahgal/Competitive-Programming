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
map<int,set<int>> m;

display()
{
    for(auto i:m)
    {
        cout<<i.first<<" -> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }
}

void print_victory()
{

    for(auto i:m)
    {
        for(auto j:i.second)
           cout<<i.first<<" "<<j<<"\n";
    }
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

    int n,k;
    cin>>n>>k;

    if( k >= n || n < 3 )
        cout<<"-1\n";
    else
    {

        for(int i=1; i<=n; i++)
        {
            int c=0;
            bool done=0;
            for(int j=1; j<=n; j++)
            {
                if(i!=j)
                {
                    if(m[j].size() == 0)
                    {
                        m[i].insert(j);
                        c++;
                    }
                    else
                    {
                        auto ptr = m[j].find(i);

                        if( ptr == m[j].end() )
                        {
                            m[i].insert(j);
                            c++;
                        }
                    }
                }

                if(c == k)
                {
                    done = 1;
                    break;
                }
            }

            if(done == 0)
            {
                cout<<"-1\n";
                return 0;
            }

        }

        //display();
        cout<<n*k<<"\n";
        print_victory();
    }
    return 0;
}



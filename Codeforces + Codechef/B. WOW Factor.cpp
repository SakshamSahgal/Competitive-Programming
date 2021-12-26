#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    vector <char> c;
    int l;
    for(int i=0; i<(s.length()-1); i++)
    {
        if(s[i] == 'w')
            {
                l=0;


            }
    }
     /*
    for(int i=0; i<c.size(); i++)
        cout<<c[i]; */

    if(c.size()<3)
        cout<<0<<"\n";
    else
    {
        int counter = 0;
        //cout<<"\n";
        vector<pair<char,int>> p;
        int k=0;
        for(int i=0; i<c.size(); i++)
        {
            k = 0;
            if(c[i] == 'w')
            {

                while( (i+k)<c.size() && c[i+k] == 'w' )
                {
                    k++;
                }

                p.push_back(make_pair('w',k));
            }
            else
            {
                while( (i+k)<c.size() && c[i+k] == 'o')
                {
                    k++;
                }

                p.push_back(make_pair('o',k));
            }

            i+=(k-1);
        }
        /*
        for(int i=0; i<p.size(); i++)
            cout<<p[i].first<<" "<<p[i].second<<"\n"; */

        //cout<<"\n";
        int ans=0;
        for(int i=0; i<p.size(); i++)
        {
            if(p[i].first == 'w')
            {
                for(int j = (p.size()-1); j>i; j--)
                {
                    if(p[j].first == 'w')
                    {
                         counter = 0;
                        for(int k=j-1;k>i;k--)
                            {
                                if(p[k].first == 'o')
                                    counter+=p[k].second;
                            }
                        ans += (p[i].second)*(p[j].second)*(counter);
                    }
                }
            }
        }
        cout<<ans<<"\n";

    }
    return 0;
}


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
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

        string s,t;
        cin>>s>>t;
        map<char,int> sf;
        map<char,int> tf;
        bool more_freq_found=0;

        int st=0;
        bool found=0;
        bool array_req=0;


        for(int i=0; i<s.length(); i++)
            sf[s[i]]++;

        for(int i=0; i<t.length(); i++)
            tf[t[i]]++;

        if(sf.size() > tf.size() )
            more_freq_found = 1;

        for(auto i = tf.begin(); i!= tf.end(); i++)
        {
            auto ptr = sf.find(i->first);
            if( ptr == sf.end() )
            {
                cout<<"need tree\n";
                return 0;
            }
            else
            {
                if( ptr->second < i->second )
                {
                    cout<<"need tree\n";
                    return 0;
                }
                else if(ptr->second > i->second )
                    more_freq_found = 1;
            }
        }

        for(int i=0; i<t.length(); i++)
        {
            found = 0;
            for(int j=st; j<s.length(); j++)
            {
                if( t[i] == s[j] )
                {
                    //cout<<"found "<<t[i]<<" at = "<<j<<"\n";
                    found = 1;
                    st = j+1;
                    break;
                }
            }

            if(found == 0)
            {
                array_req = 1;
                break;
            }
        }

        if(array_req == 1 && more_freq_found == 1)
            cout<<"both\n";
        else if(array_req == 1)
            cout<<"array\n";
        else
            cout<<"automaton\n";

    return 0;
}

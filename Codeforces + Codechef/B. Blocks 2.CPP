#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

bool all_same(string x)
{
    for(int i=0; i<x.size(); i++)
    {
        if(x[i] != x[0])
            return 0;
    }
    return 1;
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    string s;
    string s1;
    cin>>s;
    s1=s;
 vector <int> index1;
 //make all white
    for(int i=0; i<(n-1); i++)
    {
        if(s[i] != 'W')
        {
            s[i] = 'W';
            if(s[i+1] == 'B')
                s[i+1] = 'W';
            else
                s[i+1] = 'B';
            index1.push_back(i+1);
        }
    }

    if(all_same(s) == 0)
    {
        //cout<<"cant make all white \n";
        vector <int> index;
        for(int i=0; i<(n-1); i++)
        {
            if(s1[i] != 'B')
            {
                s1[i] = 'B';
                if(s1[i+1] == 'B')
                    s1[i+1] = 'W';
                else
                    s1[i+1] = 'B';

                index.push_back(i+1);
            }
        }


        if(all_same(s1) == 0)
            cout<<"-1\n";
        else
        {
            cout<<index.size()<<"\n";
            for(int i=0;i<index.size();i++)
                cout<<index[i]<<" ";
            cout<<"\n";
        }

    }
    else
        {
            cout<<index1.size()<<"\n";
            for(int i=0;i<index1.size();i++)
                cout<<index1[i]<<" ";
            cout<<"\n";
        }
    return 0;
}

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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    string s;
    vector<char> y;
    vector<char> x;
    vector<char> z;
    cin>>s;
    int n = s.size();
    int index=n;
    //y
    for(int i=n-1; i>=0; i--)
    {
        if(s[i] != 'a')
        {
            //cout<<"inserting "<<s[i]<<"\n";
            y.insert(y.begin(),s[i]);
            index = i;
        }
        else
            break;
    }
    //x z
    for(int i=0; i<index; i++)
    {
        if(s[i] != 'a')
            x.push_back(s[i]);
        z.push_back(s[i]);
    }
h:
    /*
    //////////////////////////////
    cout<<"y = \n";
    for(int i=0; i<y.size(); i++)
        cout<<y[i];


    cout<<"\nx = \n";
    for(int i=0; i<x.size(); i++)
        cout<<x[i];
    cout<<"\n";
    ////////////////////////////// */
    if(x == y)
    {
        for(int i=0; i<z.size(); i++)
            cout<<z[i];
        cout<<"\n";
        return 0;
    }
    else if(y.size()>x.size())
    {
        if(y.size() !=0)
        {
            char g = y[0];
            y.erase(y.begin());
            z.push_back(g);
            x.push_back(g);
            goto h;
        }
        else
        {
            cout<<":(\n";
            return 0;
        }

    }
    else
    {
        cout<<":(\n";
        return 0;
    }
    return 0;
}


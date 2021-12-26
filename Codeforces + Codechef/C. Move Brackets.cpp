#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int checker(vector <char> x)
{
    stack <char> ss;
    for(int i=0; i<x.size(); i++)
    {
        if(x[i] == '(')
            ss.push('(');
        else
        {
            if(ss.size() != 0)
                ss.pop();
            else
                return i;
        }
    }
    return -1;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    usi t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<char> x;
        for(int i=0; i<n; i++)
            x.push_back(s[i]);

        int counter=0;
        u:
        int index = checker(x);
        if(index == -1)
            cout<<counter<<"\n";
        else
        {
            counter++;
            for(int i = x.size()-1; i>index; i--)
            {
                if(x[i] == '(')
                {
                    auto ptr = x.begin() + i;
                    x.erase(ptr);
                    ptr = x.begin();
                    x.insert(x.begin(),'(');
                    //cout<<"\n------------\n";
                    //for(int i=0; i<n; i++)
                      //  cout<<x[i];
                    //cout<<"\n------------\n";
                    goto u;
                }

            }


        }
        t--;
    }

    return 0;
}


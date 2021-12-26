#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;




bool checking(string s,string t,int r,int l,int st)
{

    //cout<<"right = "<<r<<" left = "<<l<<"\n";
    //cout<<"st = "<<st<<"\n";
    if(r == 0 && (st - l + 1) >= 0)
    {
        for(int i=r,j = st; i<t.size() && j>=0; i++,j--)
        {
            if(t[i] != s[j])
            {
                //cout<<"missmatched in L -"<<t[i]<<" "<<s[j]<<"\n";
                return 0;
            }

        }
        return 1;
    }
    else if( l == 0 && (st + r - 1) <= s.size() - 1 )
    {
        for(int i=0,j=st; i<r && j<s.size(); i++,j++)
        {
            if(t[i] != s[j])
            {
                //cout<<"missmatched in R -"<<t[i]<<" "<<s[j]<<"\n";
                return 0;
            }

        }
        return 1;
    }
    else
    {
        if( (st + r - 1) <=(s.size() - 1)   && (st + r - 1 - l) >= 0)
        {
            for(int i=0,j=st; i<r && j<s.size(); i++,j++)
            {
                //cout<<"comparing R "<<t[i]<<" "<<s[j]<<"\n";
                if(t[i] != s[j])
                {
                    //cout<<"missmatched in R -"<<t[i]<<" "<<s[j]<<"\n";
                    return 0;
                }

            }

            for(int i=r,j=(st + r - 2); i<t.size() && j>=0; i++,j--)
            {
               // cout<<"comparing L "<<t[i]<<" "<<s[j]<<"\n";
                if(t[i] != s[j])
                {
                    //cout<<"missmatched in L -"<<t[i]<<" "<<s[j]<<"\n";
                    return 0;
                }

            }

            return 1;
        }
        else
            return 0;

    }

}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int q;
    cin>>q;
    while(q)
    {
        string s;
        string t;
        cin>>s>>t;

        vector<int> index;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == t[0])
                index.push_back(i);
        }

        for(int i=0; i<index.size(); i++)
        {
            for(int x=0; x<=t.size(); x++)
            {
                if(checking(s,t,x,t.size()-x,index[i]) == 1)
                {
                    cout<<"YES\n";
                    goto h;
                }
            }
        }

        cout<<"NO\n";
        h:
        q--;
    }

    return 0;
}


#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void printer(vector<char> ss)
{
    //cout<<"\n------------------------------\n";
    for(int i=0; i<ss.size(); i++)
        cout<<ss[i];
    //cout<<"\n------------------------------\n";
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
        char s[n];
        string str;
        cin>>str;
        for(int i=0;i<n;i++)
            s[i]=str[i];

        n = unique(s,s+n) - s;

        if(n == 2 && s[0] == '0' && s[1] == '1')
            cout<<str<<"\n";

        else
        {
             vector<char> sv;
             for(int i=0; i<n; i++)
                sv.push_back(s[i]);

            int li = 0;
g:
            // cout<<"No starting at index "<<li<<"\n";
            for(int i=sv.size()-1; i>0; i--)
            {

                if(sv[i] == '0' && sv[i-1] == '1')
                {
                    //cout<<"found at index = "<<i<<"\n";
                    if((i+1)<sv.size())
                    {
                        if(sv[i+1] == '0')
                        {
                            auto ptr = sv.begin();
                            sv.erase(ptr+i);
                            //cout<<"deleting index"<<i<<"\n";
                            li = i;
                            goto g;
                        }
                        else
                        {
                            auto ptr = sv.begin();
                            sv.erase(ptr+i-1);
                            // cout<<"deleting index"<<i-1<<"\n";
                            li = i;
                            goto g;
                        }
                    }
                    else
                    {
                        auto ptr = sv.begin();
                        sv.erase(ptr+i-1);
                        // cout<<"deleting index"<<i-1<<"\n";
                        li =i;
                        goto g;
                    }
                }
            }
            printer(sv);
            cout<<"\n";
        }


        t--;
    }

    return 0;
}


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
    cout<<"\n------------------------------\n";
    for(int i=0; i<ss.size(); i++)
        cout<<ss[i];
    cout<<"\n------------------------------\n";
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    usi t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        char s;
        vector<char> sv;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            sv.push_back(s);
        }

        int li = 0;
g:
    cout<<"No starting at index "<<li<<"\n";
      printer(sv);
        for(int i=li; i<sv.size()-1; i++)
        {
            if(sv[i] == '1' && sv[i+1] == '0')
            {
                cout<<"found at index = "<<i<<"\n";
                if((i+2)<n)
                {
                    if(sv[i+2] == '0')
                    {
                        auto ptr = sv.begin();
                        sv.erase(ptr+i+1);
                        li = i;
                        cout<<"deleting index"<<i+1<<"\n";
                        goto g;
                    }
                    else
                    {
                        auto ptr = sv.begin();
                        sv.erase(ptr+i);
                        cout<<"deleting index"<<i<<"\n";
                        if((i-1)<0)
                            li = i;
                        else
                            li = i-1;
                        goto g;
                    }
                }
                else
                {
                    auto ptr = sv.begin();
                        sv.erase(ptr+i);
                     cout<<"deleting index"<<i<<"\n";
                        if((i-1)<0)
                            li = i;
                        else
                            li = i-1;
                        goto g;
                }
            }


        }


        t--;
    }

    return 0;
}


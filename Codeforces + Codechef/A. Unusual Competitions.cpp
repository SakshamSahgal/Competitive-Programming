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
    lli n;
    string s;
    cin>>n;
    cin>>s;
    lli o=0;
    lli c=0;
    lli l=0;
    for(int i=0; i<n; i++)
    {
        if(s[i] == ')')
            o++;
        else
            c++;
    }

if(o != c)
    cout<<"-1\n";
else
    {
        vector <char> brackets;
        for(int i=0;i<n;i++)
            {
                if(s[i] == '(')
                    brackets.push_back(s[i]);
                else
                    {
                        if(brackets.size()!=0)
                            brackets.pop_back();
                        else
                            {
                                brackets.clear();
                                //cout<<"problem at index = "<<i<<"\n";
                                lli k=0;
                                lli starting = i;
                                lli ending = n-1;
                                lli noo=0;
                                lli noc=0;
                                for(int j=i;j<n;j++)
                                    {
                                        if(s[j] == '(')
                                            noo++;
                                        else
                                            noc++;

                                        if(noo == noc)
                                            {
                                            //cout<<"till index = "<<j<<"\n";
                                            ending = j;
                                            break;
                                            }
                                    }
                                i = ending;
                                l+=(ending-starting+1);
                            }
                    }

            }
    cout<<l<<"\n";
    }
return 0;
}


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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> indexes;
        if(s.length() == 1)
        {
            if(s[0] == '?')
                cout<<"B\n";
            else
                cout<<s<<"\n";
        }
        else
        {

            for(int i=0; i<n; i++)
            {
                if(s[i] != '?')
                {
                    if(i == 0)
                    {
                        if(s[i+1] == '?')
                            indexes.push_back(i);
                    }
                    else if(i == n-1)
                    {
                        if(s[i-1] == '?')
                            indexes.push_back(i);
                    }
                    else
                    {
                        if(s[i-1] == '?' || s[i+1] == '?')
                            indexes.push_back(i);
                    }
                }
            }

            if(indexes.size() == 0)
            {
                if(s[0] == '?')
                {
                    for(int i=0; i<n; i++)
                    {
                        if(i%2 == 0)
                            s[i] = 'B';
                        else
                            s[i] = 'R';
                    }

                    cout<<s<<"\n";
                }
                else
                    cout<<s<<"\n";
            }
            else
            {
                for(int i=0; i<indexes.size(); i++)
                {
                    //cout<<"Doing = "<<indexes[i]<<"\n";
                    for(int j=indexes[i]-1,k=0; i>=0; j--,k++)
                    {
                        if(s[j] != '?')
                            break;
                        else
                        {
                            if(s[indexes[i]] == 'R')
                            {
                                if(k%2 == 0)
                                    s[j] = 'B';
                                else
                                    s[j] = 'R';
                            }
                            else
                            {
                                if(k%2 == 0)
                                    s[j] = 'R';
                                else
                                    s[j] = 'B';
                            }
                        }
                    }
                    for(int j=indexes[i]+1,k=0; i<n; j++,k++)
                    {
                        if(s[j] != '?')
                            break;
                        else
                        {
                            if(s[indexes[i]] == 'R')
                            {
                                if(k%2 == 0)
                                    s[j] = 'B';
                                else
                                    s[j] = 'R';
                            }
                            else
                            {
                                if(k%2 == 0)
                                    s[j] = 'R';
                                else
                                    s[j] = 'B';
                            }
                        }
                    }
                }

                cout<<s<<"\n";
            }
        }

        t--;
    }
    return 0;
}



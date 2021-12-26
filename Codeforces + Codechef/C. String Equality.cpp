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

void array_printer(int a[],int n)
{
    cout<<"\n----------------\n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n----------------\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n,k;
        cin>>n>>k;
        string a,b;
        cin>>a>>b;
        int ava[26] = {0};
        int req[26] = {0};
        int ext[26] = {0};

        for(int i=0; i<n; i++)
        {
            ava[a[i]-97]++;
            req[b[i]-97]++;
        }

        int last_req=0;

        for(int i=0; i<26; i++)
        {
            if(req[i] == 0)
            {
                if(ava[i]%k == 0)
                ext[i] += ava[i];
                else
                {
                    cout<<"No\n";
                    goto h;
                }
            }
            else
                last_req = i;
        }

        //cout<<" last req = "<<last_req<<"\n";

        for(int i=last_req+1; i<26; i++)
        {
            if(ava[i] != 0)
            {
                cout<<"No\n";
                goto h;
            }
        }

        //array_printer(ava,26);
        //array_printer(req,26);
        //array_printer(ext,26);

        for(int i=0; i<26; i++)
        {
            if( req[i] != 0 )
            {
                if( req[i] <= ava[i] )
                {
                    ext[i] = ava[i] - req[i];
                    req[i] = 0;
                    if(ext[i]%k != 0)
                    {
                        cout<<"No\n";
                        goto h;
                    }
                }
                else
                {
                    req[i]-=ava[i];

                    if(req[i]%k != 0)
                    {
                        cout<<"No\n";
                        goto h;
                    }
                }
            }

        }


        for(int i=0; i<26; i++)
        {
            if(req[i] != 0)
            {
                while(req[i] != 0)
                {
                    bool found=0;
                    int mini = INT_MAX;
                    int mini_index = 0;

                    for(int j=0; j<i; j++)
                    {
                        if(ext[j] != 0 && ext[j] < mini)
                        {
                            found = 1;
                            mini = ext[j];
                            mini_index = j;
                        }
                    }

                    if(found == 1)
                    {
                        //cout<<"mini found at index = "<<mini_index<<"\n";

                        if(ext[mini_index] >= req[i])
                        {
                            ext[mini_index] -= req[i];
                            req[i] = 0;
                            break;
                        }
                        else
                        {
                             req[i] -= ext[mini_index];
                             ext[mini_index]=0;
                        }
                    }
                    else
                    {
                        cout<<"No\n";
                        goto h;
                    }
                }
            }
        }

        for(int i=0;i<26;i++)
            {
                if(ext[i] != 0)
                    {
                        cout<<"No\n";
                        goto h;
                    }

            }
        //array_printer(ava,26);
        //array_printer(req,26);
        //array_printer(ext,26);

        cout<<"Yes\n";
h:
        t--;
    }
    return 0;
}



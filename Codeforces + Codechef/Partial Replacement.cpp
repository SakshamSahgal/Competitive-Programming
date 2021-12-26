#include<iostream>
#include<algorithm>
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
    usi t;
    cin>>t;
    while(t)
    {
        int n,k,c=0;
        cin>>n>>k;
        int fi= -1;
        int li= -1;
        int nos=0;
        string s;
        cin>>s;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '*')
            {
                if(fi == -1)
                    fi = i;
                else
                    li = i;
                nos++;
            }
        }

        if(nos<=2)
            cout<<nos<<"\n";
        else
        {

            for(int i=0; i<n; i++)
            {
                if(s[i] == '*' || s[i] == 'x')
                {
                    for(int j=i+k; j>i; j--)
                    {

                        if(j>=n)
                            j = n-1;

                        if(s[j] == '*' )
                        {

                            //cout<<"i = "<<i<<" j = "<<j<<"\n";
                            c++;
                            s[j] = 'x';
                            if(i == fi)
                            {
                                s[i] = 'x';
                                c++;
                            }
                            i = j-1;
                            //cout<<s<<"\n";
                            break;
                        }

                    }

                }
            }


           // cout<<s<<"\n";
            cout<<c<<"\n";
        }


        t--;
    }

    return 0;
}


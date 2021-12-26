#include<iostream>
#include<algorithm>
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
    int m,s;
    cin>>m>>s;
    string s_max;
    if( (s == 0 && (m>1) )|| s>(9*m))
        cout<<"-1 -1";
    else if(s == 0 && m == 1)
        cout<<0<<" "<<0<<"\n";
    else
    {
        for(int j=1; j<=m; j++)
        {
            //cout<<"j = "<<j<<"\n";
            for(int i=9; i>=0; i--)
            {
                //cout<<"compare = "<<(s-i)<<" "<<(m-j)<<"\n";
                if( (s-i)>=0 )
                {
                    s_max+=(i+48);
                    s-=i;
                    // cout<<"sum now = "<<s<<"\n";
                    break;
                }
            }
        }
        if(s_max[m-1] == '0')
        {
            if(m > 2)
            {
                int index=0;
                char s_min[m];
                for(int i=0; i<m; i++)
                    s_min[i] = '0';

                for(int i=m-2; i>=0; i--)
                {
                    if(s_max[i] != '0')
                    {
                        s_min[0] = s_max[i];
                        index = i;
                        break;
                    }
                }

                for(int i=0; i<m; i++)
                {
                    if(s_max[i] != '0' && i!=index)
                    {
                        s_min[m-1-i] = s_max[i];
                    }
                    else
                        break;
                }

                for(int i=0; i<m; i++)
                    cout<<s_min[i];

                cout<<" "<<s_max<<"\n";

            }
            else
                cout<<s_max<<" "<<s_max<<"\n";
        }
        else
        {
            for(int i=m-1; i>=0; i--)
                cout<<s_max[i];
            cout<<" ";
            cout<<s_max<<"\n";
        }


    }
    return 0;
}


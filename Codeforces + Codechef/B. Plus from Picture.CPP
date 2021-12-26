#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int max_index=0;

bool continuity_check(int n,int x[])
{
    bool started=0;
    bool max_found=0;
    bool ended=0;
    for(int i=0; i<n; i++)
    {
        if(x[i] == 1 && started == 0)
        {
            started = 1;
            //cout<<"started at index "<<i<<"\n";
            continue;
        }

        if(i == n-3 && started == 0)
            return 0;


        if(started == 1 && max_found == 0)
        {
            if(x[i] != 1)
            {
                if(x[i] >= 3)
                {
                    if(x[i+1] == 1)
                    {
                        max_found = 1;
                        max_index = i;
                        //cout<<"max found at index "<<i<<"\n";
                        continue;
                    }
                    else
                        return 0;
                }

                else
                    return 0;
            }
        }

        if(i == n-2 && max_found == 0)
            return 0;

        if(max_found == 1 && ended == 0)
        {
            if(x[i] != 1 || i == n-1)
            {
                if(x[i] == 0 || (i == n-1 && x[i] == 1))
                {
                    ended = 1;
                    // cout<<"ended at index "<<i<<"\n";
                    continue;
                }
                else
                    return 0;
            }
        }

        if(i == n-1 && ended == 0)
            return 0;

        if(ended == 1)
        {
            if(x[i] != 0)
                return 0;
        }
    }
    return 1;
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int h,w;
    cin>>h>>w;
    char x[h][w];
    int rows[h];
    int cols[w];
    int sum=0;
    for(int i=0; i<h; i++)
    {
        sum=0;
        //counting rows
        for(int j=0; j<w; j++)
        {
            cin>>x[i][j];
            if(x[i][j] == '*')
                sum++;
        }

        rows[i] = sum;
    }
    if(h<3||w<3)
        cout<<"NO\n";
    else
    {
        for(int i=0; i<w; i++)
        {
            sum=0;
            //counting coloumns
            for(int j=0; j<h; j++)
            {
                if(x[j][i] == '*')
                    sum++;
            }
            cols[i] = sum;
        }
        /*
        cout<<"Row sum = \n";
        for(int i=0; i<h; i++)
            cout<<rows[i]<<"\n";
        cout<<"col sum = \n";
        for(int i=0; i<w; i++)
            cout<<cols[i]<<" "; */
        if(continuity_check(h,rows) == 1)
        {
            char d[w];
            for(int i=0; i<w; i++)
                d[i] = x[max_index][i];

            int len = unique(d,d+w)-d;
            /*
            cout<<"\n-------------max wali row --------------\n";
            for(int i=0; i<len; i++)
                cout<<d[i];
            cout<<"\n----------------------------------------\n";*/

            if((len == 1 && d[0] == '*') || (len == 2) || (len == 3 && d[0] == '.' && d[1] == '*' && d[2] == '.') )
            {
                if(continuity_check(w,cols) == 1)
                {
                    char f[h];
                    for(int i=0; i<h; i++)
                        f[i] = x[i][max_index];

                    int len2 = unique(f,f+h)-f;
                    /*
                    cout<<"\n-------------max wala col --------------\n";
                    for(int i=0; i<len2; i++)
                        cout<<f[i];
                    cout<<"\n----------------------------------------\n"; */

                   if((len2 == 1 && f[0] == '*') || (len2 == 2) || (len2 == 3 && f[0] == '.' && f[1] == '*' && f[2] == '.') )
                    cout<<"YES\n";
                   else
                    cout<<"NO\n";

                }
                else
                    cout<<"NO\n";


            }

            else
                cout<<"NO\n";
        }
        else
            cout<<"NO\n";



    }

    return 0;
}

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

int imp(string x)
{
    int c=0;
    for(int i=0; i<x.size()-1; i++)
    {
        if(x[i] == x[i+1])
            c++;
    }
    return c;
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
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(s.length() == 1)
        {
            if(s[0] == '?')
                cout<<"B\n";
            else
                cout<<s<<"\n";
        }
        else
        {
            string c,d;

            for(int i=0; i<n; i++)
            {
                if(s[i] == '?')
                {
                    if(i%2 == 0)
                    {
                        c+='B';
                        d+='R';
                    }
                    else
                    {
                        c+='R';
                        d+='B';
                    }
                }
                else
                {
                    c+=s[i];
                    d+=s[i];
                }
            }




            string a = s;

            for(int i=0; i<n; i++)
            {
                if(s[i] == '?')
                {
                    if(i == 0)
                    {
                        if( s[i+1] == 'R')
                            s[i] = 'B';
                        else if( s[i+1] == 'B')
                            s[i] = 'R';
                        else
                            s[i] = 'R';
                    }
                    else if(i == n-1)
                    {
                        if(s[i-1] == 'R')
                            s[i] = 'B';
                        if(s[i-1] == 'B')
                            s[i] = 'R';
                        else
                            s[i] = 'R';
                    }
                    else
                    {
                        if(s[i-1] == 'B' && s[i+1] == 'B')
                            s[i] = 'R';
                        else if(s[i-1] == 'R' && s[i+1] == 'R')
                            s[i] = 'B';
                        else
                        {
                            if(s[i-1] == 'R' && s[i+1] == '?')
                                s[i] = 'B';
                            else
                                s[i] = 'R';
                        }
                    }
                }
            }


            for(int i=0; i<n; i++)
            {
                if(a[i] == '?')
                {
                    if(i == 0)
                    {
                        if( a[i+1] == 'R')
                            a[i] = 'B';
                        else if( s[i+1] == 'B')
                            a[i] = 'R';
                        else
                            a[i] = 'B';
                    }
                    else if(i == n-1)
                    {
                        if(a[i-1] == 'R')
                            a[i] = 'B';
                        if(s[i-1] == 'B')
                            a[i] = 'R';
                        else
                            a[i] = 'B';
                    }
                    else
                    {
                        if(a[i-1] == 'B' && a[i+1] == 'B')
                            a[i] = 'R';
                        else if(a[i-1] == 'R' && a[i+1] == 'R')
                            a[i] = 'B';
                        else
                        {
                            if(a[i-1] == 'R' && a[i+1] == '?')
                                a[i] = 'B';
                            else
                                a[i] = 'R';
                        }
                    }
                }
            }
            int is = imp(s);
            int ia = imp(a);
            int ic = imp(c);
            int id = imp(d);
            //cout<<imp(s)<<" "<<imp(a)<<" "<<imp(c)<<" "<<imp(d)<<"\n";

            if( min(min(is,ia),min(ic,id))  == is)
                cout<<s<<"\n";
            else if( min(min(is,ia),min(ic,id)) == ia )
                cout<<a<<"\n";
            else if(min(min(is,ia),min(ic,id)) == ic )
                cout<<c<<"\n";
            else
                cout<<d<<"\n";
        }

        t--;
    }
    return 0;
}



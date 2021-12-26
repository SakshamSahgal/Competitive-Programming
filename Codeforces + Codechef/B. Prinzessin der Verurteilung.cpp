#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void map_printer(map<char,int> m)
{
    cout<<"\n";
    for(auto i=m.begin(); i!=m.end(); i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n";
}

bool search_for_two(char a,char b,string s)
{
    for(int i=0; i<s.size()-1; i++)
    {
        if(s[i] == a && s[i+1] == b)
            return 1;
    }
    return 0;
}


bool search_for_three(char a,char b,char c,string s)
{
    for(int i=0; i<s.size()-2; i++)
    {
        if(s[i] == a && s[i+1] == b && s[i+2] == c)
            return 1;
    }
    return 0;
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
        map<char,int> freq;

        for(int i=0; i<n; i++)
            freq[s[i]]++;

       // map_printer(freq);
        char x = 'a';
        int j=0;
        bool found=0;

        char d = 'a';

        for(int i=0;i<26;i++,d++)
            {
                found = 0;
                for(int j=0;j<s.size();j++)
                    {
                        if(s[j] == d)
                        {
                             found = 1;
                             break;
                        }
                    }
                if(found == 0)
                {
                    cout<<d<<"\n";
                    goto h;
                }

            }

            x = 'a';
            char a;
            char b;
            char c;
            for(int i=0; i<26; i++)
            {
                for(int j=0; j<26; j++)
                {
                    a = (char)(x+i);
                    b = (char)(x+j);
                    if(search_for_two(a,b,s) == 0)
                    {
                        cout<<a<<b<<"\n";
                        goto h;
                    }
                }
            }
            x = 'a';
            for(int i=0; i<26; i++)
            {
                for(int j=0; j<26; j++)
                {
                    for(int k=0; k<26; k++)
                    {
                        a = (char)(x+i);
                        b = (char)(x+j);
                        c = (char)(x+k);
                        if(search_for_three(a,b,c,s) == 0)
                            {
                            cout<<a<<b<<c<<"\n";
                            goto h;
                            }
                    }
                }

            }
h:
        t--;
    }

    return 0;
}

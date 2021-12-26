#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

map<string,lli> fm;
map<string,lli> fp;
map<string,lli> fs;


string generator(char s,int i)
{
    string ss;
    ss += to_string(i);
    ss += s;
    return ss;
}

void add_to(string s)
{
    if(s[1] == 'm')
        fm[s]++;
    else if(s[1] == 'p')
        fp[s]++;
    else if(s[1] == 's')
        fs[s]++;
}

bool zero_check()
{
    cout<<"\n-------------------------\n";
    for(auto i:fm)
    {
        cout<<"at = "<<i.first<<"\n";
        if(i.second == 1)
        {
            lli no = i.first[0] - 48;
            //cout<<"checking for "<<generator('m',no-1)<<"\n";
            if( fm[generator('m',no-1)] == 1 && fm[generator('m',no+1)] == 1)
                return 1;
        }
    }
    for(auto i:fs)
    {
        cout<<"at = "<<i.first<<"\n";
        if(i.second == 1)
        {
            lli no = i.first[0] - 48;
            //cout<<"at "<<i.first<<" "<<"checking for "<<generator('s',no-1)<<" and "<<generator('s',no+1)<<"\n";
            if( fs[generator('s',no-1)] == 1 && fs[generator('s',no+1)] == 1)
                return 1;
        }
    }
    for(auto i:fp)
    {
        cout<<"at = "<<i.first<<"\n";
        if(i.second == 1)
        {
            lli no = i.first[0] - 48;
            if( fp[generator('p',no-1)] == 1 && fp[generator('p',no+1)] == 1)
                return 1;
        }
    }
    cout<<"\n-------------------------\n";
    return 0;
}

bool one_check()
{
    for(auto i:fm)
    {
        if(i.second == 2)
            return 1;
    }
    for(auto i:fs)
    {
        if(i.second == 2)
            return 1;
    }
    for(auto i:fp)
    {
        if(i.second == 2)
            return 1;
    }

    for(auto i:fm)
    {
        cout<<"at = "<<i.first<<"\n";
        lli no = i.first[0] - 48;
        cout<<"no = "<<no<<"\n";
        cout<<"checking for "<<generator('m',no+1)<<"\n";
        if(i.second == 1 && fm[generator('m',no+1)] == 1)
                return 1;
    }

    for(auto i:fs)
    {
        cout<<"at = "<<i.first<<"\n";
        lli no = i.first[0] - 48;
        cout<<"checking for "<<generator('s',no+1)<<"\n";
        if(i.second == 1 && fs[generator('s',no+1)] == 1)
                return 1;
    }

    for(auto i:fp)
    {
        cout<<"at = "<<i.first<<"\n";
        lli no = i.first[0] - 48;
        cout<<"checking for "<<generator('p',no+1)<<"\n";
        if(i.second == 1 && fp[generator('p',no+1)] == 1)
                return 1;
    }

    return 0;
}


void Map_printer(map<string,lli> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin(); i!=x.end(); i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}



int main()
{
    //GO_FAST
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    add_to(s1);
    add_to(s2);
    add_to(s3);

    Map_printer(fm);
    Map_printer(fs);
    Map_printer(fp);

    if( (s1 == s2 && s2 == s3) || zero_check() )
        cout<<0<<"\n";
    else
    {
        if(one_check() == 1)
        cout<<1<<"\n";
        else
            cout<<2<<"\n";
    }
    return 0;
}

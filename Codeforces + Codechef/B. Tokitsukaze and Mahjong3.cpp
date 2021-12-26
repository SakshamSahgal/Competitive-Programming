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

void add_to(string s)
{
    if(s[1] == 'm')
        fm[s]++;
    else if(s[1] == 'p')
        fp[s]++;
    else if(s[1] == 's')
        fs[s]++;
}

void Map_printer(map<string,lli> x)
{
    cout<<"\n----------------------\n";
    for(auto i:x)
        cout<<i.first<<" -> "<<i.second<<"\n";
    cout<<"\n----------------------\n";
}

string generator(char s,int i)
{
    string ss;
    ss += to_string(i);
    ss += s;
    return ss;
}

bool zero_check()
{
    //cout<<"\n-------------------------\n";
    for(auto i:fm)
    {
        //cout<<"at = "<<i.first<<"\n";
        if(i.second == 1)
        {
            lli no = i.first[0] - 48;
            // cout<<"checking for "<<generator('m',no-1)<<" and "<<generator('m',no+1)<<"\n";
            if( fm[generator('m',no-1)] == 1 && fm[generator('m',no+1)] == 1)
                return 1;
        }
    }
    for(auto i:fs)
    {
        // cout<<"at = "<<i.first<<"\n";
        if(i.second == 1)
        {
            lli no = i.first[0] - 48;
            //  cout<<"checking for "<<generator('s',no-1)<<" and "<<generator('s',no+1)<<"\n";
            if( fs[generator('s',no-1)] == 1 && fs[generator('s',no+1)] == 1)
                return 1;
        }
    }
    for(auto i:fp)
    {
        //cout<<"at = "<<i.first<<"\n";
        if(i.second == 1)
        {
            lli no = i.first[0] - 48;
            // cout<<"checking for "<<generator('p',no-1)<<" and "<<generator('p',no+1)<<"\n";
            if( fp[generator('p',no-1)] == 1 && fp[generator('p',no+1)] == 1)
                return 1;
        }
    }
    //  cout<<"\n-------------------------\n";
}

bool one_check()
{
    for(int i=1;i<=9;i++)
    {
        if( fm[generator('m',i)] == 1)
        {
            lli no =  generator('m',i)[0] - 48;
            cout<<no<<"\n";
            if( ( fm[generator('m',no-1)] == 1 && fm[generator('m',no+1)] == 0 ) || ( fm[generator('m',no-1)] == 0 && fm[generator('m',no+1)] == 1 ) )
                return 1;
        }
        else
        {
            lli no =  generator('m',i)[0] - 48;
            cout<<no<<"\n";
            if(( fm[generator('m',no-1)] == 1 && fm[generator('m',no+1)] == 0 ))
        }
    }


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

    if( (s1 == s2 && s2 == s3) || zero_check() == 1)
        cout<<0<<"\n";
    else
    {

    }
    return 0;
}

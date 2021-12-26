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

lli Eular_GCD(lli a,lli b)
{
    lli temp;
x:
    if(a!=0 && b!=0)
    {
        temp = a;
        a = b;
        b = temp%b;
        goto x;
    }
    else
        return max(a,b);
}

lli LCM(lli a,lli b)
{
    return (a*b)/Eular_GCD(a,b);
}

pair<lli,lli> wtow(lli a,lli b,lli c,lli d)
{
    pair<lli,lli> p;
    lli lcm_ac = LCM(a,c);

    lli new_screen_width = lcm_ac;
    lli new_screen_height = b*(lcm_ac/a);

    lli new_movie_width = lcm_ac;
    lli new_movie_height = d*(lcm_ac/c);

    if(new_movie_height > new_screen_height)
    {
        p.first = -1;
        p.second = -1;
        return p;
    }
    else
    {
        lli empty_width = new_screen_width;
        lli empty_height = new_screen_height - new_movie_height;


        lli total_area = new_screen_height*new_screen_width;
        lli empty_area = empty_height*empty_width;

        p.first = empty_area/Eular_GCD(empty_area,total_area);
        p.second = total_area/Eular_GCD(empty_area,total_area);
        return p;
    }
}


pair<lli,lli> htoh(lli a,lli b,lli c,lli d)
{
    pair<lli,lli> p;
    lli lcm_db = LCM(d,b);

    lli new_screen_height = lcm_db;
    lli new_screen_width = a*(lcm_db/b);

    lli new_movie_height = lcm_db;
    lli new_movie_width = c*(lcm_db/d);

    if(new_movie_width > new_screen_width)
    {
        p.first = -1;
        p.second = -1;
        return p;
    }
    else
    {
        lli empty_height = new_screen_height;
        lli empty_width = new_screen_width - new_movie_width;

        lli total_area = new_screen_height*new_screen_width;
        lli empty_area = empty_height*empty_width;


        p.first = empty_area/Eular_GCD(empty_area,total_area);
        p.second = total_area/Eular_GCD(empty_area,total_area);
        return p;
    }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

    lli a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a == c && b == d)
        cout<<"0/1\n";
    else
    {
        if(htoh(a,b,c,d).first == -1)
            cout<<wtow(a,b,c,d).first<<"/"<<wtow(a,b,c,d).second<<"\n";
        else
            cout<<htoh(a,b,c,d).first<<"/"<<htoh(a,b,c,d).second<<"\n";
    }


    return 0;
}



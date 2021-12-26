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
string s1,s2;

void rep(int lcm)
{

    int new_length_1 = lcm/s1.length();
    int new_length_2 = lcm/s2.length();
    string temp1 = s1;
    string temp2 = s2;
    for(int i=1; i<=(new_length_1-1); i++)
        s1+=temp1;

    for(int i=1; i<=(new_length_2-1); i++)
        s2+=temp2;
}


bool all_equal()
{
    for(int i=0; i<s1.length(); i++)
    {
        if(s1[i]!=s2[i])
            return 0;
    }
    return 1;
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

        cin>>s1>>s2;
        if(s1.length() == s2.length())
        {
            if(all_equal() == 1)
                cout<<s1<<"\n";
            else
                cout<<"-1\n";
        }
        else
        {
            lli lcm = ((s1.length())*(s2.length()))/(__gcd(s1.length(),s2.length()));
            //cout<<"lcm = "<<lcm<<"\n";
            rep(lcm);
            //cout<<s1<<" "<<s2<<"\n";

           if(all_equal() == 1)
                cout<<s1<<"\n";
            else
                cout<<"-1\n";


        }
        t--;
    }
    return 0;
}



#include<iostream>
#include<cstring>
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



bool type(string s)
{
    int n = s.length();
    int a[n];
    for(int i=0; i<n; i++)
    {
        if(s[i]>=65 && s[i]<= 90)
            a[i] = 1; //char
        else
            a[i] = 0; //number
    }

    n = unique(a,a+n) - a;
    if(n == 2)
        return 0; //char and number
    else
        return 1; //char no char no
}

string extract_string(string s)
{
    string x;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]>=65 && s[i]<=90)
            x+=s[i];
        else
            break;
    }
    return x;
}

int Col_to_no(string s)
{

    int n = s.length();
    return ((s[max(n-1,0)]-64) + (n>=2)*(s[max(n-2,0)]-64)*26 + (n>=3)*(s[max(n-3,0)]-64)*pow(26,2) + (n>=4)*(s[max(n-4,0)]-64)*pow(26,3) + (n>=5)*(s[max(n-5,0)]-64)*(pow(26,4)));
}


string int_extract(string s)
{
    string x;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]>=48 && s[i] <= 57)
            x+= s[i];
    }
    return x;
}

pair<int,int> Extract_row_and_col(string s)
{
    bool row_found=0;
    bool col_found=0;
    int row=0;
    int col=0;
    int r;
    int c;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == 'R')
            r = i;
        if(s[i] == 'C')
            c = i;
    }

    //cout<<"r = "<<r<<"c = "<<c<<"\n";

    for(int i=r+1; i<c; i++)
        row += pow(10,(c-i-1))*(s[i]-48);

    for(int i=c+1; i<s.length(); i++)
        col += pow(10,(s.length()-i-1))*(s[i]-48);

    //cout<<"row & col= "<<row<<" "<<col<<" "<<"\n";
    pair<int,int> p;
    p.first = row;
    p.second = col;
    return p;
}

string no_to_string(int n)
{
   // cout<<"n = "<<n<<"\n";
    vector<char> c;
    string s;
    while( n != 0)
    {
        char x;

        if( (n%26) == 0 )
            x = 'Z';
        else
            x = 'A' + n%26 - 1;

        //cout<<"x = "<<x<<"\n";

        c.insert(c.begin(),x);

        if(n%26 == 0)
            n--;

        n = n/26;
    }

    for(int i=0;i<c.size();i++)
        s += c[i];

    return s;
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
        string s;
        cin>>s;
        //cout<<type(s)<<"\n";
        if(type(s) == 0)
        {
            //cout<<extract_string(s)<<"\n";
            cout<<"R"<<int_extract(s)<<"C"<<Col_to_no(extract_string(s))<<"\n";
        }
        else
        {
            pair<int,int> p = Extract_row_and_col(s);
            cout<<no_to_string(p.second)<<p.first<<"\n";
        }


        t--;
    }
    return 0;
}


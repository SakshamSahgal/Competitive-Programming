#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int a=0;
int b=0;
bool is_palindrome = 1;
map<int,int> fz;
int c=0;
string s;
void reverse_index(int n)
{
    map<int,int> temp;
    int x;
    for(auto i=fz.begin(); i!=fz.end(); i++)
    {
        x = i->first;
        temp[n-1-x] = n-1-x;
    }

    fz.clear();
    fz = temp;
}
void map_printer(map<int,int> m)
{
    cout<<"\n--------------------\n";
    for(auto i = m.begin(); i!=m.end(); i++)
        cout<<i->second<<"\n";
    cout<<"\n--------------------\n";
}
bool chance(int player, int n)
{

    if(is_palindrome == 0)
    {
       // if(player%2 == 0)
           // cout<<"A choose to reverse the string \n";
       // else
           // cout<<"B choose to reverse the string \n";
        reverse_index(n);
       // map_printer(fz);
        //cout<<"Now string is not reversible\n";
        is_palindrome = 1;
        return 1;
    }
    else
    {
        if(fz.size()>0)
        {
            if(n%2==1) //n&1 == 1 //odd
            {
                if(s[n/2] == '0')
                {
                    s[n/2] = '1';
                    if(player%2 == 0)
                    {
                       // cout<<"A choose to pay 1 dollar and paint index "<<n/2<<" to 1\n";
                        a++;
                    }

                    else
                    {
                       // cout<<"B choose to pay 1 dollar and paint index "<<n/2<<" to 1\n";
                        b++;
                    }
                    auto ptr = fz[n/2];
                    fz.erase(ptr);
                    is_palindrome = 1;
                    //cout<<"String is still palindrome\n";
                }
                else
                {
                    c++;
                    auto ptr = fz.begin();
                    s[ptr->second] = 1;
                    if(player%2 == 0)
                    {
                        //cout<<"A choose to pay 1 dollar and paint index "<<ptr->second<<" to 1\n";
                        a++;
                    }
                    else
                    {
                       //cout<<"B choose to pay 1 dollar and paint index "<<ptr->second<<" to 1\n";
                        b++;
                    }
                    fz.erase(fz.begin());
                    if(c%2 == 1)
                    {
                        //cout<<"Now string is not palindrome \n";
                        is_palindrome = 0;
                    }
                    else
                    {
                       //cout<<"Now string is palindrome \n";
                        is_palindrome = 1;
                    }
                }

            }
            else
            {
                c++;
                auto ptr = fz.begin();
                s[ptr->second] = 1;
                if(player%2 == 0)
                {
                    //cout<<"A choose to pay 1 dollar and paint index "<<ptr->second<<" to 1\n";
                    a++;
                }
                else
                {
                    //cout<<"B choose to pay 1 dollar and paint index "<<ptr->second<<" to 1\n";
                    b++;
                }
                fz.erase(fz.begin());
                if(c%2 == 1)
                    {
                        //cout<<"Now string is not palindrome \n";
                        is_palindrome = 0;
                    }
                    else
                    {
                       //cout<<"Now string is palindrome \n";
                        is_palindrome = 1;
                    }

            }
            if(fz.size() == 0)
                return 0;
            return 1;
        }
        else
            return 0;
    }
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
        a=0;
        b=0;
        int n;
        cin>>n;
        cin>>s;

        for(int i=0; i<n; i++)
        {
            if(s[i] == '0')
                fz[i] = i;
        }
      // map_printer(fz);
        int k=0;
        while(chance(k,n) != 0)
        {
            k++;
        }
        //cout<<a<<" "<<b<<"\n";

        if(a<b)
            cout<<"ALICE\n";
        else if(a==b)
            cout<<"DRAW\n";
        else
            cout<<"BOB\n";

        s.clear();
        fz.clear();
        is_palindrome = 1;
        c=0;
        t--;
    }

    return 0;
}

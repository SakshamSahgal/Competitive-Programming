#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
bool is_palindrome = 1;
map<int,int> fz;
int a=0;
int b=0;
string s;
void map_printer(map<int,int> m)
{
    cout<<"\n--------------------\n";
    for(auto i = m.begin(); i!=m.end(); i++)
        cout<<i->second<<"\n";
    cout<<"\n--------------------\n";
}

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

bool check(int player,int n)
{

    if(is_palindrome == 1)
    {
        if(fz.size() > 1)
        {
            auto ptr = fz.begin();

            if( n%2 == 1 && s[n/2] == '0')
            {
                if(player%2 == 0)
                {
                   // cout<<"Alice choose to pay 1 dollar and paint index "<<n/2<<" to 1\n";
                    a++;
                }
                else
                {
                    //cout<<"BOB choose to pay 1 dollar and paint index "<<n/2<<" to 1\n";
                    b++;
                }
                s[n/2] = '1';
                //cout<<"Now string is still palindrome \n";
                is_palindrome = 1;
                auto finder = fz[n/2];
                fz.erase(finder);
            }
            else
            {

                if(player%2 == 0)
                {
                   // cout<<"Alice choose to pay 1 dollar and paint index "<<ptr->second<<" to 1\n";
                    a++;
                }
                else
                {
                    //cout<<"BOB choose to pay 1 dollar and paint index "<<ptr->second<<" to 1\n";
                    b++;
                }
                s[ptr->second] = '1';

                if(ptr->second == n/2)
                {
                    //cout<<"Now string is palindrome \n";
                    is_palindrome = 1;
                }

                else
                {
                    //cout<<"Now string is not palindrome \n";
                    is_palindrome = 0;
                }

                fz.erase(ptr);
                reverse_index(n);
            }
        }
        else
        {
            auto ptr = fz.begin();
            if(player%2 == 0)
            {
               // cout<<"Alice choose to pay 1 dollar and paint index "<<ptr->second<<" to 1\n";
                a++;
            }
            else
            {
               // cout<<"BOB choose to pay 1 dollar and paint index "<<ptr->second<<" to 1\n";
                b++;
            }

            s[ptr->second] = '1';
           // cout<<"Now string is palindrome \n";
            is_palindrome = 1;
            fz.erase(ptr);
            return 0;
        }
    }
    else
    {
        if(fz.size() > 1)
        {
            auto ptr = fz.begin();

            if(player%2 == 0)
            {
               // cout<<"Alice choose to pay 1 dollar and paint index "<<ptr->second<<" to 1\n";
                a++;
            }
            else
            {
                //cout<<"BOB choose to pay 1 dollar and paint index "<<ptr->second<<" to 1\n";
                b++;
            }
            s[ptr->second] = '1';


            is_palindrome = 1;
           // cout<<"Now string is palindrome \n";
            fz.erase(ptr);
            reverse_index(n);
        }
        else
        {
            if(player%2 == 0)
            {
               // cout<<"Alice choose to reverse string \n";
            }
            else
            {
               // cout<<"BOB choose to reverse string \n";
            }

            is_palindrome = 1;
          //  cout<<"Now string cannot be reversed in next move \n";
        }
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
        int n;
        cin>>n;
        cin>>s;
        int player = 0;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '0')
                fz[i] = i;
        }

        //map_printer(fz);

        while( check(player,n) == 1)
        {
            player++;
        }

        if(a<b)
            cout<<"ALICE\n";
        else if(a==b)
            cout<<"DRAW\n";
        else
            cout<<"BOB\n";
        s.clear();
        fz.clear();
        a=0;
        b=0;
        t--;
    }

    return 0;
}

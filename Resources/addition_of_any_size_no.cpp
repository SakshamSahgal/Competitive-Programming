#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void vector_printer(vector <int> x)
{
    for(int i=0; i<x.size(); i++)
        cout<<x[i];
}
vector <int> add(vector<int> a,vector<int> b)
{
    vector<int> c;
    if(a.size() > b.size())
    {
        for(int i=1; i<=(a.size()-b.size()); i++)
            b.insert(b.begin(),0);
    }
    else if(b.size() > a.size())
    {
        for(int i=1; i<=(b.size()-a.size()); i++)
            a.insert(a.begin(),0);
    }

  //  vector_printer(a);
   // vector_printer(b);


    int carry=0;
    int sum=0;
    while(a.size() != 0)
    {
        if(a.size() == 1)
        {
            sum = a[a.size()-1] + b[b.size()-1] + carry;
            c.insert(c.begin(),sum%10);

            if(sum/10!=0)
                c.insert(c.begin(),sum/10);

            a.erase(a.end()-1);
            b.erase(b.end()-1);
        }
        else
        {
            sum = a[a.size()-1] + b[b.size()-1] + carry;
            carry = sum/10;
            c.insert(c.begin(),sum%10);
            a.erase(a.end()-1);
            b.erase(b.end()-1);
        }
    }

h:
    for(auto ptr = c.begin(); ptr!=c.end()-1; ptr++)
    {
        if(*ptr!=0)
            goto l;

        if(*ptr == 0)
        {
            c.erase(ptr);
            goto h;
        }
    }

    l:
    return c;

}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
vector<int> a;
//a = 1200
a.push_back(1);
a.push_back(2);
a.push_back(0);
a.push_back(0);

vector<int> b;
//b = 200
b.push_back(2);
b.push_back(0);
b.push_back(0);

vector <int> c = add(a,b);
vector_printer(c);
return 0;
}

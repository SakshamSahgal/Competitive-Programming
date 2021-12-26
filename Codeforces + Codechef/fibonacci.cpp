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
    int n;
    cin>>n;
    vector<int> sum;
    sum.push_back(0);

    vector<int> a;
    a.push_back(1);

    vector<int> b;
    b.push_back(1);


    vector<int> c;

    for(int i=1; i<=n; i++)
    {
       //cout<<"i = "<<i<<" ";

        if(i == 1)
        {
            sum = add(sum,(sum,a));
           // cout<<"sum = ";
           // vector_printer(sum);
           // cout<<"\n";
        }
        else if(i == 2)
        {
            sum = add(sum,(sum,b));
           // cout<<"sum = ";
           // vector_printer(sum);
           // cout<<"\n";
        }
        else
        {
            c = add(a,b);
            a.clear();
            a = b;
            b.clear();
            b = c;
            sum = add(sum,(sum,c));
           // cout<<"sum = ";
           // vector_printer(sum);
           // cout<<"\n";
        }

        if(i == n)
         vector_printer(sum);
        /*
        cout<<"a = ";
        vector_printer(a);
        cout<<" "<<" b = ";
        vector_printer(b);
        cout<<" c = ";
        vector_printer(c);
        cout<<"\n"; */
    }







    return 0;
}

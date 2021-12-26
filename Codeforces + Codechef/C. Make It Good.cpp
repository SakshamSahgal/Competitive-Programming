#include<iostream>
#include<vector>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
using namespace std;
vector <int> c;
vector <int> copy_a;

void vector_printer(vector <int> v)
{
cout<<"\n------------------------\n";
for(usi i=0;i<v.size();i++)
    cout<<v[i]<<" ";
cout<<"\n------------------------\n";
}

bool Good_array_checker(ui a[],usi n)
{

for(usi i=0;i<n;i++)
    copy_a.push_back(a[i]);
usi last = 0;
z:
auto i = copy_a.begin();
auto j = copy_a.end();

if(copy_a[0]<copy_a[(n-1)])
    {
        if(last<copy_a[0])
            {
            c.push_back(copy_a[0]);
            last = copy_a[0];
            copy_a.erase(i);
             n--;
            }
        else
            return 0;
    }
else
    {
        if(last<copy_a[n-1])
            {
            c.push_back(copy_a[n-1]);
            last = copy_a[n-1];
            copy_a.erase(j);
            n--;
            }
        else
            return 0;
    }
cout<<"a = \n";
vector_printer(copy_a);
cout<<"c = \n";
vector_printer(c);
cout<<"\n";
if(copy_a.size() == 1)
    {
     c.push_back(copy_a[0]);
        return 1;
    }
else
    goto z;

}


int main()
{
usi t;
cin>>t;
while(t--)
    {
    ui n;
    cin>>n;
    ui a[n];
    for(usi i=0;i<n;i++)
        cin>>a[i];
    cout<<Good_array_checker(a,n)<<"\n";
    }
return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
using namespace std;
vector <int> multiples;
vector <int> remaining;
void vector_printer(vector <int> v)
{
cout<<"\n------------------------\n";
for(usi i=0;i<v.size();i++)
    cout<<v[i]<<" ";
cout<<"\n------------------------\n";
}

void multiples_finder(usi z)
{
for(usi i=1;i<=z;i++)
    {
        if(z%i == 0)
        multiples.push_back(i);
    }

}
/*
bool multiples_of_x_checker(usi z,usi a[],usi n)
{
multiples.clear();

bool found = 0;
for(usi i=0;i<multiples.size();i++)
    {
        found = 0;
        for(usi j=0;j<n;j++)
            {
                if(a[j] == multiples[i])
                    {
                    found = 1;
                    break;
                    }

            }

        if(found == 0)
            return 0;
    }
return 1;
}*/
usi maxi(usi a[],usi n)
{
usi maxim = a[0];

for(usi i=0;i<n;i++)
    {
    if(a[i]>maxim)
        maxim = a[i];
    }
return maxim;
}

int maxi_vector(vector <int> a)
{
usi maxim = a[0];

for(usi i=0;i<a.size();i++)
    {
    if(a[i]>maxim)
        maxim = a[i];
    }
return maxim;
}
void remaining_vector(usi n,usi a[])
{

for(usi i=0;i<n;i++)
    remaining.push_back(a[i]);

//size of remaining = n-multiples.size()
for(usi i=0;i<multiples.size();i++)
    {
    auto pos =  find(remaining.begin(),remaining.end(),multiples[i]);

    remaining.erase(pos);

    pos =  find(remaining.begin(),remaining.end(),multiples[i]);
    }
//vector_printer(remaining);
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi n;
cin>>n;
usi a[n];
for(usi i=0;i<n;i++)
    cin>>a[i];

cout<<maxi(a,n);
multiples_finder(maxi(a,n));
//vector_printer(multiples);
remaining_vector(n,a);
cout<<" "<<maxi_vector(remaining);
return 0;
}

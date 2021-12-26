#include<iostream>
#include<vector>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
using namespace std;
vector <int> all_multiples;



void vector_printer(vector <int> distinct_elements)
{
cout<<"\n------------------------\n";
for(usi i=0;i<distinct_elements.size();i++)
    cout<<distinct_elements[i]<<" ";
cout<<"\n------------------------\n";
}
/*
usi maximum_in_arr(usi a[],usi n)
{
usi maxi = a[0];
for(usi i=0;i<n;i++)
    {
        if(a[i]>maxi)
            maxi = a[i];
    }
return maxi;
}
*/
void all_multiple_finder(usi n)
{
all_multiples.push_back(1);
for(usi i=2;i<=n;i++)
    {
        if(n%i == 0)
        all_multiples.push_back(i);
    }
}

bool all_multiples_checker(usi z,usi a[],usi n)
{
all_multiple_finder(z);
bool found = 0;
for(usi i=0;i<all_multiples.size();i++)
    {
        found = 0;
        for(usi j=0;j<n;j++)
            {
                if(all_multiples[i] == a[j])
                    {
                    found = 1;
                    break;
                    }

            }
        if(found == 0)
            return 0;
    }
return 1;
}

void remaining_filler(vector <int> m,usi a[],usi s)
{

for(usi i=0;i<m.size();i++)
    {
        for(usi j=0;j<s;j++)

    }

}
int main()
{
usi n;
cin>>n;
usi a[n];
vector <int> distinct_elements;
for(usi i=0;i<n;i++)
    cin>>a[i];
for(usi i=0;i<n;i++)
    {

        if(all_multiples_checker(a[i],a,n) == 1)
            {
            usi size_of_x = all_multiples.size();
            usi remaining_arr[n-size_of_x];
            remaining_filler(all_multiples,remaining_arr,(n-size_of_x));
            for(usi j=i+1;j<n;j++)
                {
                if(i!=j)
                    {
                        if(all_multiples_checker(a[j],a,n) == 1 && ((size_of_x+all_multiples.size()) == n) )
                            {
                            cout<<"sizes = "<<size_of_x<<" "<<all_multiples.size()<<"\n";
                            cout<<a[i]<<" "<<a[j]<<"\n";
                            return 0;
                            }
                        all_multiples.clear();
                    }
                }
            }

    }
return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;


void vector_printer( vector<int> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

vector<int> no_to_binary(int x)
{
    vector <int> binary;
    while(x!=0)
    {
        binary.insert(binary.begin(),((x%2)));
        x=x/2;
    }
    return binary;
}

int no_of_different_bits(int a,int b)
{
    vector<int> v1 = no_to_binary(a);
    vector<int> v2 = no_to_binary(b);
    int c=0;
    for(int i=v1.size()-1,j=v2.size()-1;i>=0 || j>=0 ;i--,j--)
    {
        int c1,c2;

        if(i<0)
             c1 = 0;
        else
            c1 = v1[i];

        if(j<0)
            c2 = 0;
        else
            c2 = v2[j];

        //cout<<"Comparing between = "<<c1<<" & "<<c2<<"\n";
        if(c1 != c2)
            c++;
    }
return c;
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

int n,m,k;
cin>>n>>m>>k;
int a[m+1];
for(int i=0;i<(m+1);i++)
    cin>>a[i];

int c=0;
for(int i=0;i<(m);i++)
{
    if(no_of_different_bits(a[i],a[m]) <= k )
      c++;
}
cout<<c<<"\n";
return 0;
}


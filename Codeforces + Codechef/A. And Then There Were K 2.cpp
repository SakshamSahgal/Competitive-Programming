#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
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

vector<int> Bits_Extractor(int n)
{
    vector <int> bits;
    while(n>0)
    {
        if (n%2 == 0)
        {
            bits.insert(bits.begin(),0);
            n=n>>1;
        }
        else
        {
            bits.insert(bits.begin(),1);
            n=n>>1;
        }
    }
    return bits;
}

lli value_from_bits(vector<int> bits)
{
    lli sum=0;
    for(int i=bits.size()-1,j=0; i>=0; i--,j++)
        sum += bits[i]*pow(2,j);
    return sum;
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
        vector<int> bits = Bits_Extractor(n);
        //vector_printer(bits);
        bits[0] = 0;
        for(int i=1; i<bits.size(); i++)
            bits[i] = 1;
        //vector_printer(bits);
        cout<<value_from_bits(bits)<<"\n";

        t--;
    }

    return 0;
}


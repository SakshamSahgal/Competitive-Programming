#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;




lli prod_of_digits(lli n)
{
    lli prod=1;
    while(n!=0)
    {
        prod*=n%10;
        n=n/10;
    }

    return prod;

}


int nod(lli n)
{
    int counter=0;
    while(n!=0)
    {
        counter++;
        n/=10;
    }
    return counter;

}


vector<int> no_to_vector(lli x)
{
    vector<int> v;
   while(x!=0)
   {
        v.insert(v.begin(),(int)(x%10));
        x/=10;
   }
return v;
}

lli vector_to_no(vector<int> v)
{
    int ans=0;
    for(int i=v.size()-1,k=1;i>=0;i--,k*=10)
        ans += v[i]*k;
    return ans;
}

void vector_printer( vector<int> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

    /*
    lli maxi = INT_MIN;
    int val=0;
    for(int i=1; i<=4876; i++)
    {
        maxi = INT_MIN;
        for(int j=1; j<=i; j++)
        {
            if( prod_of_digits(j) >= maxi)
            {
                maxi = prod_of_digits(j);
                val = j;
            }

        }

        cout<<"("<<i<<","<<val<<")\n";

    }

    */

    lli n;
    cin>>n;
    int maxi = prod_of_digits(n);
    if(n/10 == 0)
        cout<<n<<"\n";
    else
    {
        vector<int> v = no_to_vector(n);
     //vector_printer(v);
        for(int i=v.size()-1; i>0; i--)
        {
            if(v[i] != 9)
            {
                while(i > 0)
                {
                    if( v[i-1] > 0 )
                    {
                        v[i] = 9;
                        v[i-1]--;
                        break;
                    }
                    else
                    {
                        v[i] = 9;
                        v[i-1] = 9;
                        i--;
                    }
                }
            }
            int x = vector_to_no(v);
            if(prod_of_digits(x) > maxi)
                maxi = prod_of_digits(x);
            //cout<<x<<"\n";
        }

        cout<<maxi<<"\n";
    }


    return 0;
}

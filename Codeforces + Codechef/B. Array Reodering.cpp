#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

int Eular_GCD(int a,int b)
{
    int temp;
    if(a!=0 && b!=0)
    {
x:
        if(a == 0)
            return b;
        else if(b == 0)
            return a;
        else
        {
            temp = a;
            a = b;
            b = temp%b;
            goto x;
        }
    }
    else
        return max(a,b);
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        vector<int> a;
        int x;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            if(x%2 == 0)
                a.insert(a.begin(),x);
            else
                a.push_back(x);
        }
        //vector_printer(a);
        lli counter=0;
        for(int i=0; i<n; i++)
        {
            if(a[i]%2 == 0)
            {
                counter+=(n-i-1);
            }
            else
            {
                for(int j=i+1; j<n; j++)



                {
                    if(Eular_GCD( a[i],2*a[j] ) > 1 )
                        counter++;
                }
            }
        }
        cout<<counter<<"\n";
        t--;
    }



    return 0;
}

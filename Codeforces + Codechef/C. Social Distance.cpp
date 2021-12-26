#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

int maxi(int num,int den)
{
    if(den!= 1)
    {
        if(num%(den+1) != 0)
            return max(1,((num/(den+1))+1));
        else
            return max(1,num/(den+1));
    }
    else
        {
                    if(num%2 == 0)
                        return (num/2);
                    else
                        return (num/2 + 1);
        }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    usi t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector <int> index;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '1')
                index.push_back(i);
        }
        if(index.size() == 0 )
            cout<<maxi(n,k)<<"\n";
        else if(index.size() == 1)
        {
            lli ans=0;
            if(index[0] > k)
                ans+=maxi((index[0]-k),k);

            if( (n-index[0]-1) > k )
                ans+=maxi(( n - index[0] - 1 - k),k);

            cout<<ans<<"\n";
        }
        else
        {
            lli diff=0;
            lli ans=0;

            if(index[0] >k )   // ((index[0]-k)/k
                ans += maxi((index[0]-k),k);

            for(int i=0; i<(index.size()-1); i++)
            {
                diff = (index[i+1] - index[i] - 1) ;
                if( diff > 2*k )
                {
                    //int x = (  );   //( diff- (2*k) ) / k
                    ans+= maxi(( diff- (2*k) ),k);
                }
            }

            if( (n - index[index.size()-1] - 1 ) > k )
                ans+= maxi( (( n - index[index.size()-1] - 1 ) - k),k);  //(( ( n - index[index.size()-1] - 1 ) - k)/k

            cout<<ans<<"\n";
        }
    }
    return 0;
}

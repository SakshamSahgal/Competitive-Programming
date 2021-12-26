#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,a,b,c;
    cin>>n>>a>>b>>c;

    if(a == b && b == c)
        cout<<(n/a)<<"\n";
    else if(a == 1 || b == 1 || c == 1)
        cout<<n<<"\n";
    else
    {
        int maxx = INT_MIN;
        for(int x = 0; x <= (n/a)  ; x++)
        {
            for(int y = 0; y <= (n/b) ; y++)
            {
                if(  (n - a*x - b*y) < 0 )
                    break;

                if( (n - a*x - b*y)%c == 0 )
                {
                    int z = (n - a*x - b*y)/c;
                    if( a*x + b*y + c*z == n )
                    {
                        //cout<<"x y z = "<<x<<" "<<y<<" "<<z<<" \n";
                        maxx = max((x+y+z),maxx);
                    }
                }
            }
        }
        cout<<maxx<<"\n";
    }



    return 0;
}



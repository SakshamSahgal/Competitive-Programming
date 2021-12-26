#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    if( floor(1.08*n) < 206 )
        cout<<"Yay!";
    else if( floor(1.08*n) == 206)
            cout<<"so-so";
            else
                cout<<":(";
                return 0;
    }

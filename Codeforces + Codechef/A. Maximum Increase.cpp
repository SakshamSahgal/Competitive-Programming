
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
    int n;
    cin>>n;
    int a[n];
    vector<int> cross;

    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(i == 0)
                cross.push_back(i);
            else
                {
                    if(a[i-1] >= a[i] )
                     cross.push_back(i);
                }
        }

    int len = 1;

    for(int i=0;i< cross.size();i++)
    {
        if(i != cross.size() - 1)
            len = max(cross[i+1] - cross[i],len);
        else
            len = max(n - cross[i],len);
    }

    cout<<len<<"\n";



    return 0;
}


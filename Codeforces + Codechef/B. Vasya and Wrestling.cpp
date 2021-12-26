#include<iostream>
#include<algorithm>
#include<vector>
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
    vector<lli> first;
    vector<lli> second;
    lli first_sum=0;
    lli second_sum=0;
    lli last=0;
    for(int i=0; i<n; i++)
    {
        lli a;
        cin>>a;
        if(i == n-1)
            last = a;
        if(a > 0)
        {
            first_sum+=a;
            first.push_back(a);
        }
        else
        {
            a = -a;
            second_sum += a;
            second.push_back(a);
        }
    }
    //cout<<second<<" = "<<second_sum<<" "<<first<<" "<<first_sum<<"\n";

    if(first_sum > second_sum)
        cout<<"first\n";
    else if(first_sum < second_sum)
        cout<<"second\n";
    else
    {
        if(first < second)
            cout<<"second\n";
        else if(first > second)
            cout<<"first\n";
        else
        {
            //cout<<"aaiya\n";
            if(last > 0)
                cout<<"first\n";
            else
                cout<<"second\n";
        }
    }
    return 0;
}


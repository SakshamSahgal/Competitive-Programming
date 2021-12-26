#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include <chrono>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace std::chrono;

void time_khao_function()
{
    for(int i=1; i<=100000000; i++)
    {
        //
    }
}
int main()
{
    //GO_FAST
    auto start = high_resolution_clock::now();

    //Your code here

    time_khao_function();


    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout<<endl << duration.count() << endl;
    return 0;
}

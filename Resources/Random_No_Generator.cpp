#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include <cstdlib>   // rand and srand
#include <ctime>     // For the time function
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int generate_random_btw(int a, int b)
{
    return (a + rand()%(b-a+1));
}
int main()
{
    //GO_FAST
    int seed = time(0);
    srand(seed);
    cout<<generate_random_btw(10,20)<<"\n";
    cout<<generate_random_btw(10,20)<<"\n";
    cout<<generate_random_btw(10,20)<<"\n";
    return 0;
}

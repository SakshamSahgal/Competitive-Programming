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
vector<int> a;
a.push_back(1);
a.push_back(5);
a.push_back(7);
a.push_back(9);
a.push_back(10);
a.push_back(12);
a.push_back(13);

auto st = lower_bound(a.begin(),a.end(),14); //left se chalne pe sabse pehla uss element ka index jo >= argument ho
auto ed = upper_bound(a.begin(),a.end(),13); //right se chalne pe sabse pehla woh index + 1 jo <= argument ho
cout<<st-a.begin()<<"\n";
cout<<(st == a.end())<<"\n";
cout<<ed-a.begin()<<"\n";
return 0;
}


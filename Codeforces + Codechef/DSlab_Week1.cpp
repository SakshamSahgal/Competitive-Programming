#include<iostream>
#include<vector>
#include<algorithm> //for std reverse
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);

    for(auto &&i:a)
        cin>>i;


    cout<<"initial array \n";
    for(auto i:a)
        cout<<i<<" ";
    cout<<"\n";

    std::reverse(a.begin(), a.end());

    cout<<"final array \n";
    for(auto i:a)
        cout<<i<<" ";
    cout<<"\n";
    cout<<"Enroll no - 20103224\n";
    cout<<"Name - Saksham Sahgal\n";
    return 0;
}

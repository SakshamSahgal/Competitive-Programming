#include<iostream>
#include<algorithm>
using namespace std;

class edge
{
public:
    int a;
    int b;
    int c;
};

edge arr[50];

bool custom_sort(edge a,edge b)
{
    return (a.c<b.c);
}

int main()
{
    sort(arr,arr+50,custom_sort);
    return 0;
}

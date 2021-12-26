#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

int max_happiness = INT_MIN;
int g[5][5];
void display(int a[], int n)
{
    int x = g[a[0]-1][a[1]-1] + g[a[1]-1][a[0]-1] + g[a[1]-1][a[2]-1] + 2*g[a[2]-1][a[3]-1] + g[a[2]-1][a[1]-1] + 2*g[a[3]-1][a[2]-1] + 2*g[a[3]-1][a[4]-1] + 2*g[a[4]-1][a[3]-1];
    if(x > max_happiness)
        max_happiness = x;
    //cout<<x<<"\n";
}

// Function to find the permutations
void findPermutations(int a[], int n)
{

    // Sort the given array
    sort(a, a + n);

    // Find all possible permutations
    //cout << "Possible permutations are:\n";
    do
    {
        display(a, n);
    }
    while (next_permutation(a, a + n));
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            cin>>g[i][j];
    }

    int a[5] = {1,2,3,4,5};
    findPermutations(a,5);
    cout<<max_happiness<<"\n";
    return 0;
}


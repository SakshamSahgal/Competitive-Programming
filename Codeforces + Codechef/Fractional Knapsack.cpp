#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
using namespace std;

struct Item
{
    int value;
    int weight;
};

void Map_printer2(multimap<float,int,greater<float>> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin(); i!=x.end(); i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}

class Solution
{
public:

    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {

        multimap<float,int,greater<float>> fraction;
        // Your code here
        for(int i=0; i<n; i++)
            fraction.insert({((arr[i].value*1.0)/arr[i].weight),i});
       // Map_printer2(fraction);
        auto ptr = fraction.begin();
        double sum=0;
        h:

        if(arr[ptr->second].weight <= W)
        {
            sum+=arr[ptr->second].value;
            //cout<<"Adding"<<arr[ptr->second].value<<"\n";
            W-=arr[ptr->second].weight;
            ptr++;
            if(ptr == fraction.end())
                return sum;
            else
                goto h;
        }
        else
        {
            //cout<<"adding"<<((W*1.0)/arr[ptr->second].weight)*arr[ptr->second].value<<"\n";
            sum += ((W*1.0)/arr[ptr->second].weight)*arr[ptr->second].value;
            W=0;
            return sum;
        }


    }
};


// { Driver Code Starts.
int main()
{
    int t;
    //taking testcases
    cin>>t;
    //cout<<setprecision(2)<<fixed;
    while(t--)
    {
        //size of array and weight
        int n, W;
        cin>>n>>W;

        Item arr[n];
        //value and weight of each item
        for(int i=0; i<n; i++)
        {
            cin>>arr[i].value>>arr[i].weight;
        }

        //function call
        Solution ob;
        cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends

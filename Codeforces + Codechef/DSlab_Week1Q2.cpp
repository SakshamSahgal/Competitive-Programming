#include<iostream>
#include<vector>
using namespace std;
template<typename T>


T sum(vector<T> x)
{
    T sum;
    for(int i=0; i<x.size(); i++)
        sum += x[i];
    return sum;
}

int largest(vector<int> a)
{
    int maxx = INT_MIN;
    for(int i=0; i<a.size(); i++)
        maxx = max(a[i],maxx);
    return maxx;
}

int countlargest(vector<int> a,int lgst)
{
    int c=0;
    for(int i=0; i<a.size(); i++)
    {
        if( a[i] >= lgst)
            c++;
    }
    return c;
}

int countTrues(vector<bool> a)
{
    int c=0;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i])
            c++;
    }
    return c;
}

vector<int> stringLength(vector<string> s)
{
    vector<int> l;
    for(int i=0; i<s.size(); i++)
        l.push_back((s[i].length()));
    return l;
}

int main()
{
    cout<<"\n Enter Array Size\n";
    int n;
    cin>>n;
    vector<double> double_array;
    cout<<"\n Enter Double Array\n";
    for(int i=0; i<n; i++)
    {
        double x;
        cin>>x;
        double_array.push_back(x);
    }


    cout<<"\n double array sum = "<<sum(double_array)<<"\n";

    vector<int> integer_array;
    cout<<"\nEnter int Array\n";
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        integer_array.push_back(x);
    }


    cout<<"\n integer array sum = "<<sum(integer_array)<<"\n";
    cout<<"\n largest int array = "<<largest(integer_array)<<"\n";
    cout<<"\n numbers atleast as large as 2 = "<<countlargest(integer_array,2)<<"\n";
    cout<<"\nEnter Boolean array = \n";
    vector<bool> boolean_Array;

    for(int i=0; i<n; i++)
    {
        bool x;
        cin>>x;
        boolean_Array.push_back(x);
    }

    cout<<"\n No of trues = "<<countTrues(boolean_Array)<<"\n";

    cout<<"\n Enter array of Strings = \n";
    vector<string> string_Array;

    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        string_Array.push_back(s);
    }
    vector<int> lengths = stringLength(string_Array);
    cout<<"\n String lengths = \n";
    for(auto i:lengths)
        cout<<i<<" ";
    cout<<"\n";

    cout<<"\n";

    cout<<"Enroll no - 20103224\n";
    cout<<"Name - Saksham Sahgal\n";
    return 0;
}

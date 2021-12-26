#include<iostream>
using namespace std;
#include<cmath>
void insertion_sort(int a[],int n)
{
int temp;
for(unsigned int i=1;i<n;i++)
    {
    temp = a[i];
    for(int j=i-1;j>=0 && temp<a[j];j--)
        {
        a[j+1] = a[j];
        a[j] = temp;
        }
    }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
string s;
cin>>s;
int a_ki_size =ceil((s.size()/2.0));
int a[a_ki_size];
for(int i=0,j=0;i<s.size();i++)
    {
        if(i%2 == 0)
        {
        //cout<<j<<"\n";
        a[j] = s[i]-48;
        j++;
        }
    }

    insertion_sort(a,a_ki_size);
    for(int i=0;i<a_ki_size;i++)
        {
            if(i==a_ki_size-1)
            cout<<a[i];
        else
            cout<<a[i]<<"+";
        }

    cout<<"\n";
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
void vector_printer(vector <int> v)
{
cout<<"\n-----\n";
for(int i=0;i<v.size();i++)
cout<<v[i]<<" ";
cout<<"\n-----\n";
}*/
int main()
{

int n;
scanf("%d",&n);
int a[n];
int c=0;
vector <int> freq;
for(int i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    if(a[i] == 1)
        {
        c++;
        }
    if(a[i] == 0 || i == (n-1))
        {
        freq.push_back(c);
        c=0;
        }
    }
if(a[n-1] == 0)
    freq.push_back(0);

if( (freq[0]+freq[freq.size()-1]) > (*max_element(freq.begin(),freq.end())) )
    printf("%d",(freq[0]+freq[freq.size()-1]));
else
     printf("%d",*max_element(freq.begin(),freq.end()) );
return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#include<cmath>
using namespace std;
/*
void vector_printer(vector <int> v)
{
cout<<"\n-----\n";
for(ui i=0;i<v.size();i++)
cout<<v[i]<<" ";
cout<<"\n-----\n";
}*/
ui sum_returner(int ix,int a[],int n)
{
int sum = 0;
for(int i = ix;i<n;i+=a[i])
    {
     sum+=a[i];
    if(a[i]>(n-1-i))
        {
        return sum;
        }
    }
return sum;
}
int main()
{
usi t;
cin>>t;
while(t--)
    {
    vector <int> score;
    vector <int> review;
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        if(a[i]>(n-1-i))
            {
            score.push_back(a[i]);
            }
        else
            {
            review.push_back(i);
            score.push_back(0);
            }
        }
    int c = 0;
    for(;c<review.size();)
        {
        score[review[c]] = sum_returner(review[c],a,n);
        c++;
        }
        printf("%d\n",*max_element(score.begin(),score.end()));
    }

return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
void vector_printer(vector<int> v1)
{
//cout<<"\n--------\n";
for(int i=0;i<v1.size();i++)
    printf("%d ",(v1[i]));
//cout<<"\n--------\n";
cout<<"\n";
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi t;
cin>>t;
while(t)
    {
    int n,m;
    cin>>n>>m;
    char s[n];
    int p[m];
    vector <int> a(26,0);

    scanf("%s",&s);

    for(int i=0;i<n;i++)
        a[(int)s[i]-97]++;

    for(int i=0;i<m;i++)
        {
          scanf("%d",&p[i]);
        for(int k=0;k<p[i];k++)
            a[(int)s[k]-97]++;

        }
    vector_printer(a);
    t--;
    }


return 0;
}

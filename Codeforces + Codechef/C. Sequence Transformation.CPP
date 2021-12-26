#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
void vector_printer(vector <int> v)
{
cout<<"\n-------------\n";
for(ui i=0;i<v.size();i++)
    cout<<v[i]<<" ";
cout<<"\n-------------\n";
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t--)
{
ui n;
cin>>n;
ui a[n];
bool all_same = 1;
bool all_different = 1;
vector <int> b(n+1,0);
//vector_printer(b);
for(ui i=0;i<n;i++)
    {
        scanf("%u",&a[i]);
        if(all_same == 1 && i!= 0 && a[i]!= a[i-1])
           all_same = 0;

        if( (i!= 0) && (a[i] == a[i-1]) )
            {
            //nothing
            }
        else
            {
            b[a[i]]++;
            if(b[a[i]] >= 2)
                all_different = 0;
            }

    }
if(all_same == 1)
    cout<<0<<"\n";

else if(all_different == 1)
    cout<<1<<"\n";

else
    {
    b[a[0]]--;
    b[a[n-1]]--;
    //vector_printer(b);
    int mini = INT_MAX;
    for(ui i=0;i<n;i++)
        {

                    if(b[a[i]]<mini)
                        mini = b[a[i]];

        }
    cout<<mini+1<<"\n";
    }

}



return 0;
}

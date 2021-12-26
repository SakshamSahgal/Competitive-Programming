#include<iostream>
using namespace std;
int main()
{
    int n,t,countit=0;
    cin>>n>>t;
    char arr[n];
    int pos[n];
    char temp;
    for(int i=0;i<n;i++)
        {
        cin>>arr[i];
        }
        for(int i=0;i<n;i++)
        {
        pos[i] = 52;
        }

while(t--)
    {
      for(int i=0;i<n-1;i++)
        {
        if(arr[i] == 'B' && arr[i+1] == 'G')
            {
            pos[countit] = i;
            countit++;
            }
        }
        for(int i=0;i<n;i++)
        {
        if(pos[i] != 52)
            {
                arr[pos[i]]  = 'G';
                arr[pos[i] + 1] = 'B';
            }

        }
        for(int i=0;i<n;i++)
        {
        pos[i] = 52;
        }
        countit = 0;
    }
for(int i=0;i<n;i++)
        {
        cout<<arr[i];
        }
    return 0;
}

 #include<iostream>
 #include<algorithm>
 using namespace std;

 /*void printer(int arr[],int n)
 {
 for(int i=0;i<n;i++)
    {
    cout<<arr[i]<<"  ";
    }
 } */

 int main()
{

int t=0,n,longest_sequence=0;
cin>>t;
while(t--)
    {
    longest_sequence = 0;
    cin>>n;
    int arr[n],countit=0;
    int newer[n*n];
    for(int i=0;i<n;i++) //input
        {
        cin>>arr[i];
        }


    for(int i=0;i<n*n;i++)  //new array filling
        {
            newer[i] = arr[countit];
            if(countit == n-1)
                {
                countit = -1;
                }
            countit++;
        }
     int s = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+s);
    //cout<<"\n sorted array -------------------\n";
    //printer(arr,n);
    //cout<<" \n new array --------------------------------  \n";
   // printer(newer,n*n);
   countit = 0;
    for(int i=0;i<n*n;i++)
        {
        if(newer[i] == arr[countit])
            {
            //cout<<"same found at index "<<i<<"\n";
            countit++;
            longest_sequence++;
            }
        for(int j=countit-1;(arr[j] == arr[j+1]) && ((j+1)<=n*n);j++)
            {
            countit++;
            }
        }
    cout<<longest_sequence<<"\n";
    }
 }

#include<iostream>
using namespace std;



void fun(int c,int n,int a[],int vis[],int ans[])
{
   // cout<<"c = "<<c<<"\n";
    if(c == n)
    {
        cout<<"\n-------------\n";
        for(int i=0; i<n; i++)
            cout<<ans[i]<<" ";
        cout<<"\n-------------\n";
        return;
    }

    for(int i=0; i<n; i++)
    {
        //cout<<"vis["<<i<<"] = "<<vis[i]<<"\n";
        if(vis[i] == -1)
        {
            vis[i] = 1;
            ans[c] = a[i];
            fun(c+1,n,a,vis,ans);
            vis[i] = -1;
            ans[c] = 0;
        }
    }

}

int main()
{
    int n;
    cin>>n;
    int a[n];
    int ans[n];
    int vis[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        vis[i] = -1;
    }



    fun(0,n,a,vis,ans);
    return 0;
}

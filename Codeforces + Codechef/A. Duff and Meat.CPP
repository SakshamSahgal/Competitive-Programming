#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,a,p,i,sum=0,price=101;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&a,&p);
        if(p<price){
            price=p;
        }
        sum+=a*price;
    }
    printf("%d\n",sum);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main()
{
    string a;
    cin>>a;
    lli len=a.length();
    lli strt=0,lst=len-1;
    lli count=0;
    while(strt<=lst)
    {
        if(a[strt] != a[lst])
        {
            int ai_sathi=-1,aj_sathi=-1;
            for(int k=strt+1; k<=lst-1; k++)
            {
                if(a[k]==a[lst])
                {
                    ai_sathi=k;
                    break;
                }
            }
            for(int k=lst-1; k>=strt+1; k--)
            {
                if(a[k]==a[strt])
                {
                    aj_sathi=k;
                    break;
                }
            }
            if(aj_sathi==-1 && ai_sathi==-1)
            {
                if(abs(strt-lst)==1)
                    count+=1;
                else
                    count+=2;
            }
            else if(ai_sathi==-1 && aj_sathi!=-1)
            {
                for(int de=strt; de<aj_sathi; de++)
                    count++;

                strt=aj_sathi;
            }
            else if(ai_sathi!=-1 && aj_sathi==-1)
            {
                for(int de=ai_sathi+1; de<lst; de++)
                    count++;

                lst=ai_sathi;
            }
            else
            {
                int check1=abs(strt-aj_sathi);
                int check2=abs(lst-ai_sathi);
                if(check1<=check2)
                {
                    for(int de=strt; de<aj_sathi; de++)
                        count++;
                    strt=aj_sathi;
                }
                else
                {
                    for(int de=ai_sathi+1; de<lst; de++)
                        count++;
                    lst=ai_sathi;
                }
            }
        }
        strt++;
        lst--;
    }
    if(count%2!=0 || count==0)
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;

    return 0;
}

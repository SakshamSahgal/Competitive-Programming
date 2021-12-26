#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t)
    {
    int px;
    int py;
    cin>>px>>py;
    string s;
    cin>>s;
    bool xdone=0;
    bool ydone = 0;
    int xsum=0;
    int ysum = 0;
    int LC=0;
    int RC=0;
    int UC=0;
    int DC=0;
    for(int i=0;i<s.length();i++)
        {
        if(s[i] == 'U' || s[i] == 'D')
            {
                if(s[i] == 'U')
                    {
                    UC++;
                    ysum++;
                    }
                else
                    {
                    DC++;
                    ysum--;
                    }
            }
            else
            {
                 if(s[i] == 'L')
                    {
                    LC++;
                    xsum--;
                    }
                else
                    {
                    RC++;
                    xsum++;
                    }
            }


        }
    //cout<<"UC = "<<UC<<" DC = "<<DC<<" RC = "<<RC<<" LC = "<<LC<<" xsum = "<<xsum<<" ysum = "<<ysum<<"\n";

    if(xsum == px)
    xdone = 1;
    else
        {
           if(px>xsum)
                {
                   if(LC>=(px-xsum))
                        {
                            xdone = 1;
                            goto g;
                        }
                    else
                    {
                        xdone = 0;
                        goto h;
                    }

                }
            else
                {
                    if(RC>=(xsum-px))
                        {
                            xdone = 1;
                            goto g;
                        }
                    else
                    {
                        xdone = 0;
                        goto h;
                    }
                }

        }


    g:


    if(ysum == py)
        ydone = 1;
    else
        {

                if(py>ysum)
                {
                   if(DC>=(py-ysum))
                        {
                            ydone = 1;
                            goto h;
                        }
                    else
                    {
                        ydone = 0;
                        goto h;
                    }

                }
            else
                {
                    if(UC>=(ysum-py))
                        {
                            ydone = 1;
                            goto h;
                        }
                    else
                    {
                        ydone = 0;
                        goto h;
                    }
                }

        }


    h:
    //cout<<"xdone = "<<xdone<<" ydone  = "<<ydone<<" XSUM = "<<xsum<<" ysum =  "<<ysum<<"\n";
    if(xdone == 1 && ydone == 1)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    t--;
    }



return 0;
}

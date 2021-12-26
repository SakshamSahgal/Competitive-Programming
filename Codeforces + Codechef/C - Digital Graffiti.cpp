#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
void reset_dir(bool dir[])
{
dir[0] = 0; //r
dir[1] = 0; //l
dir[2] = 0; //u
dir[3] = 0; //d
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
int h,w;
cin>>h>>w;
char a[h][w];
int s=0;
int sx,sy;
int px,py;

for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
        cin>>a[i][j];

bool dir[4];
reset_dir(dir);

for(int i=1;i<=(h-2);i++)
    {
        for(int j=1;j<=(w-2);j++)
            {

                if(s == 0)
                {
                    if(a[i][j] == '#')
                    {
                        sx = i;
                        sy = j;

                        if( a[i][j+1] == '#' ) //right
                        {
                            int k=j;
                            int c=0;
                            while( a[i][k] == '#')
                                {
                                    c++;
                                    k++;
                                }
                            cout<<"Edge length = "<<c<<"\n";
                            s++;
                            px = i;
                            py = k-1;
                            dir[0] = 1;
                            goto g;
                        }

                 else if(a[i+1][j] == '#') //down
                       {
                          int k=i;
                          int c=0;
                            while( a[k][j] == '#')
                                {
                                    c++;
                                    k++;
                                }
                            cout<<"Edge length = "<<c<<"\n";
                            s++;
                            px = k-1;
                            py = j;
                            dir[3] = 1;
                            goto g;
                        }
                    }
               }
            }
    }

    g:
    cout<<px<<" "<<py<<"\n";

    while(px != sx && py != sy)
        {
            for(int i=px;i<=(h-2);i++)
                {
                for(int j=py;j<=(w-2);j++)
                    {
                    if(a[i][j] == '#')
                        {
                            if(a[i][j+1] == '#' && dir[1] == 0) //right
                                {
                                    reset_dir(dir);
                                    dir[0] = 1;
                                    int k=j;
                                    int c=0;
                                    while( a[i][k] == '#')
                                    {
                                    c++;
                                    k++;
                                    }
                                    cout<<"Edge length = "<<c<<"\n";
                                    s++;
                                    px = i;
                                    py = k-1;
                                    goto x;
                                }
                            else if(a[i][j-1] == '#' && dir[0] == 0) //left
                                {
                                    reset_dir(dir);
                                    dir[1] = 1;
                                    int k=j;
                                    int c=0;
                                    while(a[i][k] == '#')
                                        {
                                            k--;
                                            c++;
                                        }
                                    cout<<"Edge length = "<<c<<"\n";
                                    s++;
                                    px=i;
                                    py = k+1;
                                    goto x;
                                }
                            else if(a[i+1][j] == '#' && dir[2] == 0) //down
                                {
                                    reset_dir(dir);
                                    dir[3] = 1;
                                    int k=i;
                                    int c=0;
                                    while(a[k][j] == '#')
                                        {
                                         k++;
                                        c++;
                                        }
                                    cout<<"Edge length = "<<c<<"\n";
                                    s++;
                                    px = k-1;
                                    py = j;
                                }
                        }

                    }
                }


        x:
        }


return 0;
}

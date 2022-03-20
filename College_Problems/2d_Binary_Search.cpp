#include<iostream>
using namespace std;



int main()
{
    //GO_FAST
    int a[6][4] = { {1,2,17,20},
        {2,3,18,22},
        {5,6,19,23},
        {5,6,19,23},
        {8,9,20,24},
        {10,11,21,25}
    };

    int r=0;
    int c=3;
    int target=11;
    bool found=0;
    while(r < 6 && c >= 0)
    {
        if(a[r][c] == target)
        {
            cout<<"Found "<<target<<" at "<<r<<" "<<c<<"\n";
            found=1;
            break;
        }
        else if(a[r][c] < target)
            r++;
        else
            c--;
    }

    if(!found)
        cout<<"Not found\n";
    return 0;
}


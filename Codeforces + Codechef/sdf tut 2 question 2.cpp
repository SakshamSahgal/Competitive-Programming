#include<iostream>
using namespace std;

static int its_size;
int *ptr;

void insert_element(int n)
    {

    if(its_size == 0)
        {
        its_size++;
        ptr = new int;
        *ptr = n;
        }
    else
        {
        int *ptr2 = new int[its_size+1];
        for(int i=0;i<its_size;i++)
                *(ptr2+i) = *(ptr+i);

        *(ptr2+its_size) = n;
        ptr = ptr2;
        its_size++;
        }
    }

void display_element()
    {
        cout<<"\n";
        for(int i=0;i<its_size;i++)
            cout<<*(ptr+i)<<" ";
    }
void delete_element()
    {
        if(its_size>=1)
            {
                int *ptr2 = new int[its_size-1];
                for(int i=0;i<(its_size-1);i++)
                    *(ptr2+i) = *(ptr+i);

               ptr = ptr2;
                its_size--;
            }
        else
            cout<<"Nothing to delete \n";
    }

int main()
{
insert_element(1);
insert_element(2);
insert_element(3);
insert_element(4);
insert_element(5);
display_element();
delete_element();
delete_element();
display_element();
return 0;
}


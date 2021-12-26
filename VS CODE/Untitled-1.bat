#include <iostream>
#include <string>
using namespace std;
int main()
{
    int *p= NULL;
    p= new int();
    int *a= new int(10);
    if(!p)
    {
        cout<<"bad memory allocation"<<endl;
    }
    else
    {
        cout<<"memory allocated successfully"<<endl;
        *p= 5;
        cout<<"*p= "<<*p<<endl;
        cout<<"*a= "<<*a<<endl;
    }
    double *arr= NULL;
    arr= new double[10];
    if(!arr)
    {
        cout<<"memory not allocated"<<endl;
    }
    else
    {
        for(int i=0; i<5; i++)
            arr[i] = i+1;
        cout<<"Array values : ";
        for(int i=0; i<5; i++)
            cout<<arr[i]<<"\t";
    }
    cout<<"\n-------------------\n";
    delete p;
    delete a;
    cout<<"*p= "<<*p<<endl;
    cout<<"*a= "<<*a<<endl;
    delete[] arr;
    for(int i=0; i<5; i++)
        cout<<arr[i]<<"\t";
    cout<<"\n-------------------\n";
    return 0;
}

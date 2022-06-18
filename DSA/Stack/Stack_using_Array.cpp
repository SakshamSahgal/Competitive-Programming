#include<iostream>
#include <cstdlib> // rand and srand
#include <ctime> // For the time function

using namespace std;


int generate_random_btw(int a, int b)
{
    return (a + rand()%(b-a+1));
}

class Stack_Using_Array
{
public:
    int *a;
    int sz;
    int top = -1;

    Stack_Using_Array(int Size)
    {
        a = new int[Size];
    }

    void push(int x)
    {
        if(top == sz - 1)
            cout<<"OverFlow\n";
        else
            a[++top] = x;
    }

    int Pop()
    {
        if(top == -1)
            cout<<"UnderFlow\n";
        else
            return a[top--];
    }

    int Top()
    {
        return a[top];
    }

    void Printer()
    {
        int tt = top;
        while(tt != -1)
        {
            cout<<a[tt]<<"\n";
            tt--;
        }
    }
};


void Random_Insert(Stack_Using_Array &a)
{

    cout<<"Randomly Generated Stack = : \n";
    int n = generate_random_btw(3,10);
    cout<<"Size = "<<n<<"\n";
    for(int i=0; i<n; i++)
        a.push(generate_random_btw(10,50));

    a.Printer();
}

int main()
{
    int seed = time(0);
    srand(seed);
    Stack_Using_Array a(10);
    Random_Insert(a);
    return 0;
}

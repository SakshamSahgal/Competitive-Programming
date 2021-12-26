#include<iostream>
using namespace std;

class A
{
public:
    virtual void fun()=0; //do nothing
    void f1()
    {
        cout<<"hi\n";
    }
};

class B :public A
{
public:
    void fun()
    {
        cout<<"Fun";
    }
};
//void A::fun(){}
int main()
{
//A a1;
    B B1;
    B1.f1();
    A *ptr;
    B d;
    ptr  = &d;
    ptr->fun();
//a1.fun();
    return 0;
}


#include <iostream>
using namespace std;
class B
{
    public:
       virtual void display()
         { cout<<"Content of base class.\n"; }
};

class D : public B
{
    public:
       void display()
         { cout<<"Content of derived class.\n"; }
};

int main()
{
    B *b = new B();;
    D d;

    b->display();

    b = &d;    /* Address of object d in pointer variable */
    b->display();
    return 0;
}

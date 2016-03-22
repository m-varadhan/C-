#include <iostream>

using namespace std;

class A {
   public:
      virtual void print(){ cout << "print A" << endl; };
};

class B: public virtual A {
    public:
       void print(){ cout << "print B" << endl; };
};

class C: public virtual A {
     public:
        void print(){ cout << "print C" << endl; };
};

class D: public B, public C {
     public:
        void print(){ cout << "print D" << endl; };
};

int main()
{
   A *b = new B();
   A *c = new C();
   A *d = new D();

   c->print(); 
   b->print(); 
   d->print(); 

   return 0;
}

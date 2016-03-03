#include <iostream>

using namespace std;

#if 0
class A {
   public:
      //void print(){ cout << "print A" << endl; };
      //virtual void f() {} ;
	virtual ~A() {} ;
};

class B: A {
    public:
       //virtual void print(){ cout << "print B" << endl; };
       //virtual void print(){ cout << "print B" << endl; };
       virtual void print(){ } ;
};

#if 0
class C: public B {
     public:
        virtual void print(){ cout << "print C" << endl; };
};
#endif
#endif

struct Base {
    virtual ~Base() {}
};
 
struct Derived: Base {
    virtual void name() {}
};
 

int main()
{
   //A *a = new B();
   //B *b = new B();
   //C *c = dynamic_cast<C*>(new B());
   
   //B *d = dynamic_cast<B*>(new A()) ;
   //d->print() ;

   //C *stick = dynamic_cast<C*>(b) ;
   //a->print() ;
   //b->print() ;
   //c->print() ;
   //stick->A::print() ;

   //C *stick = static_cast<C*>(a) ;
   //B *stick = dynamic_cast<B*>(c) ;
   //B *stick = c ;
   //
    Base* b1 = new Base;
    if(Derived* d = dynamic_cast<Derived*>(b1))
    {
        std::cout << "downcast from b1 to d successful\n";
        d->name(); // safe to call
    }
 
    Base* b2 = new Derived;
    if(Derived* d = dynamic_cast<Derived*>(b2))
    {
        std::cout << "downcast from b2 to d successful\n";
        d->name(); // safe to call
    }
 

   return 1;
}

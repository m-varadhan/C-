#include <boost/shared_ptr.hpp>
#include <iostream>

class MyInt {
	int i ;
	public:
		MyInt(int _i) : i(_i) {
			std::cout << "Success Constructor MyInt: " << i << "\n";
		}
		~MyInt() {
			std::cout << "Called Destructor MyInt: " << i << "\n";
		}
		int operator *() { return i; };
		operator int() { return i; };
};

class Owner {
	boost::shared_ptr<MyInt> myint;
	public:
	Owner(boost::shared_ptr<MyInt> _myint) : myint(_myint) { 
		std::cout << "Called Constructor Owner " << *myint << "\n" ;
	}
	~Owner() {
		std::cout << "Called Destructor Owner " << *myint << "\n" ;
	}
};

int main()
{
  boost::shared_ptr<MyInt> p{new MyInt{1}};
  {
  Owner a(p);
  p.reset(new MyInt{2});
  Owner b(p);
  }
  p.reset(new MyInt{3});
  Owner c(p);
  Owner d(p);
}

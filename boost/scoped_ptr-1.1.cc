#include <boost/scoped_ptr.hpp>
#include <iostream>

class MyInt {
	int i ;
	public:
		MyInt(int _i) : i(_i) {
			if(_i == 2) {
				throw "invalid value" ;
			}
			std::cout << "Success Constructor MyInt: " << i << "\n";
		}
		~MyInt() {
			std::cout << "Called Destructor MyInt: " << i << "\n";
		}
		int operator *() { return i; };
		operator int() { return i; };
};

int main()
{
  boost::scoped_ptr<MyInt> p{new MyInt{1}};
  std::cout << *p << '\n';
  try {
  p.reset(new MyInt{2});
  }
  catch(char const *str) { } 
  std::cout << *p.get() << '\n';
  std::cout << std::boolalpha << static_cast<bool>(p) << '\n';
  p.reset();
  std::cout << std::boolalpha << static_cast<bool>(p) << '\n';
}

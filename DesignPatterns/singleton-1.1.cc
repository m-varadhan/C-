#include <iostream>

namespace SingleTon {
	class Instance {
		int iValue ;
		static Instance *_instance ;
		Instance(int v=0) : iValue(v) { std::cout << "Called Instance Constructor with value\n";  };
		~Instance() { std::cout << "Called Instance Destructor\n";  };
		public:
			static Instance *get() { 
				if(!_instance) {
					_instance = new Instance ;
				}
				return _instance; 
			} ;
			static Instance *destory() { 
				delete _instance;
				return (_instance = NULL) ;
			}
			int getInstanceValue() { return iValue; } 
			int setInstanceValue(int v) { iValue = v; } 
			
			Instance *operator->() {
				std::cout << "Called Operator ->\n" ;
				return get() ;
			}
			Instance *operator*() {
				std::cout << "Called Operator *\n" ;
				return get() ;
			}
	} ;
};
SingleTon::Instance *SingleTon::Instance::_instance = 0;


int main() {
	SingleTon::Instance *inst = *(*inst);

	(*inst)->setInstanceValue(10) ;
	std::cout << "Instant value:" << inst->getInstanceValue() << "\n" ;	

	inst->get()->destory() ;
	std::cout << "Instant value:" << inst->get()->getInstanceValue() << "\n" ;	
}

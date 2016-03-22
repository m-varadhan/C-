#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>

class Shape {
	public:
		virtual void draw() = 0;
};

class Circle : public Shape {
	public:
		void draw() { std::cout << "Drawning Circle\n" ; }
};

class Square : public Shape {
	public:
		void draw() { std::cout << "Drawning Square\n" ; }
};

class Rectangle : public Shape {
	public:
		void draw() { std::cout << "Drawning Rectangle\n" ; }
};

class Color {
	public:
		virtual void fill() = 0;
};

class Red : public Color {
	public:
		void fill() { std::cout << "Filling Red\n" ; }
};

class Green : public Color {
	public:
		void fill() { std::cout << "Filling Green\n" ; }
};

class Blue : public Color {
	public:
		void fill() { std::cout << "Filling Blue\n" ; }
};

class AbstractFactory {
	public:
		virtual Shape *getShape(std::string type) = 0;
		virtual Color *getColor(std::string type) = 0;
};

class ShapeFactory : public AbstractFactory {
	public:
		Shape *getShape(std::string type) {
			if(boost::iequals(type,"CIRCLE")) {
				return new Circle() ;
			}
			if(boost::iequals(type,"SQUARE")) {
				return new Square() ;
			}
			if(boost::iequals(type,"RECTANGLE")) {
				return new Rectangle() ;
			}
			return NULL ;
		}
		Color *getColor(std::string type) { return NULL; }
};

class ColorFactory : public AbstractFactory {
	public:
		Shape *getShape(std::string type) { return NULL; }
		Color *getColor(std::string type) {
			if(boost::iequals(type,"RED")) {
				return new Red() ;
			}
			if(boost::iequals(type,"GREEN")) {
				return new Green() ;
			}
			if(boost::iequals(type,"BLUE")) {
				return new Blue() ;
			}
			return NULL ;
		}
};

class FactoryProducer {
	public:
	static AbstractFactory *getFactory(std::string type) {
		if(boost::iequals(type,"SHAPE")) {
			return new ShapeFactory();
		}
		if(boost::iequals(type,"COLOR")) {
			return new ColorFactory();
		}
		return NULL;
	}
};

int main() {
	AbstractFactory *ProduceShape = FactoryProducer::getFactory("SHAPE");	
	AbstractFactory *ProduceColor = FactoryProducer::getFactory("COLOR");	

	Shape *square = ProduceShape->getShape("SQUARE");

	square->draw() ;
}

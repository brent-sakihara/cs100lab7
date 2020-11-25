#include <iostream>
#include "factory.hpp"
#include "base.hpp"

using namespace std;

int main (int argc, char** argv) {
	Factory* pointer = new Factory();
	Base* point = nullptr;
	point = pointer->parse(argv, argc);
	if (point != nullptr){
		cout << point->stringify() << " = " << point->evaluate() << endl;
	}
	return 0;
};

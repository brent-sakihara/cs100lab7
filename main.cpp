#include <iostream>
#include "factory.hpp"
#include "base.hpp"
int main (int argc, char** argv) {
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << std::endl;
	}
	std::cout << argc << std::endl;
	Factory* pointer = new Factory();
	Base* point = nullptr;
	point = pointer->parse(argv, argc);
	if (point != nullptr){
		point->stringify();
	}
	return 0;
};

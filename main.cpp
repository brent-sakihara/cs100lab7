#include <iostream>
#include "factory.hpp"
#include "base.hpp"

using namespace std;

int main (int argc, char** argv) {
	/*for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << std::endl;
	}
	std::cout << argc << std::endl; 
        */

	Factory* pointer = new Factory();
	Base* point = nullptr;
	point = pointer->parse(argv, argc);
	if (point != nullptr){
		cout << point->stringify() << " = " << point->evaluate() << endl;
	}

	//cout << "STOI TEST: " << "56p22i = " << stoi("56p22i") << endl;
	/*
 	To detect whether number is a valid input: 
        string cap(argv[1]);
	int a = stoi(argv[1]);

	cout << "size of original arg: " << cap.size() << endl;
	cout << "new size of first arg: " << to_string(a).size() << endl;	
	
	if original size is not equal to new size, then number was not valid input
	There is one potential PROBLEM with this tho: 
		this doesn't work well with doubles
	*/

	return 0;
};

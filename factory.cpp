#include "factory.hpp"
#include <iostream>
#include <stack>
#include <ctype.h>
#include "op.hpp"
#include "arithmetic_operations.hpp"
#include "pow.hpp"
using namespace std;

Base* Factory::parse(char** input, int length) { 
	for (int i = 0; i < input; i++) {
                std::cout << input[i] << std::endl;
        }
        std::cout << length << std::endl;
	if (length % 2 == 1){
		cerr << "ERROR with size" << endl;
		return nullptr;
	}
	string sign = "";
	stack <Base*> ops;
	Base* temp;
	Base* temp2;
	for (int i = 1; i < length; i++) {
		if (i % 2 == 0){
			if ( input [i] == "+"  || input [i] == "-" || input [i] == "*" || input [i] == "**" || input [i] == "/") {
				sign = input[i];
			}
			else{
				cerr << "ERROR in sign" << endl;
		                return nullptr;
			}
		}
		else{
			string number (input[i]);
			if (isdigit(stoi(number))){
				Op* newOp = new Op(stoi(input[i]));
				ops.push(newOp);
			}
			if (ops.size() >= 2){
                                if (sign == "+"){
                                        temp = ops.top();
                                        ops.pop();
                                        Add* a = new Add(temp, ops.top());
                                        ops.pop();
                                        ops.push(a);
                                }
                                if (sign == "-"){
                                        temp = ops.top();
                                        ops.pop();
                                        Sub* s = new Sub(temp, ops.top());
                                        ops.pop();
                                        ops.push(s);
                                }
                                if (sign == "*"){
                                        temp = ops.top();
                                        ops.pop();
                                        Mult* m = new Mult(temp, ops.top());
                                        ops.pop();
                                        ops.push(m);
                                }
                                if (sign == "**"){
                                        temp = ops.top();
                                        ops.pop();
                                        Pow* p = new Pow(temp, ops.top());
                                        ops.pop();
                                        ops.push(p);
                                }
                                if (sign == "/"){
                                        temp = ops.top();
                                        ops.pop();
                                        Div* d = new Div(temp, ops.top());
                                        ops.pop();
                                        ops.push(d);
                                }

                        }
			if (!isdigit(stoi(input[i]))){
				cerr << "ERROR not digit" << endl;
		                return nullptr;
			}
		}
	}
	return ops.top();
}

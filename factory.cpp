#include "factory.hpp"
#include <iostream>
//#include <stack>
#include <queue>
#include <ctype.h>
#include "op.hpp"
#include "arithmetic_operations.hpp"
#include "pow.hpp"
#include <stdexcept>

using namespace std;

Base* Factory::parse(char** input, int length) { 
	if (length % 2 == 1){
		//cerr << "ERROR with size" << endl;
		cerr << "Invalid number of inputs. Expression tree cannot be generated." << endl;
		return nullptr;
	}
	string sign = "";
	//stack <Base*> ops;
	queue <Base*> ops;
	Base* temp;
	Base* temp2;
	for (int i = 1; i < length; i++) {
		if (i % 2 == 0){
			//converted input[i] to string
			string signString(input[i]);
			// Cannot do input[i] == "+" because input[i] is of type char*
			if ( signString == "+"  || signString == "-" || signString == "*" || signString == "**" || signString == "/") {
				sign = input[i];
			}
			else{
				//cerr << "ERROR in sign" << endl;
				cerr << "Invalid sign operator detected. Expression tree cannot be generated." << endl;
		                return nullptr;
			}
		}
		else{
			//string number (input[i]);
			//isdigit is not being used correctly
			/*if (isdigit(stoi(number))){
				Op* newOp = new Op(stoi(input[i]));
				ops.push(newOp);
			} */
			try {
				if (stoi(input[i])) {
 
					//to account for the weird functionality of stoi():
					/*string originalStr(input[i]);
					int newInt = stoi(input[i]);
					if (originalStr.size() != to_string(newInt).size() ){
						throw logic_error("Invalid number input");
					} */

					Op* newOp = new Op(stoi(input[i]));
					ops.push(newOp);
				}
			}

			catch (...) {
				cerr << input[i] << " is not a number. Expression tree cannot be generated." << endl;
                                return nullptr;	
			}

			if (ops.size() >= 2){
                                if (sign == "+"){
					temp = ops.front();
                                        //temp = ops.top();
                                        ops.pop();
                                        //Add* a = new Add(temp, ops.top());
                                        Add* a = new Add(temp, ops.front());
                                        ops.pop();
                                        ops.push(a);
                                }
                                if (sign == "-"){
					temp = ops.front();
                                        //temp = ops.top();
                                        ops.pop();
                                        //Sub* s = new Sub(temp, ops.top());
					Sub* s = new Sub(temp, ops.front());
                                        ops.pop();
                                        ops.push(s);
                                }
                                if (sign == "*"){
					temp = ops.front();
                                       // temp = ops.top();
                                        ops.pop();
                                       // Mult* m = new Mult(temp, ops.top());
                                        Mult* m = new Mult(temp, ops.front());
                                        ops.pop();
                                        ops.push(m);
                                }
                                if (sign == "**"){
					temp = ops.front();
                                       // temp = ops.top();
                                        ops.pop();
                                        //Pow* p = new Pow(temp, ops.top());
                                        Pow* p = new Pow(temp, ops.front());
                                        ops.pop();
                                        ops.push(p);
                                }
                                if (sign == "/"){
					temp = ops.front();
                                       // temp = ops.top();
                                        ops.pop();
                                        //Div* d = new Div(temp, ops.top());
					Div* d = new Div(temp, ops.front());
                                        ops.pop();
                                        ops.push(d);
                                }

                        }
			//I messed up, isdigit takes in a character input, not an integer input
			//if (!isdigit(stoi(input[i]))){
				//cerr << "ERROR not digit" << endl;
				// return nullptr;
		}
	}
	//return ops.top();
	return ops.front();
}

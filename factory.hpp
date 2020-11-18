#ifndef __FACTORY_HPP__
#define __FACTORY_HPP_
#include "base.hpp"

class Factory {
public:
	Factory() {};
	Base* parse (char** input, int length);
};

#endif

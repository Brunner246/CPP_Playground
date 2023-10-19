//
// Created by michael.brunner on 19/10/2023.
//

#ifndef CPP_PLAYGROUND_CANOTHERCIRCLESTRATEGY_H
#define CPP_PLAYGROUND_CANOTHERCIRCLESTRATEGY_H

#include <iostream>
#include "../CCircle.h"

class CAnotherCircleStrategy : public IDrawStrategy<CCircle>
{
public:
	void draw(const CCircle &aShape) override
	{
		std::cout << "Another Circle with radius " << aShape.getRadius() << std::endl;
	}
};

#endif //CPP_PLAYGROUND_CANOTHERCIRCLESTRATEGY_H

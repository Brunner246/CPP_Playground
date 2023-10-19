//
// Created by michael.brunner on 19/10/2023.
//

#ifndef CPP_PLAYGROUND_COPENGLCIRCLESTRATEGY_H
#define CPP_PLAYGROUND_COPENGLCIRCLESTRATEGY_H

#include <iostream>
#include "../CCircle.h"

class COpenGLCircleStrategy : public IDrawStrategy<CCircle>
{
public:
	void draw(const CCircle &aShape) override
	{
		std::cout << "OpenGL Circle with radius " << aShape.getRadius() << std::endl;
	}
};

#endif //CPP_PLAYGROUND_COPENGLCIRCLESTRATEGY_H

//
// Created by michael.brunner on 19/10/2023.
//

#ifndef CPP_PLAYGROUND_COPENGLSQUARESTRATEGY_H
#define CPP_PLAYGROUND_COPENGLSQUARESTRATEGY_H

#include <iostream>
#include "../CSquare.h"

class COpenGLSquareStrategy : public IDrawStrategy<CSquare>
{
public:
	void draw(CSquare const &aShape) override
	{
		std::cout << "OpenGL Square with side " << aShape.getSide() << std::endl;
	}
};

#endif //CPP_PLAYGROUND_COPENGLSQUARESTRATEGY_H

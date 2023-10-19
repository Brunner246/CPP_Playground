//
// Created by michael.brunner on 19/10/2023.
//

#include <vector>
#include <memory>
#include "StrategyMain.h"
#include "IShape.h"
#include "CCircle.h"
#include "Strategies/COpenGLCircleStrategy.h"
#include "Strategies/CAnotherCircleStrategy.h"
#include "CSquare.h"
#include "Strategies/COpenGLSquareStrategy.h"

namespace Strategy {

	void drawAllShapes(std::vector<std::unique_ptr<IShape>> const &aShapes);

	void strategyMain()
	{
		using Shapes = std::vector<std::unique_ptr<IShape>>;

		Shapes shapes{};

		shapes.emplace_back(std::make_unique<CCircle>(1.0, std::make_unique<COpenGLCircleStrategy>()));
		shapes.emplace_back(std::make_unique<CCircle>(2.0, std::make_unique<CAnotherCircleStrategy>()));
		shapes.emplace_back(std::make_unique<CSquare>(3.0, std::make_unique<COpenGLSquareStrategy>()));

		drawAllShapes(shapes);
	}

	void drawAllShapes(std::vector<std::unique_ptr<IShape>> const &aShapes)
	{
		for (const auto &shape : aShapes)
		{
			shape->draw();
		}
	}

} // Strategy
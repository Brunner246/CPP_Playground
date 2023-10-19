//
// Created by michael.brunner on 19/10/2023.
//

#ifndef CPP_PLAYGROUND_CSQUARE_H
#define CPP_PLAYGROUND_CSQUARE_H


#include <memory>
#include "IShape.h"
#include "Strategies/IDrawStrategy.h"

class CSquare : public IShape
{
public:
	explicit CSquare(const double aSide, std::unique_ptr<IDrawStrategy<CSquare>> &&aDrawStrategy)
			: mSide{aSide}
			  , mDrawStrategy{std::move(aDrawStrategy)}
	{
	}

	~CSquare() override = default;

	void draw() const override
	{
		mDrawStrategy->draw(*this);
	}

	[[nodiscard]] double getSide() const
	{
		return mSide;
	}

private:
	double mSide;

	std::unique_ptr<IDrawStrategy<CSquare>> mDrawStrategy;
};

#endif //CPP_PLAYGROUND_CSQUARE_H

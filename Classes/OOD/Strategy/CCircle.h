//
// Created by michael.brunner on 19/10/2023.
//

#ifndef CPP_PLAYGROUND_CCIRCLE_H
#define CPP_PLAYGROUND_CCIRCLE_H

#include <memory>
#include "IShape.h"
#include "Strategies/IDrawStrategy.h"

class CCircle : public IShape
{
public:
	explicit CCircle(const double aRadius, std::unique_ptr<IDrawStrategy<CCircle>>&& aDrawStrategy)
			: mRadius{aRadius}
			  , mDrawStrategy{std::move(aDrawStrategy)}
	{
	}

	~CCircle() override = default;

	void draw() const override
	{
		mDrawStrategy->draw(*this);
	}

	[[nodiscard]] double getRadius() const
	{
		return mRadius;
	}

private:
	double mRadius;

	std::unique_ptr<IDrawStrategy<CCircle>> mDrawStrategy;
};

#endif //CPP_PLAYGROUND_CCIRCLE_H

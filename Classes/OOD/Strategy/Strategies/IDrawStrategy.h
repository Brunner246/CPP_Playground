//
// Created by michael.brunner on 19/10/2023.
//

#ifndef CPP_PLAYGROUND_IDRAWSTRATEGY_H
#define CPP_PLAYGROUND_IDRAWSTRATEGY_H

template<typename T>
concept DerivedFrom = requires(T aShape)
{
	{ std::derived_from<T, IShape> };
};

template<DerivedFrom T>
class IDrawStrategy
{
public:
	virtual ~IDrawStrategy() noexcept = default;

	virtual void draw(const T &aShape) = 0;
};

#endif //CPP_PLAYGROUND_IDRAWSTRATEGY_H

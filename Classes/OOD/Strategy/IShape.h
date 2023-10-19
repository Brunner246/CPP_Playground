//
// Created by michael.brunner on 19/10/2023.
//

#ifndef CPP_PLAYGROUND_ISHAPE_H
#define CPP_PLAYGROUND_ISHAPE_H

class IShape
{
	public:
	virtual ~IShape() noexcept = default;

	virtual void draw() const = 0;
};

#endif //CPP_PLAYGROUND_ISHAPE_H

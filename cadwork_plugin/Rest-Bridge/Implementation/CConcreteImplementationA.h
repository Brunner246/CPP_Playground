//
// Created by michael.brunner on 02/10/2023.
//

#include "IBridgeImplementation.h"

#ifndef CPP_PLAYGROUND_CCONCRETEIMPLEMENTATIONA_H
#define CPP_PLAYGROUND_CCONCRETEIMPLEMENTATIONA_H


class CConcreteImplementationA : public IBridgeImplementation
{
public:
	~CConcreteImplementationA() override = default;

	void performRequestImpl(const std::string& aUrl, std::stringstream& aOut) const override;

private:

};


#endif //CPP_PLAYGROUND_CCONCRETEIMPLEMENTATIONA_H

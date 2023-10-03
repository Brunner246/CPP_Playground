//
// Created by michael.brunner on 03/10/2023.
//

#ifndef CPP_PLAYGROUND_CCONCRETEIMPLEMENTATIONB_H
#define CPP_PLAYGROUND_CCONCRETEIMPLEMENTATIONB_H


#include "IBridgeImplementation.h"

class CConcreteImplementationB : public IBridgeImplementation
{
public:
	~CConcreteImplementationB() override = default;

	void performRequestImpl(const std::string& aUrl, std::stringstream& aOut) const override;


private:

};


#endif //CPP_PLAYGROUND_CCONCRETEIMPLEMENTATIONB_H

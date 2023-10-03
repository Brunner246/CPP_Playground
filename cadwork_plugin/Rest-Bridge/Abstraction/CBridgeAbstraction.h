//
// Created by michael.brunner on 02/10/2023.
//

#ifndef CPP_PLAYGROUND_CBRIDGEABSTRACTION_H
#define CPP_PLAYGROUND_CBRIDGEABSTRACTION_H


#include <memory>
#include "IBridgeAbstraction.h"

class CBridgeAbstraction : public IBridgeAbstraction
{
public:
	explicit CBridgeAbstraction(std::unique_ptr<IBridgeImplementation> impl);

	void performRequest(const std::string& aUrl, std::stringstream& aOut) const override;

private:
	std::unique_ptr<IBridgeImplementation> implementation;
};


#endif //CPP_PLAYGROUND_CBRIDGEABSTRACTION_H

//
// Created by michael.brunner on 02/10/2023.
//

#include <stdexcept>
#include "CBridgeAbstraction.h"

void CBridgeAbstraction::performRequest(const std::string &aUrl, std::stringstream &aOut) const
{
	implementation->performRequestImpl(aUrl, aOut);
}

CBridgeAbstraction::CBridgeAbstraction(std::unique_ptr<IBridgeImplementation> impl)
		: implementation(std::move(impl))
{
	if (!implementation) {
		throw std::invalid_argument("Implementation must not be null");
	}
}

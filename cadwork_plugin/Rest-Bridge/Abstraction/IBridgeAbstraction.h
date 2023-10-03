//
// Created by michael.brunner on 02/10/2023.
//

#ifndef CPP_PLAYGROUND_IBRIDGEABSTRACTION_H
#define CPP_PLAYGROUND_IBRIDGEABSTRACTION_H

#include "../Implementation/IBridgeImplementation.h"

class IBridgeAbstraction {
public:
	virtual ~IBridgeAbstraction() = default;
	virtual void performRequest(const std::string& aUrl, std::stringstream& aOut) const = 0;
};


#endif //CPP_PLAYGROUND_IBRIDGEABSTRACTION_H

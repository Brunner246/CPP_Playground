//
// Created by michael.brunner on 02/10/2023.
//

#ifndef CPP_PLAYGROUND_IBRIDGEIMPLEMENTATION_H
#define CPP_PLAYGROUND_IBRIDGEIMPLEMENTATION_H

#include <string>

// Implementation
class IBridgeImplementation {
public:
	virtual ~IBridgeImplementation() = default;
	virtual void performRequestImpl(const std::string& aUrl, std::stringstream& aOut) const = 0;
};

#endif //CPP_PLAYGROUND_IBRIDGEIMPLEMENTATION_H

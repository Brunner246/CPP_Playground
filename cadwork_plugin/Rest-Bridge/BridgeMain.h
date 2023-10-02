//
// Created by michael.brunner on 02/10/2023.
//

#ifndef CPP_PLAYGROUND_BRIDGEMAIN_H
#define CPP_PLAYGROUND_BRIDGEMAIN_H

#include <sstream>
#include "Abstraction/IBridgeAbstraction.h"
#include "Implementation/CConcreteImplementationA.h"
#include "Abstraction/CBridgeAbstraction.h"

inline auto bridgeMain()
{

	std::unique_ptr<IBridgeImplementation> lImpl = std::make_unique<CConcreteImplementationA>();
	std::unique_ptr<IBridgeAbstraction> lBridge = std::make_unique<CBridgeAbstraction>(std::move(lImpl));

	std::wstringstream lOut;
	std::wstring lUrl = L"https:\\api.github.com\\users\\octocat\\orgs";

	lBridge->performRequest(lUrl, lOut);

	return lOut.str();

}


#endif //CPP_PLAYGROUND_BRIDGEMAIN_H

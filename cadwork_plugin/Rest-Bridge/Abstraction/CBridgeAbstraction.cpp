//
// Created by michael.brunner on 02/10/2023.
//

#include "CBridgeAbstraction.h"

void CBridgeAbstraction::performRequest(const std::wstring &aUrl, std::wstringstream &aOut) const
{
	implementation->performRequestImpl(aUrl, aOut);
}

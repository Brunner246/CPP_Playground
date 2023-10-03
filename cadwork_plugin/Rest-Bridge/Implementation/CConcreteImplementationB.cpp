//
// Created by michael.brunner on 03/10/2023.
//

#include <cpr/cpr.h>
#include "CConcreteImplementationB.h"

void CConcreteImplementationB::performRequestImpl(const std::string &aUrl, std::stringstream &aOut) const
{

	cpr::Response r = cpr::Get(cpr::Url{aUrl},
	                           cpr::Parameters{{"", ""}});
	r.status_code;                  // 200
	r.header["content-type"];       // application/json; charset=utf-8
	auto lResponse = r.text;                       // JSON text string
	aOut << lResponse.c_str();
}

//
// Created by michael.brunner on 02/10/2023.
//

#include <cpprest/http_client.h>
#include "CConcreteImplementationA.h"

void CConcreteImplementationA::performRequestImpl(const std::string &aUrl, std::stringstream &aOut) const
{
	web::http::client::http_client client(std::wstring(aUrl.begin(), aUrl.end()));

	client.request(web::http::methods::GET)
			.then([&aOut](const web::http::http_response &response) {
				if (response.status_code() == web::http::status_codes::OK) {
					return response.extract_json();
				} else {
					std::wcerr << L"Error: " << response.status_code() << std::endl;
					return concurrency::task_from_result(web::json::value());
				}
			})
			.then([&aOut](const web::json::value &jsonValue) {
				std::wstringstream lStream;
				auto lTest = jsonValue.serialize();

//				lStream << jsonValue.serialize();
//				auto lWString = lStream.str();
				std::string lString(lTest.begin(), lTest.end());


				aOut << lString;
			})
			.wait();
}

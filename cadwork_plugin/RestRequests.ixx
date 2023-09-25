//
// Created by michael.brunner on 25/09/2023.
//

module;

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <sstream>

export module RestRequests;


namespace Rest {

	export void GET(const std::wstring& aUrl, std::wstringstream& aJsonStream)
	{
		web::http::client::http_client client(aUrl);

		client.request(web::http::methods::GET)
			.then([&aJsonStream](const web::http::http_response& response)
				{
					if (response.status_code() == web::http::status_codes::OK)
					{
						return response.extract_json();
					}
					else
					{
						std::wcerr << L"Error: " << response.status_code() << std::endl;
						return concurrency::task_from_result(web::json::value());
					}
				})
			.then([&aJsonStream](const web::json::value& jsonValue)
				{
					aJsonStream << jsonValue.serialize();
				})
			.wait();
	}

//	web::http::client::http_client client(U("https://jsonplaceholder.typicode.com"));
//
//	web::http::uri_builder builder(U("/users"));
//
//	std::wstringstream lJsonStream;
//
//	client.request(web::http::methods::GET, builder.to_string())
//	.then([&lJsonStream](const web::http::http_response& response)
//{
//	if (response.status_code() == web::http::status_codes::OK)
//{
//	// Extract the response body as JSON
//	return response.extract_json();
//}
//else
//{
//std::wcerr << L"Error: " << response.status_code() << std::endl;
//return concurrency::task_from_result(web::json::value());
//}
//})
//.then([&lJsonStream](const web::json::value& jsonValue)
//{
//// Process the JSON data
//std::wcout << L"Response JSON: " << jsonValue.serialize() << std::endl;
//lJsonStream << jsonValue.serialize();
//})
//.wait();
//



}
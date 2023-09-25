//
// Created by michael.brunner on 21/09/2023.
//


#include <iostream>
#include "CwAPI3D.h"
#include "IButton.h"
#include <vector>
#include <functional>
#include <sstream>
import TestModule;
import RestRequests;



CWAPI3D_PLUGIN bool plugin_x64_init(CwAPI3D::ControllerFactory* aFactory);

bool plugin_x64_init(CwAPI3D::ControllerFactory* aFactory)
{
	if (!aFactory) {
		return EXIT_FAILURE;
	}


	aFactory->getUtilityController()->printToConsole(L"plugin_x64_init");

	aFactory->getElementController()->createTextObject(L"Hello World", {0., 0., 0.},
	                                                   {1., 0., 0.}, {0., 0., 1.}, 25);

	std::function<void(void)> lOnClick = [&aFactory, counter = 0]() mutable {
		auto lDefaultText = std::wstring(L"Hello World");
		auto lCount = std::to_wstring(counter++);

		aFactory->getUtilityController()->printToConsole((lDefaultText + lCount).c_str());
	};

	std::unique_ptr<TestModule::IButton> lButton;
	try {
		lButton = std::make_unique<TestModule::CButton>(std::move(lOnClick));
	}
	catch (const std::invalid_argument &e) {
		auto lWhat = e.what();
		CwAPI3D::narrowString lWhatCwAPI3D(lWhat);
		CwAPI3D::wideString s = L"Error: ";
		std::wstringstream wss;
		wss << std::wstring(lWhatCwAPI3D.begin(), lWhatCwAPI3D.end());
		std::wstring wideString = wss.str();

		aFactory->getUtilityController()->printToConsole(wideString.c_str());
		return EXIT_FAILURE;
	}

	TestModule::Sleep::sleep(5);

	aFactory->getUtilityController()->printToConsole(L"\n");
	for (const auto il: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
		aFactory->getUtilityController()->printToConsole(std::to_wstring(il).c_str());
		aFactory->getUtilityController()->printToConsole(L"\n");
		lButton->onClick();
	}
	aFactory->getUtilityController()->printToConsole(L"\n");

	// auto lResult = std::exchange(lButton, nullptr);


	std::wstringstream lJsonStream;
	Rest::GET(L"https://jsonplaceholder.typicode.com/users", lJsonStream);
	aFactory->getUtilityController()->printToConsole(lJsonStream.str().c_str());

	aFactory->getUtilityController()->printToConsole(L"plugin_x64_init done");

	return EXIT_SUCCESS;
}

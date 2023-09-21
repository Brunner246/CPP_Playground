//
// Created by michael.brunner on 21/09/2023.
//


#include <iostream>
#include "CwAPI3D.h"
#include "IButton.h"
#include <vector>
#include <functional>

import TestModule;

CWAPI3D_PLUGIN bool plugin_x64_init(CwAPI3D::ControllerFactory* aFactory);



bool plugin_x64_init(CwAPI3D::ControllerFactory* aFactory)
{
	if (!aFactory) {
		return EXIT_FAILURE;
	}
	aFactory->getUtilityController()->printToConsole(L"plugin_x64_init");

	aFactory->getElementController()->createTextObject(L"Hello World", {0., 0., 0.},
	                                                   {1., 0., 0.}, {0., 0., 1.}, 25);

	std::function<void(void)> lOnClick = [&aFactory, counter = 0] () mutable   {
		auto lDefaultText = std::wstring(L"Hello World");
		auto lCount = std::to_wstring(counter++);

		aFactory->getUtilityController()->printToConsole((lDefaultText + lCount).c_str());
	};

	std::unique_ptr<TestModule::IButton> lButton = std::make_unique<TestModule::CButton>(std::move(lOnClick));

	TestModule::Sleep::sleep(15);

	aFactory->getUtilityController()->printToConsole(L"\n");
	for (const auto il: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
		aFactory->getUtilityController()->printToConsole(std::to_wstring(il).c_str());
		aFactory->getUtilityController()->printToConsole(L"\n");
		lButton->onClick();
	}
	aFactory->getUtilityController()->printToConsole(L"\n");
	aFactory->getUtilityController()->printToConsole(L"plugin_x64_init done");

	return EXIT_SUCCESS;
}

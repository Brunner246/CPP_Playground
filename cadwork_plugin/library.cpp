//
// Created by michael.brunner on 21/09/2023.
//


#include <iostream>
#include "CwAPI3D.h"
#include <vector>


CWAPI3D_PLUGIN bool plugin_x64_init(CwAPI3D::ControllerFactory* aFactory);


bool plugin_x64_init(CwAPI3D::ControllerFactory* aFactory)
{
	if (!aFactory) {
		return EXIT_FAILURE;
	}
	aFactory->getUtilityController()->printToConsole(L"plugin_x64_init");

	aFactory->getElementController()->createTextObject(L"Hello World", {0., 0., 0.},
	                                                   {1., 0., 0.}, {0., 0., 1.}, 25);

	std::this_thread::sleep_for(std::chrono::seconds(15));
	aFactory->getUtilityController()->printToConsole(L"\n");
	for (const auto il: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
		aFactory->getUtilityController()->printToConsole(std::to_wstring(il).c_str());
		aFactory->getUtilityController()->printToConsole(L"\n");
	}
	aFactory->getUtilityController()->printToConsole(L"\n");
	aFactory->getUtilityController()->printToConsole(L"plugin_x64_init done");

	return EXIT_SUCCESS;
}

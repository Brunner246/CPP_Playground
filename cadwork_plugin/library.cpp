//
// Created by michael.brunner on 21/09/2023.
//


#include <iostream>
#include "CwAPI3D.h"
#include "IButton.h"
#include <vector>
#include <functional>
#include <sstream>
#include <format>
import TestModule;
import RestRequests;



CWAPI3D_PLUGIN bool plugin_x64_init(CwAPI3D::ControllerFactory* aFactory);

bool plugin_x64_init(CwAPI3D::ControllerFactory* aFactory)
{
	if (!aFactory) {
		return EXIT_FAILURE;
	}
	aFactory->getUtilityController()->printToConsole(L"plugin_x64_init");

	auto lGroupingType = aFactory->getAttributeController()->getElementGroupingType();
	std::wstring lGroupBy = lGroupingType == CwAPI3D::elementGroupingType::subgroup ? L"Subgroup" : L"Group";
	aFactory->getUtilityController()->printToConsole(lGroupBy.data());
	auto lActiveElementIds = aFactory->getElementController()->getActiveIdentifiableElementIDs();
	CwAPI3D::Interfaces::ICwAPI3DIfcOptions* lOptions = aFactory->createIfcOptions();
	auto lProjectData = lOptions->getCwAPI3DIfcOptionsProjectData();

	// aFactory->getBimController()->exportIfc2x3SilentlyWithOptions(lActiveElementIds, L"test.ifc",

	if (lActiveElementIds->count() > 0) {
		for (auto lCount{0}; lCount < lActiveElementIds->count(); lCount++) {
			auto lFacetList = aFactory->getGeometryController()->getElementFacets(lActiveElementIds->at(lCount));
			for (auto il{0}; il < lFacetList->count(); il++) {
				auto lNormal = lFacetList->getNormalVector(il);
				lFacetList->getDistanceToOrigin(il);
				auto lFormat = std::format("Normal: ({}, {}, {})", lNormal.mX, lNormal.mY, lNormal.mZ);
				auto lWideString = std::wstring(lFormat.begin(), lFormat.end());
				aFactory->getUtilityController()->printToConsole(lWideString.c_str());
			}
		}
	}

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

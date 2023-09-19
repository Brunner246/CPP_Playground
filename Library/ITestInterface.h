//
// Created by michael.brunner on 19/09/2023.
//

#ifndef LIBRARY_ITESTINTERFACE_H
#define LIBRARY_ITESTINTERFACE_H

#include "Library_Api.h"

namespace Library {
	class GEOM_API ITestInterface
	{
	public:
		virtual ~ITestInterface() = default;

		virtual void doSomething() = 0;
	};
}

#endif //LIBRARY_ITESTINTERFACE_H

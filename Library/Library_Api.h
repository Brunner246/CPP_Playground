//
// Created by michael.brunner on 19/09/2023.
//

#ifndef CPP_PLAYGROUND_LIBRARY_API_H
#define CPP_PLAYGROUND_LIBRARY_API_H


#ifdef LIBRARY
#define GEOM_API __declspec(dllexport)
#else
#define GEOM_API __declspec(dllimport)
#endif


#endif //CPP_PLAYGROUND_LIBRARY_API_H

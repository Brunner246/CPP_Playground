//
// Created by michael.brunner on 21/09/2023.
//

#ifndef CPP_PLAYGROUND_LIBRARY_API_H
#define CPP_PLAYGROUND_LIBRARY_API_H

#ifdef CWPLUGIN_EXPORTS
#define CW_API __declspec(dllexport)
#else
#define CW_API __declspec(dllimport)
#endif

#endif //CPP_PLAYGROUND_LIBRARY_API_H

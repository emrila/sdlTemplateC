//
// Created by emmar on 11/20/2024.
//
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace constants
{
    //gResPath-contains the relative path to your resources.

    //if Makefile and '/resources/' is used, use the following:
   // const std::string gResPath = "../../resources/";

    //if '/build/debug/resources/' is used, use the following:
    // const std::string gResPath = "./resources/";

    //If CMake is used, use the following:
    const std::string gResPath = "../resources/";
}

#endif
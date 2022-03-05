// Copyright 2022 mgshim

#ifndef STRINGUTIL_H_
#define STRINGUTIL_H_

#include <vector>
#include <string>

std::vector<std::string> split(const std::string &s, std::string delim);
std::string trim(const std::string &s);

#endif  // STRINGUTIL_H_

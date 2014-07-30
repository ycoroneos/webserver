#pragma once
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctemplate/template.h>
#include <string>

int cacheTemplates(const char* file);
std::string route_dynamic(char* uri, int len);

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>

/* get the input line from the command line */
std::string input(std::string);

/* convert ribbon to vector by dividing symbol */
std::vector<std::string> split(std::string, char);

/* put the vector in order */
std::vector<std::string> analyzer(std::vector<std::string>);

/* write/append mode file */
std::ofstream mode(std::string);

/* generate combinations and write them to a file */
void generate_dictionary(int, int, std::vector<std::string>,
	std::ofstream &, std::function<void(unsigned int, unsigned int)>);

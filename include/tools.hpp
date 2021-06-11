#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <ctime>
#include <locale>
#include <cmath>
#include <utility>
#include <algorithm>
#include <functional>

// get the input line from the command line
std::string input(std::string);

// convert ribbon to vector by dividing symbol
std::vector<std::string> split(std::string, char);

// put the vector in order
std::vector<std::string> analyzer(std::vector<std::string>);

// write/append mode file
std::ofstream mode(std::string);

// generate combinations and write them to a file
void generate_dictionary(int, int, std::vector<std::string>,
	std::ofstream &, std::function<void(std::size_t, std::size_t, std::time_t)>);

// transfer to string
std::string time_format(std::time_t);

// number of possible combinations
std::size_t number_combinations(int, int, int);

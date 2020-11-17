#include "tools.hpp"

#include <iostream>

int main() {

	std::cout << "DICTIONARY GENERATOR" << '\n';
	std::cout << '\n';

	auto min = std::stoi(input("elements minimum: "));
	auto max = std::stoi(input("elements maximum: "));
	auto kw = analyzer(split(input("keywords: "), ' '));
	auto fn = input("file name: ");

	generate_dictionary(min, max, kw, fn, [](unsigned int count, unsigned int size) {
		std::cout << "count: " << count << '/' << size << '\r';
	});
	std::cout << '\n';

	return (0);

};

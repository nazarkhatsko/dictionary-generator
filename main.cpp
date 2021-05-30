#include "tools.hpp"

#include <iostream>

int main() {

	std::cout << "DG (Dictionary Generator)" << '\n';
	std::cout << "Version 1.0.0" << '\n';
	std::cout << '\n';

	auto min = std::stoi(input("Enter elements minimum: "));
	auto max = std::stoi(input("Enter elements maximum: "));
	auto kw = analyzer(split(input("Enter keywords: "), ' '));
	auto dict = mode(input("Enter dictionary name: "));

	std::cout << '\n';
	std::cout << "\033[0;32m" << "PROGRESS" << "\033[0m" << '\n';
	generate_dictionary(min, max, kw, dict, [](unsigned int count, unsigned int size) {
		std::cout << count << '/' << size << " -> " << (count / (size / 100)) << '%' << '\r';
	});
	std::cout << '\n';

	return 0;

};

#include "tools.hpp"

#include <iostream>

int main() {

	std::cout << "DG (Dictionary Generator)\n";
	std::cout << "Version 1.0.1\n";
	std::cout << "\n";

	auto min = std::stoi(input("Enter elements minimum: "));
	auto max = std::stoi(input("Enter elements maximum: "));
	auto kw = analyzer(split(input("Enter keywords: "), ' '));
	auto dict = mode(input("Enter dictionary name: "));

	std::cout << "\n";
	std::cout << "\033[0;32m" << "PROGRESS" << "\033[0m\n";
	generate_dictionary(min, max, kw, dict, [](std::size_t count, std::size_t size, std::time_t tm) {
		std::cout << count << "/" << size;
		std::cout << " -> " << (count / (size / 100)) << "%";
		std::cout << " (" <<  time_format(tm) << ")\r";
	});
	std::cout << "\n";

	return 0;

};

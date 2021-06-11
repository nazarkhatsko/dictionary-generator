#include "tools.hpp"

std::string input(std::string title) {

	// print title
	std::cout << title;

	// get input
	std::string line;
	std::getline(std::cin, line);

	return line;

};

std::vector<std::string> split(std::string text, char separation) {

	std::vector<std::string> v;

	std::stringstream ss(text);
	std::string str;
	while (std::getline(ss, str, separation)) {
		// add elements to the vector
		v.push_back(str);
	};

	return v;

};

std::vector<std::string> analyzer(std::vector<std::string> v) {

	// map initialization
	std::map<std::string, std::pair<int, int>> keys = {
		{"-0", std::make_pair(48, 57)},
		{"-a", std::make_pair(97, 122)},
		{"-A", std::make_pair(65, 90)},
		{"-!", std::make_pair(33, 47)}
	};

	// search by map keys
	for (auto key : keys) {
		auto it = std::find(v.begin(), v.end(), key.first);

		if (it != v.end()) {
			// replace key with elements
			v.erase(it);
			for (int n = key.second.first; n <= key.second.second; n++) {
				v.push_back(std::string(1, static_cast<char> (n)));
			};
		};
	};

	// sord and remove copy
	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());

	return v;

};

std::ofstream mode(std::string path) {

	// is file create
	if (std::ifstream(path).good()) {
		// select mode
		auto mode = input("Enter write/append dictionary (w/a): ");
		if (mode == "a") {
			return std::ofstream(path, std::ios::app);
		};
	};

	return std::ofstream(path);

};

void generate_dictionary(int min, int max, std::vector<std::string> kw,
	std::ofstream &dict, std::function<void(std::size_t, std::size_t, std::time_t)> print) {

	// init
	std::size_t count = 1;
	std::size_t size = number_combinations(min, max, kw.size());
	std::time_t tm = std::time(0);

	// generate a combination and write it to a file
	if (dict.is_open()) {
		std::vector<std::string> v(min, kw.front());
		for (int i = 0; i < kw.size(); i++) {
			v.back() = kw.at(i);

			// print status
			print(count, size, std::time(0) - tm);
			count++;

			// write to file
			for (auto i : v) {
				dict << i;
			};
			dict << "\n";

			// next item
			if (v.back() == kw.back()) {
				i = -1;

				for (int n = v.size() - 1; n > -1; n--) {
					if (v.at(n) == kw.back()) {
						v.at(n) = kw.front();

						// add a new first element
						if (n == 0) {
							v.insert(v.begin(), kw.front());
						};
					} else {
						// find the next item
						auto it = std::find(kw.begin(), kw.end(), v.at(n));
						auto index = std::distance(kw.begin(), it);
						v.at(n) = kw.at(index + 1);
						break;
					};
				};
			};

			// max length
			if (v.size() > max) {
				break;
			};
		};
		dict.close();
	};

};

std::string time_format(std::time_t t) {

	char buff[9];
	std::strftime(buff, sizeof (buff), "%H:%M:%S", std::localtime(&t));

	return buff;

};

std::size_t number_combinations(int min, int max, int size) {

	std::size_t n = 0;
	for (int i = min; i <= max; i++) {
		n += std::pow(size, i);
	};

	return n;

};

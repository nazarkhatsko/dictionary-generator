#include "tools.hpp"

std::string input(std::string title) {

	/* print title */
	std::cout << title;

	/* get input */
	std::string line;
	std::getline(std::cin, line);

	return line;

};

std::vector<std::string> split(std::string line, char separation) {

	std::vector<std::string> v;

	/* add elements to the vector */
	v.push_back("");
	line.push_back(separation);
	for (auto ch : line) {
		if (ch != separation) {
			v.back().push_back(ch);
			continue;
		};

		v.push_back("");
	};

	/* delete empty cells from vector */
	v.erase(std::remove_if(v.begin(), v.end(), [](std::string s) {
		return (s.empty());
	}), v.end());

	return v;

};

std::vector<std::string> analyzer(std::vector<std::string> v) {

	/* map initialization */
	std::map<std::string, std::pair<int, int>> keys = {
		{"-0", std::make_pair(48, 57)},
		{"-a", std::make_pair(97, 122)},
		{"-A", std::make_pair(65, 90)},
		{"-!", std::make_pair(33, 47)}
	};

	/* search by map keys */
	for (auto key : keys) {
		auto it = std::find(v.begin(), v.end(), key.first);

		if (it != v.end()) {
			/* replace key with elements */
			v.erase(it);
			for (int n = key.second.first; n <= key.second.second; n++) {
				v.push_back(std::string(1, static_cast<char> (n)));
			};
		};
	};

	/* sord and remove copy */
	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());

	return v;

};

std::ofstream mode(std::string path) {

	/* is file create */
	if (std::ifstream(path).good()) {
		/* select mode */
		auto mode = input("Enter write/append dictionary (w/a): ");
		if (mode == "a") {
			return std::ofstream(path, std::ios::app);
		};
	};

	return std::ofstream(path);

};

void generate_dictionary(int min, int max, std::vector<std::string> kw,
	std::ofstream &dict, std::function<void(unsigned int, unsigned int)> print) {

	/* number of all combinations */
	unsigned int num_all = 0;
	for (int i = min; i <= max; i++) {
		num_all += std::pow(kw.size(), i);
	};
	unsigned int num_curr = 1;

	/* generate a combination and write it to a file */
	if (dict.is_open()) {
		std::vector<std::string> v(min, kw.front());
		for (int i = 0; i < kw.size(); i++) {
			v.back() = kw.at(i);

			/* print status */
			print(num_curr, num_all);
			num_curr++;

			/* write to file */
			for (auto i : v) {
				dict << i;
			};
			dict << '\n';

			/* next item */
			if (v.back() == kw.back()) {
				i = -1;

				for (int n = v.size() - 1; n > -1; n--) {
					if (v.at(n) == kw.back()) {
						v.at(n) = kw.front();

						/* add a new first element */
						if (n == 0) {
							v.insert(v.begin(), kw.front());
						};
					} else {
						/* find the next item */
						auto it = std::find(kw.begin(), kw.end(), v.at(n));
						auto index = std::distance(kw.begin(), it);
						v.at(n) = kw.at(index + 1);
						break;
					};
				};
			};

			/* max lenght */
			if (v.size() > max) {
				break;
			};
		};
		dict.close();
	};

};

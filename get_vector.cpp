#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <cassert>

template<typename T, typename ... Ts>
const std::vector<T>& get_vector(const std::tuple<std::vector<Ts>...>& Tuple) {
	return std::get<std::vector<T>>(Tuple);
}
template<typename T, typename ... Ts>
std::vector<T>& get_vector(std::tuple<std::vector<Ts>...>& Tuple) {
	return std::get<std::vector<T>>(Tuple);
}

int main() {
	int a = 3;
	int* b = &a;
	std::tuple<std::vector<int>, std::vector<char>, std::vector<std::string>> T1;
	get_vector<int>(T1).push_back(a);
	assert(get_vector<int>(T1).back() == a);

	get_vector<int>(T1).push_back(2 * a);
	get_vector<int>(T1).push_back(3 * a);

	for (auto it = get_vector<int>(T1).begin(); it != get_vector<int>(T1).end(); it++) {
		std::cout << *it << " ";
	}
	get_vector<int>(T1)[0] = 111;
	std::cout << std::endl;
	for (auto it = get_vector<int>(T1).begin(); it != get_vector<int>(T1).end(); it++) {
		std::cout << *it << " ";
	}
	system("pause");
	return 0;
}
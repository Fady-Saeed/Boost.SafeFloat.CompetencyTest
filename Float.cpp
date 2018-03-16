#include <iostream>
#include <array>
#include <limits>

#define INVALID_FLOAT_NUMBER "Invalid floating point number"

namespace SafeFloats {
	constexpr double pow_impl(double base, int exp);
	constexpr double pow(double base, int exp);

	template<std::size_t SIZE>
	constexpr float atof_fraction(int exp, const std::array<char, SIZE>& chars, int index) {
		if (index == SIZE)
			return 0;
		return pow(10, exp - 1)*(chars[index] - '0') + atof_fraction(exp - 1, chars, index + 1);
	}
	template<std::size_t SIZE>
	constexpr float atof_fraction(const std::array<char, SIZE>& chars, int index = 0) {
		if (index == SIZE)
			return 0;
		if (chars[index] == '.')
			return atof_fraction(0, chars, index + 1);
		return atof_fraction(chars, index + 1);
	}


	constexpr double pow_impl(double base, int exp) {
		return (exp == 0 ? 1.0 : base*pow_impl(base, exp - 1));
	}

	constexpr double pow(double base, int exp) {
		return (exp >= 0 ? pow_impl(base, exp) : pow_impl(1.0 / base, -1 * exp));
	}
	constexpr bool isPowerOfHalf(float const number) {
		if (number == 0.5)
			return true;
		else if (number > 0.5)
			return false;
		else if (number < 0.5)
			return isPowerOfHalf(number * 2);
	}
}

template<char... numberDigits>
constexpr float operator"" _f() {
	constexpr std::array<char, sizeof...(numberDigits)> numberDigitsArr = { numberDigits... };
	constexpr float number = SafeFloats::atof_fraction(numberDigitsArr);
	static_assert(SafeFloats::isPowerOfHalf(number), INVALID_FLOAT_NUMBER);
	return number;
}
int main() {
	0.5_f;
	0.25_f;
	0.125_f;
	//0.625_f; // Fails Compilation
	//0.2_f; // Fails Compilation
	//0.1_f; // Fails Compilation

	return 0;
}
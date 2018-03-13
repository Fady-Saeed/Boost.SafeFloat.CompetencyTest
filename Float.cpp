#include <iostream>
#include <array>
#include <cmath>
#include <limits>

template<std::size_t SIZE>
constexpr float atof_fraction(int exp,const std::array<char,SIZE>& chars,int index){
 	if(index==SIZE)
 		return 0;
 	return pow(10,exp-1)*(chars[index]-'0')+atof_fraction(exp-1,chars,index+1);
}
template<std::size_t SIZE>
constexpr float atof_fraction(const std::array<char,SIZE>& chars,int index=0){
 	if(chars[index]=='.')
 		return atof_fraction(0,chars,index+1);
 	return atof_fraction(chars,index+1);
}

template<char... numberDigits>
constexpr float operator"" _f(){
	constexpr std::array<char, sizeof...(numberDigits)> numberDigitsArr = { numberDigits... };
	constexpr float number = atof_fraction(numberDigitsArr);
	static_assert(log10(number)/log10(0.5)-int(log10(number)/log10(0.5)) < std::numeric_limits<float>::min(),"Error");
	return number;
}

int main(){
	float x = 0.5_f;
	// x=0.25_f;
	// x=0.1_f; // Fails Compilation
	return 0;
}
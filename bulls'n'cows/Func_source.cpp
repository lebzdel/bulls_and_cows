#include "Func_heads.h"
#include <iostream>


char* Begining_Number() {
	char* number_str = new char[4];
	do { number_str[0] = '0' + rand() % 10; } while (number_str[0] == '0');
	do { number_str[1] = '0' + rand() % 10; } while (number_str[1] == number_str[0]);
	do { number_str[2] = '0' + rand() % 10; } while (number_str[2] == number_str[1] || number_str[2] == number_str[0]);
	do { number_str[3] = '0' + rand() % 10; } while (number_str[3] == number_str[2] || number_str[3] == number_str[1] || number_str[3] == number_str[0]);

	return number_str;
}


char* Get_Number(std::istream& input, std::ostream& output) {
	char* number_str = new char[4];
	do {
		output << " ¬ведите 4-значное число : ";
		input >> number_str;
	} while (sizeof(number_str) / sizeof(number_str[0]) != 4);

	return number_str;
}


bool End(const char* ch1, const char* ch2) {
	return ch1[0] == ch2[0] && ch1[1] == ch2[1] && ch1[2] == ch2[2] && ch1[3] == ch2[3];
}


void Sravn(const char* s1, const char* s2, int& bulls, int& cows) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (s1[i] == s2[j]) {
				if (i == j) { bulls++; }
				else { cows++; }
			}
		}
	}

	return;
}
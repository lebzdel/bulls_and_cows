#pragma once
#include <string>
#include <iostream>



char* Begining_Number();
char* Get_Number(std::istream& input = std::cin, std::ostream& output = std::cout);
bool End(const char* ch1, const char* ch2);
void Sravn(const char* s1, const char* s2, int& bulls, int& cows);
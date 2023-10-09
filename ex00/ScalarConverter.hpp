#pragma once

#include <iostream>
#include <iomanip>
#include "ConversionInput.hpp"

class ScalarConverter
{
public:
	static void	convertChar(const ConversionInput& input);
	static void	printChar(const char& c);
	static void	convertInt(const ConversionInput& input);
	static void	convertFloat(const ConversionInput& input);
	static void	convertDouble(const ConversionInput& input);
	static void	convertSpcF(const ConversionInput& input);
	static void	convertSpcD(const ConversionInput& input);
	static void	convert(const ConversionInput& input);
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& sC);
	ScalarConverter	&operator=(const ScalarConverter& sC);
};


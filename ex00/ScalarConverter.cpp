#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};
ScalarConverter::~ScalarConverter() {};
ScalarConverter::ScalarConverter(const ScalarConverter& sC) {};
ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& sC) { return (*this); };

void	ScalarConverter::printChar(const char& c)
{
	if (std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: " << "Not Displayable" << std::endl;

}

void	ScalarConverter::convertChar(const ConversionInput& input)
{
	const std::string&	str(input.getInput());

	if (std::isprint(static_cast<unsigned char>(str[0])))
	std::cout << "char: " << str[0] << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
}

void	ScalarConverter::convertInt(const ConversionInput& input)
{
	const std::string&	str(input.getInput());
	int	n;

	n = std::stoi(str);
	printChar(static_cast<char>(n));
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

void	ScalarConverter::convertFloat(const ConversionInput& input)
{
	const std::string&	str(input.getInput());
	float	n;

	n = std::stof(str);
	printChar(static_cast<char>(n));
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << n << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << std::endl;
}

void	ScalarConverter::convertDouble(const ConversionInput& input)
{
	const std::string&	str(input.getInput());
	double	n;

	n = std::stod(str);
	printChar(static_cast<char>(n));
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << n << std::endl;
}

void	ScalarConverter::convertSpcF(const ConversionInput& input)
{
	const std::string&	str(input.getInput());

	std::cout << "char: " << "Impossible" << std::endl;
	std::cout << "int: " << "Impossible" << std::endl;
	std::cout << "float: " << str << std::endl;
	std::cout << "double: ";
	for (int i = 0; i < str.length() - 1; i++)
		std::cout << str[i];
	std::cout << std::endl;
}

void	ScalarConverter::convertSpcD(const ConversionInput& input)
{
	const std::string&	str(input.getInput());

	std::cout << "char: " << "Impossible" << std::endl;
	std::cout << "int: " << "Impossible" << std::endl;
	std::cout << "float: " << str << "f" << std::endl;
	std::cout << "double: " << str << std::endl;
}


void	ScalarConverter::convert(const ConversionInput& input)
{
	enum e_inputType inputType;

	inputType = input.getInputType();
	if (inputType == IT_CHAR)
		ScalarConverter::convertChar(input);
	else if (inputType == IT_INT)
		ScalarConverter::convertInt(input);
	else if (inputType == IT_FLOAT)
		ScalarConverter::convertFloat(input);
	else if (inputType == IT_DOUBLE)
		ScalarConverter::convertDouble(input);
	else if (inputType == IT_SPC_F)
		ScalarConverter::convertSpcF(input);
	else if (inputType == IT_SPC_D)
		ScalarConverter::convertSpcD(input);
	else
		std::cout << "Invalid argument" << std::endl;
}
#include "ConversionInput.hpp"

ConversionInput::ConversionInput()
	: m_input(""), m_inputType(IT_INVALID) {}

ConversionInput::ConversionInput(const std::string &input)
	: m_input(input)
{
	setInputType();
}

ConversionInput::~ConversionInput() { };

ConversionInput::ConversionInput(const ConversionInput& conversionInput)
	:	m_input(conversionInput.m_input), m_inputType(conversionInput.m_inputType) { };

ConversionInput&	ConversionInput::operator=(const ConversionInput& conversionInput)
{ (void)conversionInput; return (*this); }

void	ConversionInput::setInputType()
{
	if (m_input.empty())
		m_inputType = IT_INVALID;
	else if (inputIsChar(m_input))
		m_inputType = IT_CHAR;
	else if (inputIsInt(m_input))
		m_inputType = IT_INT;
	else if (inputIsDouble(m_input))
		m_inputType = IT_DOUBLE;
	else if (inputIsFloat(m_input))
		m_inputType = IT_FLOAT;
	else if (inputIsSpecialD(m_input))
		m_inputType = IT_SPC_D;
	else if (inputIsSpecialF(m_input))
		m_inputType = IT_SPC_F;
	else
		m_inputType = IT_INVALID;
}

const enum e_inputType	&ConversionInput::getInputType() const
{
	return (m_inputType);
}

const std::string&	ConversionInput::getInput() const
{
	return (m_input);
}

bool	ConversionInput::inputIsChar(const std::string& input)
{
	if (input.length() > 1 || std::isdigit(static_cast<unsigned char>(input[0]))
		|| !std::isprint(input[0]))
		return (false);
	return (true);
}

bool	ConversionInput::inputIsInt(const std::string& input)
{
	int	i;

	if (input.find('.') != std::string::npos)
		return (false);
	i = 0;
	if (input[i] == '-' || input[i] == '+') i++;
	for (std::string::size_type j = i; j < input.length(); j++)
		if (!std::isdigit(static_cast<unsigned char>(input[j])))
			return (false);
	return (true);
}

bool	ConversionInput::inputIsDouble(const std::string& input)
{
	int		i;
	int		input_length;

	i = 0;
	input_length = input.length();
	if (input[i] == '-' || input[i] == '+') i++;
	for (int j = i; j < input_length; j++)
		if (!(std::isdigit(static_cast<unsigned char>(input[j])) || input[j] == '.'))
			return (false);
	return (!(input[input_length - 1] == '.'));
}

bool	ConversionInput::inputIsFloat(const std::string& input)
{
	int		i;
	int		input_length;

	i = 0;
	input_length = input.length();
	if (input[i] == '-' || input[i] == '+') i++;
	for (int j = i; j < input_length - 1; j++)
		if (!(std::isdigit(static_cast<unsigned char>(input[j])) || input[j] == '.'))
			return (false);
	return (input[input_length - 1] == 'f');
}

bool	ConversionInput::inputIsSpecialF(const std::string& input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return (true);
	return (false);
}

bool	ConversionInput::inputIsSpecialD(const std::string& input)
{
	if (input == "-inf" || input == "+inf" || input == "nan")
		return (true);
	return (false);
}

std::ostream&	operator<<(std::ostream& o, const enum e_inputType& inputType)
{
	std::string	inputTypes[] = {"INVALID", "CHAR", "INT", "FLOAT", "DOUBLE", "SPC_F", "SPC_D"};
	o << inputTypes[inputType];
	return (o);
}

#pragma once

#include <iostream>

enum e_inputType
{
	IT_INVALID,
	IT_CHAR,
	IT_INT,
	IT_FLOAT,
	IT_DOUBLE,
	IT_SPC_F,
	IT_SPC_D
};

// To build canonical stuff later
class ConversionInput
{
public:
	ConversionInput();
	ConversionInput(const std::string &input);
	static bool				inputIsChar(const std::string& input);
	static bool				inputIsInt(const std::string& input);
	static bool				inputIsFloat(const std::string& input);
	static bool				inputIsDouble(const std::string& input);
	static bool				inputIsSpecialF(const std::string& input);
	static bool				inputIsSpecialD(const std::string& input);
	static bool				inputIsOnlyDigits(const std::string& input);
	void					setInputType();
	const std::string&		getInput()  const;
	const enum e_inputType	&getInputType() const;
	
private:
	const std::string		m_input;
	enum e_inputType		m_inputType;
};

std::ostream&	operator<<(std::ostream& o, const enum e_inputType& inputType);
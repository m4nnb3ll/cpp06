/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelayad <abelayad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:04:49 by abelayad          #+#    #+#             */
/*   Updated: 2023/10/09 11:26:52 by abelayad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ConversionInput.hpp"
#include "ScalarConverter.hpp"

// STOPPED HERE
int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	ConversionInput inp(argv[1]);
	std::cout << "The input type is: " << inp.getInputType() << std::endl;
	ScalarConverter::convert(inp);
	return (0);
}
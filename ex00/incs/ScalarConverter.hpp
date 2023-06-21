#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <exception>
#include <cstdlib> // For atoi and atof
#include <string>
#include <iomanip> // For std::fixed and std::setprecision


class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ~ScalarConverter();
    ScalarConverter& operator=(const ScalarConverter& other);
    static void convert(const std::string& input);

private:
    static void convertChar(const std::string &input);
    static void convertInt(const std::string &input);
    static void convertFloat(const std::string &input);
    static void convertDouble(const std::string &input);

    static bool isDisplayable(char c);
};

#endif

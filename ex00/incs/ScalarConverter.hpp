#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream> // input / output streams
#include <exception> // handle exceptions
#include <cstdlib> // For atoi and atof
#include <string> // string related
#include <iomanip> // For std::fixed and std::setprecision
#include <cctype> // character classification and conversion
#include <sstream> // working with string streams

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ~ScalarConverter();
    ScalarConverter& operator=(const ScalarConverter& other);
    static void convert(const std::string &input);

private:
    static void convertChar(const std::string &input);
    static void convertInt(const std::string &input);
    static void convertFloat(const std::string &input);
    static void convertDouble(const std::string &input);

    static bool isDisplayable(char c);
};

#endif

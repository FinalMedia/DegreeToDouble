/** 
* Converts coordinates from minutes to degrees
* E.g. N 51° 53' 39,26 to 51.8942
* 
* Namespace DegreeConverter
* Class Converter
**/


#ifndef CONVERTER_H
#define CONVERTER_H


#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <vector>
#include <iterator>

using namespace std;

namespace DegreeConverter {
	class Converter {

		public:
			/**
			* Converts a Minute based coordinate to a double
			* 
			* @param string (N 51° 53' 39,26)
			* @return double 51.8942
			* @throws Exception in case of invalid string
			**/
			static double convertDegreeToDouble(string);
	
		private:
			/**
			* Converts a Minute based coordinate to a double
			* 
			* @param string str the subject string
			* @param string from what to search for
			* @param string and what to replace it with
			* @return void, replacement is by reference
			**/
			static void replaceAll(string&, const string&, const string&);
			/**
			* Explodes a string based on delimiter
			* 
			* @param string& delimiter a references to the delimiter
			* @param string& str a reference to the string to split
			* @return a vector of the splitted string
			**/
			static vector<string> explode(const string&, const string&);
	};
}
#endif
#include "converter.h"

namespace DegreeConverter {
	
	/**
	* Converts a Minute based coordinate to a double
	* 
	* @param string (N 51° 53' 39,26)
	* @return double 51.8942
	* @throws Exception in case of invalid string
	**/
	double Converter::convertDegreeToDouble(string degree) {

		int multiplier = ((degree.find("S") != string::npos) || (degree.find("W") != string::npos)) ? -1 : 1;


		replaceAll(degree," ",".");
		replaceAll(degree,"°","");
		replaceAll(degree,"'","");
		replaceAll(degree,"\"","");
		replaceAll(degree,",",".");

		degree = degree.substr(1,degree.length());

		//cout << "After regex: " << degree << endl;

		//split at dot
		vector <string> pointArray;
		string delimiter = ".";
		size_t pos = 0;
		while ((pos = degree.find(delimiter)) != string::npos) {
			pointArray.insert(pointArray.end(), degree.substr(0, pos));
	
			degree.erase(0, pos + delimiter.length());
		}


		double degrees = 0;
		double minutes = 0;
		double seconds = 0;

		if (pointArray.size()==3)
		{
			degrees = stod(pointArray[0]);
			minutes = stod(pointArray[1]) / 60;
			seconds = stod(pointArray[2]) / 3600;
		}

		//cout << degrees << " " << minutes << " " << seconds << endl;

		return (degrees + minutes + seconds) * multiplier;

	}
	
	/**
	* Explodes a string based on delimiter
	* 
	* @param string& delimiter a references to the delimiter
	* @param string& str a reference to the string to split
	* @return a vector of the splitted string
	**/

	vector<string> Converter::explode( const string &delimiter, const string &str) {
		vector<string> arr;

		int strleng = str.length();
		int delleng = delimiter.length();
		if (delleng==0)
			return arr;//no change

		int i=0;
		int k=0;
		while( i<strleng )
		{
			int j=0;
			while (i+j<strleng && j<delleng && str[i+j]==delimiter[j])
				j++;
			if (j==delleng)//found delimiter
			{
				arr.push_back(  str.substr(k, i-k) );
				i+=delleng;
				k=i;
			}
			else
			{
				i++;
			}
		}
		arr.push_back(  str.substr(k, i-k) );
		return arr;
	}
	
	/**
	* Converts a Minute based coordinate to a double
	* 
	* @param string str the subject string
	* @param string from what to search for
	* @param string and what to replace it with
	* @return void, replacement is by reference
	**/
	void Converter::replaceAll(std::string& str, const std::string& from, const std::string& to) {
		if(from.empty())
			return;
		size_t start_pos = 0;
		while((start_pos = str.find(from, start_pos)) != std::string::npos) {
			str.replace(start_pos, from.length(), to);
			start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
		}
	}
}
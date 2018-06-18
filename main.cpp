#include <iostream>
#include <string>
#include "converter.h"

using namespace std;



void getInput(string&, string);

int main() {

	string latitude, longitude;
	getInput(latitude, "Latitude");
	getInput(longitude, "Longitude");

	cout << "Latitude: " << DegreeConverter::Converter::convertDegreeToDouble(latitude) << endl;
	cout << "Longitude: " << DegreeConverter::Converter::convertDegreeToDouble(longitude)<< endl;
	
	return 0;
	

}


void getInput(string &inputString, string text) {
	cout << text << ": ";
	cin.ignore();
	getline(cin, inputString);
}	


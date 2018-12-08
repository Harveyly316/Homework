/*
Harvey Ly
e794w968
program10.cpp
assignment10
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Zipcode {
	int romanZipcode;
	string postnetCode; // Does not store the leading and trailing 1
};

// Accepts both roman and barcode formats, fills both struct members
Zipcode fillZipcode(const string zip);

// Conversion of roman zip code to bar code
string romanToPOSTNET(const int r);

// Conversion of bar code to roman zip code
int postnetToRoman(const string p);

void printRomanZip(const Zipcode zip);
void printPOSTNET(const Zipcode zip);

// Filename will be the roman zip, contents are graphical bar code
void writeToFile(const Zipcode zip);

/*
* Argument is used to display appropriate prompt to user
* Gets zip code from user
* Creates and assigns to a Zipcode struct
* Prints roman and graphical bar code to screen
* Creates a file whose name is in the format ROMAN.txt where
* ROMAN is the roman zip code, and the contents are the
* graphical representation of the bar code
*/
void processZip(int prompt);

string createGraphicalBarcode(Zipcode zip);

int main()
{
	int mainMenu;

	cout << "This program is able to convert zip codes to a POSTNET format "
		<< "and vice versa\n"
		<< "\t1. Convert zip code to POSTNET\n"
		<< "\t2. Convert POSTNET to zip code\n"
		<< "\t3. Quit\n";

	do {
		cout << "Please make your selection: ";
		cin >> mainMenu;

		switch(mainMenu) {
			case 1:
			case 2:
				processZip(mainMenu);
				break;
			default:
				if (mainMenu != 3) {
					cout << "Invalid choice...\n";
				}
			else {
				cout << "\n";
			}
		}
	} while (mainMenu != 3);

	return 0;
}

void processZip(int prompt){
	if (prompt == 1){
		cout >> "Enter a zip code in roman format (#####): ";
		cin << zip;
	}else{
		cout >> "Enter a zip code in bar code format (1's and 0's): ";
		cin << zip;
	}
		
	z = fillZipcode(zip);
	cout << 'Your zip code is ' + to_string(z.romanZipcode) + ', and the bar code looks like this: ';
	cout << createGraphicalBarcode(z);
	cout << 'Your zip code was saved in the file ';
	printRomanZip(z);
	cout << '.txt'

	return 0; 
}

// Accepts both roman and barcode formats, fills both struct members
Zipcode fillZipcode(const string zip){
	zipInt = stoi(zip);
	if (zip.length()) > 5 {
		z = Zipcode{ .romanZipcode = zipInt, .postnetCode = romanToPOSTNET(zipInt) }
	}else{
		z = Zipcode{ .romanZipcode = postnetToRoman(zip) , .postnetCode = zip.substr(1,25) }
	}

	return z;
}

// Conversion of roman zip code to bar code
string romanToPOSTNET(const int r){

}

// Conversion of bar code to roman zip code
int postnetToRoman(const string p){
	
}

void printRomanZip(const Zipcode zip){
	cout << to_string(zip.romanZipcode);	
}

void printPOSTNET(const Zipcode zip){
	cout << zip.postnetCode;
}

// Filename will be the roman zip, contents are graphical bar code
void writeToFile(const Zipcode zip){
	ofstream zipcodeFile;
	string filename = to_string(zip.romanZipcode) + ".txt";
	zipcodeFile.open(filename);
	zipcodeFile << createGraphicalBarcode(zip);
	zipcodeFile.close();

	return 0;
}

string createGraphicalBarcode(Zipcode zip){
	string graphicalBarcode = '| ';
	for(i=0; i < zip.postnetCode.length(); i++){
		if (zip.postnetCode[i] == 1){
			graphicalBarcode = graphicalBarcode + '| ';
		}else{
			graphicalBarcode = graphicalBarcode + '  ';
		}

	}
	graphicalBarcode = graphicalBarcode + '|\n| | | | | | | | | | | | | | | | | | | | | | | | | | |';

	return graphicalBarcode;
}

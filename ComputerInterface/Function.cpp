#include "Function.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Event::DataIn() {
	ifstream indata;
	uint8_t buffer;
	std::vector<uint8_t> DATAVECTOR;
	indata.open("test_file.txt");
	if (!indata) {
		cout << "Could not open file." << endl;
	}
	if (indata.is_open()) {
		string temp;
		while (getline(indata, temp)) {
			
		}
	}
}

void Event::SaveToCSV() {

}
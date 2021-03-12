#include "Function.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

void Event::DataIn(wxListBox* listbox) {
	ifstream indata;
	uint8_t buffer;
	std::vector<uint8_t> DATAVECTOR;
	std::vector<string> LISTBOXIN;
	indata.open("test_file.txt");
	if (!indata) {
		cout << "Could not open file." << endl;
	}
	if (indata.is_open()) {
		string temp;
		while (getline(indata, temp)) {
			wxString add(temp);
			listbox->Append(add);
		}
		indata.close();
	}

}

void Event::SaveToCSV(vector<string> data) {
	ofstream outdata;
	string filename;
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H.%M.%S", timeinfo);
	string str(buffer);
	filename = "Solar Data " + str + ".csv";
	outdata.open("C:\\Users\\kitsu\\Desktop\\" + filename);
	for (int i = 0; i < data.size(); i++) {
		cout << data[i] << endl;
	}
	outdata.close();


}
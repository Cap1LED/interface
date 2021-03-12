#include "Function.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>





void Event::DataIn(wxListBox* listbox) {
	std::ifstream indata;
	////uint8_t buffer;
	//std::vector<uint8_t> DATAVECTOR;
	//std::vector<string> LISTBOXIN;
	//indata.open("test_file.txt");
	//if (!indata) {
	//	cout << "Could not open file." << endl;
	//}
	//if (indata.is_open()) {
	//	string temp;
	//	while (getline(indata, temp)) {
	//		wxString add(temp);
	//		listbox->Append(add);
	//	}
	//	indata.close();
	//}

}

void Event::SaveToCSV(std::vector<std::string> data) {
	std::ofstream outdata;
	std::string filename;
	//time_t t = time(0);   // get time now
	//struct tm* now = localtime(&t);

	//char buffer[80];
	//strftime(buffer, 80, "%Y-%m-%d.", now);
	//filename = "Solar Data " + (string)buffer + ".csv";
	//outdata.open("C:\\Users\\kitsu\\Desktop\\");// + filename);
	//for (int i = 0; i < (int)data.size(); i++) {
	//	cout << data[i] << endl;
	//}
	//outdata.close();


}
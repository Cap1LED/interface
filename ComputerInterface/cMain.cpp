#include "cMain.h"
#include <vector>
#include <string>
#include <fstream>
#include <string>
#include <ctime>
#include <iostream>
#include <wiringPiI2C.h>
#include <iostream>
#include <cmath>
using namespace std;

#define DEVICE_ID 0x08

int i = 0;
string received3000k;
const int fd = wiringPiI2CSetup(DEVICE_ID);
    
wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_SLIDER(1, cMain::OnBright1Update)
EVT_SLIDER(5, cMain::OnBright2Update)
EVT_SLIDER(7, cMain::OnBright3Update)
EVT_SLIDER(9, cMain::OnBright4Update)
EVT_SLIDER(11, cMain::OnBright5Update)
EVT_BUTTON(103, cMain::OnSaveClick)
EVT_BUTTON(102, cMain::OnRecordClick)
EVT_TIMER(10, cMain::OnTimer)
EVT_BUTTON(104, cMain::OnUpdateClick)
wxEND_EVENT_TABLE()



cMain::cMain() :wxFrame(nullptr, wxID_ANY, "SolarLED", wxPoint(30, 30), wxSize(700, 500)) {


	m_color1 = new wxSlider(this, 1, 0, 0, 100, wxPoint(410, 100), wxSize(260, 30), wxSL_HORIZONTAL);
	m_bright1 = new wxTextCtrl(this, 4, "Brightness", wxPoint(400, 130), wxSize(65, 30));
	m_temp1 = new wxTextCtrl(this, 13, "Temp", wxPoint(470, 130), wxSize(65, 30));
	m_current1 = new wxTextCtrl(this, 14, "Current", wxPoint(540, 130), wxSize(65, 30));
	m_power1 = new wxTextCtrl(this, 15, "Power", wxPoint(610, 130), wxSize(65, 30));
    m_label1 = new wxStaticText(this, 31, "3000K", wxPoint(340, 105));
    
	m_color2 = new wxSlider(this, 5, 0, 0, 100, wxPoint(410, 170), wxSize(260, 30), wxSL_HORIZONTAL);
	m_bright2 = new wxTextCtrl(this, 4, "Brightness", wxPoint(400, 200), wxSize(65, 30));
	m_temp2 = new wxTextCtrl(this, 16, "Temp", wxPoint(470, 200), wxSize(65, 30));
	m_current2 = new wxTextCtrl(this, 17, "Current", wxPoint(540, 200), wxSize(65, 30));
	m_power2 = new wxTextCtrl(this, 18, "Power", wxPoint(610, 200), wxSize(65, 30));
    m_label2 = new wxStaticText(this, 32, "4000K", wxPoint(340, 175));
    
	m_color3 = new wxSlider(this, 7, 0, 0, 100, wxPoint(410, 240), wxSize(260, 30), wxSL_HORIZONTAL);
	m_bright3 = new wxTextCtrl(this, 8, "Brightness", wxPoint(400, 270), wxSize(65, 30));
	m_temp3 = new wxTextCtrl(this, 19, "Temp", wxPoint(470, 270), wxSize(65, 30));
	m_current3 = new wxTextCtrl(this, 20, "Current", wxPoint(540, 270), wxSize(65, 30));
	m_power3 = new wxTextCtrl(this, 21, "Power", wxPoint(610, 270), wxSize(65, 30));
    m_label3 = new wxStaticText(this, 33, "Cyan", wxPoint(340, 245));

	m_color4 = new wxSlider(this, 9, 0, 0, 100, wxPoint(410, 310), wxSize(260, 30), wxSL_HORIZONTAL);
	m_bright4 = new wxTextCtrl(this, 10, "Brightness", wxPoint(400, 340), wxSize(65, 30));
	m_temp4 = new wxTextCtrl(this, 22, "Temp", wxPoint(470, 340), wxSize(65, 30));
	m_current4 = new wxTextCtrl(this, 23, "Current", wxPoint(540, 340), wxSize(65, 30));
	m_power4 = new wxTextCtrl(this, 24, "Power", wxPoint(610, 340), wxSize(65, 30));
    m_label4 = new wxStaticText(this, 34, "Far Red", wxPoint(340, 315));

	m_color5 = new wxSlider(this, 11, 0, 0, 100, wxPoint(410, 380), wxSize(260, 30), wxSL_HORIZONTAL);
	m_bright5 = new wxTextCtrl(this, 12, "Brightness", wxPoint(400, 410), wxSize(65, 30));
	m_temp5 = new wxTextCtrl(this, 25, "Temp", wxPoint(470, 410), wxSize(65, 30));
	m_current5 = new wxTextCtrl(this, 26, "Current", wxPoint(540, 410), wxSize(65, 30));
	m_power5 = new wxTextCtrl(this, 27, "Power", wxPoint(610, 410), wxSize(65, 30));
    m_label5 = new wxStaticText(this, 35, "Deep Red", wxPoint(330, 385));
    
	m_data = new wxListBox(this, 100, wxPoint(10, 110), wxSize(250, 300));
	m_export = new wxButton(this, 103, "Save", wxPoint(10, 20), wxSize(60, 30));
	m_stop = new wxButton(this, 101, "Stop", wxPoint(80, 20), wxSize(60, 30));
	m_record = new wxButton(this, 102, "Record", wxPoint(150, 20), wxSize(60, 30));
	m_update = new wxButton(this, 104, "Update", wxPoint(220, 20), wxSize(60,30));
	m_timer = new wxTimer(this,10);
	
	
	if(fd == -1){
        cout << "Fail to make connection" << endl;
    }
	m_timer->Start(500); // 1 second interval
	m_bright1->SetValue(wxString::Format(wxT("%d"), 0));
	m_bright2->SetValue(wxString::Format(wxT("%d"), 0));
	m_bright3->SetValue(wxString::Format(wxT("%d"), 0));
	m_bright4->SetValue(wxString::Format(wxT("%d"), 0));
	m_bright5->SetValue(wxString::Format(wxT("%d"), 0));
	
}

cMain::~cMain() {

}

void cMain::OnTimer(wxTimerEvent& evt){
    int input = wiringPiI2CRead(fd);
    double part1 = (51.0*65536.0/input-51.0)/100.0;
    int value = -45*log10(part1)+25;

    if(input != -1){
       m_temp1->SetValue(wxString::Format(wxT("%d"), value));
       m_temp2->SetValue(wxString::Format(wxT("%d"), value));
       m_temp3->SetValue(wxString::Format(wxT("%d"), value));
       m_temp4->SetValue(wxString::Format(wxT("%d"), value));
       m_temp5->SetValue(wxString::Format(wxT("%d"), value));
       
    }
    
}


void cMain::OnBright1Update(wxCommandEvent& evt) {
	m_bright1->SetValue(wxString::Format(wxT("%d"), (int)m_color1->GetValue()));
}

void cMain::OnBright2Update(wxCommandEvent& evt) {
	m_bright2->SetValue(wxString::Format(wxT("%d"), (int)m_color2->GetValue()));
}

void cMain::OnBright3Update(wxCommandEvent& evt) {
	m_bright3->SetValue(wxString::Format(wxT("%d"), (int)m_color3->GetValue()));
}

void cMain::OnBright4Update(wxCommandEvent& evt) {
	m_bright4->SetValue(wxString::Format(wxT("%d"), (int)m_color4->GetValue()));
}

void cMain::OnBright5Update(wxCommandEvent& evt) {
	m_bright5->SetValue(wxString::Format(wxT("%d"), (int)m_color5->GetValue()));
}

void cMain::OnSaveClick(wxCommandEvent& evt) {

	std::vector<std::string> data;
	double listsize = (double)m_data->GetCount();
	for (int i = 0; i < listsize; i++) {
		data.push_back((std::string)m_data->GetString(i));
	}
	SaveToCSV(data);

	//Close(TRUE);
	

}

void cMain::OnRecordClick(wxCommandEvent& evt) {
	
	DataIn(m_data);
	
}

void cMain::OnUpdateClick(wxCommandEvent& evt){
    wiringPiI2CWrite(fd, 101); // Sending contol byte
    wiringPiI2CWrite(fd, stoi(std::string(m_bright1->GetValue().mb_str()))); // Sends brightness level of (color)
    wiringPiI2CWrite(fd, stoi(std::string(m_bright2->GetValue().mb_str()))); // Sends brightness level of (color)
    wiringPiI2CWrite(fd, stoi(std::string(m_bright3->GetValue().mb_str()))); // Sends brightness level of (color)
    wiringPiI2CWrite(fd, stoi(std::string(m_bright4->GetValue().mb_str()))); // Sends brightness level of (color)
    wiringPiI2CWrite(fd, stoi(std::string(m_bright5->GetValue().mb_str()))); // Sends brightness level of (color)
    
    
}
void cMain::DataIn(wxListBox* listbox) {
	//ifstream indata;
	//uint8_t buffer;
	//std::vector<uint8_t> DATAVECTOR;
	//std::vector<string> LISTBOXIN;
	//indata.open("test_file.txt");
	//if (!indata) {
	//	cout << "Could not open file." << endl;
	//}
	//if (indata.is_open()) {
		//string temp;
		//while (getline(indata, temp)) {
			//wxString add(temp);
			//listbox->Append(add);
		//}
		//indata.close();
	//}
	wxString add(m_temp1->GetValue());
	listbox->Append(add);

}

void cMain::SaveToCSV(vector<string> data) {
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
	outdata.open("/home/odroid/Desktop/SolarLEDData" + filename); //RunkeBenjamin
	for (int i = 0; i < (int)data.size(); i++) {
		outdata << data[i] << endl;
	}
	outdata.close();


}









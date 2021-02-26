#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_SLIDER(1, cMain::OnBright1Update)
EVT_SLIDER(5, cMain::OnBright2Update)
EVT_SLIDER(7, cMain::OnBright3Update)
EVT_SLIDER(9, cMain::OnBright4Update)
EVT_SLIDER(11, cMain::OnBright5Update)

// This is a test

wxEND_EVENT_TABLE()



cMain::cMain() :wxFrame(nullptr, wxID_ANY, "SolarLED", wxPoint(30, 30), wxSize(500, 500)) {

	m_color1 = new wxSlider(this, 1, 0, 0, 100, wxPoint(210, 100), wxSize(260, 30), wxSL_HORIZONTAL);
	m_bright1 = new wxTextCtrl(this, 4, "Brightness", wxPoint(200, 130), wxSize(65, 30));
	m_temp1 = new wxTextCtrl(this, 13, "Temp", wxPoint(270, 130), wxSize(65, 30));
	m_current1 = new wxTextCtrl(this, 14, "Current", wxPoint(340, 130), wxSize(65, 30));
	m_power1 = new wxTextCtrl(this, 15, "Power", wxPoint(410, 130), wxSize(65, 30));

	m_color2 = new wxSlider(this, 5, 0, 0, 100, wxPoint(210, 170), wxSize(260, 30), wxSL_HORIZONTAL);
	m_bright2 = new wxTextCtrl(this, 4, "Brightness", wxPoint(200, 200), wxSize(65, 30));
	m_temp2 = new wxTextCtrl(this, 16, "Temp", wxPoint(270, 200), wxSize(65, 30));
	m_current2 = new wxTextCtrl(this, 17, "Current", wxPoint(340, 200), wxSize(65, 30));
	m_power2 = new wxTextCtrl(this, 18, "Power", wxPoint(410, 200), wxSize(65, 30));

	m_color3 = new wxSlider(this, 7, 0, 0, 100, wxPoint(210, 240), wxSize(260, 30), wxSL_HORIZONTAL);
	m_bright3 = new wxTextCtrl(this, 8, "Brightness", wxPoint(200, 270), wxSize(65, 30));
	m_temp3 = new wxTextCtrl(this, 19, "Temp", wxPoint(270, 270), wxSize(65, 30));
	m_current3 = new wxTextCtrl(this, 20, "Current", wxPoint(340, 270), wxSize(65, 30));
	m_power3 = new wxTextCtrl(this, 21, "Power", wxPoint(410, 270), wxSize(65, 30));

	m_color4 = new wxSlider(this, 9, 0, 0, 100, wxPoint(210, 310), wxSize(260, 30), wxSL_HORIZONTAL);
	m_bright4 = new wxTextCtrl(this, 10, "Brightness", wxPoint(200, 340), wxSize(65, 30));
	m_temp4 = new wxTextCtrl(this, 22, "Temp", wxPoint(270, 340), wxSize(65, 30));
	m_current4 = new wxTextCtrl(this, 23, "Current", wxPoint(340, 340), wxSize(65, 30));
	m_power4 = new wxTextCtrl(this, 24, "Power", wxPoint(410, 340), wxSize(65, 30));

	m_color5 = new wxSlider(this, 11, 0, 0, 100, wxPoint(210, 380), wxSize(260, 30), wxSL_HORIZONTAL);
	m_bright5 = new wxTextCtrl(this, 12, "Brightness", wxPoint(200, 410), wxSize(65, 30));
	m_temp5 = new wxTextCtrl(this, 25, "Temp", wxPoint(270, 410), wxSize(65, 30));
	m_current5 = new wxTextCtrl(this, 26, "Current", wxPoint(340, 410), wxSize(65, 30));
	m_power5 = new wxTextCtrl(this, 27, "Power", wxPoint(410, 410), wxSize(65, 30));

	m_data = new wxListBox(this, 100, wxPoint(10, 110), wxSize(150, 300));
	m_export = new wxButton(this, 103, "Save", wxPoint(10, 20), wxSize(60, 30));
	m_stop = new wxButton(this, 101, "Stop", wxPoint(80, 20), wxSize(60, 30));
	m_record = new wxButton(this, 102, "Record", wxPoint(150, 20), wxSize(60, 30));

}

cMain::~cMain() {

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

//void cMain::OnTextEnter(wxEVT_COMMAND_TEXT_UPDATED &evt) {
//	m_slider->SetValue(wxAtoi(m_txt1->GetValue()));
//}
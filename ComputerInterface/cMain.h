#pragma once
#include "wx/wx.h"
class cMain : public wxFrame
{

public:
	cMain();
	~cMain();

public:
	wxSlider* m_color1 = nullptr;
	wxSlider* m_color2 = nullptr;
	wxSlider* m_color3 = nullptr;
	wxSlider* m_color4 = nullptr;
	wxSlider* m_color5 = nullptr;
	wxTextCtrl* m_temp1 = nullptr;
	wxTextCtrl* m_temp2 = nullptr;
	wxTextCtrl* m_temp3 = nullptr;
	wxTextCtrl* m_temp4 = nullptr;
	wxTextCtrl* m_temp5 = nullptr;
	wxTextCtrl* m_current1 = nullptr;
	wxTextCtrl* m_current2 = nullptr;
	wxTextCtrl* m_current3 = nullptr;
	wxTextCtrl* m_current4 = nullptr;
	wxTextCtrl* m_current5 = nullptr;
	wxTextCtrl* m_bright1 = nullptr;
	wxTextCtrl* m_bright2 = nullptr;
	wxTextCtrl* m_bright3 = nullptr;
	wxTextCtrl* m_bright4 = nullptr;
	wxTextCtrl* m_bright5 = nullptr;
	wxTextCtrl* m_power1 = nullptr;
	wxTextCtrl* m_power2 = nullptr;
	wxTextCtrl* m_power3 = nullptr;
	wxTextCtrl* m_power4 = nullptr;
	wxTextCtrl* m_power5 = nullptr;
	wxListBox* m_data = nullptr;
	wxButton* m_stop = nullptr;
	wxButton* m_record = nullptr;
	wxButton* m_export = nullptr;
	void OnBright1Update(wxCommandEvent& evt);
	void OnBright2Update(wxCommandEvent& evt);
	void OnBright3Update(wxCommandEvent& evt);
	void OnBright4Update(wxCommandEvent& evt);
	void OnBright5Update(wxCommandEvent& evt);
	void OnSaveClick(wxCommandEvent& evt);

	
	wxDECLARE_EVENT_TABLE();
};


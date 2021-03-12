#ifndef FUNCTION_H
#define FUNCTION_H

#include<string>
#include "wx/wx.h"
#include "cMain.h"

class Event {

public:
	void DataIn(wxListBox* listbox);
	void SaveToCSV(std::vector<std::string>);

};



#endif
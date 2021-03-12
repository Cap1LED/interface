#ifndef FUNCTION_H
#define FUNCTION_H

#include<string>
#include"wx/listbox.h"


class Event {

public:
	void DataIn(wxListBox* listbox);
	void SaveToCSV(std::vector<std::string>);

};



#endif
#pragma once

#include "wx/wx.h"
#include "wx/filedlg.h"
#include "wx/grid.h"
#include "wx/listctrl.h"

#include "wx/file.h"



class AddMovie: public wxFrame
{
private:
	char name[20];
	char userName[20];
	float price;
	char seatsNum[30];
	char filePath[100];
public:
	
	AddMovie(const wxString& title);
	void populateListView();

	//Frames
	wxPanel* topPanel = nullptr;
	wxPanel* rightPanel = nullptr;
	wxPanel* bottomPanel = nullptr;
	wxBoxSizer* windowSizer = nullptr;
	wxBoxSizer* sizer = nullptr;
	wxBoxSizer* sizer1 = nullptr;
	wxGrid* tableGrid = nullptr;
	wxTextCtrl* movieName;
	wxTextCtrl* moviePrice;
	wxListView* basicListView;
	
	//operation
	
	//Events
	void addFile(wxCommandEvent& evt);
	void addMovie(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
	~AddMovie();
};




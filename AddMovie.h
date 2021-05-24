#pragma once

#include "wx/wx.h"
#include "wx/filedlg.h"



class AddMovie: public wxFrame
{
public:
	AddMovie(const wxString& title);
	~AddMovie();


	void addFile(wxCommandEvent& evt);
	void addMovie(wxCommandEvent& evt);

	//Frames
	wxPanel* topPanel = nullptr;
	wxPanel* rightPanel = nullptr;
	wxPanel* bottomPanel = nullptr;
	wxBoxSizer* sizer = nullptr;
	wxBoxSizer* sizer1 = nullptr;

	wxDECLARE_EVENT_TABLE();
};


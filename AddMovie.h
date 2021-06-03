#pragma once

#include "wx/wx.h"
#include "wx/filedlg.h"
#include "wx/grid.h"
#include "wx/listctrl.h"



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
	wxBoxSizer* windowSizer = nullptr;
	wxBoxSizer* sizer = nullptr;
	wxBoxSizer* sizer1 = nullptr;
	wxGrid* tableGrid = nullptr;
	wxTextCtrl* movieName;
	wxTextCtrl* moviePrice;

	void populateListView();
	wxListView* basicListView;

	wxDECLARE_EVENT_TABLE();
};


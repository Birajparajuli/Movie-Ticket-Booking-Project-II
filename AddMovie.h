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
	wxDECLARE_EVENT_TABLE();
};


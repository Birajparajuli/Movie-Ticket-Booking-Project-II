#pragma once

#include "wx/wx.h"
#include "wx/filedlg.h"
#include "wx/grid.h"
#include "wx/listctrl.h"

#include "wx/file.h"
#include "wx/ffile.h"
#include <wx/datetime.h>
#include <wx/wxsqlite3.h>
#include <wx/textfile.h>
#include <iostream>
#include <fstream>



using namespace std;


class AddMovie: public wxFrame
{
private:
	
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
	wxString path;
	wxDateTime now = wxDateTime::Now();
	wxString date1 = now.Format();
	wxString getName, getUser, getSeat, getPath;
	
	//Files
	wxFFile* file = new wxFFile;
	
	//operation
	
	//Events
	void addFile(wxCommandEvent& evt);
	void addMovie(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
	~AddMovie();

	friend class NewMovie;
};



class NewMovie {
public:
	char name[20] ;
	char userName[20];
	float price;
	char seatsNum[30];
	char filePath[100];

public:
	/*NewMovie(const char n[20] = "Movie name", const char un[20] = "User Name", float p = 0, const char s[30] = "aa", const char f[100] = "c://") {
		wxStrcpy(name, n);
		wxStrcpy(userName, un);
		wxStrcpy(seatsNum, s);
		wxStrcpy(filePath, f);
		price = p;

	}
	*/
	friend class AddMovie;
};


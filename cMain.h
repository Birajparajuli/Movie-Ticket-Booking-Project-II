#pragma once
#include "wx/wx.h"
#include "wx/image.h"
#include "wx/grid.h"
#include "wx/bmpbuttn.h"
#include "wx/datetime.h"

#include "AdminLogin.h"


class cMain : public wxFrame
{

public:
	cMain();
	~cMain();



	wxToolBar* m_ToolBar = nullptr;
	wxMenuBar* m_MenuBar = nullptr;

	wxButton* m_Button = nullptr;
	wxImage* m_Image = nullptr;
	wxStaticText* m_Text = nullptr;

	wxStatusBar* stats = nullptr;
	wxDateTime now = wxDateTime::Now();
	wxString date1 = now.Format(wxT("%B %d %Y"));

	//wxGrid* grid = nullptr;

	wxGridSizer* gridSizer = nullptr;

	
	void OnMenuExit(wxCommandEvent& evt);
	void OnAdmin(wxCommandEvent& evt);

	void ClrScr(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};


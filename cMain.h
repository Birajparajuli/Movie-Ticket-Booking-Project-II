#pragma once
#include "wx/wx.h"
#include "wx/image.h"
#include "wx/grid.h"
#include "wx/bmpbuttn.h"


#include "AdminLogin.h"


class cMain : public wxFrame
{

public:
	cMain();
	~cMain();


private:
	wxToolBar* m_ToolBar = nullptr;
	wxMenuBar* m_MenuBar = nullptr;

	wxButton* m_Button = nullptr;
	wxImage* m_Image = nullptr;
	wxStaticText* m_Text = nullptr;

	wxStatusBar* stats = nullptr;

	//wxGrid* grid = nullptr;

	wxGridSizer* gridSizer = nullptr;

	
	void OnMenuExit(wxCommandEvent& evt);
	void OnAdmin(wxCommandEvent& evt);

	void ClrScr(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

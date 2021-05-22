#pragma once

#include "wx/wx.h"
#include "wx/image.h"
#include "wx/vscroll.h"
#include "wx/richtext/richtextbuffer.h"

class AdminLogin : public wxFrame
{
public:
	AdminLogin(const wxString& title);
	~AdminLogin();

private:
	//UI Elements
	wxButton* m_Button = nullptr;
	wxTextCtrl* m_InputID = nullptr;
	wxTextCtrl* m_InputPS = nullptr;
	wxStaticText* m_Text = nullptr;

	//char Uname[10] = "admin";                               /*Username: admin, Password: password*/
	//char Pword[10] = "password";
	//char getPW[10], getID[10];
	
	wxString Uname = "admin";
	wxString Pword = "password";
	wxString getID, getPW;

	//Events
	void Login(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
	
};


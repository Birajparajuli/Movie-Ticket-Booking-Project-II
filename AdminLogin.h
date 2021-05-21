#pragma once

#include "wx/wx.h"
#include "wx/image.h"
#include "wx/vscroll.h"
#include "wx/richtext/richtextbuffer.h"

class AdminLogin : public wxFrame
{
public:
	AdminLogin(const wxString& title);
	wxButton* m_Button = nullptr;
	wxTextCtrl* m_Input = nullptr;
	
	wxStaticText* m_Text = nullptr;

	

	~AdminLogin();
};


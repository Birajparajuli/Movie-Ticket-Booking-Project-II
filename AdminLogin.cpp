//Admin Login Window 

#include "AdminLogin.h"



AdminLogin::AdminLogin(const wxString& title): wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(600, 400))
{


	m_Text = new wxStaticText(this, wxID_ANY, "ADMIN LOGIN", wxPoint(140, 30), wxSize(300, 40));
	m_Text = new wxStaticText(this, wxID_ANY, "Username", wxPoint(140, 60), wxSize(300, 20));
	m_Input = new wxTextCtrl(this, 101, "", wxPoint(140, 80), wxSize(300, 30));
	m_Text = new wxStaticText(this, wxID_ANY, "Password", wxPoint(140, 110), wxSize(300, 20));
	m_Input = new wxTextCtrl(this, 102, "", wxPoint(140, 130), wxSize(300, 30));
	m_Button = new wxButton(this, wxID_ANY, "Login", wxPoint(140, 180), wxSize(300, 30));
	m_Button->SetBackgroundColour(wxColour(0, 128, 128));
	CenterOnScreen();
}	

AdminLogin::~AdminLogin() {

} 
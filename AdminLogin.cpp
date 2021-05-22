//Admin Login Window 

#include "AdminLogin.h"
#include "AddMovie.h"
#include "cMain.h"

//Event Handlers
wxBEGIN_EVENT_TABLE(AdminLogin, wxFrame)
EVT_BUTTON(1010, AdminLogin::Login)
wxEND_EVENT_TABLE()



AdminLogin::AdminLogin(const wxString& title): wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(600, 400))
{


	m_Text = new wxStaticText(this, wxID_ANY, "ADMIN LOGIN", wxPoint(140, 30), wxSize(300, 40));
	m_Text = new wxStaticText(this, wxID_ANY, "Username", wxPoint(140, 60), wxSize(300, 20));
	m_InputID = new wxTextCtrl(this, 101, "", wxPoint(140, 80), wxSize(300, 30));
	m_Text = new wxStaticText(this, wxID_ANY, "Password", wxPoint(140, 110), wxSize(300, 20));
	m_InputPS = new wxTextCtrl(this, 102, "", wxPoint(140, 130), wxSize(300, 30));
	m_Button = new wxButton(this, 1010, "Login", wxPoint(140, 180), wxSize(300, 30));
	m_Button->SetBackgroundColour(wxColour(0, 128, 128));
	CenterOnScreen();
}	

AdminLogin::~AdminLogin() {

}
void AdminLogin::Login(wxCommandEvent& evt)
{
	getPW = m_InputPS->GetValue();
	getID = m_InputID->GetValue();

	if (((wxStrcmp(Pword,getPW)==0)&& ((wxStrcmp(Uname, getID))==0))) {

		AddMovie* a = new AddMovie("Admin:Add New Movie To List");
		a->Show();
		Close();
		evt.Skip();
	}
	else if ((getID=="")&&(getPW=="")) {
		wxMessageDialog dialog(NULL, wxT("Username/Password cannot be empty."), wxT("Login Error !"), wxOK_DEFAULT | wxICON_INFORMATION);

		switch (dialog.ShowModal())
		{
		case wxID_OK:
			wxLogStatus(wxT("You pressed ok "));
			break;
		}
	}else {
		wxMessageDialog dialog(NULL, wxT("Username or Password didn't match."),wxT("Login Error !"), wxOK_DEFAULT | wxICON_INFORMATION);

		switch (dialog.ShowModal())
		{
		case wxID_OK:
			wxLogStatus(wxT("You pressed ok "));
			break;
		}
	}

	
}



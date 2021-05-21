// CApp Class Is used to run the application

#include "cApp.h"

wxIMPLEMENT_APP(cApp);


cApp::cApp() {

}

cApp::~cApp() {

}

bool cApp::OnInit()
{
	m_frame1 = new cMain();
	m_frame1->Show();
	
	return true;
}
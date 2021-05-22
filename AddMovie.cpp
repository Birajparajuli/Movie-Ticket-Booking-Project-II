#include "AddMovie.h"

AddMovie::AddMovie(const wxString& title):wxFrame(NULL, -1,title,wxPoint(-1,-1),wxSize(800,800)) {
	wxStaticText *m_Text = new wxStaticText(this, wxID_ANY, "ADMIN LOGIN", wxPoint(140, 30), wxSize(300, 40));

}

AddMovie::~AddMovie() {

}

#include "AddMovie.h"

AddMovie::AddMovie(const wxString& title):wxFrame(NULL, -1,title,wxPoint(-1,-1),wxSize(800,800)) {
	wxStaticText *m_Text = new wxStaticText(this, wxID_ANY, "ADMIN LOGIN", wxPoint(140, 30), wxSize(300, 40));


	wxString caption = wxT("Choose a file");
	wxString wildcard =
		wxT("PNG files(*.png) | *.png | JPG files(*.jpg) | *.jpg");
		wxString defaultDir = wxT("c : \\temp");
		wxString defaultFilename = wxEmptyString;
		wxFileDialog dialog(this, caption, defaultDir, defaultFilename,
			wildcard);
		if (dialog.ShowModal() == wxID_OK)
		{
			wxString path = dialog.GetPath();
			int filterIndex = dialog.GetFilterIndex();
		}

}

AddMovie::~AddMovie() {

}

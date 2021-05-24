#include "AddMovie.h"

//Event Handlers
wxBEGIN_EVENT_TABLE(AddMovie, wxFrame)
EVT_BUTTON(2020, AddMovie::addFile)
EVT_BUTTON(2021, AddMovie::addMovie)
wxEND_EVENT_TABLE()

AddMovie::AddMovie(const wxString& title):wxFrame(NULL, -1,title,wxPoint(-1,-1),wxSize(800,800)) {
	//wxStaticText *m_Text = new wxStaticText(this, wxID_ANY, "ADMIN LOGIN", wxPoint(140, 30), wxSize(300, 40));




	//Movie Info Input

	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	//Movie Name Field

	wxBoxSizer* nameSizer = new wxBoxSizer(wxHORIZONTAL);

	//Movie name label
	wxStaticText* nameLabel = new wxStaticText(this, wxID_ANY,"Movie Name");
	nameSizer->Add(nameLabel);

	//space between label and box
	nameSizer->Add(20, 0);

	//Movie name box
	wxTextCtrl* movieName = new wxTextCtrl(this, wxID_ANY);
	nameSizer->Add(movieName,1);
	
	mainSizer->Add(nameSizer, 0,wxEXPAND|wxALL,5);



	//Movie price Field
	wxBoxSizer* priceSizer = new wxBoxSizer(wxHORIZONTAL);

	//Movie pice label
	wxStaticText* priceLabel = new wxStaticText(this, wxID_ANY, "Movie Price");
	priceSizer->Add(priceLabel);

	//space between label and box
	priceSizer->Add(20, 0);

	//Movie price box
	wxTextCtrl* moviePrice = new wxTextCtrl(this, wxID_ANY);
	priceSizer->Add(moviePrice, 1);

	mainSizer->Add(priceSizer, 0, wxEXPAND | wxALL, 5);

	SetSizer(mainSizer);

	//Add image button
	wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);
	//Movie price box
	wxButton* fileBtn = new wxButton(this, 2020, "Add Poster Image");
	buttonSizer->Add(fileBtn);

	mainSizer->Add(buttonSizer, 0, wxEXPAND | wxALL, 5);


	//Add movie button
	wxBoxSizer* AddButtonSizer = new wxBoxSizer(wxHORIZONTAL);
	//Movie price box
	wxButton* addBtn = new wxButton(this, 2021, "Add Movie");
	AddButtonSizer->Add(addBtn);

	mainSizer->Add(AddButtonSizer, 0, wxEXPAND | wxALL, 5);
	SetSizer(mainSizer);

	//mainSizer->Fit(this);


}

AddMovie::~AddMovie() {

}

void AddMovie::addFile(wxCommandEvent& evt)
{

	//File Choose module | Image Poster Choose | copy file and paste that to the assets/poster folder(not working)

	wxString caption = wxT("Choose a movie poster");
	wxString wildcard = wxT("PNG files(*.png) | *.png | JPG files(*.jpg) | *.jpg");
	wxString defaultDir = wxT("c : \\temp");
	wxString defaultFilename = wxEmptyString;
	wxFileDialog dialog(this, caption, defaultDir, defaultFilename, wildcard);
	if (dialog.ShowModal() == wxID_OK)
	{
		wxString path = dialog.GetPath();
		wxString pastePath = "Assets\poster";
		int filterIndex = dialog.GetFilterIndex(); //returns bool value i think
		wxLogStatus(path);

		wxCopyFile(path, pastePath,true);

		
	}


}

void AddMovie::addMovie(wxCommandEvent& evt)
{
	wxLogStatus(wxT("You pressed Add Button"));

}

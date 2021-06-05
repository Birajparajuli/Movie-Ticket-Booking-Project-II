#include "AddMovie.h"

//Event Handlers
wxBEGIN_EVENT_TABLE(AddMovie, wxFrame)
EVT_BUTTON(2020, AddMovie::addFile)
EVT_BUTTON(2021, AddMovie::addMovie)
wxEND_EVENT_TABLE()



AddMovie::AddMovie(const wxString& title):wxFrame(NULL, -1,title,wxPoint(-1,-1),wxSize(800,800)) {
	//wxStaticText *m_Text = new wxStaticText(this, wxID_ANY, "ADMIN LOGIN", wxPoint(140, 30), wxSize(300, 40));

	/*-----------------------------------------------------------------
								ADMIN PANEL LAYOUT
	--------------------------------------------------------------------*/
	topPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200,100));
	topPanel->SetBackgroundColour(wxColour(100, 100, 200));

	bottomPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
	bottomPanel->SetBackgroundColour(wxColour(100,200,100));

	rightPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
	rightPanel->SetBackgroundColour(wxColour(0, 200, 100));

	
	windowSizer = new wxBoxSizer(wxHORIZONTAL);

	sizer1 = new wxBoxSizer(wxVERTICAL);
	sizer1->Add(rightPanel, 1, wxEXPAND | wxRIGHT | wxBOTTOM | wxRIGHT,5);

	sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(topPanel, 1, wxEXPAND | wxALL, 5);
	sizer->Add(bottomPanel, 1, wxEXPAND | wxRIGHT | wxBOTTOM | wxLEFT, 5);

	windowSizer->Add(sizer, 1, wxEXPAND | wxALL);
	windowSizer->Add(sizer1, 2, wxEXPAND | wxALL);

	this->SetSizer(windowSizer);

	
	/*-------------------------------------------------------
						ADD NEW MOVIE PANEL
	---------------------------------------------------------*/
	
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	//Movie Name Field
	wxBoxSizer* nameSizer = new wxBoxSizer(wxVERTICAL);

	//Title 
	wxStaticText* addMovieTitle = new wxStaticText(topPanel, wxID_ANY,"Add New Movie");
	addMovieTitle->SetBackgroundColour(wxColour(400, 10, 10));
	nameSizer->Add(addMovieTitle);

	//Movie name label
	wxStaticText* nameLabel = new wxStaticText(topPanel, wxID_ANY,"Movie Name");
	nameSizer->Add(nameLabel);

	//space between label and box
	nameSizer->Add(0, 10);

	//Movie name box
	movieName = new wxTextCtrl(topPanel, wxID_ANY);
	nameSizer->Add(movieName,1,wxEXPAND|wxRIGHT);
	mainSizer->Add(nameSizer, 0,wxEXPAND|wxALL,5);

	//Movie price Field
	wxBoxSizer* priceSizer = new wxBoxSizer(wxVERTICAL);

	//Movie pice label
	wxStaticText* priceLabel = new wxStaticText(topPanel, wxID_ANY, "Movie Price");
	priceSizer->Add(priceLabel);

	//space between label and box
	priceSizer->Add(0, 10);

	//Movie price box
	moviePrice = new wxTextCtrl(topPanel, wxID_ANY);
	priceSizer->Add(moviePrice, 1, wxEXPAND | wxRIGHT);
	mainSizer->Add(priceSizer, 0, wxEXPAND | wxALL, 5);


	//Add movie poster
	wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

	//Movie poster button
	wxButton* fileBtn = new wxButton(topPanel, 2020, "Add Poster Image");
	buttonSizer->Add(fileBtn);
	mainSizer->Add(buttonSizer, 0, wxEXPAND | wxALL, 5);

	//Add movie button
	wxBoxSizer* AddButtonSizer = new wxBoxSizer(wxHORIZONTAL);
	wxButton* addBtn = new wxButton(topPanel, 2021, "Add Movie");
	AddButtonSizer->Add(addBtn);
	mainSizer->Add(AddButtonSizer, 0, wxEXPAND | wxALL, 5);

	//setting sizers
	topPanel->SetSizer(mainSizer);

	/*---------------------------------------------------------------
				           DELETE MOVIES PANEL
	-----------------------------------------------------------------*/

	


	/*-----------------------------------------------------------------
				         BOOKED SEAT LISTS
	-------------------------------------------------------------------*/
	basicListView = new wxListView(rightPanel);
	basicListView->AppendColumn("SN");
	basicListView->AppendColumn("Movie Name");
	basicListView->AppendColumn("Booked Seats");
	basicListView->AppendColumn("Name");
	basicListView->AppendColumn("Amount");
	basicListView->SetColumnWidth(0, 80);
	basicListView->SetColumnWidth(1, 140);
	basicListView->SetColumnWidth(2, 140);
	basicListView->SetColumnWidth(3, 120);
	basicListView->SetColumnWidth(4, 100);

	
	auto sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(basicListView, 1, wxALL|wxEXPAND, 0);
	rightPanel->SetSizerAndFit(sizer);

	populateListView();
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
	if (movieName->GetValue() == "" && moviePrice->GetValue() == "") {
		wxMessageDialog dialog(NULL, wxT("Movie Name/ Movie Price cannot be empty."), wxT("ERROR !"), wxOK_DEFAULT | wxICON_INFORMATION);

		switch (dialog.ShowModal())
		{
		case wxID_OK:
			wxLogStatus(wxT("You pressed ok "));
			break;
		}

	}
	else {
		wxFile file;
		file.Create("Datafile", true);
		if (file.IsOpened()) {
			wxPuts("File Is opened");
			
		}
	}

}

void AddMovie::populateListView()
{
	basicListView->InsertItem(0, "1");
	basicListView->SetItem(0,1, "TENET");
	basicListView->SetItem(0,2, "A1,A2,A3");
	basicListView->SetItem(0,3, "Biraj");
	basicListView->SetItem(0,4, "1500");

	basicListView->InsertItem(1, "2");
	basicListView->SetItem(1, 1, "ENDGAME");
	basicListView->SetItem(1, 2, "A1,A2,A3");
	basicListView->SetItem(1, 3, "Biraj");
	basicListView->SetItem(1, 4, "1500");
}

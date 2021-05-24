#include "Seats.h"

wxBEGIN_EVENT_TABLE(Seats, wxFrame)
//EVT_BUTTON(101, Seats::onClickBook)
//EVT_BUTTON(101, Seats::onButtonClicked)
wxEND_EVENT_TABLE()


Seats::Seats(const wxString& title): wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(800, 800))
{
	topPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
	panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
	//panel->SetBackgroundColour(wxColour(100, 100, 200));

	bottomPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
	bottomPanel->SetBackgroundColour(wxColour(100,200,100));
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

	sizer->Add(topPanel, 1, wxEXPAND | wxALL, 20);
	sizer->Add(panel, 3, wxEXPAND|wxLEFT|wxRIGHT,5);
	sizer->Add(bottomPanel, 1, wxEXPAND|wxALL,5);

	this->SetSizer(sizer);

	//Toolbar for forward home and back buttons
	::wxInitAllImageHandlers();
	wxBitmap bmpBack("Assets/back.png", wxBITMAP_TYPE_PNG);
	wxBitmap bmpForward("Assets/forward.png", wxBITMAP_TYPE_PNG);
	wxBitmap bmpHome("Assets/home.png", wxBITMAP_TYPE_PNG);
	wxToolBar* toolBar = CreateToolBar();

	//add toolbar items
	toolBar->AddTool(wxID_ANY, "BAACK", bmpBack);
	toolBar->AddTool(wxID_ANY, "HOME", bmpHome);
	toolBar->AddTool(wxID_ANY, "FORWARD", bmpForward);

	//Show Toolbar
	toolBar->Realize();
	//Grid
	/*
	gridSizer = new wxGridSizer(6, 6, 10, 10);
	SetSizer(gridSizer);
	

	wxColour not_booked = wxColour(0, 128, 0);
	
	
	for (int i = 0; i < 36; i++) {
		m_Seats = new wxButton(this, 101, "", wxDefaultPosition, wxSize(50, 60), 0);
		gridSizer->Add(m_Seats, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxALL, i);
		m_Seats->SetBackgroundColour(not_booked);
	}
	*/

	//Box Sizer
	/*
	wxBoxSizer* secondSizer =new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxTextCtrl* FirstName = new wxTextCtrl(this, wxID_ANY);
	secondSizer->Add(FirstName, 1, wxEXPAND | wxALL, 10);
	SetSizer(secondSizer);
	mainSizer->Add(secondSizer);
	*/

	btn = new wxButton * [FieldHeight * FieldWidth];
	gridSizer = new wxGridSizer(FieldWidth, FieldHeight, 20, 20);
	
	

	for (int x = 0; x < FieldWidth; x++) {
		for (int y = 0; y < FieldHeight; y++) {
			btn[y * FieldWidth + x ] = new wxButton(panel, 10000+(y*FieldWidth+x));
			gridSizer->Add(btn[y * FieldWidth + x], 1, wxEXPAND | wxALL);
			btn[y * FieldWidth + x]->SetBackgroundColour(not_booked);

			btn[y * FieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Seats::OnButtonClicked, this);

		}
	}

	//Add grid sizer to this window
	panel->SetSizer(gridSizer);
	//mainSizer->Add(gridSizer);

	//wxImage::AddHandler(new wxJPEGHandler);
	//wxBitmap background(wxT("Assets/2.jpg"), wxBITMAP_TYPE_JPEG);
	//wxStaticBitmap* sd = new wxStaticBitmap(this, -10, background);

	//wxBitmap TempBitmap;
	//TempBitmap.LoadFile("bike.jpg", wxBITMAP_TYPE_JPEG);
	//Seats* NotebookBackground = new Seats(background);
	//this->PushEventHandler(NotebookBackground);
	
	//Bottom Status Bar
	stats = CreateStatusBar(2);
	stats->SetStatusText(_("Hamro Movie Theater"));
	stats->SetStatusText(_("Total avilable Seats: 56 Booked Seats: 0"),1);
	
}


Seats::~Seats() {
	delete[]btn; 
}

/*
void Seats::onClickBook(wxCommandEvent& evt) {
wxColour booked = wxColour(0, 128, 128);

//m_Seats->SetForegroundColour(booked);


}
*/

void Seats::OnButtonClicked(wxCommandEvent& evt) {
	wxColour booked = wxColour(0, 128, 128);
	int x = (evt.GetId() - 10000) % FieldWidth;
	int y = (evt.GetId() - 10000) / FieldHeight;
	btn[y * FieldWidth + x]->SetBackgroundColour(booked);

	btn[y * FieldWidth + x]->Enable(false);
	
	s++;
	//wxString con = wxString("Total seats selected")::Format(wxT("%d"), s);
	//m_Text = new wxStaticText(this, wxID_ANY, "Seat Selected", wxPoint(40, 40));
	
	m_Text = new wxStaticText(bottomPanel, wxID_ANY, "Seat Selected", wxPoint(40,40));
	m_Text = new wxStaticText(bottomPanel, wxID_ANY, wxT(" "), wxPoint(40,60));
	m_Price = new wxStaticText(bottomPanel, wxID_ANY, "Price Rs.", wxPoint(40, 80));
	m_Price = new wxStaticText(bottomPanel, wxID_ANY, wxT("0"), wxPoint(40, 100));
	m_Text->SetLabel(wxString::Format(wxT(" %d"), s));
	m_Price->SetLabel(wxString::Format(wxT(" Rs. %d"), s*500));
	

	

}
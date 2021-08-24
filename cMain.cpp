//This is the frame of the Application
#include "cMain.h"
#include "AdminLogin.h"
#include "Seats.h"
#include "AddMovie.h"
#include "BuildBy.h"

//Event Handlers Here

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_MENU(10002, cMain::OnMenuExit)
EVT_MENU(10001, cMain::OnAdmin)
EVT_MENU(10003, cMain::DevelopBy)
wxEND_EVENT_TABLE()



//Main Window
cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Movie Ticket Booking ", wxPoint(30, 30), wxSize(1000, 800))
{
	NewMovie m;

	
	//Icon
	wxIcon icon4;
	::wxInitAllImageHandlers();
	wxBitmap bitmap(wxT("Assets/logo/icon.png"), wxBITMAP_TYPE_PNG);
	icon4.CopyFromBitmap(bitmap);

	this->SetIcon(icon4);

	//Menu Bar
	m_MenuBar = new wxMenuBar();
	m_MenuBar->SetBackgroundColour(wxColor(1, 2, 3));
	this->SetMenuBar(m_MenuBar);

	//Add Menu Items
	wxMenu* menuFile = new wxMenu();
	menuFile->Append(10001, "Admin");
	menuFile->Append(10003, "Develop By");
	menuFile->Append(10002, "Exit");
	

	//Add Menu Items to Menu Bar
	m_MenuBar->Append(menuFile, "All");



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
	

	//Grid Sizers
	
	wxBoxSizer* movieList = new wxBoxSizer(wxVERTICAL);
	
	wxGridSizer* grid = new wxGridSizer(4, 5, 5);
	wxFont titleFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	wxFont secondaryFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL, false);
	
/*
	for (int i = 0; i < 8; i++)
	{
		::wxInitAllImageHandlers();
		wxBitmap bmp1("Assets/poster/joker.png", wxBITMAP_TYPE_PNG);

		wxBitmapButton* button = new wxBitmapButton(panel, 222, bmp1);
		gridSizer->Add(button, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTRE_VERTICAL | wxALL,5);
	}
	*/

	//Opening File in Reading Mode
	file->Open("data.txt", "r");

	//Check either file is opened or not
	if (file->IsOpened()) 
	{
		wxLogStatus(wxT("File is opened"));
		
		//Reading Data from File
		while ((file->Read(&m, sizeof(m)))) 
		{
			//Initializing all image handlers
			::wxInitAllImageHandlers();
			
			//wxBitmap bmp(m.filePath, wxBITMAP_TYPE_PNG);
			//button = new wxBitmapButton(panel, 222, moviePhoto[i]);

			//Display Movie poster from file location
			wxBitmap movie = wxBitmap(m.filePath, wxBITMAP_TYPE_PNG);
			m_bitmap = new wxStaticBitmap(this, 212, movie,wxDefaultPosition, wxDefaultSize);
			movieList->Add(m_bitmap);
			
			//Display Movie Name From File
			m_name = new wxStaticText(this, 4004, m.name);
			m_name->SetFont(titleFont);
			movieList->Add(m_name);
			
			//Displays Movie Price From File
			m_price = new wxStaticText(this, 4005, (wxString::Format(wxT("Rs.%d"),m.price)));
			m_price->SetFont(secondaryFont);
			movieList->Add(m_price);
			
			//Book Now || Button
			m_button = new wxButton(this, m.id,"Book Now");
			m_button->SetFont(secondaryFont);
			movieList->Add(m_button);
			
			//Bind click event to the button
			m_button->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnClick, this);
			
			
			
		}
		
	}
	else 
	{
		wxLogStatus(wxT("Error Opening Files."));
	}
	grid->Add(movieList);
	//Setting Sizer for this window
	SetSizer(grid);

	SetScrollbar(wxVERTICAL, 0, 16, 50);
	//SetScrollRate(5, -1);
 
	//Bottom Status Bar
	stats = CreateStatusBar(2);
	stats->SetStatusText(_("Hamro Movie Theater"));
	stats->SetStatusText(date1, 1);

}


cMain::~cMain()
{
	delete[]button;
	

}

//Close window event
void cMain::OnMenuExit(wxCommandEvent &evt)
{
	Close();
	evt.Skip();
}

//Open Login Screen Event
void cMain::OnAdmin(wxCommandEvent &evt)
{
	AdminLogin *f = new AdminLogin("Admin Login");
	f->FitInside();
	//f->Show();
	evt.Skip();
}

//Team Member window Event
void cMain::DevelopBy(wxCommandEvent& evt) 
{
	BuildBy* b = new BuildBy("Developed By");
	b->Show();
	evt.Skip();
}

//Seat Booking Page Event
void cMain::OnClick(wxCommandEvent& evt)
{
	Seats* s = new Seats("Book Seats");
	//s->Fit();
	s->Show();
	id = evt.GetId();
	evt.Skip();
}




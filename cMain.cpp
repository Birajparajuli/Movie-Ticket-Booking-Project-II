//This is the frame of the Application
#include "cMain.h"
#include "AdminLogin.h"
#include "Seats.h"

//Event Handlers Here

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_MENU(10002, cMain::OnMenuExit)
EVT_MENU(10001, cMain::OnAdmin)
EVT_BUTTON(222, cMain::ClrScr)
wxEND_EVENT_TABLE()

//Main Window
cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Movie Ticket Booking ", wxPoint(30, 30), wxSize(1000, 800))
{
	wxPanel* panel = new wxPanel(this, -1);
	//m_Text = new wxStaticText(panel, wxID_ANY, "MOVIES", wxPoint(500, 0));
	
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
	
	


	//Creating Grid Like Excel || Can be used in Admin Section
	/*
	grid = new wxGrid(this, wxID_ANY, wxDefaultPosition, wxSize(400, 300));
	grid->CreateGrid(4, 8);
	grid->SetRowSize(0, 60);
	grid->SetColSize(0, 120);

	grid->SetCellValue(0, 0, wxT("HAHAHAHA"));
	*/

	//Grid Sizers

	gridSizer = new wxGridSizer(2, 4, 10, 10);
	SetSizer(gridSizer);

	//Movie List
	wxImage::AddHandler(new wxJPEGHandler);

	
	wxBitmap bmp(wxT("Assets/2.jpg"), wxBITMAP_TYPE_JPEG);





	for (int i = 0; i < 8; i++)
	{
		::wxInitAllImageHandlers();
		wxBitmap bmp1("Assets/poster/2.png", wxBITMAP_TYPE_PNG);

		//Draw Over Image Button
		/*wxMemoryDC mdc(bmp);
		mdc.SetTextForeground(*wxRED);
		mdc.SetTextBackground(wxColor(0, 0, 0));
		mdc.SetFont(wxFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
		mdc.DrawText("ENDGAME", 0, 200);
		mdc.SelectObject(wxNullBitmap);
		*/

		wxBitmapButton* button = new wxBitmapButton(panel, 222, bmp1);
		gridSizer->Add(button, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTRE_VERTICAL | wxALL, 5);
	}

	//Movie List Using BitMap Button

	/*wxBitmap bitmap(wxT("Assets/2.jpg"), wxBITMAP_TYPE_JPEG);
	wxBitmapButton* button = new wxBitmapButton(this, wxID_OK,
		bitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW);

	m_Text = new wxStaticText(this, wxID_ANY, "Chakka Panja 15", wxPoint(140, 110), wxSize(300, 20));

	gridSizer->Add(button, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTRE_VERTICAL, 5);
	*/
	/*
	wxStaticBitmap* sb = new wxStaticBitmap(this, -1, bmp);
	gridSizer->Add(sb, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTRE_VERTICAL | wxALL, 5);

	wxStaticBitmap* sk = new wxStaticBitmap(this, -1, bmp);
	gridSizer->Add(sk, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTRE_VERTICAL | wxALL, 5);

	wxStaticBitmap* ss = new wxStaticBitmap(this, -1, bmp);
	gridSizer->Add(ss, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTRE_VERTICAL | wxALL, 5);

	wxStaticBitmap* sa = new wxStaticBitmap(this, -1, bmp);
	gridSizer->Add(sa, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTRE_VERTICAL | wxALL, 5);

	wxStaticBitmap* sc = new wxStaticBitmap(this, -1, bmp);
	gridSizer->Add(sc, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTRE_VERTICAL | wxALL, 5);

	wxStaticBitmap* sd = new wxStaticBitmap(this, -1, bmp);
	gridSizer->Add(sd, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTRE_VERTICAL | wxALL, 5);

	wxStaticBitmap* se = new wxStaticBitmap(this, -1, bmp);
	gridSizer->Add(se, 0, wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTRE_VERTICAL | wxALL, 5);

	*/

	//Test Button
	//m_Button = new wxButton(this, 901, "Click Here", wxPoint(150, 350), wxSize(150, 50));

	Center();


	//Bottom Status Bar
	stats = CreateStatusBar(2);
	stats->SetStatusText(_("Hamro Movie Theater"));
	stats->SetStatusText(date1, 1);

}
cMain::~cMain()
{
}

void cMain::OnMenuExit(wxCommandEvent &evt)
{
	//Close window event
	Close();
	evt.Skip();
}

void cMain::OnAdmin(wxCommandEvent &evt)
{
	AdminLogin *f = new AdminLogin("Admin Login");
	f->Show();
	evt.Skip();
}

void cMain::ClrScr(wxCommandEvent &evt)
{

	Seats *s = new Seats("Book Seats");
	s->Show();
}

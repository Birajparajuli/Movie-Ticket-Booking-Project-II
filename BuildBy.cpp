#include "BuildBy.h"


BuildBy::BuildBy(const wxString& title) : wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(400, 400)) {

	wxPanel* main = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(400, 400));

	wxBoxSizer* horiList = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* verticalList = new wxBoxSizer(wxVERTICAL);

	wxStaticText* text = new wxStaticText(main, wxID_ANY, "Github Repositary");
	horiList->Add(text);
	wxHyperlinkCtrl* text1 = new wxHyperlinkCtrl(main, wxID_ANY, "Github Link", "https://github.com/Birajparajuli/Movie-Ticket-Booking-Project-II");
	wxStaticText* text2 = new wxStaticText(main, wxID_ANY, "Built by:");
	wxStaticText* text3 = new wxStaticText(main, wxID_ANY, "Biraj Parajuli");
	wxStaticText* text4 = new wxStaticText(main, wxID_ANY, "Aashish Timilsina");
	wxStaticText* text5 = new wxStaticText(main, wxID_ANY, "Saurav Tandukar");
	wxStaticText* text6 = new wxStaticText(main, wxID_ANY, "Sandip Kumar Chaudharay");
	wxStaticText* text7 = new wxStaticText(main, wxID_ANY, "  Movie Seat Booking System © 2021");

	verticalList->Add(text1);
	verticalList->Add(text2);
	verticalList->Add(text3);
	verticalList->Add(text4);
	verticalList->Add(text5);
	verticalList->Add(text6);
	verticalList->Add(text7);

	horiList->Add(verticalList);
	main->SetSizer(horiList);


}
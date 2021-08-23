#pragma once

#include "wx/wx.h"
#include "wx/chartype.h"
#include "wx/bitmap.h"
#include "wx/ffile.h"

class Seats : public wxFrame
{
public:
	Seats(const wxString& title);
	~Seats();
	wxGridSizer* gridSizer = nullptr;
	int FieldWidth = 6;
	int FieldHeight = 6;
	int s = 0;
	//wxButton** btn;
	wxBitmapButton** btn;
	wxColour not_booked = wxColour(0, 128, 0);
	int* nField = nullptr;
	bool bFirstClick = true;
	int x, y, seatNum, seatStats;

	//File
	wxFFile* sFile = new wxFFile;
private:
	wxButton* m_Seats = nullptr;
	wxButton* m_Seats1 = nullptr;
	wxStaticText* m_Text = nullptr;
	wxStaticText* m_Price = nullptr;
	

	wxStatusBar* stats = nullptr;

	//wxPanel 
	wxPanel* topPanel = nullptr;
	wxPanel* panel = nullptr;
	wxPanel* bottomPanel = nullptr;
	
	wxStaticBitmap* bg_image = nullptr;

	//void onClickBook(wxCommandEvent& evt);
	void OnButtonClicked(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();

	friend class seatStats;
};


class seatStats {
public:
	int movieId;
	int seat [36];
	friend class Seats;
};

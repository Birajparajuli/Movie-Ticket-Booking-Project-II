#pragma once

#include "wx/wx.h"
#include "wx/chartype.h"
#include "wx/bitmap.h"

class Seats : public wxFrame
{
public:
	Seats(const wxString& title);
	~Seats();
	wxGridSizer* gridSizer = nullptr;
	int FieldWidth = 7;
	int FieldHeight = 7;
	int s = 0;
	wxButton** btn;
	wxBitmapButton** button;
	wxColour not_booked = wxColour(0, 128, 0);
private:
	wxButton* m_Seats = nullptr;
	wxButton* m_Seats1 = nullptr;
	wxStaticText* m_Text = nullptr;
	wxStaticText* m_Price = nullptr;
	

	wxStatusBar* stats = nullptr;

	



	//void onClickBook(wxCommandEvent& evt);
	void OnButtonClicked(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

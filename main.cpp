// wxWidgets Sample Program
// src: http://docs.wxwidgets.org/3.0/overview_helloworld.html
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx-3.0/wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx-3.0/wx/wx.h>
#endif

class TheApp : public wxApp
{
public:
    virtual bool OnInit();
};

class TheFrame : public wxFrame
{
public:
    TheFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
    void OnHello(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    wxDECLARE_EVENT_TABLE();
};

enum
{
    MENU_ID = 1
};

wxBEGIN_EVENT_TABLE(TheFrame, wxFrame)
    EVT_MENU(MENU_ID, TheFrame::OnHello)
    EVT_MENU(wxID_EXIT, TheFrame::OnExit)
    EVT_MENU(wxID_ABOUT, TheFrame::OnAbout)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(TheApp);

bool TheApp::OnInit()
{
    TheFrame *frame = new TheFrame(
        "The Devs Tech",
        wxPoint(50, 50),
        wxSize(450, 340)
    );
    frame->Show(true);

    return true;
}

TheFrame::TheFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(
        MENU_ID,
        "&Hello...\tCtrl-H",
        "Help string shown in status bar for this menu item"
    );
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("Welcome from The Devs Tech!");
}

void TheFrame::OnExit(wxCommandEvent &event)
{
    Close(true);
}

void TheFrame::OnAbout(wxCommandEvent &event)
{
    wxMessageBox(
        "This is a wxWidgets sample by The Devs Tech",
        "About",
        wxOK | wxICON_INFORMATION
    );
}

void TheFrame::OnHello(wxCommandEvent &event)
{
    wxLogMessage("Hello world from The Devs Tech!");
}
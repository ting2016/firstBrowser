#include "tab.h"
#include "browser.h"
#include "page.h"
#include <QtWidgets>
#include <iostream>
using namespace std;

Tab::Tab(Browser * pBrowser)
{

    this->pBrowser = pBrowser;
    pPage = new Page(this);
    connect(this,SIGNAL(askLoad(QUrl)), this, SLOT(doLoad(QUrl)));
    connect(this, SIGNAL(askEnableJavaScript()), this, SLOT(doEnableJavScript()));
    connect(this, SIGNAL(loadFinished(bool)), SLOT(adjustLocation()));

    QWebSettings *sets = this->settings();
    sets->setAttribute(QWebSettings::LocalStorageEnabled, true);
    sets->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    sets->setAttribute(QWebSettings::PrivateBrowsingEnabled, false);
}

Tab::~Tab()
{

}

Page& Tab::getPage()
{
    return *pPage;
}

void Tab::doLoad(QUrl url)
{
    setUrl(url);
}

void Tab::activate()
{
    isActive = true;
    show();
}

void Tab::disActivate()
{
    isActive = false;
    hide();
}

void Tab::doEnableJavScript()
{
    QWebSettings *sets = this->settings();
    sets->setAttribute(QWebSettings::JavascriptEnabled,true);
}

QWebView* Tab::createWindow(QWebPage::WebWindowType type)
{

    Tab* pTab = nullptr;

     if(type != QWebPage::WebWindowType::WebBrowserWindow)
    {
        std::cout<<"WebVindowType != QWebPage::WebWindowType::WebBrowserWindow, Will not create a new tab."<<endl;
    }
    else
    {
        Q_UNUSED(type);
        pTab = new Tab(pBrowser);
        emit pTab->askEnableJavaScript();
        pTab->setAttribute(Qt::WA_DeleteOnClose, true);
        emit pBrowser->askAddTab(pTab);
    }
    return pTab;
}

void Tab::adjustLocation()
{
    pBrowser->getLocationEdit()->setText(this->url().toString());
}

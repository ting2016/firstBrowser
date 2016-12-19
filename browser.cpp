#include "browser.h"
#include "tab.h"
#include <QtWidgets>
#include <QtNetwork>
#include <QtWebKitWidgets>
#include <QMainWindow>
#include <QWebView>
class Tab;
Browser::Browser(){
    defaultUrl = QUrl("http://www.pengfu.com");
    Tab *pTab = new Tab(this);
    tabs.push_back(pTab);
    currentTabIndex = 0;


    //QNetworkProxyFactory::setUseSystemConfiguration(true);

    setGeometry(QRect( 100, 0, 800, 600));
    QToolBar *toolBar = addToolBar(tr("Navigation"));
    toolBar->addAction(tabs.at(currentTabIndex)->pageAction(QWebPage::Back));
    toolBar->addAction(tabs.at(currentTabIndex)->pageAction(QWebPage::Forward));
    toolBar->addAction(tabs.at(currentTabIndex)->pageAction(QWebPage::Reload));
    toolBar->addAction(tabs.at(currentTabIndex)->pageAction(QWebPage::Stop));

    locationEdit = new QLineEdit(this);
    toolBar->addWidget(locationEdit);
    locationEdit->setSizePolicy(QSizePolicy::Expanding, locationEdit->sizePolicy().verticalPolicy());
    locationEdit->setText(defaultUrl.toString());

    //first time, load default url automatically

    connect(locationEdit, SIGNAL(returnPressed()), SLOT(changeLocation()));
    connect(this, SIGNAL(askLoad(QUrl)), this, SLOT(doLoad(QUrl)));
    connect(this, SIGNAL(askAddTab(Tab*)), this, SLOT(doAddTab(Tab*)));

    //setCentralWidget(tabs.at(currentTabIndex));

    setUnifiedTitleAndToolBarOnMac(true);
    emit askLoad(defaultUrl);
}

void Browser::changeLocation()
{
    QUrl url = QUrl::fromUserInput(locationEdit->text());

    emit askLoad(url);
}

void Browser::doLoad(QUrl url)
{
    tabs.at(currentTabIndex)->activate();
    emit tabs.at(currentTabIndex)->askLoad(url);
}

void Browser::doAddTab(Tab * thisTab)
{

    tabs.at(currentTabIndex)->disActivate();
    tabs.push_back(thisTab);
    currentTabIndex = tabs.size() - 1;
    thisTab->activate();

}

QLineEdit* Browser::getLocationEdit()
{
    return locationEdit;
}

Browser::~Browser()
{


}

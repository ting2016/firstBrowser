#include "browser.h"
#include "tab.h"
#include <QtWidgets>
#include <QtNetwork>
#include <QtWebKitWidgets>
#include <QMainWindow>
#include <QWebView>
class Tab;
Browser::Browser(){
    pTab = new Tab(this);

    QNetworkProxyFactory::setUseSystemConfiguration(true);
    QToolBar *toolBar = addToolBar(tr("Navigation"));
    toolBar->addAction(pTab->pageAction(QWebPage::Back));
    toolBar->addAction(pTab->pageAction(QWebPage::Forward));
    toolBar->addAction(pTab->pageAction(QWebPage::Reload));
    toolBar->addAction(pTab->pageAction(QWebPage::Stop));

    locationEdit = new QLineEdit(this);
    toolBar->addWidget(locationEdit);
    locationEdit->setSizePolicy(QSizePolicy::Expanding, locationEdit->sizePolicy().verticalPolicy());
    connect(locationEdit, SIGNAL(returnPressed()), SLOT(changeLocation()));

    connect(pTab->getPage(),SIGNAL(linkClicked(const QUrl &clickedUrl)),this,SLOT(doClickOnLink(const QUrl &clickedUrl)));

    setCentralWidget(pTab);
    setUnifiedTitleAndToolBarOnMac(true);
}

void Browser::changeLocation()
{
    QUrl url = QUrl::fromUserInput(locationEdit->text());
    pTab->load(url);
    pTab->setFocus();
}

void Browser::doClickOnLink(const QUrl &clickedUrl)
{
    pTab->load(clickedUrl);
    pTab->setFocus();
}

Browser::~Browser()
{
    delete pTab;

}

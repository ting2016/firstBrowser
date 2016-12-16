#include "page.h"
#include "tab.h"
#include "browser.h"
#include <iostream>
using namespace std;
class Tab;
Page::Page(Tab *pTab)
{
     this->pTab = pTab;
    this->setForwardUnsupportedContent(true);
}

Page::~Page()
{

}

QString Page::userAgentForUrl(const QUrl &url) const
{   QString ua = userAgentForUrl(url);
    std::cout<<"user agent string for url: "<<url.toString().toStdString()<<" is: "<<ua.toStdString()<<endl;
    return ua;
}


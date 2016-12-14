#include "tab.h"
#include "browser.h"
#include "page.h"
#include <QtWidgets>

Tab::Tab(Browser * pBrowser)
{

    this->pBrowser = pBrowser;
    pPage = new Page(this);
    url = QUrl("http://www.pengfu.com");
    this->load(url);
}

Tab::~Tab()
{

}

Page& Tab::getPage()
{
    return *pPage;
}

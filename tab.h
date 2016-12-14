#ifndef TAB_H
#define TAB_H

#include <QWebView>
#include "page.h"

class Page;
class Browser;
class Tab: public QWebView
{
    Q_OBJECT
private:
    Browser * pBrowser;
    Page *pPage;
    QUrl url;
public:
    Tab(Browser * pBrowser);
    ~Tab();
    Page& getPage();

protected slots:


//protected signals:

};

#endif // TAB_H

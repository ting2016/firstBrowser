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
    bool isActive;
public:
    Tab(Browser * pBrowser);
    ~Tab();
    Page& getPage();
    QWebView* createWindow(QWebPage::WebWindowType type);
    void activate();
    void disActivate();

protected slots:
    void doEnableJavScript();
    void doLoad(QUrl);
    void adjustLocation();



signals:
    void askEnableJavaScript();
    void askLoad(QUrl);

};

#endif // TAB_H

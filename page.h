#ifndef PAGE_H
#define PAGE_H

#include <QWebPage>

class Tab;
class Page : public QWebPage
{
    Q_OBJECT

private:
    Tab * pTab;

public:
    Page(Tab* pTab);
    ~Page();


protected:
    virtual QString userAgentForUrl(const QUrl & url) const;

protected slots:

//protected signals:

};

#endif // PAGE_H

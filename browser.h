#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "tab.h"

class Browser : public QMainWindow
{
    Q_OBJECT
 private:
    QLineEdit *locationEdit;
    QVector<Tab*> tabs;
    int currentTabIndex;
    QUrl defaultUrl;

 public:
    Browser();
    ~Browser();
    QLineEdit* getLocationEdit();

 protected slots:
    void changeLocation();
    void doAddTab(Tab* thisTab);
    void doLoad(QUrl);
 signals:
    void askAddTab(Tab*);
    void askLoad(QUrl);


};

#endif // MAINWINDOW_H

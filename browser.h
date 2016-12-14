#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include "tab.h"

class Browser : public QMainWindow
{
    Q_OBJECT
 private:
    Tab * pTab;
    QLineEdit *locationEdit;
 public:
    Browser();
    ~Browser();

 protected slots:

 //protected signals:

    void changeLocation();
    void doClickOnLink(const QUrl &clickedUrl);

};

#endif // MAINWINDOW_H

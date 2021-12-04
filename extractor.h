#ifndef EXTRACTOR_H
#define EXTRACTOR_H


#include <QtPdf/QPdfDocument>
#include <QtPdf/QPdfSelection>
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <QFileDialog>
#include <QMessageBox>
#include <QObject>


using namespace std;

class extractor
{


public:
    extractor();
    void load(QWidget * t);
    void extr(int page);
    bool checkboxc;
    int pgcount;
    bool filestatus;

    // obj
    QString *allText;
    QStringList *s;
    QStringList *gg;

private:
    QPdfDocument *document = new QPdfDocument;
    QString filename;

    // objs
    QStringList * splitter(string);
    void readal();
    QStringList *templist;


    QString *selectedText;

};

#endif // EXTRACTOR_H

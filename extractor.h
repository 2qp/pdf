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

    // obj
    QString *allText;
    QStringList *s;
    QStringList *gg;
    QStringList *templist;
    QString *selectedText;
    QPdfDocument *document = new QPdfDocument;
    QString *b;

private:
    //QPdfDocument *document = new QPdfDocument;
    QString filename;

    // objs
    QStringList * splitter(string);
    void readal();






};

#endif // EXTRACTOR_H

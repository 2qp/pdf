#ifndef EXTRACTOR_H
#define EXTRACTOR_H


#include <QtPdf/QPdfDocument>
#include <QtPdf/QPdfSelection>
#include <iostream>
#include <sstream>
#include <QFileDialog>
#include <QMessageBox>
#include <QObject>
#include <QTextStream>


using namespace std;

class extractor
{


public:
    extractor();
    void load(QWidget * t);
    void extr(int page);
    void save(QString);
    bool checkboxc;
    int pgcount;

    // obj
    QString *allText;
    QStringList *rawSliced;
    QStringList *templist;
    QString *selectedText;
    QPdfDocument *document = new QPdfDocument;
    QString *format;
    bool extracted;

private:
    //QPdfDocument *document = new QPdfDocument;
    QString filename;

    // objs
    QStringList * splitter(string);
    void readal();






};

#endif // EXTRACTOR_H

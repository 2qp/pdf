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

private:
    QPdfDocument *document = new QPdfDocument;
    QString filename;
};

#endif // EXTRACTOR_H

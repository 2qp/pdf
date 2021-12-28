#include "extractor.h"

extractor::extractor()
{
}

void extractor::load(QWidget * (t))
{
    document->close();
    filename = QFileDialog::getOpenFileName(t,
                                            QObject::tr("Open PDF File"), "./", QObject::tr("PDF Files (*.pdf)"));
    document->load(filename);
    // pages count
    pgcount = document->pageCount();
    // bool on set
    extracted = false;
}


void extractor::extr(int page)
{
    allText = new QString;
    if(checkboxc == true) {
        readal();
    } else {
        *allText = document->getAllText(page).text();
    }
    // Removing special characters
    format = new QString;
    *format = allText->remove(QRegExp("[\\^$(){},>.:;*#_=<!+-/]+"));
    std::string a = format->toStdString();
    delete format;
    // Takes only space separated C++ strings.
    splitter(a);
    // Conversion of Qlist to const to pump texedit
    rawSliced = new QStringList;
    *rawSliced = *templist;
    delete templist;
    // set da bool
    extracted = true;
}

QStringList * extractor::splitter(string t)

{
    stringstream ss(t);
    string word;
    templist = new QStringList;
    while (ss >> word) {
        QString str = QString::fromUtf8(word.c_str());
        templist->append(str);
    }
    return templist;
}

void extractor::readal()

{
    int pgcounts = document->pageCount();
    selectedText = new QString;
    for (int i = 0; i <= pgcounts ; i++ ) {
        *selectedText = document->getAllText(i).text();
        allText->append(*selectedText);
    }
    delete selectedText;
}


void extractor::save(QString text)
{
    QString outputFile = QFileDialog::getSaveFileName(nullptr, "Save as", ".", "Docs (*.docx *.odf);;Text files (*.txt);;XML files (*.xml)" );
    QFile Saved(outputFile);
    Saved.open(QFile::WriteOnly | QFile::Truncate | QFile::Text);
    QTextStream out(&Saved);
    out << text;
}

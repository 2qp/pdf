#include "extractor.h"

extractor::extractor()
{
    //QObject::connect(ui->checkBox, SIGNAL(clicked(bool)), this, SLOT(ischecked(bool)));
}

void extractor::load(QWidget * (t))
{
    filename = QFileDialog::getOpenFileName(t,
                                            QObject::tr("Open PDF File"), "./", QObject::tr("PDF Files (*.pdf)"));
    document->load(filename);
    // objs
    s = new QStringList;
    templist = new QStringList;
    gg = new QStringList;
    selectedText = new QString;
    allText = new QString;
    b = new QString;
}


void extractor::extr(int page)
{
    if(checkboxc == true) {
        readal();
    } else {
        *allText = document->getAllText(page).text();
    }
    // Removing special characters
    *b = allText->remove(QRegExp("[\\^$(){},>.:;*#_=<!+-/]+"));
    std::string a = b->toStdString();
    // Takes only space separated C++ strings.
    splitter(a);
    // Converstion of Qlist to const to pump texedit
    //s = new QStringList;
    s = templist;
    //delete templist;
    // pages count
    pgcount = document->pageCount();
}

QStringList * extractor::splitter(string t)

{
    stringstream ss(t);
    string word;
    while (ss >> word) {
        QString str = QString::fromUtf8(word.c_str());
        templist->append(str);
    }
    return templist;
}

void extractor::readal()

{
    int pgcounts = document->pageCount();
    for (int i = 0; i <= pgcounts ; i++ ) {
        *selectedText = document->getAllText(i).text();
        allText->append(*selectedText);
    }
}



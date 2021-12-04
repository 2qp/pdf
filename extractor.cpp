#include "extractor.h"

extractor::extractor()
{
}

void extractor::load(QWidget * (t))
{
    filename = QFileDialog::getOpenFileName(t,
                                            QObject::tr("Open PDF File"), "./", QObject::tr("PDF Files (*.pdf)"));
    document->load(filename);
}

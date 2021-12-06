#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(on_actionLoad_triggered()));
    connect(ui->checkBox, SIGNAL(clicked(bool)), this, SLOT(ischecked(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionLoad_triggered()
{
    extract.load(this);
}

void MainWindow::on_actionRead_triggered()
{
    if(extract.document->status() == 2) {
        int page = ui->spinBox->text().toInt();
        if(ui->checkBox->isChecked()) {
            extract.checkboxc = true;
            extract.extr(page);
            ui->plainTextEdit->appendPlainText(*extract.allText);
        } else {
            extract.checkboxc = false;
            extract.extr(page);
            ui->plainTextEdit->setPlainText(*extract.allText);
        }
        // appending to splitter
        for(int i = 0 ; i < extract.s->length() ; i++) {
            ui->splitter->appendPlainText(extract.s->at(i));
        }
        // counting the list
        int counter = ui->splitter->document()->blockCount();
        ui->counts->display(counter);
        // page count of pdf
        ui->pgcount->display(extract.pgcount);
    } else  {
        QMessageBox::information(this, "Error", "PDF File Not Loaded", QMessageBox::Ok);
    }
}

void MainWindow::ischecked(bool checked)
{
    if(checked) {
        ui->spinBox->setDisabled(true);
    }
    if(!checked) {
        // removing fixed size
        ui->spinBox->setEnabled(true);
    }
}

void MainWindow::on_actionDuplicates_triggered()
{
    ui->splitter->clear();
    extract.s->removeDuplicates();
    extract.gg = extract.s;
    for(int i = 0 ; i < extract.gg->length() ; i++) {
        ui->splitter->appendPlainText(extract.gg->at(i));
    }
    //delete gg;
    // --
    // redisplay list count
    int counter = ui->splitter->document()->blockCount();
    ui->counts->display(counter);
    //size
    //unsigned long ab = sizeof (gg);
    //QString vv = QString::number(ab);
    // ui->label->setText(vv);
}

void MainWindow::on_actionClear_triggered()
{
    //delete document;
    //delete s;
    //delete templist;
    //delete gg;
    extract.templist->clear();
    extract.s->clear();
    extract.gg->clear();
    ui->splitter->clear();
    ui->plainTextEdit->clear();
    extract.allText->clear();
    extract.selectedText->clear();
    extract.document->close();
    extract.b->clear();
    //document->destroyed();
}

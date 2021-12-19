#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent, Qt::FramelessWindowHint ) // making da window frameless
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground); // window transparent
    // Manual Actions
    QMenu *menu = new QMenu();
    menu->addAction(ui->actionSave);
    menu->addAction(ui->actionSave_Sliced_Output);
    QToolButton* toolButton = new QToolButton();
    toolButton->setIcon(QIcon(":/icons/save2.png"));
    toolButton->setMenu(menu);
    toolButton->setPopupMode(QToolButton::InstantPopup);
    ui->toolBar->addWidget(toolButton);
    //
    // Connections
    //connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(on_actionLoad_triggered()));
    connect(ui->checkBox, SIGNAL(clicked(bool)), this, SLOT(ischecked(bool)));
    //
    // panel buttons
    connect(ui->btn_min, SIGNAL(clicked(bool)), this, SLOT(showMinimized()));
    connect(ui->btn_max, SIGNAL(clicked(bool)), this, SLOT(showMax()));
    connect(ui->btn_close, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionLoad_triggered()
{
    extract.load(this);
    // page count of pdf
    ui->pgcount->display(extract.pgcount);
}

void MainWindow::on_actionRead_triggered()
{
    // if document is laoded
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
        // enabling spinbox if !ticked
        ui->spinBox->setEnabled(true);
    }
}

void MainWindow::on_actionDuplicates_triggered()
{
    if(extract.document->status() == 2) {
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
    } else  {
        QMessageBox::information(this, "Error", "PDF File Not Loaded", QMessageBox::Ok);
    }
    //size
    //unsigned long ab = sizeof (gg);
    //QString vv = QString::number(ab);
    // ui->label->setText(vv);
}

void MainWindow::on_actionClear_triggered()
{
    if(extract.document->status() == 2) {
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
    } else {
        QMessageBox::information(this, "Error", "Nothing to clear", QMessageBox::Ok);
    }
}

void MainWindow::on_actionSave_triggered()
{
    // getting plain text frm textedit n pass arg
    QString text = ui->plainTextEdit->toPlainText();
    extract.save(text);
}

void MainWindow::on_actionSave_Sliced_Output_triggered()
{
    QString text2 = ui->splitter->toPlainText();
    extract.save(text2);
}

void MainWindow::showMax()
{
    // func to max / normal window
    if(this->isMaximized()) {
        this->showNormal();
    } else {
        this->showMaximized();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // click evnt on window
    m_x = event->x();
    m_y = event->y();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    // moving da widget to current cursor position
    move(event->globalX() - m_x, event->globalY() - m_y);
}

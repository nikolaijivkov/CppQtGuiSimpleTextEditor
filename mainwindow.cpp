#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->findJobBtn->setStyleSheet("QPushButton:hover{color : green;}");
    ui->findJobBtn->setToolTip("<p align='center'>This button is going to open a new <br><b>web browser</b> "
                               "for you. <b>Good luck!</b><br>"
                               "<img height='128' src='qrc:/png/cpp-logo.png'/></p>");

    // connect clicked signals for different buttons to their appropriate slots
    connect(ui->copyBtn, SIGNAL(clicked()), ui->textEdit, SLOT(copy()));
    connect(ui->cutBtn, SIGNAL(clicked()), ui->textEdit, SLOT(cut()));
    connect(ui->pasteBtn, SIGNAL(clicked()), ui->textEdit, SLOT(paste()));
    connect(ui->clearBtn, SIGNAL(clicked()), ui->textEdit, SLOT(clear()));
    connect(ui->undoBtn, SIGNAL(clicked()), ui->textEdit, SLOT(undo()));
    connect(ui->redoBtn, SIGNAL(clicked()), ui->textEdit, SLOT(redo()));

    // make QVector and iterate over it with cpp11 range-based for loop
    QVector<QWidget*> buttons {ui->copyBtn, ui->cutBtn, ui->pasteBtn, ui->clearBtn, ui->undoBtn, ui->redoBtn};
    for(QVector<QWidget*>::const_reverse_iterator it = buttons.crbegin(); it!= buttons.crend(); ++it)
        connect(*it, SIGNAL(clicked()), ui->textEdit, SLOT(setFocus()));

    connect(ui->findJobBtn, SIGNAL(clicked()), this, SLOT(onFindJob()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onFindJob()
{
    //stop clicking around and go find a job already...
    QDesktopServices::openUrl(QUrl("https://www.jobs.bg/front_job_search.php?keyword=c%2B%2B"));
}

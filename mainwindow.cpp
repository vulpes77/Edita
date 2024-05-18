#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // QPalette pal = QPalette();
    //pal.setColor(QPalette::Window, "#090A1C");
    //ui->textEdit->setAutoFillBackground(true);
    //ui->textEdit->setPalette(pal);
    //ui->textEdit->setBackgroundVisible(true);
    //ui->textEdit->show();
    //this->setCentralWidget(ui->textEdit);
    ui->textEdit->setTabStopDistance(QFontMetricsF(ui->textEdit->font()).horizontalAdvance(' ') * 8);
    QPalette p = ui->textEdit->palette();

    p.setColor(QPalette::Active, QPalette::Base, "#090A1C");
    p.setColor(QPalette::Active, QPalette::Text, "#F0FBFA");
    p.setColor(QPalette::Inactive, QPalette::Base, "#090A1C");

    ui->textEdit->setPalette(p);

    ui->textEdit->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setPlainText(QString());

}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Files:");
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Error", "Cannot open" + file.errorString());
    }

    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setPlainText(text);
    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Files:");
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Error", "Cannot save" + file.errorString());
    }
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}



void MainWindow::on_actionRedo_2_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionUndo_2_triggered()
{
     ui->textEdit->undo();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("About"),
            tr("Who cares about this shit!? Btw. Babis is KOKOT!!!"));
}


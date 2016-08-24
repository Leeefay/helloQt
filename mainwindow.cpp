#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QColorDialog>
#include <QFontDialog>
#include <QMessageBox>
#include <QPalette>
#include <QDebug>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->quitButton->installEventFilter(this);
    ui->label->adjustSize();
    ui->statusBar->showMessage ("Press SHOW to start, Press COLOR to select color, Press FONT to set font");
    setWindowIcon(QIcon("icon.ico"));
    setWindowTitle("Message from LYF");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeWarning(QCloseEvent *event)
{
    qDebug() << "Trying to quit " ;
    ui->statusBar->showMessage("Trying to quit ");

    int ret = QMessageBox::question(0, tr("Quit "), tr("Do you really want to exit?"), QMessageBox::Yes | QMessageBox::No, QMessageBox::No);     //using ret as a number to set into if/switch etc.
    if (ret == QMessageBox::Yes) {
        event->accept(); //assure to close
    } else {
        event->ignore(); //not to close
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    closeWarning(event);
}

void MainWindow::on_quitButton_clicked()
{
    emit close();
}

void MainWindow::on_showButton_toggled(bool checked)
{
    if (checked)
    {
        ui->label->setText("I LOVE YOU!");
        ui->statusBar->showMessage ("Message status: ON");
        //qDebug("lalala");
    }
    else
    {
        ui->label->clear();
        ui->statusBar->showMessage ("Message status: OFF");
    }
}

void MainWindow::on_colorButton_clicked()
{
    QColor color = QColorDialog::getColor(Qt::black,this);
    QPalette labelPalette;
    labelPalette.setColor(QPalette::WindowText,color);
    ui->label->setPalette(labelPalette);
}

void MainWindow::on_fontButton_clicked()
{
    bool ok;
    QFont f = QFontDialog::getFont(&ok,this);
    if (ok)
        ui->label->setFont(f);
}

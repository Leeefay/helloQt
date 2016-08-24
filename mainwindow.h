#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void closeEvent(QCloseEvent * event);

    ~MainWindow();

private slots:
    void on_quitButton_clicked();

    void on_showButton_toggled(bool checked);

    void on_colorButton_clicked();

    void on_fontButton_clicked();

private:
    Ui::MainWindow *ui;
    void closeWarning(QCloseEvent *event);
};

#endif // MAINWINDOW_H

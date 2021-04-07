#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_item_clicked();

    void on_delete_item_clicked();

    void on_pushButton_SelectPlanet_clicked();

    void on_pushButton_ConfChang_clicked();

    void on_pushButton_sizeVictor_clicked();

    void on_Author_triggered();

    void on_action_triggered();

    void on_action_2_triggered();

    void on_Merge_in_file_triggered();

    void on_Merge_from_file_triggered();

    void on_pushButton_back_clicked();

    void on_pushButton_next_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

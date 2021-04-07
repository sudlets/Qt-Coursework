#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
using namespace std;
#include "Planet.h"
#include "basevect.h"
#include <QMessageBox>
#include <fstream>

Planet
Earth("Земля", 1, 0, "Human"),
Mars("Марс", 2, -2000, "Unknown"),
Venera("Венера", 3, 1610, "Galileo_Galilei"),
Mercyri("Меркурий", 4, -3000, "the_Sumerians"),
Upiter("Юпитер", 5, 1610, "Galileo_Galilei"),
Saturn("Сатурн", 6, 1659, "Christiaan_Huygens"),
Uran("Уран", 7, 1781, "William_Herschel"),
Neptun("Нептун", 8, 1846, "Team"),
Pluton("Плутон", 9, 1930, "Clyde_William");
Planet mass[] = { Earth, Mars, Venera, Mercyri, Upiter, Saturn, Uran, Neptun, Pluton };
VectPlanet Planets(mass, 9);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_item_clicked()
{
    Planets.add_planet();
}

void MainWindow::on_delete_item_clicked()
{
    Planets.delete_planet(ui->lineEdit_EnterPlanet->text().toInt());
}

void MainWindow::on_pushButton_SelectPlanet_clicked()
{
    int number_planet = ui->lineEdit_EnterPlanet->text().toInt();
    if(number_planet < Planets.get_size() && number_planet > -1)
    {
        ui->lineEdit_EnterPlanet->setDisabled(true);
        ui->lineEdit_Mass->setEnabled(true);
        ui->lineEdit_Name->setEnabled(true);
        ui->lineEdit_WhoOpen->setEnabled(true);
        ui->lineEdit_YearOpen->setEnabled(true);
        VectPlanet::Iterator iter;
        QString T;
        iter = Planets.begin();
        iter += number_planet;
        T = QString::fromStdString(iter.get_name());
        ui->lineEdit_Name->setText(T);
        T = QString::fromStdString(iter.get_Who_opening());
        ui->lineEdit_WhoOpen->setText(T);
        T.sprintf("%d", iter.get_mass());
        ui->lineEdit_Mass->setText(T);
        T.sprintf("%d", iter.get_Year_of_opening());
        ui->lineEdit_YearOpen->setText(T);
    }
    else
    {
        ui->lineEdit_Name->setText("Не существует");
        ui->lineEdit_Mass->setText("-1");
        ui->lineEdit_WhoOpen->setText("Не существует");
        ui->lineEdit_YearOpen->setText("-1");
    }
}

void MainWindow::on_pushButton_ConfChang_clicked()
{
    int number_planet = ui->lineEdit_EnterPlanet->text().toInt();
    if(number_planet < Planets.get_size() && number_planet > -1 && ui->lineEdit_Name->isEnabled())
    {
    ui->lineEdit_EnterPlanet->setEnabled(true);
    ui->lineEdit_Mass->setDisabled(true);
    ui->lineEdit_Name->setDisabled(true);
    ui->lineEdit_WhoOpen->setDisabled(true);
    ui->lineEdit_YearOpen->setDisabled(true);
    Planet tmp( ui->lineEdit_Name->text().toStdString(),
                ui->lineEdit_Mass->text().toInt(),
                ui->lineEdit_YearOpen->text().toInt(),
                ui->lineEdit_WhoOpen->text().toStdString());
    VectPlanet::Iterator iter;
    iter = Planets.begin();
    iter += ui->lineEdit_EnterPlanet->text().toInt();
    *iter = tmp;
    }
}

void MainWindow::on_pushButton_sizeVictor_clicked()
{
    QString SizeVector;
    SizeVector.sprintf("%d", Planets.get_size());
    ui->lineEdit_EnterPlanet->setText(SizeVector);
}

void MainWindow::on_Author_triggered()
{
    QMessageBox::information(this,
    "О программе:",
    "Выполнил:\n"
    "Студент 2-го курса\n"
    "группы ИКПИ-73\n"
    "Сударев Андрей Владимирович",
    QMessageBox::Ok);
}

void MainWindow::on_action_triggered()
{
    ofstream fout;
    fout.open("Planets.txt");
    fout << Planets.get_size() << endl;
    for(VectPlanet::Iterator iter = Planets.begin(); iter != Planets.end(); iter++)
        fout << iter;
    fout.close();
}

void MainWindow::on_action_2_triggered()
{
    ifstream fin;
    fin.open("Planets.txt");
    if(fin.is_open())
    {
        int size = Planets.get_size();
        fin >> size;
        Planets.new_size(size);
        for(VectPlanet::Iterator iter = Planets.begin(); iter != Planets.end(); iter++)
            fin >> *iter;
    }
}

void MainWindow::on_Merge_in_file_triggered()
{
    ifstream fin("Planets.txt");
    if(fin.is_open())
    {
        int size;
        fin >> size;
        VectPlanet tmp;
        tmp.new_size(size);
        for(VectPlanet::Iterator iter = tmp.begin(); iter != tmp.end(); iter++)
            fin >> *iter;
        fin.close();

        ofstream fout("Planets.txt");
        fout << size + Planets.get_size() << endl;
        for(VectPlanet::Iterator iter = tmp.begin(); iter != tmp.end(); iter++)
            fout << iter;
        for(VectPlanet::Iterator iter = Planets.begin(); iter != Planets.end(); iter++)
            fout << iter;
        fout.close();
    }
   else
    {
        ofstream fout;
        fout.open("Planets.txt");
        fout << Planets.get_size() << endl;
        for(VectPlanet::Iterator iter = Planets.begin(); iter != Planets.end(); iter++)
            fout << iter;
        fout.close();
    }
}

void MainWindow::on_Merge_from_file_triggered()
{
    ifstream fin("Planets.txt");
    if(fin.is_open())
    {
        int size, old_size;
        old_size = Planets.get_size();
        fin >> size;
        Planets.add_size(size);
        VectPlanet::Iterator iter = Planets.begin();
        iter += old_size;
        for(; iter != Planets.end(); iter++)
            fin >> *iter;
    }
}

void MainWindow::on_pushButton_back_clicked()
{
    ui->lineEdit_EnterPlanet->setEnabled(true);
    ui->lineEdit_Mass->setDisabled(true);
    ui->lineEdit_Name->setDisabled(true);
    ui->lineEdit_WhoOpen->setDisabled(true);
    ui->lineEdit_YearOpen->setDisabled(true);
    int number = ui->lineEdit_EnterPlanet->text().toInt() - 1;
    QString NumberVector;
    NumberVector.sprintf("%d", number);
    ui->lineEdit_EnterPlanet->setText(NumberVector);

    if(number < Planets.get_size() && number > -1)
    {
    VectPlanet::Iterator iter;
    QString T;
    iter = Planets.begin();
    iter += number;
    T = QString::fromStdString(iter.get_name());
    ui->lineEdit_Name->setText(T);
    T = QString::fromStdString(iter.get_Who_opening());
    ui->lineEdit_WhoOpen->setText(T);
    T.sprintf("%d", iter.get_mass());
    ui->lineEdit_Mass->setText(T);
    T.sprintf("%d", iter.get_Year_of_opening());
    ui->lineEdit_YearOpen->setText(T);
    }
    else
    {
        ui->lineEdit_Name->setText("Не существует");
        ui->lineEdit_Mass->setText("-1");
        ui->lineEdit_WhoOpen->setText("Не существует");
        ui->lineEdit_YearOpen->setText("-1");
    }
}

void MainWindow::on_pushButton_next_clicked()
{
    ui->lineEdit_EnterPlanet->setEnabled(true);
    ui->lineEdit_Mass->setDisabled(true);
    ui->lineEdit_Name->setDisabled(true);
    ui->lineEdit_WhoOpen->setDisabled(true);
    ui->lineEdit_YearOpen->setDisabled(true);
    int number = ui->lineEdit_EnterPlanet->text().toInt() + 1;
    QString NumberVector;
    NumberVector.sprintf("%d", number);
    ui->lineEdit_EnterPlanet->setText(NumberVector);

    if(number < Planets.get_size() && number > -1)
    {
    VectPlanet::Iterator iter;
    QString T;
    iter = Planets.begin();
    iter += number;
    T = QString::fromStdString(iter.get_name());
    ui->lineEdit_Name->setText(T);
    T = QString::fromStdString(iter.get_Who_opening());
    ui->lineEdit_WhoOpen->setText(T);
    T.sprintf("%d", iter.get_mass());
    ui->lineEdit_Mass->setText(T);
    T.sprintf("%d", iter.get_Year_of_opening());
    ui->lineEdit_YearOpen->setText(T);
    }
    else
    {
        ui->lineEdit_Name->setText("Не существует");
        ui->lineEdit_Mass->setText("-1");
        ui->lineEdit_WhoOpen->setText("Не существует");
        ui->lineEdit_YearOpen->setText("-1");
    }
}

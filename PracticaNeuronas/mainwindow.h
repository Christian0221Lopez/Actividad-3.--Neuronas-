#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<iostream>
#include<string>
#include <QMainWindow>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    friend class Neurona;
    friend class Clista;
};
#endif // MAINWINDOW_H


class Neurona
{
private:
    Neurona* pAnt;
    Neurona* pSig;
    int Id;
    float Voltaje;
    int Pos_x;
    int Pos_y;
    int Red;
    int Green;
    int Blue;
    friend class Clista;
public:
    void InsertarAdelantefloat(int,float,int,int,int,int,int);
    float EliminarSiguiente();
};

class Clista
{
private:
    Neurona* Inicio;
    Neurona* Final;
    friend class Neurona;
public:
    Clista();
    ~Clista();
    void InsertarInicio(int,float,int,int,int,int,int);
    void InsertarFinal(int,float,int,int,int,int,int);
    float EliminarInicio();
    float EliminarFinal();
    int Tamanio();
    bool isEmpty();
    bool isFull();
    void Imprimir();
    void Vaciar();
};


#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<iostream>
#include<stdio.h>
#include<fstream>
#include <string>
#include <sstream>
#include <QApplication>

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


Clista::Clista()
{
    Inicio = new Neurona;
    Final = new Neurona;

    Inicio->pSig = Final;
    Final->pAnt = Inicio;

    Final->pSig = NULL;
    Inicio->pAnt = NULL;
}

Clista::~Clista()
{
    Vaciar();
}

void Clista::InsertarInicio(int id,float voltaje,int pos_x,int pos_y,int red,int green,int blue)
{

    Inicio->InsertarAdelantefloat(id,voltaje,pos_x,pos_y,red,green,blue);

}

void Clista::InsertarFinal(int id,float voltaje,int pos_x,int pos_y,int red,int green,int blue)
{

    Final->pAnt->InsertarAdelantefloat(id,voltaje,pos_x,pos_y,red,green,blue);
}

float Clista::EliminarInicio()
{

    Inicio->pSig->pSig->EliminarSiguiente();

    return 0;
}

float Clista::EliminarFinal()
{

    Final->EliminarSiguiente();

    return 0;
}

bool Clista::isEmpty()
{
    return Inicio->pSig == Final;
}

void Clista::Imprimir()
{
    Neurona* Pnn = Inicio->pSig;

    while (Pnn != Final)
    {
        cout << Pnn->Id << " ";
        cout << Pnn->Voltaje << " ";
        cout << Pnn->Pos_x << " ";
        cout << Pnn->Pos_y << " ";
        cout << Pnn->Red << " ";
        cout << Pnn->Green << " ";
        cout << Pnn->Blue << " ||";
        Pnn = Pnn->pSig;
    }
}

int Clista::Tamanio()
{
    Neurona* Pnn = Inicio->pSig;
    int l = 0;

    while (Pnn != Final)
    {
        l++;
        Pnn = Pnn->pSig;
    }
    return l;
}

bool Clista::isFull()
{
    return false;
}

void Clista::Vaciar()
{
    Inicio->pSig = Final;
    Final->pAnt = Inicio;
}

void Neurona::InsertarAdelantefloat(int id,float voltaje,int pos_x,int pos_y,int red,int green,int blue)
{
    Neurona* Pnn = new Neurona;
    Pnn->Id = id;
    Pnn->Voltaje = voltaje;
    Pnn->Pos_x = pos_x;
    Pnn->Pos_y = pos_y;
    Pnn->Red = red;
    Pnn->Green = green;
    Pnn->Blue = blue;

    Pnn->pAnt = this;
    this->pSig->pAnt = Pnn;
    Pnn->pSig = this->pSig;
    this->pSig = Pnn;
}

float Neurona::EliminarSiguiente()
{
    Neurona* Pnn = this->pAnt->pAnt;

    delete this->pAnt;

    this->pAnt = Pnn;
    Pnn->pSig = this;

    return 0;

}

int main()
{
    Clista P;
    int Resultado = 0;
    bool boolean = true;
    bool booleanFull = true;

    cout <<"\nInsertamos 2 veces al Inicio..."<<endl;
    P.InsertarInicio(218,5.1,4,7,255,255,255);
    P.InsertarInicio(234,4.6,2,8,125,125,125);
    P.Imprimir();
    cout <<"\nInsertamos 1 vez al Final..."<<endl;
    P.InsertarFinal(440,21.4,12,5,245,27,124);
    P.Imprimir();

    Resultado = P.Tamanio();
    cout << "\n Tamanio: " << Resultado;

    P.EliminarInicio();
    cout << "\n\t Eliminar Inicio: ";
    P.Imprimir();

    P.EliminarFinal();
    cout << "\n\t Eliminar Final: ";
    P.Imprimir();

    return 0;
}


void MainWindow::on_pushButton_clicked()
{
    QString id = ui->datoN->text();
    id = setText();
    Clista* P;

    P->InsertarInicio(id);

}






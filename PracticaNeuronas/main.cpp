#include "mainwindow.h"
#include<iostream>
#include<stdio.h>
#include<fstream>
#include <string>
#include <sstream>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

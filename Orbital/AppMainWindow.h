#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AppMainWindow.h"

class AppMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    AppMainWindow(QWidget *parent = Q_NULLPTR);

private:
    Ui::AppMainWindowClass ui;
};

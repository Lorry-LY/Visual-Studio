#pragma once

#include <QtWidgets/QWidget>
#include "ui_qt_setup2.h"

class Qt_setup2 : public QWidget
{
    Q_OBJECT

public:
    Qt_setup2(QWidget *parent = Q_NULLPTR);

private:
    Ui::Qt_setup2Class ui;
};

#pragma once

#include<QtWidgets/qwidget.h>

#include"QtUiTools/5.14.2/QtUiTools/private/quiloader_p.h"
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace cv;

class Widget:public QWidget
{
	Q_OBJECT;

public:
	Widget(QWidget *parent=Q_NULLPTR);
	~Widget();


public slots:
	void on_pushButton_clicked();

private:
	

};

Widget::Widget()
{
}

Widget::~Widget()
{
}
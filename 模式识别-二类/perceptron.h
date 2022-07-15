#pragma once

#include"mnist.h"


Mat train_perceptron(Mat& images, Mat& labels);

float testImage(Mat& images, Mat& labels, Mat& w);
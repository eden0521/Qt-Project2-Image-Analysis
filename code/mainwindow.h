#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPixmap>
#include <QDebug>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QString>
#include <QFileDialog>
#include <cstdio>
#include <opencv2/opencv.hpp>
#include <time.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QImage convertProcess(cv::Mat image);
    QImage convertGrayProcess(cv::Mat image);

private slots:
    void on_OpenImageButton_clicked();

    void on_GrayButton_clicked();

    void on_ClearProcessingButton_clicked();

    void on_EqhistButton_clicked();

    void on_CloseAppButton_clicked();

    void on_BlurButton_clicked();

    void on_MedianBlurButton_clicked();

    void on_GaussianBlurButton_clicked();

    void on_BilateralBlurButton_clicked();

    void on_ThresholdButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_ThresholdOtsuButton_clicked();

    void on_DilateButton_clicked();

    void on_ErodeButton_clicked();

    void on_OpenButton_clicked();

    void on_ClosingButton_clicked();

    void on_GradientButton_clicked();

    void on_TopHatButton_clicked();

    void on_BlackHatButton_clicked();

private:
    Ui::MainWindow *ui;
    QString s;  //image dir
    int thresholdValue;
    double ClockStart;
    double ClockEnd;
    QString Clockms;
};

#endif // MAINWINDOW_H

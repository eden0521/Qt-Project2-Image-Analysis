#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;
using namespace cv;

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

QImage MainWindow::convertProcess(cv::Mat image)
{
    if(image.type() == CV_8UC1)
    {
        return QImage((unsigned char * )image.data, image.cols, image.rows, image.step, QImage::Format_Indexed8);
    }
    else
    {
        cv::cvtColor(image, image, CV_BGR2RGB);
        return QImage((unsigned char * )image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
    }
}

void MainWindow::on_OpenImageButton_clicked()
{
    ClockStart = clock();

    s = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home/ubuntu/pj2", tr("Image Files (*.png *.jpg *.bmp)"));
    cv::Mat image = cv::imread(s.toStdString());
    QImage myShowImage;
    myShowImage = convertProcess(image);
    ui->OriginalImage->setPixmap(QPixmap::fromImage(myShowImage).scaled(this->ui->OriginalImage->size()));

    ClockEnd = clock();
    Clockms = QString::number(ClockEnd - ClockStart);
    ui->msTime->setText(Clockms);
}

void MainWindow::on_GrayButton_clicked()
{
    ClockStart = clock();

    cv::Mat imageGray = cv::imread(s.toStdString(),CV_LOAD_IMAGE_GRAYSCALE);
    //cv::cvtColor(imageGray, imageGray, CV_BGR2GRAY);
    QImage myShowImageGray;
    myShowImageGray = convertProcess(imageGray);
    ui->GrayImage->setPixmap(QPixmap::fromImage(myShowImageGray).scaled(this->ui->GrayImage->size()));

    ClockEnd = clock();
    Clockms = QString::number(ClockEnd - ClockStart);
    ui->msTime->setText(Clockms);
}

void MainWindow::on_EqhistButton_clicked()  // PPT P.36
{
    ClockStart = clock();

    cv::Mat imageHist = cv::imread(s.toStdString(),CV_LOAD_IMAGE_GRAYSCALE);
    //cv::cvtColor(imageHist, imageHist, CV_BGR2GRAY);
    cv::equalizeHist(imageHist, imageHist);
    QImage myShowImageHist;
    myShowImageHist = convertProcess(imageHist);
    ui->GrayImage->setPixmap(QPixmap::fromImage(myShowImageHist).scaled(this->ui->GrayImage->size()));

    ClockEnd = clock();
    Clockms = QString::number(ClockEnd - ClockStart);
    ui->msTime->setText(Clockms);
}

void MainWindow::on_ClearProcessingButton_clicked()
{
    ClockStart = clock();

    ui->GrayImage->setText(" ");
    ui->DenoiseImage->setText(" ");
    ui->ThresholdImage->setText(" ");
    ui->MorphologyImage->setText(" ");

    ClockEnd = clock();
    Clockms = QString::number(ClockEnd - ClockStart);
    ui->msTime->setText(Clockms);
}

void MainWindow::on_CloseAppButton_clicked()
{
    close();
}

void MainWindow::on_BlurButton_clicked()  // PPT P.51
{
    ClockStart = clock();

    cv::Mat imageBlur = cv::imread(s.toStdString(),CV_LOAD_IMAGE_GRAYSCALE);
    //cv::cvtColor(imageBlur, imageBlur, CV_BGR2GRAY);
    cv::blur(imageBlur, imageBlur, Size(3,3), cv::Point(-1, -1), BORDER_DEFAULT);
    QImage myShowImageBlur;
    myShowImageBlur = convertProcess(imageBlur);
    ui->DenoiseImage->setPixmap(QPixmap::fromImage(myShowImageBlur).scaled(this->ui->DenoiseImage->size()));

    ClockEnd = clock();
    Clockms = QString::number(ClockEnd - ClockStart);
    ui->msTime->setText(Clockms);
}

void MainWindow::on_MedianBlurButton_clicked()  // PPT P.55
{
    ClockStart = clock();

    cv::Mat imageMedianBlur = cv::imread(s.toStdString(),CV_LOAD_IMAGE_GRAYSCALE);
    //cv::cvtColor(imageMedianBlur, imageMedianBlur, CV_BGR2GRAY);
    cv::medianBlur(imageMedianBlur, imageMedianBlur, 5);
    QImage myShowImageMedianBlur;
    myShowImageMedianBlur = convertProcess(imageMedianBlur);
    ui->DenoiseImage->setPixmap(QPixmap::fromImage(myShowImageMedianBlur).scaled(this->ui->DenoiseImage->size()));

    ClockEnd = clock();
    Clockms = QString::number(ClockEnd - ClockStart);
    ui->msTime->setText(Clockms);
}

void MainWindow::on_GaussianBlurButton_clicked() // PPT P.62
{
    ClockStart = clock();

    cv::Mat imageGaussianBlur = cv::imread(s.toStdString(),CV_LOAD_IMAGE_GRAYSCALE);
    //cv::cvtColor(imageGaussianBlur, imageGaussianBlur, CV_BGR2GRAY);
    cv::GaussianBlur(imageGaussianBlur, imageGaussianBlur, Size(3,3) ,0 ,0);
    QImage myShowImageGaussianBlur;
    myShowImageGaussianBlur = convertProcess(imageGaussianBlur);
    ui->DenoiseImage->setPixmap(QPixmap::fromImage(myShowImageGaussianBlur).scaled(this->ui->DenoiseImage->size()));

    ClockEnd = clock();
    Clockms = QString::number(ClockEnd - ClockStart);
    ui->msTime->setText(Clockms);
}


void MainWindow::on_BilateralBlurButton_clicked() //not yet PPT P.73
{
    ClockStart = clock();

    cv::Mat imageBilateralBlur = cv::imread(s.toStdString(),CV_LOAD_IMAGE_GRAYSCALE);
    cv::Mat imageBilateralBlur_1 = Mat::zeros(imageBilateralBlur.rows, imageBilateralBlur.cols, imageBilateralBlur.type());
    cv::bilateralFilter(imageBilateralBlur, imageBilateralBlur_1, 5 ,30, 30);
    QImage myShowImageBilateralBlur;
    myShowImageBilateralBlur = convertProcess(imageBilateralBlur_1);
    ui->DenoiseImage->setPixmap(QPixmap::fromImage(myShowImageBilateralBlur).scaled(this->ui->DenoiseImage->size()));

    ClockEnd = clock();
    Clockms = QString::number(ClockEnd - ClockStart);
    ui->msTime->setText(Clockms);
}

void MainWindow::on_ThresholdButton_clicked()  // PPT P.27
{
    ClockStart = clock();

    cv::Mat imageThreshold = cv::imread(s.toStdString(),CV_LOAD_IMAGE_GRAYSCALE);
    //cv::cvtColor(imageThreshold, imageThreshold, CV_BGR2GRAY);
    cv::threshold(imageThreshold, imageThreshold, thresholdValue, 255, CV_THRESH_BINARY);
    QImage myShowImageThreshold;
    myShowImageThreshold = convertProcess(imageThreshold);
    ui->ThresholdImage->setPixmap(QPixmap::fromImage(myShowImageThreshold).scaled(this->ui->ThresholdImage->size()));

    ClockEnd = clock();
    Clockms = QString::number(ClockEnd - ClockStart);
    ui->msTime->setText(Clockms);
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QString str = arg1;    

    int valueCompare = str.toInt();

    if(valueCompare > 255)
    {
        ui->lineEdit->setText("255");
    }
    else if(valueCompare < 0)
    {
        ui->lineEdit->setText("0");
    }

    thresholdValue = valueCompare;
}

void MainWindow::on_ThresholdOtsuButton_clicked() // PPT P.45
{
    ClockStart = clock();

    cv::Mat imageThresholdOtsu = cv::imread(s.toStdString(),CV_LOAD_IMAGE_GRAYSCALE);
    //cv::cvtColor(imageThresholdOtsu, imageThresholdOtsu, CV_BGR2GRAY);
    cv::threshold(imageThresholdOtsu, imageThresholdOtsu, thresholdValue, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    QImage myShowImageThresholdOtsu;
    myShowImageThresholdOtsu = convertProcess(imageThresholdOtsu);
    ui->ThresholdImage->setPixmap(QPixmap::fromImage(myShowImageThresholdOtsu).scaled(this->ui->ThresholdImage->size()));

    ClockEnd = clock();
    Clockms = QString::number(ClockEnd - ClockStart);
    ui->msTime->setText(Clockms);
}

void MainWindow::on_DilateButton_clicked() //not yet PPT P.80
{
    ClockStart = clock();

    cv::Mat imageDilate = cv::imread(s.toStdString(),CV_LOAD_IMAGE_GRAYSCALE);
    //threshold(imageThreshold, imageThreshold, thresholdValue, 255, CV_THRESH_BINARY);
    cv::threshold(imageDilate, imageDilate, thresholdValue, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    dilate(imageDilate, imageDilate, Mat(), Point(-1,-1), 3);
    QImage myShowImageDilate;
    myShowImageDilate = convertProcess(imageDilate);
    ui->MorphologyImage->setPixmap(QPixmap::fromImage(myShowImageDilate).scaled(this->ui->MorphologyImage->size()));

    ClockEnd = clock();
    Clockms = QString::number(ClockEnd - ClockStart);
    ui->msTime->setText(Clockms);
}

void MainWindow::on_ErodeButton_clicked() //not yet PPT P.86
{
    ClockStart = clock();

    cv::Mat imageErode = cv::imread(s.toStdString(),CV_LOAD_IMAGE_GRAYSCALE);
    //threshold(imageThreshold, imageThreshold, thresholdValue, 255, CV_THRESH_BINARY);
    cv::threshold(imageErode, imageErode, thresholdValue, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    erode(imageErode, imageErode, Mat(), Point(-1,-1), 3);
    QImage myShowImageErode;
    myShowImageErode = convertProcess(imageErode);
    ui->MorphologyImage->setPixmap(QPixmap::fromImage(myShowImageErode).scaled(this->ui->MorphologyImage->size()));

    ClockEnd = clock();
    Clockms = QString::number(ClockEnd - ClockStart);
    ui->msTime->setText(Clockms);
}

void MainWindow::on_OpenButton_clicked() // PPT P.91
{
    ClockStart = clock();

    cv::Mat imageOpen = cv::imread(s.toStdString(),CV_LOAD_IMAGE_GRAYSCALE);
    //cv::cvtColor(imageOpen, imageOpen, CV_BGR2GRAY);
    //cv::Mat imageOpen_1 = Mat::zeros(imageOpen.rows, imageOpen.cols, imageOpen.type());
    morphologyEx(imageOpen, imageOpen, MORPH_OPEN, Mat(), Point(-1,-1), 3);
    QImage myShowImageOpen;
    myShowImageOpen = convertProcess(imageOpen);
    ui->MorphologyImage->setPixmap(QPixmap::fromImage(myShowImageOpen).scaled(this->ui->MorphologyImage->size()));

    ClockEnd = clock();
    Clockms = QString::number(ClockEnd - ClockStart);
    ui->msTime->setText(Clockms);
}

void MainWindow::on_ClosingButton_clicked() // PPT P.91
{
    ClockStart = clock();

    cv::Mat imageClosing = cv::imread(s.toStdString(),CV_LOAD_IMAGE_GRAYSCALE);
    //cv::Mat imageClosing_1 = Mat::zeros(imageClosing.rows, imageClosing.cols, imageClosing.type());
    cv::threshold(imageClosing, imageClosing, thresholdValue, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    morphologyEx(imageClosing, imageClosing, MORPH_CLOSE, Mat(), Point(-1,-1), 3);
    QImage myShowImageClosing;
    myShowImageClosing = convertProcess(imageClosing);
    ui->MorphologyImage->setPixmap(QPixmap::fromImage(myShowImageClosing).scaled(this->ui->MorphologyImage->size()));

    ClockEnd = clock();
    Clockms = QString::number(ClockEnd - ClockStart);
    ui->msTime->setText(Clockms);
}

void MainWindow::on_GradientButton_clicked() // PPT P.91
{
    ClockStart = clock();

    cv::Mat imageGradient = cv::imread(s.toStdString(),CV_LOAD_IMAGE_GRAYSCALE);
    //cv::Mat imageGradient_1 = Mat::zeros(imageGradient.rows, imageGradient.cols, imageGradient.type());
    cv::threshold(imageGradient, imageGradient, thresholdValue, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    morphologyEx(imageGradient, imageGradient, MORPH_GRADIENT, Mat(), Point(-1,-1), 3);
    QImage myShowImageGradient;
    myShowImageGradient = convertProcess(imageGradient);
    ui->MorphologyImage->setPixmap(QPixmap::fromImage(myShowImageGradient).scaled(this->ui->MorphologyImage->size()));

    ClockEnd = clock();
    Clockms = QString::number(ClockEnd - ClockStart);
    ui->msTime->setText(Clockms);
}

void MainWindow::on_TopHatButton_clicked() // PPT P.91
{
    ClockStart = clock();

    cv::Mat imageTopHat = cv::imread(s.toStdString(),CV_LOAD_IMAGE_GRAYSCALE);
    //cv::Mat imageTopHat_1 = Mat::zeros(imageTopHat.rows, imageTopHat.cols, imageTopHat.type());
    cv::threshold(imageTopHat, imageTopHat, thresholdValue, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    morphologyEx(imageTopHat, imageTopHat, MORPH_TOPHAT, Mat(), Point(-1,-1), 3);
    QImage myShowImageTopHat;
    myShowImageTopHat = convertProcess(imageTopHat);
    ui->MorphologyImage->setPixmap(QPixmap::fromImage(myShowImageTopHat).scaled(this->ui->MorphologyImage->size()));

    ClockEnd = clock();
    Clockms = QString::number(ClockEnd - ClockStart);
    ui->msTime->setText(Clockms);
}

void MainWindow::on_BlackHatButton_clicked() // PPT P.91
{
    ClockStart = clock();

    cv::Mat imageBlackHat = cv::imread(s.toStdString(),CV_LOAD_IMAGE_GRAYSCALE);
    cv::Mat imageBlackHat_1 = Mat::zeros(imageBlackHat.rows, imageBlackHat.cols, imageBlackHat.type());
    morphologyEx(imageBlackHat, imageBlackHat, MORPH_BLACKHAT, Mat(), Point(-1,-1), 3);
    QImage myShowImageBlackHat;
    myShowImageBlackHat = convertProcess(imageBlackHat);
    ui->MorphologyImage->setPixmap(QPixmap::fromImage(myShowImageBlackHat).scaled(this->ui->MorphologyImage->size()));

    ClockEnd = clock();
    Clockms = QString::number(ClockEnd - ClockStart);
    ui->msTime->setText(Clockms);

}

#-------------------------------------------------
#
# Project created by QtCreator 2018-10-06T22:08:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pj2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


INCLUDEPATH += /usr/include

LIBS +=/usr/local/lib/libopencv_imgproc.so \
/usr/local/lib/libopencv_highgui.so \
/usr/local/lib/libopencv_core.so \
/usr/local/lib/libopencv_calib3d.so \
/usr/local/lib/libopencv_ml.so \
/usr/local/lib/libopencv_contrib.so \
/usr/local/lib/libopencv_photo.so \
/usr/local/lib/libopencv_legacy.so \
/usr/local/lib/libopencv_stitching.so \
/usr/local/lib/libopencv_features2d.so \
/usr/local/lib/libopencv_flann.so \
/usr/local/lib/libopencv_objdetect.so \
/usr/local/lib/libopencv_gpu.so \
/usr/local/lib/libopencv_video.so \
/usr/local/lib/libopencv_videostab.so \
/usr/local/lib/libopencv_superres.so

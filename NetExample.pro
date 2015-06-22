!include("../Common/retroshare_plugin.pri"): error("Could not include file ../Common/retroshare_plugin.pri")

greaterThan(QT_MAJOR_VERSION, 4) {
	# Qt 5
	QT += widgets
}

exists($$[QMAKE_MKSPECS]/features/mobility.prf) {
  CONFIG += mobility
} else {
  QT += multimedia
}
CONFIG += qt uic qrc resources
MOBILITY = multimedia

DEPENDPATH += ../../retroshare-gui/src/temp/ui ../../libretroshare/src
INCLUDEPATH += ../../retroshare-gui/src/temp/ui ../../libretroshare/src

#################################### Windows #####################################

linux-* {
	INCLUDEPATH += /usr/include
	LIBS += $$system(pkg-config --libs opencv)
}

win32 {
	LIBS_DIR = $$PWD/../../../libs
	LIBS += -L"$$LIBS_DIR/lib/opencv"

	OPENCV_VERSION = 249
	LIBS += -lopencv_core$$OPENCV_VERSION -lopencv_highgui$$OPENCV_VERSION -lopencv_imgproc$$OPENCV_VERSION -llibjpeg -llibtiff -llibpng -llibjasper -lIlmImf -lole32 -loleaut32 -luuid -lavicap32 -lavifil32 -lvfw32 -lz
}

QMAKE_CXXFLAGS *= -Wall

SOURCES = NetExamplePlugin.cpp               \
          services/p3NetExample.cc           \
          services/rsNetExampleItems.cc \
    gui/NEMainpage.cpp \
    gui/NetExampleNotify.cpp \
    gui/paintwidget.cpp

HEADERS = NetExamplePlugin.h                 \
          services/p3NetExample.h            \
          services/rsNetExampleItems.h       \
          interface/rsNetExample.h \
    gui/NEMainpage.h \
    gui/NetExampleNotify.h \
    gui/paintwidget.h

#FORMS   = gui/AudioInputConfig.ui

TARGET = NetExample

RESOURCES = gui/NetExample_images.qrc


LIBS += -lspeex -lspeexdsp

FORMS += \
    gui/NEMainpage.ui

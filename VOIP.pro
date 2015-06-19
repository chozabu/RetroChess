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

SOURCES = VOIPPlugin.cpp               \
          services/p3VOIP.cc           \
          services/rsVOIPItems.cc

HEADERS = VOIPPlugin.h                 \
          services/p3VOIP.h            \
          services/rsVOIPItems.h       \
          interface/rsVOIP.h

#FORMS   = gui/AudioInputConfig.ui

TARGET = VOIP

RESOURCES = gui/VOIP_images.qrc lang/VOIP_lang.qrc

TRANSLATIONS +=  \
            lang/VOIP_ca_ES.ts \
            lang/VOIP_cs.ts \
            lang/VOIP_da.ts \
            lang/VOIP_de.ts \
            lang/VOIP_el.ts \
            lang/VOIP_en.ts \
            lang/VOIP_es.ts \
            lang/VOIP_fi.ts \
            lang/VOIP_fr.ts \
            lang/VOIP_hu.ts \
            lang/VOIP_it.ts \
            lang/VOIP_ja_JP.ts \
            lang/VOIP_ko.ts \
            lang/VOIP_nl.ts \
            lang/VOIP_pl.ts \
            lang/VOIP_ru.ts \
            lang/VOIP_sv.ts \
            lang/VOIP_tr.ts \
            lang/VOIP_zh_CN.ts

LIBS += -lspeex -lspeexdsp

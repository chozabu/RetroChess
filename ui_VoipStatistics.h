/********************************************************************************
** Form generated from reading UI file 'VoipStatistics.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOIPSTATISTICS_H
#define UI_VOIPSTATISTICS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QScrollArea>
#include <QtGui/QSplitter>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VoipStatistics
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QScrollArea *_tunnel_statistics_F;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *VoipStatistics)
    {
        if (VoipStatistics->objectName().isEmpty())
            VoipStatistics->setObjectName(QString::fromUtf8("VoipStatistics"));
        VoipStatistics->resize(611, 408);
        gridLayout = new QGridLayout(VoipStatistics);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter = new QSplitter(VoipStatistics);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        _tunnel_statistics_F = new QScrollArea(splitter);
        _tunnel_statistics_F->setObjectName(QString::fromUtf8("_tunnel_statistics_F"));
        _tunnel_statistics_F->setFrameShape(QFrame::NoFrame);
        _tunnel_statistics_F->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        _tunnel_statistics_F->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 587, 384));
        _tunnel_statistics_F->setWidget(scrollAreaWidgetContents);
        splitter->addWidget(_tunnel_statistics_F);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);


        retranslateUi(VoipStatistics);

        QMetaObject::connectSlotsByName(VoipStatistics);
    } // setupUi

    void retranslateUi(QWidget *VoipStatistics)
    {
        VoipStatistics->setWindowTitle(QApplication::translate("VoipStatistics", "VoipTest Statistics", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VoipStatistics: public Ui_VoipStatistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOIPSTATISTICS_H

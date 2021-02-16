/********************************************************************************
** Form generated from reading UI file 'PlotEditorDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTEDITORDIALOG_H
#define UI_PLOTEDITORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlotEditorDialog
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QFrame *frame_globalSettings;
    QVBoxLayout *verticalLayout_globalSettings;
    QLabel *label_globalSettings;
    QFrame *frame_globalSettings_minSize;
    QHBoxLayout *horizontalLayout_globalSettings_minSize;
    QFrame *frame_plotMinWidth;
    QHBoxLayout *horizontalLayout_plotMinWidth;
    QLabel *label_plotMinWidth;
    QLineEdit *lineEdit_plotMinWidth;
    QFrame *frame_plotMinHeight;
    QHBoxLayout *horizontalLayout_plotMinHeight;
    QLabel *label_plotMinHeight;
    QLineEdit *lineEdit_plotMinHeight;
    QSpacerItem *horizontalSpacer;
    QFrame *frame_gridControls;
    QHBoxLayout *horizontalLayout_gridControls;
    QSpacerItem *horizontalSpacer_gridControls;
    QLabel *label_arrangementSet;
    QPushButton *pushButton_apply;
    QPushButton *pushButton_gridArrangement;
    QFrame *frame_controls;
    QHBoxLayout *horizontalLayout_controls;
    QSpacerItem *horizontalSpacer_controls;
    QPushButton *pushButton_save;
    QPushButton *pushButton_cancel;
    QFrame *frame_plotSettings;
    QVBoxLayout *verticalLayout_plotSettings;
    QLabel *label_plotSettings;
    QTabWidget *tabWidget_plotSettings;

    void setupUi(QDialog *PlotEditorDialog)
    {
        if (PlotEditorDialog->objectName().isEmpty())
            PlotEditorDialog->setObjectName(QString::fromUtf8("PlotEditorDialog"));
        PlotEditorDialog->resize(820, 616);
        verticalLayout = new QVBoxLayout(PlotEditorDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(PlotEditorDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 818, 614));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame_globalSettings = new QFrame(scrollAreaWidgetContents);
        frame_globalSettings->setObjectName(QString::fromUtf8("frame_globalSettings"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_globalSettings->sizePolicy().hasHeightForWidth());
        frame_globalSettings->setSizePolicy(sizePolicy);
        frame_globalSettings->setAutoFillBackground(true);
        frame_globalSettings->setFrameShape(QFrame::StyledPanel);
        frame_globalSettings->setFrameShadow(QFrame::Plain);
        verticalLayout_globalSettings = new QVBoxLayout(frame_globalSettings);
        verticalLayout_globalSettings->setSpacing(6);
        verticalLayout_globalSettings->setContentsMargins(11, 11, 11, 11);
        verticalLayout_globalSettings->setObjectName(QString::fromUtf8("verticalLayout_globalSettings"));
        label_globalSettings = new QLabel(frame_globalSettings);
        label_globalSettings->setObjectName(QString::fromUtf8("label_globalSettings"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_globalSettings->sizePolicy().hasHeightForWidth());
        label_globalSettings->setSizePolicy(sizePolicy1);
        label_globalSettings->setMinimumSize(QSize(0, 32));
        label_globalSettings->setMaximumSize(QSize(16777215, 32));
        QFont font;
        font.setPointSize(10);
        label_globalSettings->setFont(font);
        label_globalSettings->setFrameShape(QFrame::Panel);
        label_globalSettings->setFrameShadow(QFrame::Raised);
        label_globalSettings->setAlignment(Qt::AlignCenter);

        verticalLayout_globalSettings->addWidget(label_globalSettings);

        frame_globalSettings_minSize = new QFrame(frame_globalSettings);
        frame_globalSettings_minSize->setObjectName(QString::fromUtf8("frame_globalSettings_minSize"));
        sizePolicy1.setHeightForWidth(frame_globalSettings_minSize->sizePolicy().hasHeightForWidth());
        frame_globalSettings_minSize->setSizePolicy(sizePolicy1);
        frame_globalSettings_minSize->setFrameShape(QFrame::StyledPanel);
        frame_globalSettings_minSize->setFrameShadow(QFrame::Plain);
        horizontalLayout_globalSettings_minSize = new QHBoxLayout(frame_globalSettings_minSize);
        horizontalLayout_globalSettings_minSize->setSpacing(6);
        horizontalLayout_globalSettings_minSize->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_globalSettings_minSize->setObjectName(QString::fromUtf8("horizontalLayout_globalSettings_minSize"));
        horizontalLayout_globalSettings_minSize->setContentsMargins(0, 0, 0, 0);
        frame_plotMinWidth = new QFrame(frame_globalSettings_minSize);
        frame_plotMinWidth->setObjectName(QString::fromUtf8("frame_plotMinWidth"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_plotMinWidth->sizePolicy().hasHeightForWidth());
        frame_plotMinWidth->setSizePolicy(sizePolicy2);
        frame_plotMinWidth->setFrameShape(QFrame::StyledPanel);
        frame_plotMinWidth->setFrameShadow(QFrame::Raised);
        horizontalLayout_plotMinWidth = new QHBoxLayout(frame_plotMinWidth);
        horizontalLayout_plotMinWidth->setSpacing(4);
        horizontalLayout_plotMinWidth->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_plotMinWidth->setObjectName(QString::fromUtf8("horizontalLayout_plotMinWidth"));
        label_plotMinWidth = new QLabel(frame_plotMinWidth);
        label_plotMinWidth->setObjectName(QString::fromUtf8("label_plotMinWidth"));
        sizePolicy2.setHeightForWidth(label_plotMinWidth->sizePolicy().hasHeightForWidth());
        label_plotMinWidth->setSizePolicy(sizePolicy2);
        label_plotMinWidth->setMinimumSize(QSize(89, 0));
        label_plotMinWidth->setFont(font);

        horizontalLayout_plotMinWidth->addWidget(label_plotMinWidth);

        lineEdit_plotMinWidth = new QLineEdit(frame_plotMinWidth);
        lineEdit_plotMinWidth->setObjectName(QString::fromUtf8("lineEdit_plotMinWidth"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEdit_plotMinWidth->sizePolicy().hasHeightForWidth());
        lineEdit_plotMinWidth->setSizePolicy(sizePolicy3);
        lineEdit_plotMinWidth->setMinimumSize(QSize(64, 0));
        lineEdit_plotMinWidth->setMaximumSize(QSize(64, 16777215));

        horizontalLayout_plotMinWidth->addWidget(lineEdit_plotMinWidth);


        horizontalLayout_globalSettings_minSize->addWidget(frame_plotMinWidth);

        frame_plotMinHeight = new QFrame(frame_globalSettings_minSize);
        frame_plotMinHeight->setObjectName(QString::fromUtf8("frame_plotMinHeight"));
        sizePolicy2.setHeightForWidth(frame_plotMinHeight->sizePolicy().hasHeightForWidth());
        frame_plotMinHeight->setSizePolicy(sizePolicy2);
        frame_plotMinHeight->setFrameShape(QFrame::StyledPanel);
        frame_plotMinHeight->setFrameShadow(QFrame::Raised);
        horizontalLayout_plotMinHeight = new QHBoxLayout(frame_plotMinHeight);
        horizontalLayout_plotMinHeight->setSpacing(4);
        horizontalLayout_plotMinHeight->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_plotMinHeight->setObjectName(QString::fromUtf8("horizontalLayout_plotMinHeight"));
        label_plotMinHeight = new QLabel(frame_plotMinHeight);
        label_plotMinHeight->setObjectName(QString::fromUtf8("label_plotMinHeight"));
        sizePolicy2.setHeightForWidth(label_plotMinHeight->sizePolicy().hasHeightForWidth());
        label_plotMinHeight->setSizePolicy(sizePolicy2);
        label_plotMinHeight->setMinimumSize(QSize(91, 0));
        label_plotMinHeight->setFont(font);

        horizontalLayout_plotMinHeight->addWidget(label_plotMinHeight);

        lineEdit_plotMinHeight = new QLineEdit(frame_plotMinHeight);
        lineEdit_plotMinHeight->setObjectName(QString::fromUtf8("lineEdit_plotMinHeight"));
        sizePolicy3.setHeightForWidth(lineEdit_plotMinHeight->sizePolicy().hasHeightForWidth());
        lineEdit_plotMinHeight->setSizePolicy(sizePolicy3);
        lineEdit_plotMinHeight->setMinimumSize(QSize(64, 0));
        lineEdit_plotMinHeight->setMaximumSize(QSize(64, 16777215));

        horizontalLayout_plotMinHeight->addWidget(lineEdit_plotMinHeight);


        horizontalLayout_globalSettings_minSize->addWidget(frame_plotMinHeight);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_globalSettings_minSize->addItem(horizontalSpacer);


        verticalLayout_globalSettings->addWidget(frame_globalSettings_minSize);

        frame_gridControls = new QFrame(frame_globalSettings);
        frame_gridControls->setObjectName(QString::fromUtf8("frame_gridControls"));
        sizePolicy1.setHeightForWidth(frame_gridControls->sizePolicy().hasHeightForWidth());
        frame_gridControls->setSizePolicy(sizePolicy1);
        frame_gridControls->setFrameShape(QFrame::NoFrame);
        frame_gridControls->setFrameShadow(QFrame::Raised);
        horizontalLayout_gridControls = new QHBoxLayout(frame_gridControls);
        horizontalLayout_gridControls->setSpacing(4);
        horizontalLayout_gridControls->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_gridControls->setObjectName(QString::fromUtf8("horizontalLayout_gridControls"));
        horizontalLayout_gridControls->setContentsMargins(-1, 0, 0, 0);
        horizontalSpacer_gridControls = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_gridControls->addItem(horizontalSpacer_gridControls);

        label_arrangementSet = new QLabel(frame_gridControls);
        label_arrangementSet->setObjectName(QString::fromUtf8("label_arrangementSet"));
        label_arrangementSet->setMaximumSize(QSize(24, 24));
        label_arrangementSet->setScaledContents(true);

        horizontalLayout_gridControls->addWidget(label_arrangementSet);

        pushButton_apply = new QPushButton(frame_gridControls);
        pushButton_apply->setObjectName(QString::fromUtf8("pushButton_apply"));

        horizontalLayout_gridControls->addWidget(pushButton_apply);

        pushButton_gridArrangement = new QPushButton(frame_gridControls);
        pushButton_gridArrangement->setObjectName(QString::fromUtf8("pushButton_gridArrangement"));

        horizontalLayout_gridControls->addWidget(pushButton_gridArrangement);


        verticalLayout_globalSettings->addWidget(frame_gridControls);


        gridLayout->addWidget(frame_globalSettings, 0, 1, 1, 1);

        frame_controls = new QFrame(scrollAreaWidgetContents);
        frame_controls->setObjectName(QString::fromUtf8("frame_controls"));
        sizePolicy1.setHeightForWidth(frame_controls->sizePolicy().hasHeightForWidth());
        frame_controls->setSizePolicy(sizePolicy1);
        frame_controls->setMinimumSize(QSize(0, 32));
        frame_controls->setAutoFillBackground(true);
        frame_controls->setFrameShape(QFrame::NoFrame);
        frame_controls->setFrameShadow(QFrame::Raised);
        horizontalLayout_controls = new QHBoxLayout(frame_controls);
        horizontalLayout_controls->setSpacing(6);
        horizontalLayout_controls->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_controls->setObjectName(QString::fromUtf8("horizontalLayout_controls"));
        horizontalLayout_controls->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_controls = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_controls->addItem(horizontalSpacer_controls);

        pushButton_save = new QPushButton(frame_controls);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton_save->sizePolicy().hasHeightForWidth());
        pushButton_save->setSizePolicy(sizePolicy4);
        pushButton_save->setFont(font);

        horizontalLayout_controls->addWidget(pushButton_save);

        pushButton_cancel = new QPushButton(frame_controls);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        sizePolicy4.setHeightForWidth(pushButton_cancel->sizePolicy().hasHeightForWidth());
        pushButton_cancel->setSizePolicy(sizePolicy4);
        pushButton_cancel->setFont(font);

        horizontalLayout_controls->addWidget(pushButton_cancel);


        gridLayout->addWidget(frame_controls, 1, 1, 1, 1);

        frame_plotSettings = new QFrame(scrollAreaWidgetContents);
        frame_plotSettings->setObjectName(QString::fromUtf8("frame_plotSettings"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(frame_plotSettings->sizePolicy().hasHeightForWidth());
        frame_plotSettings->setSizePolicy(sizePolicy5);
        frame_plotSettings->setMinimumSize(QSize(384, 128));
        frame_plotSettings->setMaximumSize(QSize(384, 16777215));
        frame_plotSettings->setAutoFillBackground(true);
        frame_plotSettings->setFrameShape(QFrame::StyledPanel);
        frame_plotSettings->setFrameShadow(QFrame::Plain);
        verticalLayout_plotSettings = new QVBoxLayout(frame_plotSettings);
        verticalLayout_plotSettings->setSpacing(6);
        verticalLayout_plotSettings->setContentsMargins(11, 11, 11, 11);
        verticalLayout_plotSettings->setObjectName(QString::fromUtf8("verticalLayout_plotSettings"));
        label_plotSettings = new QLabel(frame_plotSettings);
        label_plotSettings->setObjectName(QString::fromUtf8("label_plotSettings"));
        sizePolicy1.setHeightForWidth(label_plotSettings->sizePolicy().hasHeightForWidth());
        label_plotSettings->setSizePolicy(sizePolicy1);
        label_plotSettings->setMinimumSize(QSize(0, 32));
        label_plotSettings->setMaximumSize(QSize(16777215, 32));
        label_plotSettings->setFont(font);
        label_plotSettings->setFrameShape(QFrame::Panel);
        label_plotSettings->setFrameShadow(QFrame::Raised);
        label_plotSettings->setAlignment(Qt::AlignCenter);

        verticalLayout_plotSettings->addWidget(label_plotSettings);

        tabWidget_plotSettings = new QTabWidget(frame_plotSettings);
        tabWidget_plotSettings->setObjectName(QString::fromUtf8("tabWidget_plotSettings"));

        verticalLayout_plotSettings->addWidget(tabWidget_plotSettings);


        gridLayout->addWidget(frame_plotSettings, 0, 0, 2, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(PlotEditorDialog);

        tabWidget_plotSettings->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(PlotEditorDialog);
    } // setupUi

    void retranslateUi(QDialog *PlotEditorDialog)
    {
        PlotEditorDialog->setWindowTitle(QApplication::translate("PlotEditorDialog", "Plot Editor", nullptr));
        label_globalSettings->setText(QApplication::translate("PlotEditorDialog", "Global Settings", nullptr));
        label_plotMinWidth->setText(QApplication::translate("PlotEditorDialog", "Minimum Width", nullptr));
        lineEdit_plotMinWidth->setText(QString());
        label_plotMinHeight->setText(QApplication::translate("PlotEditorDialog", "Minimum Height", nullptr));
        lineEdit_plotMinHeight->setText(QString());
        pushButton_apply->setText(QApplication::translate("PlotEditorDialog", "Apply", nullptr));
        pushButton_gridArrangement->setText(QApplication::translate("PlotEditorDialog", "Arrangement", nullptr));
        pushButton_save->setText(QApplication::translate("PlotEditorDialog", "Save", nullptr));
        pushButton_cancel->setText(QApplication::translate("PlotEditorDialog", "Cancel", nullptr));
        label_plotSettings->setText(QApplication::translate("PlotEditorDialog", "Plot Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlotEditorDialog: public Ui_PlotEditorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTEDITORDIALOG_H

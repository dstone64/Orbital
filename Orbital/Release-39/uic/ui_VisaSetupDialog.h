/********************************************************************************
** Form generated from reading UI file 'VisaSetupDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISASETUPDIALOG_H
#define UI_VISASETUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VisaSetupDialog
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_scrollAreaWidgetContents;
    QSpacerItem *verticalSpacer;
    QFrame *frame_controls;
    QHBoxLayout *horizontalLayout_controls;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_save;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *VisaSetupDialog)
    {
        if (VisaSetupDialog->objectName().isEmpty())
            VisaSetupDialog->setObjectName(QString::fromUtf8("VisaSetupDialog"));
        VisaSetupDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(VisaSetupDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(VisaSetupDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 380, 231));
        verticalLayout_scrollAreaWidgetContents = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_scrollAreaWidgetContents->setSpacing(6);
        verticalLayout_scrollAreaWidgetContents->setContentsMargins(11, 11, 11, 11);
        verticalLayout_scrollAreaWidgetContents->setObjectName(QString::fromUtf8("verticalLayout_scrollAreaWidgetContents"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_scrollAreaWidgetContents->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        frame_controls = new QFrame(VisaSetupDialog);
        frame_controls->setObjectName(QString::fromUtf8("frame_controls"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_controls->sizePolicy().hasHeightForWidth());
        frame_controls->setSizePolicy(sizePolicy);
        frame_controls->setFrameShape(QFrame::StyledPanel);
        frame_controls->setFrameShadow(QFrame::Raised);
        horizontalLayout_controls = new QHBoxLayout(frame_controls);
        horizontalLayout_controls->setSpacing(6);
        horizontalLayout_controls->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_controls->setObjectName(QString::fromUtf8("horizontalLayout_controls"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_controls->addItem(horizontalSpacer);

        pushButton_save = new QPushButton(frame_controls);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));

        horizontalLayout_controls->addWidget(pushButton_save);

        pushButton_cancel = new QPushButton(frame_controls);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout_controls->addWidget(pushButton_cancel);


        verticalLayout->addWidget(frame_controls);


        retranslateUi(VisaSetupDialog);

        QMetaObject::connectSlotsByName(VisaSetupDialog);
    } // setupUi

    void retranslateUi(QDialog *VisaSetupDialog)
    {
        VisaSetupDialog->setWindowTitle(QApplication::translate("VisaSetupDialog", "Visa Setup", nullptr));
        pushButton_save->setText(QApplication::translate("VisaSetupDialog", "Save", nullptr));
        pushButton_cancel->setText(QApplication::translate("VisaSetupDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VisaSetupDialog: public Ui_VisaSetupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISASETUPDIALOG_H

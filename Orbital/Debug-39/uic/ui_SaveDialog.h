/********************************************************************************
** Form generated from reading UI file 'SaveDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEDIALOG_H
#define UI_SAVEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SaveDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_dataSelect;
    QHBoxLayout *horizontalLayout_dataSelect;
    QScrollArea *scrollArea_dataSelect;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_dataSelect;
    QSpacerItem *verticalSpacer;
    QLabel *label_error;
    QFrame *frame_controls;
    QHBoxLayout *horizontalLayout_controls;
    QCheckBox *checkBox_timeStamp;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SaveDialog)
    {
        if (SaveDialog->objectName().isEmpty())
            SaveDialog->setObjectName(QString::fromUtf8("SaveDialog"));
        SaveDialog->resize(318, 252);
        verticalLayout = new QVBoxLayout(SaveDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_dataSelect = new QGroupBox(SaveDialog);
        groupBox_dataSelect->setObjectName(QString::fromUtf8("groupBox_dataSelect"));
        QFont font;
        font.setPointSize(10);
        groupBox_dataSelect->setFont(font);
        groupBox_dataSelect->setAutoFillBackground(true);
        horizontalLayout_dataSelect = new QHBoxLayout(groupBox_dataSelect);
        horizontalLayout_dataSelect->setSpacing(6);
        horizontalLayout_dataSelect->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_dataSelect->setObjectName(QString::fromUtf8("horizontalLayout_dataSelect"));
        scrollArea_dataSelect = new QScrollArea(groupBox_dataSelect);
        scrollArea_dataSelect->setObjectName(QString::fromUtf8("scrollArea_dataSelect"));
        scrollArea_dataSelect->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 278, 144));
        verticalLayout_dataSelect = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_dataSelect->setSpacing(2);
        verticalLayout_dataSelect->setContentsMargins(11, 11, 11, 11);
        verticalLayout_dataSelect->setObjectName(QString::fromUtf8("verticalLayout_dataSelect"));
        verticalLayout_dataSelect->setContentsMargins(2, 2, 2, 2);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_dataSelect->addItem(verticalSpacer);

        scrollArea_dataSelect->setWidget(scrollAreaWidgetContents);

        horizontalLayout_dataSelect->addWidget(scrollArea_dataSelect);


        verticalLayout->addWidget(groupBox_dataSelect);

        label_error = new QLabel(SaveDialog);
        label_error->setObjectName(QString::fromUtf8("label_error"));
        label_error->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_error->sizePolicy().hasHeightForWidth());
        label_error->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_error->setFont(font1);
        label_error->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_error);

        frame_controls = new QFrame(SaveDialog);
        frame_controls->setObjectName(QString::fromUtf8("frame_controls"));
        sizePolicy.setHeightForWidth(frame_controls->sizePolicy().hasHeightForWidth());
        frame_controls->setSizePolicy(sizePolicy);
        frame_controls->setFont(font);
        horizontalLayout_controls = new QHBoxLayout(frame_controls);
        horizontalLayout_controls->setSpacing(6);
        horizontalLayout_controls->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_controls->setObjectName(QString::fromUtf8("horizontalLayout_controls"));
        horizontalLayout_controls->setContentsMargins(0, 0, 0, 0);
        checkBox_timeStamp = new QCheckBox(frame_controls);
        checkBox_timeStamp->setObjectName(QString::fromUtf8("checkBox_timeStamp"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBox_timeStamp->sizePolicy().hasHeightForWidth());
        checkBox_timeStamp->setSizePolicy(sizePolicy1);
        checkBox_timeStamp->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_controls->addWidget(checkBox_timeStamp);

        buttonBox = new QDialogButtonBox(frame_controls);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setFont(font);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        horizontalLayout_controls->addWidget(buttonBox);


        verticalLayout->addWidget(frame_controls);


        retranslateUi(SaveDialog);

        QMetaObject::connectSlotsByName(SaveDialog);
    } // setupUi

    void retranslateUi(QDialog *SaveDialog)
    {
        SaveDialog->setWindowTitle(QApplication::translate("SaveDialog", "Save", nullptr));
        groupBox_dataSelect->setTitle(QApplication::translate("SaveDialog", "Select Data To Save", nullptr));
        label_error->setText(QString());
        checkBox_timeStamp->setText(QApplication::translate("SaveDialog", "Time Stamp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SaveDialog: public Ui_SaveDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEDIALOG_H

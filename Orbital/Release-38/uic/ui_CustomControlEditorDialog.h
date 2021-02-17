/********************************************************************************
** Form generated from reading UI file 'CustomControlEditorDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMCONTROLEDITORDIALOG_H
#define UI_CUSTOMCONTROLEDITORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CustomControlEditorDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_customControlNames;
    QGridLayout *gridLayout_customControlNames;
    QSpacerItem *verticalSpacer;
    QFrame *frame_controls;
    QHBoxLayout *horizontalLayout_controls;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_save;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *CustomControlEditorDialog)
    {
        if (CustomControlEditorDialog->objectName().isEmpty())
            CustomControlEditorDialog->setObjectName(QString::fromUtf8("CustomControlEditorDialog"));
        CustomControlEditorDialog->resize(384, 256);
        verticalLayout = new QVBoxLayout(CustomControlEditorDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_customControlNames = new QFrame(CustomControlEditorDialog);
        frame_customControlNames->setObjectName(QString::fromUtf8("frame_customControlNames"));
        frame_customControlNames->setAutoFillBackground(true);
        frame_customControlNames->setFrameShape(QFrame::StyledPanel);
        frame_customControlNames->setFrameShadow(QFrame::Raised);
        gridLayout_customControlNames = new QGridLayout(frame_customControlNames);
        gridLayout_customControlNames->setSpacing(6);
        gridLayout_customControlNames->setContentsMargins(11, 11, 11, 11);
        gridLayout_customControlNames->setObjectName(QString::fromUtf8("gridLayout_customControlNames"));
        gridLayout_customControlNames->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(frame_customControlNames);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        frame_controls = new QFrame(CustomControlEditorDialog);
        frame_controls->setObjectName(QString::fromUtf8("frame_controls"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_controls->sizePolicy().hasHeightForWidth());
        frame_controls->setSizePolicy(sizePolicy);
        frame_controls->setMinimumSize(QSize(0, 32));
        frame_controls->setAutoFillBackground(true);
        frame_controls->setFrameShape(QFrame::NoFrame);
        frame_controls->setFrameShadow(QFrame::Raised);
        horizontalLayout_controls = new QHBoxLayout(frame_controls);
        horizontalLayout_controls->setSpacing(6);
        horizontalLayout_controls->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_controls->setObjectName(QString::fromUtf8("horizontalLayout_controls"));
        horizontalLayout_controls->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_controls->addItem(horizontalSpacer);

        pushButton_save = new QPushButton(frame_controls);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_save->sizePolicy().hasHeightForWidth());
        pushButton_save->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(10);
        pushButton_save->setFont(font);

        horizontalLayout_controls->addWidget(pushButton_save);

        pushButton_cancel = new QPushButton(frame_controls);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        sizePolicy1.setHeightForWidth(pushButton_cancel->sizePolicy().hasHeightForWidth());
        pushButton_cancel->setSizePolicy(sizePolicy1);
        pushButton_cancel->setFont(font);

        horizontalLayout_controls->addWidget(pushButton_cancel);


        verticalLayout->addWidget(frame_controls);


        retranslateUi(CustomControlEditorDialog);

        QMetaObject::connectSlotsByName(CustomControlEditorDialog);
    } // setupUi

    void retranslateUi(QDialog *CustomControlEditorDialog)
    {
        CustomControlEditorDialog->setWindowTitle(QApplication::translate("CustomControlEditorDialog", "Custom Controls Editor", nullptr));
        pushButton_save->setText(QApplication::translate("CustomControlEditorDialog", "Save", nullptr));
        pushButton_cancel->setText(QApplication::translate("CustomControlEditorDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomControlEditorDialog: public Ui_CustomControlEditorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMCONTROLEDITORDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'ModuleInfoDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODULEINFODIALOG_H
#define UI_MODULEINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ModuleInfoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_currentModule;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_currentModule;
    QLineEdit *lineEdit_currentModule;
    QFrame *frame_scriptParameters;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_scriptParameters;
    QPlainTextEdit *plainTextEdit_scriptParameters;

    void setupUi(QDialog *ModuleInfoDialog)
    {
        if (ModuleInfoDialog->objectName().isEmpty())
            ModuleInfoDialog->setObjectName(QString::fromUtf8("ModuleInfoDialog"));
        ModuleInfoDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(ModuleInfoDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_currentModule = new QFrame(ModuleInfoDialog);
        frame_currentModule->setObjectName(QString::fromUtf8("frame_currentModule"));
        frame_currentModule->setFrameShape(QFrame::StyledPanel);
        frame_currentModule->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_currentModule);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_currentModule = new QLabel(frame_currentModule);
        label_currentModule->setObjectName(QString::fromUtf8("label_currentModule"));
        QFont font;
        font.setPointSize(10);
        label_currentModule->setFont(font);

        verticalLayout_2->addWidget(label_currentModule);

        lineEdit_currentModule = new QLineEdit(frame_currentModule);
        lineEdit_currentModule->setObjectName(QString::fromUtf8("lineEdit_currentModule"));
        lineEdit_currentModule->setReadOnly(true);

        verticalLayout_2->addWidget(lineEdit_currentModule);


        verticalLayout->addWidget(frame_currentModule);

        frame_scriptParameters = new QFrame(ModuleInfoDialog);
        frame_scriptParameters->setObjectName(QString::fromUtf8("frame_scriptParameters"));
        frame_scriptParameters->setFrameShape(QFrame::StyledPanel);
        frame_scriptParameters->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_scriptParameters);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_scriptParameters = new QLabel(frame_scriptParameters);
        label_scriptParameters->setObjectName(QString::fromUtf8("label_scriptParameters"));
        label_scriptParameters->setFont(font);

        verticalLayout_3->addWidget(label_scriptParameters);

        plainTextEdit_scriptParameters = new QPlainTextEdit(frame_scriptParameters);
        plainTextEdit_scriptParameters->setObjectName(QString::fromUtf8("plainTextEdit_scriptParameters"));
        plainTextEdit_scriptParameters->setFocusPolicy(Qt::NoFocus);
        plainTextEdit_scriptParameters->setReadOnly(true);

        verticalLayout_3->addWidget(plainTextEdit_scriptParameters);


        verticalLayout->addWidget(frame_scriptParameters);


        retranslateUi(ModuleInfoDialog);

        QMetaObject::connectSlotsByName(ModuleInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *ModuleInfoDialog)
    {
        ModuleInfoDialog->setWindowTitle(QApplication::translate("ModuleInfoDialog", "Module Info", nullptr));
        label_currentModule->setText(QApplication::translate("ModuleInfoDialog", "Current Module File", nullptr));
        label_scriptParameters->setText(QApplication::translate("ModuleInfoDialog", "Script Parameter Dictionary", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModuleInfoDialog: public Ui_ModuleInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULEINFODIALOG_H

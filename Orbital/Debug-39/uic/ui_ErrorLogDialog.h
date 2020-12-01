/********************************************************************************
** Form generated from reading UI file 'ErrorLogDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORLOGDIALOG_H
#define UI_ERRORLOGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ErrorLogDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *ErrorLogDialog)
    {
        if (ErrorLogDialog->objectName().isEmpty())
            ErrorLogDialog->setObjectName(QString::fromUtf8("ErrorLogDialog"));
        ErrorLogDialog->resize(440, 323);
        horizontalLayout = new QHBoxLayout(ErrorLogDialog);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        plainTextEdit = new QPlainTextEdit(ErrorLogDialog);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setFocusPolicy(Qt::NoFocus);
        plainTextEdit->setReadOnly(true);

        horizontalLayout->addWidget(plainTextEdit);


        retranslateUi(ErrorLogDialog);

        QMetaObject::connectSlotsByName(ErrorLogDialog);
    } // setupUi

    void retranslateUi(QDialog *ErrorLogDialog)
    {
        ErrorLogDialog->setWindowTitle(QApplication::translate("ErrorLogDialog", "Error Log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ErrorLogDialog: public Ui_ErrorLogDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORLOGDIALOG_H

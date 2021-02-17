/********************************************************************************
** Form generated from reading UI file 'DataBufferDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABUFFERDIALOG_H
#define UI_DATABUFFERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DataBufferDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *DataBufferDialog)
    {
        if (DataBufferDialog->objectName().isEmpty())
            DataBufferDialog->setObjectName(QString::fromUtf8("DataBufferDialog"));
        DataBufferDialog->resize(400, 300);
        horizontalLayout = new QHBoxLayout(DataBufferDialog);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        plainTextEdit = new QPlainTextEdit(DataBufferDialog);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setReadOnly(true);

        horizontalLayout->addWidget(plainTextEdit);


        retranslateUi(DataBufferDialog);

        QMetaObject::connectSlotsByName(DataBufferDialog);
    } // setupUi

    void retranslateUi(QDialog *DataBufferDialog)
    {
        DataBufferDialog->setWindowTitle(QApplication::translate("DataBufferDialog", "Current Data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataBufferDialog: public Ui_DataBufferDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABUFFERDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'PlotArrangementDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTARRANGEMENTDIALOG_H
#define UI_PLOTARRANGEMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_PlotArrangementDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *PlotArrangementDialog)
    {
        if (PlotArrangementDialog->objectName().isEmpty())
            PlotArrangementDialog->setObjectName(QString::fromUtf8("PlotArrangementDialog"));
        PlotArrangementDialog->resize(457, 357);
        horizontalLayout = new QHBoxLayout(PlotArrangementDialog);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        plainTextEdit = new QPlainTextEdit(PlotArrangementDialog);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setReadOnly(true);

        horizontalLayout->addWidget(plainTextEdit);


        retranslateUi(PlotArrangementDialog);

        QMetaObject::connectSlotsByName(PlotArrangementDialog);
    } // setupUi

    void retranslateUi(QDialog *PlotArrangementDialog)
    {
        PlotArrangementDialog->setWindowTitle(QApplication::translate("PlotArrangementDialog", "Current Plot Arrangement", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlotArrangementDialog: public Ui_PlotArrangementDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTARRANGEMENTDIALOG_H

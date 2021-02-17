/********************************************************************************
** Form generated from reading UI file 'DataInfoDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAINFODIALOG_H
#define UI_DATAINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataInfoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_info;
    QVBoxLayout *verticalLayout_info;
    QGroupBox *groupBox_dataFileInfo;
    QHBoxLayout *horizontalLayout_dataFileInfo;
    QPlainTextEdit *plainTextEdit_dataFileInfo;
    QGroupBox *groupBox_dataSetInfo;
    QHBoxLayout *horizontalLayout_dataSetInfo;
    QTabWidget *tabWidget;
    QGroupBox *groupBox_data;
    QHBoxLayout *horizontalLayout_data;
    QScrollArea *scrollArea_data;
    QWidget *scrollAreaWidgetContents_data;
    QVBoxLayout *verticalLayout_scrollAreaWidgetContents_data;
    QSpacerItem *verticalSpacer;
    QFrame *frame_controls;
    QHBoxLayout *horizontalLayout_controls;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_save;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *DataInfoDialog)
    {
        if (DataInfoDialog->objectName().isEmpty())
            DataInfoDialog->setObjectName(QString::fromUtf8("DataInfoDialog"));
        DataInfoDialog->resize(558, 448);
        verticalLayout = new QVBoxLayout(DataInfoDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(DataInfoDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame_info = new QFrame(frame);
        frame_info->setObjectName(QString::fromUtf8("frame_info"));
        verticalLayout_info = new QVBoxLayout(frame_info);
        verticalLayout_info->setSpacing(6);
        verticalLayout_info->setContentsMargins(11, 11, 11, 11);
        verticalLayout_info->setObjectName(QString::fromUtf8("verticalLayout_info"));
        verticalLayout_info->setContentsMargins(0, 0, 0, 0);
        groupBox_dataFileInfo = new QGroupBox(frame_info);
        groupBox_dataFileInfo->setObjectName(QString::fromUtf8("groupBox_dataFileInfo"));
        horizontalLayout_dataFileInfo = new QHBoxLayout(groupBox_dataFileInfo);
        horizontalLayout_dataFileInfo->setSpacing(6);
        horizontalLayout_dataFileInfo->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_dataFileInfo->setObjectName(QString::fromUtf8("horizontalLayout_dataFileInfo"));
        horizontalLayout_dataFileInfo->setContentsMargins(6, 6, 6, 6);
        plainTextEdit_dataFileInfo = new QPlainTextEdit(groupBox_dataFileInfo);
        plainTextEdit_dataFileInfo->setObjectName(QString::fromUtf8("plainTextEdit_dataFileInfo"));

        horizontalLayout_dataFileInfo->addWidget(plainTextEdit_dataFileInfo);


        verticalLayout_info->addWidget(groupBox_dataFileInfo);

        groupBox_dataSetInfo = new QGroupBox(frame_info);
        groupBox_dataSetInfo->setObjectName(QString::fromUtf8("groupBox_dataSetInfo"));
        horizontalLayout_dataSetInfo = new QHBoxLayout(groupBox_dataSetInfo);
        horizontalLayout_dataSetInfo->setSpacing(6);
        horizontalLayout_dataSetInfo->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_dataSetInfo->setObjectName(QString::fromUtf8("horizontalLayout_dataSetInfo"));
        horizontalLayout_dataSetInfo->setContentsMargins(6, 4, 4, 6);
        tabWidget = new QTabWidget(groupBox_dataSetInfo);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));

        horizontalLayout_dataSetInfo->addWidget(tabWidget);


        verticalLayout_info->addWidget(groupBox_dataSetInfo);


        horizontalLayout->addWidget(frame_info);

        groupBox_data = new QGroupBox(frame);
        groupBox_data->setObjectName(QString::fromUtf8("groupBox_data"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_data->sizePolicy().hasHeightForWidth());
        groupBox_data->setSizePolicy(sizePolicy);
        groupBox_data->setMinimumSize(QSize(144, 0));
        horizontalLayout_data = new QHBoxLayout(groupBox_data);
        horizontalLayout_data->setSpacing(6);
        horizontalLayout_data->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_data->setObjectName(QString::fromUtf8("horizontalLayout_data"));
        horizontalLayout_data->setContentsMargins(1, 1, 1, 1);
        scrollArea_data = new QScrollArea(groupBox_data);
        scrollArea_data->setObjectName(QString::fromUtf8("scrollArea_data"));
        scrollArea_data->setFrameShape(QFrame::NoFrame);
        scrollArea_data->setWidgetResizable(true);
        scrollAreaWidgetContents_data = new QWidget();
        scrollAreaWidgetContents_data->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_data"));
        scrollAreaWidgetContents_data->setGeometry(QRect(0, 0, 140, 366));
        verticalLayout_scrollAreaWidgetContents_data = new QVBoxLayout(scrollAreaWidgetContents_data);
        verticalLayout_scrollAreaWidgetContents_data->setSpacing(6);
        verticalLayout_scrollAreaWidgetContents_data->setContentsMargins(11, 11, 11, 11);
        verticalLayout_scrollAreaWidgetContents_data->setObjectName(QString::fromUtf8("verticalLayout_scrollAreaWidgetContents_data"));
        verticalLayout_scrollAreaWidgetContents_data->setContentsMargins(6, 6, 6, 6);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_scrollAreaWidgetContents_data->addItem(verticalSpacer);

        scrollArea_data->setWidget(scrollAreaWidgetContents_data);

        horizontalLayout_data->addWidget(scrollArea_data);


        horizontalLayout->addWidget(groupBox_data);


        verticalLayout->addWidget(frame);

        frame_controls = new QFrame(DataInfoDialog);
        frame_controls->setObjectName(QString::fromUtf8("frame_controls"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_controls->sizePolicy().hasHeightForWidth());
        frame_controls->setSizePolicy(sizePolicy1);
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


        retranslateUi(DataInfoDialog);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(DataInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *DataInfoDialog)
    {
        DataInfoDialog->setWindowTitle(QApplication::translate("DataInfoDialog", "DataInfoDialog", nullptr));
        groupBox_dataFileInfo->setTitle(QApplication::translate("DataInfoDialog", "Data File Info", nullptr));
        groupBox_dataSetInfo->setTitle(QApplication::translate("DataInfoDialog", "Data Set Info", nullptr));
        groupBox_data->setTitle(QApplication::translate("DataInfoDialog", "Buffered Data", nullptr));
        pushButton_save->setText(QApplication::translate("DataInfoDialog", "Save", nullptr));
        pushButton_cancel->setText(QApplication::translate("DataInfoDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataInfoDialog: public Ui_DataInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAINFODIALOG_H

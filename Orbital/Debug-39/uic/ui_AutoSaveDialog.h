/********************************************************************************
** Form generated from reading UI file 'AutoSaveDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOSAVEDIALOG_H
#define UI_AUTOSAVEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AutoSaveDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_file;
    QVBoxLayout *verticalLayout_file;
    QFrame *frame_fileName;
    QHBoxLayout *horizontalLayout_fileName;
    QLabel *label;
    QLineEdit *lineEdit_fileName;
    QFrame *frame_filePath;
    QHBoxLayout *horizontalLayout_filePath;
    QLabel *label_filePath;
    QLineEdit *lineEdit_filePath;
    QPushButton *pushButton_filePath;
    QFrame *frame_generateOnRun;
    QVBoxLayout *verticalLayout_generateOnRun;
    QFrame *frame_generateNewFile;
    QHBoxLayout *horizontalLayout_generateNewFile;
    QLabel *label_generateNewFile;
    QCheckBox *checkBox_generateNewFile;
    QFrame *frame_includeTimeStamp;
    QHBoxLayout *horizontalLayout_includeTimeStamp;
    QLabel *label_includeTimeStamp;
    QCheckBox *checkBox_includeTimeStamp;
    QFrame *frame_autoSave;
    QHBoxLayout *horizontalLayout_autoSaveLabel;
    QFrame *frame_autoSaveLabel;
    QVBoxLayout *verticalLayout_autoSaveLabel;
    QLabel *label_autoSaveLabel;
    QCheckBox *checkBox_showAutoSaveLabel;
    QPlainTextEdit *plainTextEdit_autoSaveLabel;
    QFrame *frame_autoSaveHeader;
    QHBoxLayout *horizontalLayout_autoSaveHeader;
    QLabel *label_showAutoSaveHeader;
    QCheckBox *checkBox_showAutoSaveHeader;
    QFrame *frame_dataSet;
    QHBoxLayout *horizontalLayout_dataSetLabel;
    QFrame *frame_dataSetLabel;
    QVBoxLayout *verticalLayout_dataSetLabel;
    QLabel *label_dataSetLabel;
    QCheckBox *checkBox_showDataSetLabel;
    QPlainTextEdit *plainTextEdit_dataSetLabel;
    QFrame *frame_dataSetInfo;
    QHBoxLayout *horizontalLayout_dataSetInfo;
    QLabel *label_showDataSetInfo;
    QCheckBox *checkBox_showDataSetInfo;
    QSpacerItem *verticalSpacer;
    QFrame *frame_controls;
    QHBoxLayout *horizontalLayout_controls;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_continue;

    void setupUi(QDialog *AutoSaveDialog)
    {
        if (AutoSaveDialog->objectName().isEmpty())
            AutoSaveDialog->setObjectName(QString::fromUtf8("AutoSaveDialog"));
        AutoSaveDialog->resize(322, 414);
        verticalLayout = new QVBoxLayout(AutoSaveDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_file = new QFrame(AutoSaveDialog);
        frame_file->setObjectName(QString::fromUtf8("frame_file"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_file->sizePolicy().hasHeightForWidth());
        frame_file->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        frame_file->setFont(font);
        frame_file->setFrameShape(QFrame::StyledPanel);
        verticalLayout_file = new QVBoxLayout(frame_file);
        verticalLayout_file->setSpacing(6);
        verticalLayout_file->setContentsMargins(11, 11, 11, 11);
        verticalLayout_file->setObjectName(QString::fromUtf8("verticalLayout_file"));
        frame_fileName = new QFrame(frame_file);
        frame_fileName->setObjectName(QString::fromUtf8("frame_fileName"));
        sizePolicy.setHeightForWidth(frame_fileName->sizePolicy().hasHeightForWidth());
        frame_fileName->setSizePolicy(sizePolicy);
        horizontalLayout_fileName = new QHBoxLayout(frame_fileName);
        horizontalLayout_fileName->setSpacing(6);
        horizontalLayout_fileName->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_fileName->setObjectName(QString::fromUtf8("horizontalLayout_fileName"));
        horizontalLayout_fileName->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(frame_fileName);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_fileName->addWidget(label);

        lineEdit_fileName = new QLineEdit(frame_fileName);
        lineEdit_fileName->setObjectName(QString::fromUtf8("lineEdit_fileName"));

        horizontalLayout_fileName->addWidget(lineEdit_fileName);


        verticalLayout_file->addWidget(frame_fileName);

        frame_filePath = new QFrame(frame_file);
        frame_filePath->setObjectName(QString::fromUtf8("frame_filePath"));
        sizePolicy.setHeightForWidth(frame_filePath->sizePolicy().hasHeightForWidth());
        frame_filePath->setSizePolicy(sizePolicy);
        horizontalLayout_filePath = new QHBoxLayout(frame_filePath);
        horizontalLayout_filePath->setSpacing(6);
        horizontalLayout_filePath->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_filePath->setObjectName(QString::fromUtf8("horizontalLayout_filePath"));
        horizontalLayout_filePath->setContentsMargins(0, 0, 0, 0);
        label_filePath = new QLabel(frame_filePath);
        label_filePath->setObjectName(QString::fromUtf8("label_filePath"));

        horizontalLayout_filePath->addWidget(label_filePath);

        lineEdit_filePath = new QLineEdit(frame_filePath);
        lineEdit_filePath->setObjectName(QString::fromUtf8("lineEdit_filePath"));
        lineEdit_filePath->setReadOnly(true);

        horizontalLayout_filePath->addWidget(lineEdit_filePath);

        pushButton_filePath = new QPushButton(frame_filePath);
        pushButton_filePath->setObjectName(QString::fromUtf8("pushButton_filePath"));

        horizontalLayout_filePath->addWidget(pushButton_filePath);


        verticalLayout_file->addWidget(frame_filePath);


        verticalLayout->addWidget(frame_file);

        frame_generateOnRun = new QFrame(AutoSaveDialog);
        frame_generateOnRun->setObjectName(QString::fromUtf8("frame_generateOnRun"));
        sizePolicy.setHeightForWidth(frame_generateOnRun->sizePolicy().hasHeightForWidth());
        frame_generateOnRun->setSizePolicy(sizePolicy);
        frame_generateOnRun->setFont(font);
        frame_generateOnRun->setFrameShape(QFrame::StyledPanel);
        verticalLayout_generateOnRun = new QVBoxLayout(frame_generateOnRun);
        verticalLayout_generateOnRun->setSpacing(6);
        verticalLayout_generateOnRun->setContentsMargins(11, 11, 11, 11);
        verticalLayout_generateOnRun->setObjectName(QString::fromUtf8("verticalLayout_generateOnRun"));
        frame_generateNewFile = new QFrame(frame_generateOnRun);
        frame_generateNewFile->setObjectName(QString::fromUtf8("frame_generateNewFile"));
        sizePolicy.setHeightForWidth(frame_generateNewFile->sizePolicy().hasHeightForWidth());
        frame_generateNewFile->setSizePolicy(sizePolicy);
        horizontalLayout_generateNewFile = new QHBoxLayout(frame_generateNewFile);
        horizontalLayout_generateNewFile->setSpacing(6);
        horizontalLayout_generateNewFile->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_generateNewFile->setObjectName(QString::fromUtf8("horizontalLayout_generateNewFile"));
        horizontalLayout_generateNewFile->setContentsMargins(0, 0, 0, 0);
        label_generateNewFile = new QLabel(frame_generateNewFile);
        label_generateNewFile->setObjectName(QString::fromUtf8("label_generateNewFile"));

        horizontalLayout_generateNewFile->addWidget(label_generateNewFile);

        checkBox_generateNewFile = new QCheckBox(frame_generateNewFile);
        checkBox_generateNewFile->setObjectName(QString::fromUtf8("checkBox_generateNewFile"));
        checkBox_generateNewFile->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_generateNewFile->addWidget(checkBox_generateNewFile);


        verticalLayout_generateOnRun->addWidget(frame_generateNewFile);

        frame_includeTimeStamp = new QFrame(frame_generateOnRun);
        frame_includeTimeStamp->setObjectName(QString::fromUtf8("frame_includeTimeStamp"));
        sizePolicy.setHeightForWidth(frame_includeTimeStamp->sizePolicy().hasHeightForWidth());
        frame_includeTimeStamp->setSizePolicy(sizePolicy);
        horizontalLayout_includeTimeStamp = new QHBoxLayout(frame_includeTimeStamp);
        horizontalLayout_includeTimeStamp->setSpacing(6);
        horizontalLayout_includeTimeStamp->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_includeTimeStamp->setObjectName(QString::fromUtf8("horizontalLayout_includeTimeStamp"));
        horizontalLayout_includeTimeStamp->setContentsMargins(0, 0, 0, 0);
        label_includeTimeStamp = new QLabel(frame_includeTimeStamp);
        label_includeTimeStamp->setObjectName(QString::fromUtf8("label_includeTimeStamp"));

        horizontalLayout_includeTimeStamp->addWidget(label_includeTimeStamp);

        checkBox_includeTimeStamp = new QCheckBox(frame_includeTimeStamp);
        checkBox_includeTimeStamp->setObjectName(QString::fromUtf8("checkBox_includeTimeStamp"));
        checkBox_includeTimeStamp->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_includeTimeStamp->addWidget(checkBox_includeTimeStamp);


        verticalLayout_generateOnRun->addWidget(frame_includeTimeStamp);


        verticalLayout->addWidget(frame_generateOnRun);

        frame_autoSave = new QFrame(AutoSaveDialog);
        frame_autoSave->setObjectName(QString::fromUtf8("frame_autoSave"));
        sizePolicy.setHeightForWidth(frame_autoSave->sizePolicy().hasHeightForWidth());
        frame_autoSave->setSizePolicy(sizePolicy);
        frame_autoSave->setFont(font);
        frame_autoSave->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_autoSaveLabel = new QHBoxLayout(frame_autoSave);
        horizontalLayout_autoSaveLabel->setSpacing(6);
        horizontalLayout_autoSaveLabel->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_autoSaveLabel->setObjectName(QString::fromUtf8("horizontalLayout_autoSaveLabel"));
        frame_autoSaveLabel = new QFrame(frame_autoSave);
        frame_autoSaveLabel->setObjectName(QString::fromUtf8("frame_autoSaveLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_autoSaveLabel->sizePolicy().hasHeightForWidth());
        frame_autoSaveLabel->setSizePolicy(sizePolicy1);
        frame_autoSaveLabel->setMinimumSize(QSize(100, 0));
        frame_autoSaveLabel->setFrameShape(QFrame::StyledPanel);
        frame_autoSaveLabel->setFrameShadow(QFrame::Raised);
        verticalLayout_autoSaveLabel = new QVBoxLayout(frame_autoSaveLabel);
        verticalLayout_autoSaveLabel->setSpacing(6);
        verticalLayout_autoSaveLabel->setContentsMargins(11, 11, 11, 11);
        verticalLayout_autoSaveLabel->setObjectName(QString::fromUtf8("verticalLayout_autoSaveLabel"));
        verticalLayout_autoSaveLabel->setContentsMargins(0, 0, 0, 0);
        label_autoSaveLabel = new QLabel(frame_autoSaveLabel);
        label_autoSaveLabel->setObjectName(QString::fromUtf8("label_autoSaveLabel"));
        sizePolicy.setHeightForWidth(label_autoSaveLabel->sizePolicy().hasHeightForWidth());
        label_autoSaveLabel->setSizePolicy(sizePolicy);

        verticalLayout_autoSaveLabel->addWidget(label_autoSaveLabel);

        checkBox_showAutoSaveLabel = new QCheckBox(frame_autoSaveLabel);
        checkBox_showAutoSaveLabel->setObjectName(QString::fromUtf8("checkBox_showAutoSaveLabel"));
        checkBox_showAutoSaveLabel->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_autoSaveLabel->addWidget(checkBox_showAutoSaveLabel);


        horizontalLayout_autoSaveLabel->addWidget(frame_autoSaveLabel);

        plainTextEdit_autoSaveLabel = new QPlainTextEdit(frame_autoSave);
        plainTextEdit_autoSaveLabel->setObjectName(QString::fromUtf8("plainTextEdit_autoSaveLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(plainTextEdit_autoSaveLabel->sizePolicy().hasHeightForWidth());
        plainTextEdit_autoSaveLabel->setSizePolicy(sizePolicy2);

        horizontalLayout_autoSaveLabel->addWidget(plainTextEdit_autoSaveLabel);


        verticalLayout->addWidget(frame_autoSave);

        frame_autoSaveHeader = new QFrame(AutoSaveDialog);
        frame_autoSaveHeader->setObjectName(QString::fromUtf8("frame_autoSaveHeader"));
        sizePolicy.setHeightForWidth(frame_autoSaveHeader->sizePolicy().hasHeightForWidth());
        frame_autoSaveHeader->setSizePolicy(sizePolicy);
        frame_autoSaveHeader->setFont(font);
        frame_autoSaveHeader->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_autoSaveHeader = new QHBoxLayout(frame_autoSaveHeader);
        horizontalLayout_autoSaveHeader->setSpacing(6);
        horizontalLayout_autoSaveHeader->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_autoSaveHeader->setObjectName(QString::fromUtf8("horizontalLayout_autoSaveHeader"));
        label_showAutoSaveHeader = new QLabel(frame_autoSaveHeader);
        label_showAutoSaveHeader->setObjectName(QString::fromUtf8("label_showAutoSaveHeader"));

        horizontalLayout_autoSaveHeader->addWidget(label_showAutoSaveHeader);

        checkBox_showAutoSaveHeader = new QCheckBox(frame_autoSaveHeader);
        checkBox_showAutoSaveHeader->setObjectName(QString::fromUtf8("checkBox_showAutoSaveHeader"));
        checkBox_showAutoSaveHeader->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_autoSaveHeader->addWidget(checkBox_showAutoSaveHeader);


        verticalLayout->addWidget(frame_autoSaveHeader);

        frame_dataSet = new QFrame(AutoSaveDialog);
        frame_dataSet->setObjectName(QString::fromUtf8("frame_dataSet"));
        sizePolicy.setHeightForWidth(frame_dataSet->sizePolicy().hasHeightForWidth());
        frame_dataSet->setSizePolicy(sizePolicy);
        frame_dataSet->setFont(font);
        frame_dataSet->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_dataSetLabel = new QHBoxLayout(frame_dataSet);
        horizontalLayout_dataSetLabel->setSpacing(6);
        horizontalLayout_dataSetLabel->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_dataSetLabel->setObjectName(QString::fromUtf8("horizontalLayout_dataSetLabel"));
        frame_dataSetLabel = new QFrame(frame_dataSet);
        frame_dataSetLabel->setObjectName(QString::fromUtf8("frame_dataSetLabel"));
        sizePolicy1.setHeightForWidth(frame_dataSetLabel->sizePolicy().hasHeightForWidth());
        frame_dataSetLabel->setSizePolicy(sizePolicy1);
        frame_dataSetLabel->setMinimumSize(QSize(100, 0));
        frame_dataSetLabel->setFrameShape(QFrame::StyledPanel);
        frame_dataSetLabel->setFrameShadow(QFrame::Raised);
        verticalLayout_dataSetLabel = new QVBoxLayout(frame_dataSetLabel);
        verticalLayout_dataSetLabel->setSpacing(6);
        verticalLayout_dataSetLabel->setContentsMargins(11, 11, 11, 11);
        verticalLayout_dataSetLabel->setObjectName(QString::fromUtf8("verticalLayout_dataSetLabel"));
        verticalLayout_dataSetLabel->setContentsMargins(0, 0, 0, 0);
        label_dataSetLabel = new QLabel(frame_dataSetLabel);
        label_dataSetLabel->setObjectName(QString::fromUtf8("label_dataSetLabel"));
        sizePolicy.setHeightForWidth(label_dataSetLabel->sizePolicy().hasHeightForWidth());
        label_dataSetLabel->setSizePolicy(sizePolicy);

        verticalLayout_dataSetLabel->addWidget(label_dataSetLabel);

        checkBox_showDataSetLabel = new QCheckBox(frame_dataSetLabel);
        checkBox_showDataSetLabel->setObjectName(QString::fromUtf8("checkBox_showDataSetLabel"));
        checkBox_showDataSetLabel->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_dataSetLabel->addWidget(checkBox_showDataSetLabel);


        horizontalLayout_dataSetLabel->addWidget(frame_dataSetLabel);

        plainTextEdit_dataSetLabel = new QPlainTextEdit(frame_dataSet);
        plainTextEdit_dataSetLabel->setObjectName(QString::fromUtf8("plainTextEdit_dataSetLabel"));
        sizePolicy2.setHeightForWidth(plainTextEdit_dataSetLabel->sizePolicy().hasHeightForWidth());
        plainTextEdit_dataSetLabel->setSizePolicy(sizePolicy2);

        horizontalLayout_dataSetLabel->addWidget(plainTextEdit_dataSetLabel);


        verticalLayout->addWidget(frame_dataSet);

        frame_dataSetInfo = new QFrame(AutoSaveDialog);
        frame_dataSetInfo->setObjectName(QString::fromUtf8("frame_dataSetInfo"));
        sizePolicy.setHeightForWidth(frame_dataSetInfo->sizePolicy().hasHeightForWidth());
        frame_dataSetInfo->setSizePolicy(sizePolicy);
        frame_dataSetInfo->setFont(font);
        frame_dataSetInfo->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_dataSetInfo = new QHBoxLayout(frame_dataSetInfo);
        horizontalLayout_dataSetInfo->setSpacing(6);
        horizontalLayout_dataSetInfo->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_dataSetInfo->setObjectName(QString::fromUtf8("horizontalLayout_dataSetInfo"));
        label_showDataSetInfo = new QLabel(frame_dataSetInfo);
        label_showDataSetInfo->setObjectName(QString::fromUtf8("label_showDataSetInfo"));

        horizontalLayout_dataSetInfo->addWidget(label_showDataSetInfo);

        checkBox_showDataSetInfo = new QCheckBox(frame_dataSetInfo);
        checkBox_showDataSetInfo->setObjectName(QString::fromUtf8("checkBox_showDataSetInfo"));
        checkBox_showDataSetInfo->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_dataSetInfo->addWidget(checkBox_showDataSetInfo);


        verticalLayout->addWidget(frame_dataSetInfo);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        frame_controls = new QFrame(AutoSaveDialog);
        frame_controls->setObjectName(QString::fromUtf8("frame_controls"));
        sizePolicy.setHeightForWidth(frame_controls->sizePolicy().hasHeightForWidth());
        frame_controls->setSizePolicy(sizePolicy);
        horizontalLayout_controls = new QHBoxLayout(frame_controls);
        horizontalLayout_controls->setSpacing(6);
        horizontalLayout_controls->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_controls->setObjectName(QString::fromUtf8("horizontalLayout_controls"));
        horizontalLayout_controls->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_controls->addItem(horizontalSpacer);

        pushButton_continue = new QPushButton(frame_controls);
        pushButton_continue->setObjectName(QString::fromUtf8("pushButton_continue"));
        pushButton_continue->setFont(font);

        horizontalLayout_controls->addWidget(pushButton_continue);


        verticalLayout->addWidget(frame_controls);


        retranslateUi(AutoSaveDialog);

        QMetaObject::connectSlotsByName(AutoSaveDialog);
    } // setupUi

    void retranslateUi(QDialog *AutoSaveDialog)
    {
        AutoSaveDialog->setWindowTitle(QApplication::translate("AutoSaveDialog", "Auto-Save", nullptr));
        label->setText(QApplication::translate("AutoSaveDialog", "Auto-Save File", nullptr));
        label_filePath->setText(QApplication::translate("AutoSaveDialog", "Directory", nullptr));
        pushButton_filePath->setText(QApplication::translate("AutoSaveDialog", "Browse", nullptr));
        label_generateNewFile->setText(QApplication::translate("AutoSaveDialog", "Generate New Auto-Save File On Run", nullptr));
        checkBox_generateNewFile->setText(QString());
        label_includeTimeStamp->setText(QApplication::translate("AutoSaveDialog", "Include Time Stamp", nullptr));
        checkBox_includeTimeStamp->setText(QString());
        label_autoSaveLabel->setText(QApplication::translate("AutoSaveDialog", "Auto-Save Label", nullptr));
        checkBox_showAutoSaveLabel->setText(QApplication::translate("AutoSaveDialog", "Show", nullptr));
        label_showAutoSaveHeader->setText(QApplication::translate("AutoSaveDialog", "Show Auto-Save Header", nullptr));
        checkBox_showAutoSaveHeader->setText(QString());
        label_dataSetLabel->setText(QApplication::translate("AutoSaveDialog", "Data Set Label", nullptr));
        checkBox_showDataSetLabel->setText(QApplication::translate("AutoSaveDialog", "Show", nullptr));
        label_showDataSetInfo->setText(QApplication::translate("AutoSaveDialog", "Show Data Set Info", nullptr));
        checkBox_showDataSetInfo->setText(QString());
        pushButton_continue->setText(QApplication::translate("AutoSaveDialog", "Continue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AutoSaveDialog: public Ui_AutoSaveDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOSAVEDIALOG_H

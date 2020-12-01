/********************************************************************************
** Form generated from reading UI file 'SettingsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_autoSave;
    QHBoxLayout *horizontalLayout_autoSave;
    QScrollArea *scrollArea_autoSave;
    QWidget *scrollAreaWidgetContents_autoSave;
    QVBoxLayout *verticalLayout_scrollAreaWidgetContents_autoSave;
    QFrame *frame_autoSaveFile;
    QVBoxLayout *verticalLayout_autoSaveFile;
    QFrame *frame_autoSaveFileName;
    QHBoxLayout *horizontalLayout_autoSaveFileName;
    QLabel *label_autoSaveFileName;
    QLineEdit *lineEdit_autoSaveFileName;
    QFrame *frame_autoSaveFileDirectory;
    QHBoxLayout *horizontalLayout_autoSaveFileDirectory;
    QLabel *label_autoSaveFileDirectory;
    QLineEdit *lineEdit_autoSaveFileDirectory;
    QPushButton *pushButton_autoSaveFileDirectory;
    QFrame *frame_autoSaveGenerateOptions;
    QVBoxLayout *verticalLayout_autoSaveGenerateOptions;
    QFrame *frame_autoSaveGenerateOnRun;
    QHBoxLayout *horizontalLayout_autoSaveGenerateOnRun;
    QLabel *label_autoSaveGenerateOnRun;
    QCheckBox *checkBox_autoSaveGenerateOnRun;
    QFrame *frame_autoSaveGenerateTimeStamp;
    QHBoxLayout *horizontalLayout_autoSaveGenerateTimeStamp;
    QLabel *label_autoSaveGenerateTimeStamp;
    QCheckBox *checkBox_autoSaveGenerateTimeStamp;
    QFrame *frame_autoSaveLabel;
    QHBoxLayout *horizontalLayout_autoSaveLabel;
    QFrame *frame_autoSaveLabelShow;
    QVBoxLayout *verticalLayout_autoSaveLabelShow;
    QLabel *label_autoSaveLabel;
    QCheckBox *checkBox_autoSaveLabel;
    QPlainTextEdit *plainTextEdit_autoSaveLabel;
    QFrame *frame_autoSaveHeader;
    QHBoxLayout *horizontalLayout_autoSaveHeader;
    QLabel *label_autoSaveHeader;
    QCheckBox *checkBox_autoSaveHeader;
    QFrame *frame_autoSaveDataSetLabel;
    QHBoxLayout *horizontalLayout_autoSaveDataSetLabel;
    QFrame *frame_autoSaveDataSetLabelShow;
    QVBoxLayout *verticalLayout_autoSaveDataSetLabelShow;
    QLabel *label_autoSaveDataSetLabel;
    QCheckBox *checkBox_autoSaveDataSetLabel;
    QPlainTextEdit *plainTextEdit_autoSaveDataSetLabel;
    QFrame *frame_autoSaveDataSetInfo;
    QHBoxLayout *horizontalLayout_autoSaveDataSetInfo;
    QLabel *label_autoSaveDataSetInfo;
    QCheckBox *checkBox_autoSaveDataSetInfo;
    QSpacerItem *verticalSpacer_autoSave;
    QWidget *tab_save;
    QHBoxLayout *horizontalLayout_save;
    QScrollArea *scrollArea_save;
    QWidget *scrollAreaWidgetContents_save;
    QVBoxLayout *verticalLayout_scrollAreaWidgetContents_save;
    QFrame *frame_saveUserParameters;
    QHBoxLayout *horizontalLayout_saveUserParameters;
    QLabel *label_saveUserParameters;
    QCheckBox *checkBox_saveUserParameters;
    QFrame *frame_saveDataFileInfo;
    QHBoxLayout *horizontalLayout_saveDataFileInfo;
    QLabel *label_saveDataFileInfo;
    QCheckBox *checkBox_saveDataFileInfo;
    QFrame *frame_saveDataSetLabel;
    QHBoxLayout *horizontalLayout_saveDataSetLabel;
    QFrame *frame_saveDataSetLabelShow;
    QVBoxLayout *verticalLayout_saveDataSetLabelShow;
    QLabel *label_saveDataSetLabel;
    QCheckBox *checkBox_saveDataSetLabel;
    QPlainTextEdit *plainTextEdit_saveDataSetLabel;
    QFrame *frame_saveDataSetInfo;
    QHBoxLayout *horizontalLayout_saveDataSetInfo;
    QLabel *label_saveDataSetInfo;
    QCheckBox *checkBox_saveDataSetInfo;
    QSpacerItem *verticalSpacer_save;
    QWidget *tab_parameters;
    QHBoxLayout *horizontalLayout_parameters;
    QScrollArea *scrollArea_parameters;
    QWidget *scrollAreaWidgetContents_parameters;
    QVBoxLayout *verticalLayout_scrollAreaWidgetContents_parameters;
    QFrame *frame_parametersExportOnRun;
    QHBoxLayout *horizontalLayout_parametersExportOnRun;
    QLabel *label_parametersExportOnRun;
    QCheckBox *checkBox_parametersExportOnRun;
    QFrame *frame_parametersFile;
    QHBoxLayout *horizontalLayout_parametersFile;
    QLabel *label_parametersFile;
    QLineEdit *lineEdit_parametersFile;
    QPushButton *pushButton_parametersFile;
    QSpacerItem *verticalSpacer_parameters;
    QWidget *tab_python;
    QHBoxLayout *horizontalLayout_python;
    QScrollArea *scrollArea_python;
    QWidget *scrollAreaWidgetContents_python;
    QVBoxLayout *verticalLayout_scrollAreaWidgetContents_python;
    QFrame *frame_pythonDependencies;
    QVBoxLayout *verticalLayout_pythonDependencies;
    QLabel *label_pythonDependencies;
    QListWidget *listWidget_pythonDependencies;
    QFrame *frame_pythonDependenciesControls;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_pythonDependencies;
    QPushButton *pushButton_pythonDependenciesAdd;
    QPushButton *pushButton_pythonDependenciesRemove;
    QFrame *frame_pythonRunStatus;
    QHBoxLayout *horizontalLayout_pythonRunStatus;
    QLabel *label_pythonRunStatus;
    QCheckBox *checkBox_pythonRunStatus;
    QSpacerItem *verticalSpacer_python;
    QFrame *frame_controls;
    QHBoxLayout *horizontalLayout_controls;
    QSpacerItem *horizontalSpacer_controls;
    QPushButton *pushButton_save;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QString::fromUtf8("SettingsDialog"));
        SettingsDialog->resize(420, 500);
        verticalLayout = new QVBoxLayout(SettingsDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(SettingsDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_autoSave = new QWidget();
        tab_autoSave->setObjectName(QString::fromUtf8("tab_autoSave"));
        horizontalLayout_autoSave = new QHBoxLayout(tab_autoSave);
        horizontalLayout_autoSave->setSpacing(6);
        horizontalLayout_autoSave->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_autoSave->setObjectName(QString::fromUtf8("horizontalLayout_autoSave"));
        scrollArea_autoSave = new QScrollArea(tab_autoSave);
        scrollArea_autoSave->setObjectName(QString::fromUtf8("scrollArea_autoSave"));
        scrollArea_autoSave->setWidgetResizable(true);
        scrollAreaWidgetContents_autoSave = new QWidget();
        scrollAreaWidgetContents_autoSave->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_autoSave"));
        scrollAreaWidgetContents_autoSave->setGeometry(QRect(0, 0, 376, 389));
        verticalLayout_scrollAreaWidgetContents_autoSave = new QVBoxLayout(scrollAreaWidgetContents_autoSave);
        verticalLayout_scrollAreaWidgetContents_autoSave->setSpacing(2);
        verticalLayout_scrollAreaWidgetContents_autoSave->setContentsMargins(11, 11, 11, 11);
        verticalLayout_scrollAreaWidgetContents_autoSave->setObjectName(QString::fromUtf8("verticalLayout_scrollAreaWidgetContents_autoSave"));
        verticalLayout_scrollAreaWidgetContents_autoSave->setContentsMargins(6, 6, 6, 6);
        frame_autoSaveFile = new QFrame(scrollAreaWidgetContents_autoSave);
        frame_autoSaveFile->setObjectName(QString::fromUtf8("frame_autoSaveFile"));
        frame_autoSaveFile->setFrameShape(QFrame::StyledPanel);
        verticalLayout_autoSaveFile = new QVBoxLayout(frame_autoSaveFile);
        verticalLayout_autoSaveFile->setSpacing(6);
        verticalLayout_autoSaveFile->setContentsMargins(11, 11, 11, 11);
        verticalLayout_autoSaveFile->setObjectName(QString::fromUtf8("verticalLayout_autoSaveFile"));
        frame_autoSaveFileName = new QFrame(frame_autoSaveFile);
        frame_autoSaveFileName->setObjectName(QString::fromUtf8("frame_autoSaveFileName"));
        horizontalLayout_autoSaveFileName = new QHBoxLayout(frame_autoSaveFileName);
        horizontalLayout_autoSaveFileName->setSpacing(6);
        horizontalLayout_autoSaveFileName->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_autoSaveFileName->setObjectName(QString::fromUtf8("horizontalLayout_autoSaveFileName"));
        horizontalLayout_autoSaveFileName->setContentsMargins(0, 0, 0, 0);
        label_autoSaveFileName = new QLabel(frame_autoSaveFileName);
        label_autoSaveFileName->setObjectName(QString::fromUtf8("label_autoSaveFileName"));

        horizontalLayout_autoSaveFileName->addWidget(label_autoSaveFileName);

        lineEdit_autoSaveFileName = new QLineEdit(frame_autoSaveFileName);
        lineEdit_autoSaveFileName->setObjectName(QString::fromUtf8("lineEdit_autoSaveFileName"));

        horizontalLayout_autoSaveFileName->addWidget(lineEdit_autoSaveFileName);


        verticalLayout_autoSaveFile->addWidget(frame_autoSaveFileName);

        frame_autoSaveFileDirectory = new QFrame(frame_autoSaveFile);
        frame_autoSaveFileDirectory->setObjectName(QString::fromUtf8("frame_autoSaveFileDirectory"));
        horizontalLayout_autoSaveFileDirectory = new QHBoxLayout(frame_autoSaveFileDirectory);
        horizontalLayout_autoSaveFileDirectory->setSpacing(6);
        horizontalLayout_autoSaveFileDirectory->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_autoSaveFileDirectory->setObjectName(QString::fromUtf8("horizontalLayout_autoSaveFileDirectory"));
        horizontalLayout_autoSaveFileDirectory->setContentsMargins(0, 0, 0, 0);
        label_autoSaveFileDirectory = new QLabel(frame_autoSaveFileDirectory);
        label_autoSaveFileDirectory->setObjectName(QString::fromUtf8("label_autoSaveFileDirectory"));

        horizontalLayout_autoSaveFileDirectory->addWidget(label_autoSaveFileDirectory);

        lineEdit_autoSaveFileDirectory = new QLineEdit(frame_autoSaveFileDirectory);
        lineEdit_autoSaveFileDirectory->setObjectName(QString::fromUtf8("lineEdit_autoSaveFileDirectory"));
        QPalette palette;
        QBrush brush(QColor(239, 239, 239, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        lineEdit_autoSaveFileDirectory->setPalette(palette);
        lineEdit_autoSaveFileDirectory->setReadOnly(true);

        horizontalLayout_autoSaveFileDirectory->addWidget(lineEdit_autoSaveFileDirectory);

        pushButton_autoSaveFileDirectory = new QPushButton(frame_autoSaveFileDirectory);
        pushButton_autoSaveFileDirectory->setObjectName(QString::fromUtf8("pushButton_autoSaveFileDirectory"));
        pushButton_autoSaveFileDirectory->setMaximumSize(QSize(64, 22));

        horizontalLayout_autoSaveFileDirectory->addWidget(pushButton_autoSaveFileDirectory);


        verticalLayout_autoSaveFile->addWidget(frame_autoSaveFileDirectory);


        verticalLayout_scrollAreaWidgetContents_autoSave->addWidget(frame_autoSaveFile);

        frame_autoSaveGenerateOptions = new QFrame(scrollAreaWidgetContents_autoSave);
        frame_autoSaveGenerateOptions->setObjectName(QString::fromUtf8("frame_autoSaveGenerateOptions"));
        frame_autoSaveGenerateOptions->setFrameShape(QFrame::StyledPanel);
        verticalLayout_autoSaveGenerateOptions = new QVBoxLayout(frame_autoSaveGenerateOptions);
        verticalLayout_autoSaveGenerateOptions->setSpacing(6);
        verticalLayout_autoSaveGenerateOptions->setContentsMargins(11, 11, 11, 11);
        verticalLayout_autoSaveGenerateOptions->setObjectName(QString::fromUtf8("verticalLayout_autoSaveGenerateOptions"));
        frame_autoSaveGenerateOnRun = new QFrame(frame_autoSaveGenerateOptions);
        frame_autoSaveGenerateOnRun->setObjectName(QString::fromUtf8("frame_autoSaveGenerateOnRun"));
        horizontalLayout_autoSaveGenerateOnRun = new QHBoxLayout(frame_autoSaveGenerateOnRun);
        horizontalLayout_autoSaveGenerateOnRun->setSpacing(6);
        horizontalLayout_autoSaveGenerateOnRun->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_autoSaveGenerateOnRun->setObjectName(QString::fromUtf8("horizontalLayout_autoSaveGenerateOnRun"));
        horizontalLayout_autoSaveGenerateOnRun->setContentsMargins(0, 0, 0, 0);
        label_autoSaveGenerateOnRun = new QLabel(frame_autoSaveGenerateOnRun);
        label_autoSaveGenerateOnRun->setObjectName(QString::fromUtf8("label_autoSaveGenerateOnRun"));

        horizontalLayout_autoSaveGenerateOnRun->addWidget(label_autoSaveGenerateOnRun);

        checkBox_autoSaveGenerateOnRun = new QCheckBox(frame_autoSaveGenerateOnRun);
        checkBox_autoSaveGenerateOnRun->setObjectName(QString::fromUtf8("checkBox_autoSaveGenerateOnRun"));
        checkBox_autoSaveGenerateOnRun->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_autoSaveGenerateOnRun->addWidget(checkBox_autoSaveGenerateOnRun);


        verticalLayout_autoSaveGenerateOptions->addWidget(frame_autoSaveGenerateOnRun);

        frame_autoSaveGenerateTimeStamp = new QFrame(frame_autoSaveGenerateOptions);
        frame_autoSaveGenerateTimeStamp->setObjectName(QString::fromUtf8("frame_autoSaveGenerateTimeStamp"));
        horizontalLayout_autoSaveGenerateTimeStamp = new QHBoxLayout(frame_autoSaveGenerateTimeStamp);
        horizontalLayout_autoSaveGenerateTimeStamp->setSpacing(6);
        horizontalLayout_autoSaveGenerateTimeStamp->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_autoSaveGenerateTimeStamp->setObjectName(QString::fromUtf8("horizontalLayout_autoSaveGenerateTimeStamp"));
        horizontalLayout_autoSaveGenerateTimeStamp->setContentsMargins(0, 0, 0, 0);
        label_autoSaveGenerateTimeStamp = new QLabel(frame_autoSaveGenerateTimeStamp);
        label_autoSaveGenerateTimeStamp->setObjectName(QString::fromUtf8("label_autoSaveGenerateTimeStamp"));

        horizontalLayout_autoSaveGenerateTimeStamp->addWidget(label_autoSaveGenerateTimeStamp);

        checkBox_autoSaveGenerateTimeStamp = new QCheckBox(frame_autoSaveGenerateTimeStamp);
        checkBox_autoSaveGenerateTimeStamp->setObjectName(QString::fromUtf8("checkBox_autoSaveGenerateTimeStamp"));
        checkBox_autoSaveGenerateTimeStamp->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_autoSaveGenerateTimeStamp->addWidget(checkBox_autoSaveGenerateTimeStamp);


        verticalLayout_autoSaveGenerateOptions->addWidget(frame_autoSaveGenerateTimeStamp);


        verticalLayout_scrollAreaWidgetContents_autoSave->addWidget(frame_autoSaveGenerateOptions);

        frame_autoSaveLabel = new QFrame(scrollAreaWidgetContents_autoSave);
        frame_autoSaveLabel->setObjectName(QString::fromUtf8("frame_autoSaveLabel"));
        frame_autoSaveLabel->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_autoSaveLabel = new QHBoxLayout(frame_autoSaveLabel);
        horizontalLayout_autoSaveLabel->setSpacing(9);
        horizontalLayout_autoSaveLabel->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_autoSaveLabel->setObjectName(QString::fromUtf8("horizontalLayout_autoSaveLabel"));
        frame_autoSaveLabelShow = new QFrame(frame_autoSaveLabel);
        frame_autoSaveLabelShow->setObjectName(QString::fromUtf8("frame_autoSaveLabelShow"));
        frame_autoSaveLabelShow->setMinimumSize(QSize(80, 0));
        verticalLayout_autoSaveLabelShow = new QVBoxLayout(frame_autoSaveLabelShow);
        verticalLayout_autoSaveLabelShow->setSpacing(6);
        verticalLayout_autoSaveLabelShow->setContentsMargins(11, 11, 11, 11);
        verticalLayout_autoSaveLabelShow->setObjectName(QString::fromUtf8("verticalLayout_autoSaveLabelShow"));
        verticalLayout_autoSaveLabelShow->setContentsMargins(0, 0, 0, 0);
        label_autoSaveLabel = new QLabel(frame_autoSaveLabelShow);
        label_autoSaveLabel->setObjectName(QString::fromUtf8("label_autoSaveLabel"));

        verticalLayout_autoSaveLabelShow->addWidget(label_autoSaveLabel);

        checkBox_autoSaveLabel = new QCheckBox(frame_autoSaveLabelShow);
        checkBox_autoSaveLabel->setObjectName(QString::fromUtf8("checkBox_autoSaveLabel"));
        checkBox_autoSaveLabel->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_autoSaveLabelShow->addWidget(checkBox_autoSaveLabel);


        horizontalLayout_autoSaveLabel->addWidget(frame_autoSaveLabelShow);

        plainTextEdit_autoSaveLabel = new QPlainTextEdit(frame_autoSaveLabel);
        plainTextEdit_autoSaveLabel->setObjectName(QString::fromUtf8("plainTextEdit_autoSaveLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit_autoSaveLabel->sizePolicy().hasHeightForWidth());
        plainTextEdit_autoSaveLabel->setSizePolicy(sizePolicy);

        horizontalLayout_autoSaveLabel->addWidget(plainTextEdit_autoSaveLabel);


        verticalLayout_scrollAreaWidgetContents_autoSave->addWidget(frame_autoSaveLabel);

        frame_autoSaveHeader = new QFrame(scrollAreaWidgetContents_autoSave);
        frame_autoSaveHeader->setObjectName(QString::fromUtf8("frame_autoSaveHeader"));
        frame_autoSaveHeader->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_autoSaveHeader = new QHBoxLayout(frame_autoSaveHeader);
        horizontalLayout_autoSaveHeader->setSpacing(6);
        horizontalLayout_autoSaveHeader->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_autoSaveHeader->setObjectName(QString::fromUtf8("horizontalLayout_autoSaveHeader"));
        label_autoSaveHeader = new QLabel(frame_autoSaveHeader);
        label_autoSaveHeader->setObjectName(QString::fromUtf8("label_autoSaveHeader"));

        horizontalLayout_autoSaveHeader->addWidget(label_autoSaveHeader);

        checkBox_autoSaveHeader = new QCheckBox(frame_autoSaveHeader);
        checkBox_autoSaveHeader->setObjectName(QString::fromUtf8("checkBox_autoSaveHeader"));
        checkBox_autoSaveHeader->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_autoSaveHeader->addWidget(checkBox_autoSaveHeader);


        verticalLayout_scrollAreaWidgetContents_autoSave->addWidget(frame_autoSaveHeader);

        frame_autoSaveDataSetLabel = new QFrame(scrollAreaWidgetContents_autoSave);
        frame_autoSaveDataSetLabel->setObjectName(QString::fromUtf8("frame_autoSaveDataSetLabel"));
        frame_autoSaveDataSetLabel->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_autoSaveDataSetLabel = new QHBoxLayout(frame_autoSaveDataSetLabel);
        horizontalLayout_autoSaveDataSetLabel->setSpacing(9);
        horizontalLayout_autoSaveDataSetLabel->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_autoSaveDataSetLabel->setObjectName(QString::fromUtf8("horizontalLayout_autoSaveDataSetLabel"));
        frame_autoSaveDataSetLabelShow = new QFrame(frame_autoSaveDataSetLabel);
        frame_autoSaveDataSetLabelShow->setObjectName(QString::fromUtf8("frame_autoSaveDataSetLabelShow"));
        frame_autoSaveDataSetLabelShow->setMinimumSize(QSize(80, 0));
        verticalLayout_autoSaveDataSetLabelShow = new QVBoxLayout(frame_autoSaveDataSetLabelShow);
        verticalLayout_autoSaveDataSetLabelShow->setSpacing(6);
        verticalLayout_autoSaveDataSetLabelShow->setContentsMargins(11, 11, 11, 11);
        verticalLayout_autoSaveDataSetLabelShow->setObjectName(QString::fromUtf8("verticalLayout_autoSaveDataSetLabelShow"));
        verticalLayout_autoSaveDataSetLabelShow->setContentsMargins(0, 0, 0, 0);
        label_autoSaveDataSetLabel = new QLabel(frame_autoSaveDataSetLabelShow);
        label_autoSaveDataSetLabel->setObjectName(QString::fromUtf8("label_autoSaveDataSetLabel"));

        verticalLayout_autoSaveDataSetLabelShow->addWidget(label_autoSaveDataSetLabel);

        checkBox_autoSaveDataSetLabel = new QCheckBox(frame_autoSaveDataSetLabelShow);
        checkBox_autoSaveDataSetLabel->setObjectName(QString::fromUtf8("checkBox_autoSaveDataSetLabel"));
        checkBox_autoSaveDataSetLabel->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_autoSaveDataSetLabelShow->addWidget(checkBox_autoSaveDataSetLabel);


        horizontalLayout_autoSaveDataSetLabel->addWidget(frame_autoSaveDataSetLabelShow);

        plainTextEdit_autoSaveDataSetLabel = new QPlainTextEdit(frame_autoSaveDataSetLabel);
        plainTextEdit_autoSaveDataSetLabel->setObjectName(QString::fromUtf8("plainTextEdit_autoSaveDataSetLabel"));
        sizePolicy.setHeightForWidth(plainTextEdit_autoSaveDataSetLabel->sizePolicy().hasHeightForWidth());
        plainTextEdit_autoSaveDataSetLabel->setSizePolicy(sizePolicy);

        horizontalLayout_autoSaveDataSetLabel->addWidget(plainTextEdit_autoSaveDataSetLabel);


        verticalLayout_scrollAreaWidgetContents_autoSave->addWidget(frame_autoSaveDataSetLabel);

        frame_autoSaveDataSetInfo = new QFrame(scrollAreaWidgetContents_autoSave);
        frame_autoSaveDataSetInfo->setObjectName(QString::fromUtf8("frame_autoSaveDataSetInfo"));
        frame_autoSaveDataSetInfo->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_autoSaveDataSetInfo = new QHBoxLayout(frame_autoSaveDataSetInfo);
        horizontalLayout_autoSaveDataSetInfo->setSpacing(6);
        horizontalLayout_autoSaveDataSetInfo->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_autoSaveDataSetInfo->setObjectName(QString::fromUtf8("horizontalLayout_autoSaveDataSetInfo"));
        label_autoSaveDataSetInfo = new QLabel(frame_autoSaveDataSetInfo);
        label_autoSaveDataSetInfo->setObjectName(QString::fromUtf8("label_autoSaveDataSetInfo"));

        horizontalLayout_autoSaveDataSetInfo->addWidget(label_autoSaveDataSetInfo);

        checkBox_autoSaveDataSetInfo = new QCheckBox(frame_autoSaveDataSetInfo);
        checkBox_autoSaveDataSetInfo->setObjectName(QString::fromUtf8("checkBox_autoSaveDataSetInfo"));
        checkBox_autoSaveDataSetInfo->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_autoSaveDataSetInfo->addWidget(checkBox_autoSaveDataSetInfo);


        verticalLayout_scrollAreaWidgetContents_autoSave->addWidget(frame_autoSaveDataSetInfo);

        verticalSpacer_autoSave = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_scrollAreaWidgetContents_autoSave->addItem(verticalSpacer_autoSave);

        scrollArea_autoSave->setWidget(scrollAreaWidgetContents_autoSave);

        horizontalLayout_autoSave->addWidget(scrollArea_autoSave);

        tabWidget->addTab(tab_autoSave, QString());
        tab_save = new QWidget();
        tab_save->setObjectName(QString::fromUtf8("tab_save"));
        horizontalLayout_save = new QHBoxLayout(tab_save);
        horizontalLayout_save->setSpacing(6);
        horizontalLayout_save->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_save->setObjectName(QString::fromUtf8("horizontalLayout_save"));
        scrollArea_save = new QScrollArea(tab_save);
        scrollArea_save->setObjectName(QString::fromUtf8("scrollArea_save"));
        scrollArea_save->setWidgetResizable(true);
        scrollAreaWidgetContents_save = new QWidget();
        scrollAreaWidgetContents_save->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_save"));
        scrollAreaWidgetContents_save->setGeometry(QRect(0, 0, 192, 175));
        verticalLayout_scrollAreaWidgetContents_save = new QVBoxLayout(scrollAreaWidgetContents_save);
        verticalLayout_scrollAreaWidgetContents_save->setSpacing(2);
        verticalLayout_scrollAreaWidgetContents_save->setContentsMargins(11, 11, 11, 11);
        verticalLayout_scrollAreaWidgetContents_save->setObjectName(QString::fromUtf8("verticalLayout_scrollAreaWidgetContents_save"));
        verticalLayout_scrollAreaWidgetContents_save->setContentsMargins(6, 6, 6, 6);
        frame_saveUserParameters = new QFrame(scrollAreaWidgetContents_save);
        frame_saveUserParameters->setObjectName(QString::fromUtf8("frame_saveUserParameters"));
        frame_saveUserParameters->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_saveUserParameters = new QHBoxLayout(frame_saveUserParameters);
        horizontalLayout_saveUserParameters->setSpacing(6);
        horizontalLayout_saveUserParameters->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_saveUserParameters->setObjectName(QString::fromUtf8("horizontalLayout_saveUserParameters"));
        label_saveUserParameters = new QLabel(frame_saveUserParameters);
        label_saveUserParameters->setObjectName(QString::fromUtf8("label_saveUserParameters"));

        horizontalLayout_saveUserParameters->addWidget(label_saveUserParameters);

        checkBox_saveUserParameters = new QCheckBox(frame_saveUserParameters);
        checkBox_saveUserParameters->setObjectName(QString::fromUtf8("checkBox_saveUserParameters"));
        checkBox_saveUserParameters->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_saveUserParameters->addWidget(checkBox_saveUserParameters);


        verticalLayout_scrollAreaWidgetContents_save->addWidget(frame_saveUserParameters);

        frame_saveDataFileInfo = new QFrame(scrollAreaWidgetContents_save);
        frame_saveDataFileInfo->setObjectName(QString::fromUtf8("frame_saveDataFileInfo"));
        frame_saveDataFileInfo->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_saveDataFileInfo = new QHBoxLayout(frame_saveDataFileInfo);
        horizontalLayout_saveDataFileInfo->setSpacing(6);
        horizontalLayout_saveDataFileInfo->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_saveDataFileInfo->setObjectName(QString::fromUtf8("horizontalLayout_saveDataFileInfo"));
        label_saveDataFileInfo = new QLabel(frame_saveDataFileInfo);
        label_saveDataFileInfo->setObjectName(QString::fromUtf8("label_saveDataFileInfo"));

        horizontalLayout_saveDataFileInfo->addWidget(label_saveDataFileInfo);

        checkBox_saveDataFileInfo = new QCheckBox(frame_saveDataFileInfo);
        checkBox_saveDataFileInfo->setObjectName(QString::fromUtf8("checkBox_saveDataFileInfo"));
        checkBox_saveDataFileInfo->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_saveDataFileInfo->addWidget(checkBox_saveDataFileInfo);


        verticalLayout_scrollAreaWidgetContents_save->addWidget(frame_saveDataFileInfo);

        frame_saveDataSetLabel = new QFrame(scrollAreaWidgetContents_save);
        frame_saveDataSetLabel->setObjectName(QString::fromUtf8("frame_saveDataSetLabel"));
        frame_saveDataSetLabel->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_saveDataSetLabel = new QHBoxLayout(frame_saveDataSetLabel);
        horizontalLayout_saveDataSetLabel->setSpacing(9);
        horizontalLayout_saveDataSetLabel->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_saveDataSetLabel->setObjectName(QString::fromUtf8("horizontalLayout_saveDataSetLabel"));
        frame_saveDataSetLabelShow = new QFrame(frame_saveDataSetLabel);
        frame_saveDataSetLabelShow->setObjectName(QString::fromUtf8("frame_saveDataSetLabelShow"));
        frame_saveDataSetLabelShow->setMinimumSize(QSize(80, 0));
        verticalLayout_saveDataSetLabelShow = new QVBoxLayout(frame_saveDataSetLabelShow);
        verticalLayout_saveDataSetLabelShow->setSpacing(6);
        verticalLayout_saveDataSetLabelShow->setContentsMargins(11, 11, 11, 11);
        verticalLayout_saveDataSetLabelShow->setObjectName(QString::fromUtf8("verticalLayout_saveDataSetLabelShow"));
        verticalLayout_saveDataSetLabelShow->setContentsMargins(0, 0, 0, 0);
        label_saveDataSetLabel = new QLabel(frame_saveDataSetLabelShow);
        label_saveDataSetLabel->setObjectName(QString::fromUtf8("label_saveDataSetLabel"));

        verticalLayout_saveDataSetLabelShow->addWidget(label_saveDataSetLabel);

        checkBox_saveDataSetLabel = new QCheckBox(frame_saveDataSetLabelShow);
        checkBox_saveDataSetLabel->setObjectName(QString::fromUtf8("checkBox_saveDataSetLabel"));
        checkBox_saveDataSetLabel->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_saveDataSetLabelShow->addWidget(checkBox_saveDataSetLabel);


        horizontalLayout_saveDataSetLabel->addWidget(frame_saveDataSetLabelShow);

        plainTextEdit_saveDataSetLabel = new QPlainTextEdit(frame_saveDataSetLabel);
        plainTextEdit_saveDataSetLabel->setObjectName(QString::fromUtf8("plainTextEdit_saveDataSetLabel"));
        sizePolicy.setHeightForWidth(plainTextEdit_saveDataSetLabel->sizePolicy().hasHeightForWidth());
        plainTextEdit_saveDataSetLabel->setSizePolicy(sizePolicy);

        horizontalLayout_saveDataSetLabel->addWidget(plainTextEdit_saveDataSetLabel);


        verticalLayout_scrollAreaWidgetContents_save->addWidget(frame_saveDataSetLabel);

        frame_saveDataSetInfo = new QFrame(scrollAreaWidgetContents_save);
        frame_saveDataSetInfo->setObjectName(QString::fromUtf8("frame_saveDataSetInfo"));
        frame_saveDataSetInfo->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_saveDataSetInfo = new QHBoxLayout(frame_saveDataSetInfo);
        horizontalLayout_saveDataSetInfo->setSpacing(6);
        horizontalLayout_saveDataSetInfo->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_saveDataSetInfo->setObjectName(QString::fromUtf8("horizontalLayout_saveDataSetInfo"));
        label_saveDataSetInfo = new QLabel(frame_saveDataSetInfo);
        label_saveDataSetInfo->setObjectName(QString::fromUtf8("label_saveDataSetInfo"));

        horizontalLayout_saveDataSetInfo->addWidget(label_saveDataSetInfo);

        checkBox_saveDataSetInfo = new QCheckBox(frame_saveDataSetInfo);
        checkBox_saveDataSetInfo->setObjectName(QString::fromUtf8("checkBox_saveDataSetInfo"));
        checkBox_saveDataSetInfo->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_saveDataSetInfo->addWidget(checkBox_saveDataSetInfo);


        verticalLayout_scrollAreaWidgetContents_save->addWidget(frame_saveDataSetInfo);

        verticalSpacer_save = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_scrollAreaWidgetContents_save->addItem(verticalSpacer_save);

        scrollArea_save->setWidget(scrollAreaWidgetContents_save);

        horizontalLayout_save->addWidget(scrollArea_save);

        tabWidget->addTab(tab_save, QString());
        tab_parameters = new QWidget();
        tab_parameters->setObjectName(QString::fromUtf8("tab_parameters"));
        horizontalLayout_parameters = new QHBoxLayout(tab_parameters);
        horizontalLayout_parameters->setSpacing(6);
        horizontalLayout_parameters->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_parameters->setObjectName(QString::fromUtf8("horizontalLayout_parameters"));
        scrollArea_parameters = new QScrollArea(tab_parameters);
        scrollArea_parameters->setObjectName(QString::fromUtf8("scrollArea_parameters"));
        scrollArea_parameters->setWidgetResizable(true);
        scrollAreaWidgetContents_parameters = new QWidget();
        scrollAreaWidgetContents_parameters->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_parameters"));
        scrollAreaWidgetContents_parameters->setGeometry(QRect(0, 0, 229, 91));
        verticalLayout_scrollAreaWidgetContents_parameters = new QVBoxLayout(scrollAreaWidgetContents_parameters);
        verticalLayout_scrollAreaWidgetContents_parameters->setSpacing(2);
        verticalLayout_scrollAreaWidgetContents_parameters->setContentsMargins(11, 11, 11, 11);
        verticalLayout_scrollAreaWidgetContents_parameters->setObjectName(QString::fromUtf8("verticalLayout_scrollAreaWidgetContents_parameters"));
        verticalLayout_scrollAreaWidgetContents_parameters->setContentsMargins(6, 6, 6, 6);
        frame_parametersExportOnRun = new QFrame(scrollAreaWidgetContents_parameters);
        frame_parametersExportOnRun->setObjectName(QString::fromUtf8("frame_parametersExportOnRun"));
        frame_parametersExportOnRun->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_parametersExportOnRun = new QHBoxLayout(frame_parametersExportOnRun);
        horizontalLayout_parametersExportOnRun->setSpacing(6);
        horizontalLayout_parametersExportOnRun->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_parametersExportOnRun->setObjectName(QString::fromUtf8("horizontalLayout_parametersExportOnRun"));
        label_parametersExportOnRun = new QLabel(frame_parametersExportOnRun);
        label_parametersExportOnRun->setObjectName(QString::fromUtf8("label_parametersExportOnRun"));

        horizontalLayout_parametersExportOnRun->addWidget(label_parametersExportOnRun);

        checkBox_parametersExportOnRun = new QCheckBox(frame_parametersExportOnRun);
        checkBox_parametersExportOnRun->setObjectName(QString::fromUtf8("checkBox_parametersExportOnRun"));
        checkBox_parametersExportOnRun->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_parametersExportOnRun->addWidget(checkBox_parametersExportOnRun);


        verticalLayout_scrollAreaWidgetContents_parameters->addWidget(frame_parametersExportOnRun);

        frame_parametersFile = new QFrame(scrollAreaWidgetContents_parameters);
        frame_parametersFile->setObjectName(QString::fromUtf8("frame_parametersFile"));
        frame_parametersFile->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_parametersFile = new QHBoxLayout(frame_parametersFile);
        horizontalLayout_parametersFile->setSpacing(6);
        horizontalLayout_parametersFile->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_parametersFile->setObjectName(QString::fromUtf8("horizontalLayout_parametersFile"));
        label_parametersFile = new QLabel(frame_parametersFile);
        label_parametersFile->setObjectName(QString::fromUtf8("label_parametersFile"));

        horizontalLayout_parametersFile->addWidget(label_parametersFile);

        lineEdit_parametersFile = new QLineEdit(frame_parametersFile);
        lineEdit_parametersFile->setObjectName(QString::fromUtf8("lineEdit_parametersFile"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        lineEdit_parametersFile->setPalette(palette1);
        lineEdit_parametersFile->setReadOnly(true);

        horizontalLayout_parametersFile->addWidget(lineEdit_parametersFile);

        pushButton_parametersFile = new QPushButton(frame_parametersFile);
        pushButton_parametersFile->setObjectName(QString::fromUtf8("pushButton_parametersFile"));
        pushButton_parametersFile->setMaximumSize(QSize(64, 22));

        horizontalLayout_parametersFile->addWidget(pushButton_parametersFile);


        verticalLayout_scrollAreaWidgetContents_parameters->addWidget(frame_parametersFile);

        verticalSpacer_parameters = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_scrollAreaWidgetContents_parameters->addItem(verticalSpacer_parameters);

        scrollArea_parameters->setWidget(scrollAreaWidgetContents_parameters);

        horizontalLayout_parameters->addWidget(scrollArea_parameters);

        tabWidget->addTab(tab_parameters, QString());
        tab_python = new QWidget();
        tab_python->setObjectName(QString::fromUtf8("tab_python"));
        horizontalLayout_python = new QHBoxLayout(tab_python);
        horizontalLayout_python->setSpacing(6);
        horizontalLayout_python->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_python->setObjectName(QString::fromUtf8("horizontalLayout_python"));
        scrollArea_python = new QScrollArea(tab_python);
        scrollArea_python->setObjectName(QString::fromUtf8("scrollArea_python"));
        scrollArea_python->setWidgetResizable(true);
        scrollAreaWidgetContents_python = new QWidget();
        scrollAreaWidgetContents_python->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_python"));
        scrollAreaWidgetContents_python->setGeometry(QRect(0, 0, 376, 389));
        verticalLayout_scrollAreaWidgetContents_python = new QVBoxLayout(scrollAreaWidgetContents_python);
        verticalLayout_scrollAreaWidgetContents_python->setSpacing(2);
        verticalLayout_scrollAreaWidgetContents_python->setContentsMargins(11, 11, 11, 11);
        verticalLayout_scrollAreaWidgetContents_python->setObjectName(QString::fromUtf8("verticalLayout_scrollAreaWidgetContents_python"));
        verticalLayout_scrollAreaWidgetContents_python->setContentsMargins(6, 6, 6, 6);
        frame_pythonDependencies = new QFrame(scrollAreaWidgetContents_python);
        frame_pythonDependencies->setObjectName(QString::fromUtf8("frame_pythonDependencies"));
        frame_pythonDependencies->setFrameShape(QFrame::StyledPanel);
        verticalLayout_pythonDependencies = new QVBoxLayout(frame_pythonDependencies);
        verticalLayout_pythonDependencies->setSpacing(6);
        verticalLayout_pythonDependencies->setContentsMargins(11, 11, 11, 11);
        verticalLayout_pythonDependencies->setObjectName(QString::fromUtf8("verticalLayout_pythonDependencies"));
        label_pythonDependencies = new QLabel(frame_pythonDependencies);
        label_pythonDependencies->setObjectName(QString::fromUtf8("label_pythonDependencies"));

        verticalLayout_pythonDependencies->addWidget(label_pythonDependencies);

        listWidget_pythonDependencies = new QListWidget(frame_pythonDependencies);
        listWidget_pythonDependencies->setObjectName(QString::fromUtf8("listWidget_pythonDependencies"));
        listWidget_pythonDependencies->setSelectionMode(QAbstractItemView::MultiSelection);

        verticalLayout_pythonDependencies->addWidget(listWidget_pythonDependencies);

        frame_pythonDependenciesControls = new QFrame(frame_pythonDependencies);
        frame_pythonDependenciesControls->setObjectName(QString::fromUtf8("frame_pythonDependenciesControls"));
        horizontalLayout = new QHBoxLayout(frame_pythonDependenciesControls);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_pythonDependencies = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_pythonDependencies);

        pushButton_pythonDependenciesAdd = new QPushButton(frame_pythonDependenciesControls);
        pushButton_pythonDependenciesAdd->setObjectName(QString::fromUtf8("pushButton_pythonDependenciesAdd"));

        horizontalLayout->addWidget(pushButton_pythonDependenciesAdd);

        pushButton_pythonDependenciesRemove = new QPushButton(frame_pythonDependenciesControls);
        pushButton_pythonDependenciesRemove->setObjectName(QString::fromUtf8("pushButton_pythonDependenciesRemove"));

        horizontalLayout->addWidget(pushButton_pythonDependenciesRemove);


        verticalLayout_pythonDependencies->addWidget(frame_pythonDependenciesControls);


        verticalLayout_scrollAreaWidgetContents_python->addWidget(frame_pythonDependencies);

        frame_pythonRunStatus = new QFrame(scrollAreaWidgetContents_python);
        frame_pythonRunStatus->setObjectName(QString::fromUtf8("frame_pythonRunStatus"));
        frame_pythonRunStatus->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_pythonRunStatus = new QHBoxLayout(frame_pythonRunStatus);
        horizontalLayout_pythonRunStatus->setSpacing(6);
        horizontalLayout_pythonRunStatus->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_pythonRunStatus->setObjectName(QString::fromUtf8("horizontalLayout_pythonRunStatus"));
        label_pythonRunStatus = new QLabel(frame_pythonRunStatus);
        label_pythonRunStatus->setObjectName(QString::fromUtf8("label_pythonRunStatus"));

        horizontalLayout_pythonRunStatus->addWidget(label_pythonRunStatus);

        checkBox_pythonRunStatus = new QCheckBox(frame_pythonRunStatus);
        checkBox_pythonRunStatus->setObjectName(QString::fromUtf8("checkBox_pythonRunStatus"));
        checkBox_pythonRunStatus->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_pythonRunStatus->addWidget(checkBox_pythonRunStatus);


        verticalLayout_scrollAreaWidgetContents_python->addWidget(frame_pythonRunStatus);

        verticalSpacer_python = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_scrollAreaWidgetContents_python->addItem(verticalSpacer_python);

        scrollArea_python->setWidget(scrollAreaWidgetContents_python);

        horizontalLayout_python->addWidget(scrollArea_python);

        tabWidget->addTab(tab_python, QString());

        verticalLayout->addWidget(tabWidget);

        frame_controls = new QFrame(SettingsDialog);
        frame_controls->setObjectName(QString::fromUtf8("frame_controls"));
        horizontalLayout_controls = new QHBoxLayout(frame_controls);
        horizontalLayout_controls->setSpacing(6);
        horizontalLayout_controls->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_controls->setObjectName(QString::fromUtf8("horizontalLayout_controls"));
        horizontalSpacer_controls = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_controls->addItem(horizontalSpacer_controls);

        pushButton_save = new QPushButton(frame_controls);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));

        horizontalLayout_controls->addWidget(pushButton_save);

        pushButton_cancel = new QPushButton(frame_controls);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout_controls->addWidget(pushButton_cancel);


        verticalLayout->addWidget(frame_controls);


        retranslateUi(SettingsDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Settings", nullptr));
        label_autoSaveFileName->setText(QApplication::translate("SettingsDialog", "Auto-save File", nullptr));
        label_autoSaveFileDirectory->setText(QApplication::translate("SettingsDialog", "Directory", nullptr));
        pushButton_autoSaveFileDirectory->setText(QApplication::translate("SettingsDialog", "Browse", nullptr));
        label_autoSaveGenerateOnRun->setText(QApplication::translate("SettingsDialog", "Generate new auto-save file on run", nullptr));
        checkBox_autoSaveGenerateOnRun->setText(QString());
        label_autoSaveGenerateTimeStamp->setText(QApplication::translate("SettingsDialog", "Include time stamp", nullptr));
        checkBox_autoSaveGenerateTimeStamp->setText(QString());
        label_autoSaveLabel->setText(QApplication::translate("SettingsDialog", "Auto-save label", nullptr));
        checkBox_autoSaveLabel->setText(QApplication::translate("SettingsDialog", "Show", nullptr));
        label_autoSaveHeader->setText(QApplication::translate("SettingsDialog", "Show auto-save header", nullptr));
        checkBox_autoSaveHeader->setText(QString());
        label_autoSaveDataSetLabel->setText(QApplication::translate("SettingsDialog", "Data set label", nullptr));
        checkBox_autoSaveDataSetLabel->setText(QApplication::translate("SettingsDialog", "Show", nullptr));
        label_autoSaveDataSetInfo->setText(QApplication::translate("SettingsDialog", "Show data set info", nullptr));
        checkBox_autoSaveDataSetInfo->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_autoSave), QApplication::translate("SettingsDialog", "Auto-save", nullptr));
        label_saveUserParameters->setText(QApplication::translate("SettingsDialog", "Show user parameters", nullptr));
        checkBox_saveUserParameters->setText(QString());
        label_saveDataFileInfo->setText(QApplication::translate("SettingsDialog", "Show data file info", nullptr));
        checkBox_saveDataFileInfo->setText(QString());
        label_saveDataSetLabel->setText(QApplication::translate("SettingsDialog", "Data set label", nullptr));
        checkBox_saveDataSetLabel->setText(QApplication::translate("SettingsDialog", "Show", nullptr));
        label_saveDataSetInfo->setText(QApplication::translate("SettingsDialog", "Show data set info", nullptr));
        checkBox_saveDataSetInfo->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_save), QApplication::translate("SettingsDialog", "Save", nullptr));
        label_parametersExportOnRun->setText(QApplication::translate("SettingsDialog", "Auto-export parameters on run", nullptr));
        checkBox_parametersExportOnRun->setText(QString());
        label_parametersFile->setText(QApplication::translate("SettingsDialog", "Parameter file", nullptr));
        pushButton_parametersFile->setText(QApplication::translate("SettingsDialog", "Change", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_parameters), QApplication::translate("SettingsDialog", "Parameters", nullptr));
        label_pythonDependencies->setText(QApplication::translate("SettingsDialog", "Python Dependencies", nullptr));
        pushButton_pythonDependenciesAdd->setText(QApplication::translate("SettingsDialog", "Add", nullptr));
        pushButton_pythonDependenciesRemove->setText(QApplication::translate("SettingsDialog", "Remove", nullptr));
        label_pythonRunStatus->setText(QApplication::translate("SettingsDialog", "Report script run status", nullptr));
        checkBox_pythonRunStatus->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_python), QApplication::translate("SettingsDialog", "Python", nullptr));
        pushButton_save->setText(QApplication::translate("SettingsDialog", "Save", nullptr));
        pushButton_cancel->setText(QApplication::translate("SettingsDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H

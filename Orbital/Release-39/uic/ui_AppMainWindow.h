/********************************************************************************
** Form generated from reading UI file 'AppMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPMAINWINDOW_H
#define UI_APPMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppMainWindowClass
{
public:
    QAction *actionError_Log;
    QAction *actionCurrent_Module;
    QAction *actionVisa_Setup;
    QAction *actionCustom_Controls;
    QAction *actionPlot_Editor;
    QAction *actionSettings;
    QAction *actionData_Info;
    QAction *actionCreate_New;
    QAction *actionLoad;
    QAction *actionReload;
    QAction *actionReference_Manual;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_controlPanel;
    QVBoxLayout *verticalLayout_controlPanel;
    QFrame *frame_mainControls;
    QGridLayout *gridLayout_mainControls;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_load;
    QFrame *frame_saveControls;
    QVBoxLayout *verticalLayout_saveControls;
    QPushButton *pushButton_save;
    QFrame *frame_autoSave;
    QHBoxLayout *horizontalLayout_autoSave;
    QCheckBox *checkBox_autoSave;
    QPushButton *pushButton_run;
    QFrame *frame_customControls;
    QGridLayout *gridLayout_customControls;
    QGroupBox *groupBox_scriptStatus;
    QVBoxLayout *verticalLayout_scriptStatus;
    QPlainTextEdit *plainTextEdit_scriptStatus;
    QFrame *frame_scriptParams;
    QVBoxLayout *verticalLayout;
    QFrame *frame_scriptParamsHeader;
    QHBoxLayout *horizontalLayout_scriptParamsHeader;
    QLabel *label_userParam;
    QLineEdit *lineEdit_userParam;
    QPushButton *pushButton_importParams;
    QPushButton *pushButton_exportParams;
    QTableWidget *tableWidget_scriptParams;
    QGroupBox *groupBox_scriptNotes;
    QVBoxLayout *verticalLayout_scriptNotes;
    QPlainTextEdit *plainTextEdit_scriptNotes;
    QFrame *frame_errorStatus;
    QVBoxLayout *verticalLayout_errorStatus;
    QPlainTextEdit *plainTextEdit_errorStatus;
    QFrame *frame_plotPanel;
    QVBoxLayout *verticalLayout_plotPanel;
    QScrollArea *scrollArea_plotPanel;
    QWidget *scrollAreaWidgetContents_plotPanel;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuScript;
    QMenu *menuExamples;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AppMainWindowClass)
    {
        if (AppMainWindowClass->objectName().isEmpty())
            AppMainWindowClass->setObjectName(QString::fromUtf8("AppMainWindowClass"));
        AppMainWindowClass->resize(1634, 1144);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/AppMainWindow/Resources/Orbital.ico"), QSize(), QIcon::Normal, QIcon::Off);
        AppMainWindowClass->setWindowIcon(icon);
        actionError_Log = new QAction(AppMainWindowClass);
        actionError_Log->setObjectName(QString::fromUtf8("actionError_Log"));
        actionCurrent_Module = new QAction(AppMainWindowClass);
        actionCurrent_Module->setObjectName(QString::fromUtf8("actionCurrent_Module"));
        actionVisa_Setup = new QAction(AppMainWindowClass);
        actionVisa_Setup->setObjectName(QString::fromUtf8("actionVisa_Setup"));
        actionCustom_Controls = new QAction(AppMainWindowClass);
        actionCustom_Controls->setObjectName(QString::fromUtf8("actionCustom_Controls"));
        actionPlot_Editor = new QAction(AppMainWindowClass);
        actionPlot_Editor->setObjectName(QString::fromUtf8("actionPlot_Editor"));
        actionSettings = new QAction(AppMainWindowClass);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionData_Info = new QAction(AppMainWindowClass);
        actionData_Info->setObjectName(QString::fromUtf8("actionData_Info"));
        actionCreate_New = new QAction(AppMainWindowClass);
        actionCreate_New->setObjectName(QString::fromUtf8("actionCreate_New"));
        actionLoad = new QAction(AppMainWindowClass);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionReload = new QAction(AppMainWindowClass);
        actionReload->setObjectName(QString::fromUtf8("actionReload"));
        actionReference_Manual = new QAction(AppMainWindowClass);
        actionReference_Manual->setObjectName(QString::fromUtf8("actionReference_Manual"));
        centralWidget = new QWidget(AppMainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1634, 1103));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frame_controlPanel = new QFrame(scrollAreaWidgetContents);
        frame_controlPanel->setObjectName(QString::fromUtf8("frame_controlPanel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_controlPanel->sizePolicy().hasHeightForWidth());
        frame_controlPanel->setSizePolicy(sizePolicy);
        frame_controlPanel->setMinimumSize(QSize(256, 0));
        frame_controlPanel->setMaximumSize(QSize(256, 16777215));
        frame_controlPanel->setAutoFillBackground(true);
        frame_controlPanel->setFrameShape(QFrame::NoFrame);
        verticalLayout_controlPanel = new QVBoxLayout(frame_controlPanel);
        verticalLayout_controlPanel->setSpacing(6);
        verticalLayout_controlPanel->setContentsMargins(11, 11, 11, 11);
        verticalLayout_controlPanel->setObjectName(QString::fromUtf8("verticalLayout_controlPanel"));
        verticalLayout_controlPanel->setContentsMargins(0, 0, 0, 0);
        frame_mainControls = new QFrame(frame_controlPanel);
        frame_mainControls->setObjectName(QString::fromUtf8("frame_mainControls"));
        frame_mainControls->setFrameShape(QFrame::StyledPanel);
        frame_mainControls->setFrameShadow(QFrame::Plain);
        gridLayout_mainControls = new QGridLayout(frame_mainControls);
        gridLayout_mainControls->setSpacing(4);
        gridLayout_mainControls->setContentsMargins(11, 11, 11, 11);
        gridLayout_mainControls->setObjectName(QString::fromUtf8("gridLayout_mainControls"));
        gridLayout_mainControls->setContentsMargins(4, 4, 4, 4);
        pushButton_stop = new QPushButton(frame_mainControls);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_stop->sizePolicy().hasHeightForWidth());
        pushButton_stop->setSizePolicy(sizePolicy1);
        pushButton_stop->setMinimumSize(QSize(0, 48));
        pushButton_stop->setMaximumSize(QSize(16777215, 48));
        QFont font;
        font.setPointSize(10);
        pushButton_stop->setFont(font);

        gridLayout_mainControls->addWidget(pushButton_stop, 1, 1, 1, 1);

        pushButton_load = new QPushButton(frame_mainControls);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));
        sizePolicy1.setHeightForWidth(pushButton_load->sizePolicy().hasHeightForWidth());
        pushButton_load->setSizePolicy(sizePolicy1);
        pushButton_load->setMinimumSize(QSize(0, 48));
        pushButton_load->setMaximumSize(QSize(16777215, 48));
        pushButton_load->setFont(font);

        gridLayout_mainControls->addWidget(pushButton_load, 0, 0, 1, 1);

        frame_saveControls = new QFrame(frame_mainControls);
        frame_saveControls->setObjectName(QString::fromUtf8("frame_saveControls"));
        sizePolicy1.setHeightForWidth(frame_saveControls->sizePolicy().hasHeightForWidth());
        frame_saveControls->setSizePolicy(sizePolicy1);
        frame_saveControls->setMinimumSize(QSize(0, 48));
        frame_saveControls->setMaximumSize(QSize(16777215, 48));
        frame_saveControls->setFrameShape(QFrame::NoFrame);
        frame_saveControls->setFrameShadow(QFrame::Raised);
        verticalLayout_saveControls = new QVBoxLayout(frame_saveControls);
        verticalLayout_saveControls->setSpacing(0);
        verticalLayout_saveControls->setContentsMargins(11, 11, 11, 11);
        verticalLayout_saveControls->setObjectName(QString::fromUtf8("verticalLayout_saveControls"));
        verticalLayout_saveControls->setContentsMargins(0, 0, 0, 0);
        pushButton_save = new QPushButton(frame_saveControls);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        sizePolicy1.setHeightForWidth(pushButton_save->sizePolicy().hasHeightForWidth());
        pushButton_save->setSizePolicy(sizePolicy1);
        pushButton_save->setMinimumSize(QSize(0, 26));
        pushButton_save->setMaximumSize(QSize(16777215, 26));

        verticalLayout_saveControls->addWidget(pushButton_save);

        frame_autoSave = new QFrame(frame_saveControls);
        frame_autoSave->setObjectName(QString::fromUtf8("frame_autoSave"));
        frame_autoSave->setFrameShape(QFrame::NoFrame);
        frame_autoSave->setFrameShadow(QFrame::Raised);
        horizontalLayout_autoSave = new QHBoxLayout(frame_autoSave);
        horizontalLayout_autoSave->setSpacing(0);
        horizontalLayout_autoSave->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_autoSave->setObjectName(QString::fromUtf8("horizontalLayout_autoSave"));
        horizontalLayout_autoSave->setContentsMargins(6, 0, 0, 0);
        checkBox_autoSave = new QCheckBox(frame_autoSave);
        checkBox_autoSave->setObjectName(QString::fromUtf8("checkBox_autoSave"));
        checkBox_autoSave->setEnabled(false);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(227, 227, 227, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush2(QColor(105, 105, 105, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        QBrush brush3(QColor(0, 0, 0, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        checkBox_autoSave->setPalette(palette);

        horizontalLayout_autoSave->addWidget(checkBox_autoSave);


        verticalLayout_saveControls->addWidget(frame_autoSave);


        gridLayout_mainControls->addWidget(frame_saveControls, 1, 0, 1, 1);

        pushButton_run = new QPushButton(frame_mainControls);
        pushButton_run->setObjectName(QString::fromUtf8("pushButton_run"));
        sizePolicy1.setHeightForWidth(pushButton_run->sizePolicy().hasHeightForWidth());
        pushButton_run->setSizePolicy(sizePolicy1);
        pushButton_run->setMinimumSize(QSize(0, 48));
        pushButton_run->setMaximumSize(QSize(16777215, 48));
        pushButton_run->setFont(font);

        gridLayout_mainControls->addWidget(pushButton_run, 0, 1, 1, 1);

        frame_customControls = new QFrame(frame_mainControls);
        frame_customControls->setObjectName(QString::fromUtf8("frame_customControls"));
        frame_customControls->setFrameShape(QFrame::StyledPanel);
        gridLayout_customControls = new QGridLayout(frame_customControls);
        gridLayout_customControls->setSpacing(0);
        gridLayout_customControls->setContentsMargins(11, 11, 11, 11);
        gridLayout_customControls->setObjectName(QString::fromUtf8("gridLayout_customControls"));
        gridLayout_customControls->setContentsMargins(1, 1, 1, 1);

        gridLayout_mainControls->addWidget(frame_customControls, 2, 0, 1, 2);


        verticalLayout_controlPanel->addWidget(frame_mainControls);

        groupBox_scriptStatus = new QGroupBox(frame_controlPanel);
        groupBox_scriptStatus->setObjectName(QString::fromUtf8("groupBox_scriptStatus"));
        sizePolicy1.setHeightForWidth(groupBox_scriptStatus->sizePolicy().hasHeightForWidth());
        groupBox_scriptStatus->setSizePolicy(sizePolicy1);
        groupBox_scriptStatus->setMinimumSize(QSize(0, 128));
        groupBox_scriptStatus->setMaximumSize(QSize(16777215, 128));
        verticalLayout_scriptStatus = new QVBoxLayout(groupBox_scriptStatus);
        verticalLayout_scriptStatus->setSpacing(6);
        verticalLayout_scriptStatus->setContentsMargins(11, 11, 11, 11);
        verticalLayout_scriptStatus->setObjectName(QString::fromUtf8("verticalLayout_scriptStatus"));
        verticalLayout_scriptStatus->setContentsMargins(9, 4, 9, 9);
        plainTextEdit_scriptStatus = new QPlainTextEdit(groupBox_scriptStatus);
        plainTextEdit_scriptStatus->setObjectName(QString::fromUtf8("plainTextEdit_scriptStatus"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(plainTextEdit_scriptStatus->sizePolicy().hasHeightForWidth());
        plainTextEdit_scriptStatus->setSizePolicy(sizePolicy2);
        QPalette palette1;
        QBrush brush4(QColor(239, 239, 239, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        QBrush brush5(QColor(240, 240, 240, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        plainTextEdit_scriptStatus->setPalette(palette1);
        plainTextEdit_scriptStatus->setReadOnly(true);

        verticalLayout_scriptStatus->addWidget(plainTextEdit_scriptStatus);


        verticalLayout_controlPanel->addWidget(groupBox_scriptStatus);

        frame_scriptParams = new QFrame(frame_controlPanel);
        frame_scriptParams->setObjectName(QString::fromUtf8("frame_scriptParams"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame_scriptParams->sizePolicy().hasHeightForWidth());
        frame_scriptParams->setSizePolicy(sizePolicy3);
        frame_scriptParams->setFrameShape(QFrame::StyledPanel);
        verticalLayout = new QVBoxLayout(frame_scriptParams);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_scriptParamsHeader = new QFrame(frame_scriptParams);
        frame_scriptParamsHeader->setObjectName(QString::fromUtf8("frame_scriptParamsHeader"));
        sizePolicy1.setHeightForWidth(frame_scriptParamsHeader->sizePolicy().hasHeightForWidth());
        frame_scriptParamsHeader->setSizePolicy(sizePolicy1);
        frame_scriptParamsHeader->setMinimumSize(QSize(0, 23));
        frame_scriptParamsHeader->setMaximumSize(QSize(16777215, 23));
        frame_scriptParamsHeader->setFrameShape(QFrame::NoFrame);
        frame_scriptParamsHeader->setFrameShadow(QFrame::Plain);
        frame_scriptParamsHeader->setLineWidth(0);
        horizontalLayout_scriptParamsHeader = new QHBoxLayout(frame_scriptParamsHeader);
        horizontalLayout_scriptParamsHeader->setSpacing(4);
        horizontalLayout_scriptParamsHeader->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_scriptParamsHeader->setObjectName(QString::fromUtf8("horizontalLayout_scriptParamsHeader"));
        horizontalLayout_scriptParamsHeader->setContentsMargins(0, 0, 0, 0);
        label_userParam = new QLabel(frame_scriptParamsHeader);
        label_userParam->setObjectName(QString::fromUtf8("label_userParam"));
        label_userParam->setFont(font);

        horizontalLayout_scriptParamsHeader->addWidget(label_userParam);

        lineEdit_userParam = new QLineEdit(frame_scriptParamsHeader);
        lineEdit_userParam->setObjectName(QString::fromUtf8("lineEdit_userParam"));
        lineEdit_userParam->setMinimumSize(QSize(0, 21));

        horizontalLayout_scriptParamsHeader->addWidget(lineEdit_userParam);

        pushButton_importParams = new QPushButton(frame_scriptParamsHeader);
        pushButton_importParams->setObjectName(QString::fromUtf8("pushButton_importParams"));
        pushButton_importParams->setMinimumSize(QSize(48, 0));
        pushButton_importParams->setMaximumSize(QSize(64, 16777215));

        horizontalLayout_scriptParamsHeader->addWidget(pushButton_importParams);

        pushButton_exportParams = new QPushButton(frame_scriptParamsHeader);
        pushButton_exportParams->setObjectName(QString::fromUtf8("pushButton_exportParams"));
        pushButton_exportParams->setMinimumSize(QSize(48, 0));
        pushButton_exportParams->setMaximumSize(QSize(64, 16777215));

        horizontalLayout_scriptParamsHeader->addWidget(pushButton_exportParams);


        verticalLayout->addWidget(frame_scriptParamsHeader);

        tableWidget_scriptParams = new QTableWidget(frame_scriptParams);
        if (tableWidget_scriptParams->columnCount() < 2)
            tableWidget_scriptParams->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_scriptParams->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_scriptParams->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_scriptParams->setObjectName(QString::fromUtf8("tableWidget_scriptParams"));
        sizePolicy2.setHeightForWidth(tableWidget_scriptParams->sizePolicy().hasHeightForWidth());
        tableWidget_scriptParams->setSizePolicy(sizePolicy2);
        tableWidget_scriptParams->horizontalHeader()->setStretchLastSection(true);
        tableWidget_scriptParams->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(tableWidget_scriptParams);


        verticalLayout_controlPanel->addWidget(frame_scriptParams);

        groupBox_scriptNotes = new QGroupBox(frame_controlPanel);
        groupBox_scriptNotes->setObjectName(QString::fromUtf8("groupBox_scriptNotes"));
        sizePolicy1.setHeightForWidth(groupBox_scriptNotes->sizePolicy().hasHeightForWidth());
        groupBox_scriptNotes->setSizePolicy(sizePolicy1);
        groupBox_scriptNotes->setMinimumSize(QSize(0, 128));
        groupBox_scriptNotes->setMaximumSize(QSize(16777215, 128));
        verticalLayout_scriptNotes = new QVBoxLayout(groupBox_scriptNotes);
        verticalLayout_scriptNotes->setSpacing(6);
        verticalLayout_scriptNotes->setContentsMargins(11, 11, 11, 11);
        verticalLayout_scriptNotes->setObjectName(QString::fromUtf8("verticalLayout_scriptNotes"));
        verticalLayout_scriptNotes->setContentsMargins(-1, 4, -1, -1);
        plainTextEdit_scriptNotes = new QPlainTextEdit(groupBox_scriptNotes);
        plainTextEdit_scriptNotes->setObjectName(QString::fromUtf8("plainTextEdit_scriptNotes"));
        sizePolicy2.setHeightForWidth(plainTextEdit_scriptNotes->sizePolicy().hasHeightForWidth());
        plainTextEdit_scriptNotes->setSizePolicy(sizePolicy2);

        verticalLayout_scriptNotes->addWidget(plainTextEdit_scriptNotes);


        verticalLayout_controlPanel->addWidget(groupBox_scriptNotes);

        frame_errorStatus = new QFrame(frame_controlPanel);
        frame_errorStatus->setObjectName(QString::fromUtf8("frame_errorStatus"));
        sizePolicy1.setHeightForWidth(frame_errorStatus->sizePolicy().hasHeightForWidth());
        frame_errorStatus->setSizePolicy(sizePolicy1);
        frame_errorStatus->setMinimumSize(QSize(0, 128));
        frame_errorStatus->setMaximumSize(QSize(16777215, 128));
        frame_errorStatus->setFrameShape(QFrame::StyledPanel);
        frame_errorStatus->setFrameShadow(QFrame::Plain);
        verticalLayout_errorStatus = new QVBoxLayout(frame_errorStatus);
        verticalLayout_errorStatus->setSpacing(6);
        verticalLayout_errorStatus->setContentsMargins(11, 11, 11, 11);
        verticalLayout_errorStatus->setObjectName(QString::fromUtf8("verticalLayout_errorStatus"));
        plainTextEdit_errorStatus = new QPlainTextEdit(frame_errorStatus);
        plainTextEdit_errorStatus->setObjectName(QString::fromUtf8("plainTextEdit_errorStatus"));
        sizePolicy2.setHeightForWidth(plainTextEdit_errorStatus->sizePolicy().hasHeightForWidth());
        plainTextEdit_errorStatus->setSizePolicy(sizePolicy2);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        plainTextEdit_errorStatus->setPalette(palette2);
        plainTextEdit_errorStatus->setReadOnly(true);

        verticalLayout_errorStatus->addWidget(plainTextEdit_errorStatus);


        verticalLayout_controlPanel->addWidget(frame_errorStatus);


        horizontalLayout_2->addWidget(frame_controlPanel);

        frame_plotPanel = new QFrame(scrollAreaWidgetContents);
        frame_plotPanel->setObjectName(QString::fromUtf8("frame_plotPanel"));
        frame_plotPanel->setMinimumSize(QSize(256, 256));
        frame_plotPanel->setAutoFillBackground(true);
        frame_plotPanel->setFrameShape(QFrame::StyledPanel);
        frame_plotPanel->setFrameShadow(QFrame::Plain);
        verticalLayout_plotPanel = new QVBoxLayout(frame_plotPanel);
        verticalLayout_plotPanel->setSpacing(6);
        verticalLayout_plotPanel->setContentsMargins(11, 11, 11, 11);
        verticalLayout_plotPanel->setObjectName(QString::fromUtf8("verticalLayout_plotPanel"));
        verticalLayout_plotPanel->setContentsMargins(1, 1, 1, 1);
        scrollArea_plotPanel = new QScrollArea(frame_plotPanel);
        scrollArea_plotPanel->setObjectName(QString::fromUtf8("scrollArea_plotPanel"));
        scrollArea_plotPanel->setFrameShape(QFrame::NoFrame);
        scrollArea_plotPanel->setWidgetResizable(true);
        scrollAreaWidgetContents_plotPanel = new QWidget();
        scrollAreaWidgetContents_plotPanel->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_plotPanel"));
        scrollAreaWidgetContents_plotPanel->setGeometry(QRect(0, 0, 1350, 1081));
        scrollArea_plotPanel->setWidget(scrollAreaWidgetContents_plotPanel);

        verticalLayout_plotPanel->addWidget(scrollArea_plotPanel);


        horizontalLayout_2->addWidget(frame_plotPanel);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        AppMainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AppMainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1634, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuScript = new QMenu(menuBar);
        menuScript->setObjectName(QString::fromUtf8("menuScript"));
        menuExamples = new QMenu(menuScript);
        menuExamples->setObjectName(QString::fromUtf8("menuExamples"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        AppMainWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(AppMainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AppMainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuScript->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionCustom_Controls);
        menuFile->addAction(actionPlot_Editor);
        menuFile->addAction(actionData_Info);
        menuFile->addAction(actionSettings);
        menuScript->addAction(actionCurrent_Module);
        menuScript->addAction(actionVisa_Setup);
        menuScript->addSeparator();
        menuScript->addAction(actionCreate_New);
        menuScript->addAction(menuExamples->menuAction());
        menuHelp->addAction(actionError_Log);
        menuHelp->addAction(actionReference_Manual);

        retranslateUi(AppMainWindowClass);

        QMetaObject::connectSlotsByName(AppMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *AppMainWindowClass)
    {
        AppMainWindowClass->setWindowTitle(QApplication::translate("AppMainWindowClass", "Orbital", nullptr));
        actionError_Log->setText(QApplication::translate("AppMainWindowClass", "Error Log", nullptr));
        actionCurrent_Module->setText(QApplication::translate("AppMainWindowClass", "Current Module", nullptr));
        actionVisa_Setup->setText(QApplication::translate("AppMainWindowClass", "Visa Setup", nullptr));
        actionCustom_Controls->setText(QApplication::translate("AppMainWindowClass", "Custom Controls", nullptr));
        actionPlot_Editor->setText(QApplication::translate("AppMainWindowClass", "Plot Editor", nullptr));
        actionSettings->setText(QApplication::translate("AppMainWindowClass", "Settings", nullptr));
        actionData_Info->setText(QApplication::translate("AppMainWindowClass", "Data Info", nullptr));
        actionCreate_New->setText(QApplication::translate("AppMainWindowClass", "Create New", nullptr));
        actionLoad->setText(QApplication::translate("AppMainWindowClass", "Load", nullptr));
        actionReload->setText(QApplication::translate("AppMainWindowClass", "Reload", nullptr));
        actionReference_Manual->setText(QApplication::translate("AppMainWindowClass", "Reference Manual", nullptr));
        pushButton_stop->setText(QApplication::translate("AppMainWindowClass", "Stop", nullptr));
        pushButton_load->setText(QApplication::translate("AppMainWindowClass", "Load Module", nullptr));
        pushButton_save->setText(QApplication::translate("AppMainWindowClass", "Save Data As", nullptr));
        checkBox_autoSave->setText(QApplication::translate("AppMainWindowClass", "Auto-Save", nullptr));
        pushButton_run->setText(QApplication::translate("AppMainWindowClass", "Run", nullptr));
        groupBox_scriptStatus->setTitle(QApplication::translate("AppMainWindowClass", "Script Status", nullptr));
        label_userParam->setText(QApplication::translate("AppMainWindowClass", "User", nullptr));
        pushButton_importParams->setText(QApplication::translate("AppMainWindowClass", "Import", nullptr));
        pushButton_exportParams->setText(QApplication::translate("AppMainWindowClass", "Export", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_scriptParams->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("AppMainWindowClass", "Parameter", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_scriptParams->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("AppMainWindowClass", "Value", nullptr));
        groupBox_scriptNotes->setTitle(QApplication::translate("AppMainWindowClass", "Notes", nullptr));
        menuFile->setTitle(QApplication::translate("AppMainWindowClass", "File", nullptr));
        menuScript->setTitle(QApplication::translate("AppMainWindowClass", "Script", nullptr));
        menuExamples->setTitle(QApplication::translate("AppMainWindowClass", "Examples", nullptr));
        menuHelp->setTitle(QApplication::translate("AppMainWindowClass", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppMainWindowClass: public Ui_AppMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPMAINWINDOW_H

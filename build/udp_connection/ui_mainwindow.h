/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QAction *action_Preferences;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *receivedMessageLabel;
    QLineEdit *messageLineEdit;
    QPushButton *sendButton;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *conditionLabel;
    QLineEdit *ipAddressLineEdit;
    QPushButton *setIPAddressButton;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(944, 704);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(MainWindowDesign);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Quit->setShortcutContext(Qt::ShortcutContext::ApplicationShortcut);
        action_Preferences = new QAction(MainWindowDesign);
        action_Preferences->setObjectName(QString::fromUtf8("action_Preferences"));
        actionAbout = new QAction(MainWindowDesign);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(MainWindowDesign);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 480, 941, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        receivedMessageLabel = new QLabel(verticalLayoutWidget);
        receivedMessageLabel->setObjectName(QString::fromUtf8("receivedMessageLabel"));

        verticalLayout->addWidget(receivedMessageLabel);

        messageLineEdit = new QLineEdit(verticalLayoutWidget);
        messageLineEdit->setObjectName(QString::fromUtf8("messageLineEdit"));

        verticalLayout->addWidget(messageLineEdit);

        sendButton = new QPushButton(verticalLayoutWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        verticalLayout->addWidget(sendButton);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(770, 10, 160, 81));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        conditionLabel = new QLabel(verticalLayoutWidget_2);
        conditionLabel->setObjectName(QString::fromUtf8("conditionLabel"));
        conditionLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(conditionLabel);

        ipAddressLineEdit = new QLineEdit(verticalLayoutWidget_2);
        ipAddressLineEdit->setObjectName(QString::fromUtf8("ipAddressLineEdit"));

        verticalLayout_2->addWidget(ipAddressLineEdit);

        setIPAddressButton = new QPushButton(verticalLayoutWidget_2);
        setIPAddressButton->setObjectName(QString::fromUtf8("setIPAddressButton"));

        verticalLayout_2->addWidget(setIPAddressButton);

        MainWindowDesign->setCentralWidget(centralwidget);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QCoreApplication::translate("MainWindowDesign", "QRosApp", nullptr));
        action_Quit->setText(QCoreApplication::translate("MainWindowDesign", "&Quit", nullptr));
#if QT_CONFIG(shortcut)
        action_Quit->setShortcut(QCoreApplication::translate("MainWindowDesign", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Preferences->setText(QCoreApplication::translate("MainWindowDesign", "&Preferences", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindowDesign", "&About", nullptr));
        actionAbout_Qt->setText(QCoreApplication::translate("MainWindowDesign", "About &Qt", nullptr));
        receivedMessageLabel->setText(QCoreApplication::translate("MainWindowDesign", "received msg", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindowDesign", "Send", nullptr));
        conditionLabel->setText(QCoreApplication::translate("MainWindowDesign", "condition", nullptr));
        setIPAddressButton->setText(QCoreApplication::translate("MainWindowDesign", "Setting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

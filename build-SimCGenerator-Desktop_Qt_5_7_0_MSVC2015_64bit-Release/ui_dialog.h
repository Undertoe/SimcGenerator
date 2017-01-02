/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QTabWidget *tabWidget;
    QWidget *tabTalents;
    QPushButton *buttonGenerateTalents;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *comboBoxClass;
    QComboBox *comboBoxSpec;
    QLabel *label_8;
    QLabel *label_9;
    QCheckBox *checkBox1_1;
    QCheckBox *checkBox2_1;
    QCheckBox *checkBox3_1;
    QCheckBox *checkBox4_1;
    QCheckBox *checkBox5_1;
    QCheckBox *checkBox6_1;
    QCheckBox *checkBox7_1;
    QCheckBox *checkBox6_2;
    QCheckBox *checkBox3_2;
    QCheckBox *checkBox2_2;
    QCheckBox *checkBox1_2;
    QCheckBox *checkBox4_2;
    QCheckBox *checkBox5_2;
    QCheckBox *checkBox7_2;
    QCheckBox *checkBox5_3;
    QCheckBox *checkBox2_3;
    QCheckBox *checkBox4_3;
    QCheckBox *checkBox6_3;
    QCheckBox *checkBox1_3;
    QCheckBox *checkBox7_3;
    QCheckBox *checkBox3_3;
    QLabel *labelTalentsTabInfo;
    QCheckBox *checkBoxIgnoreZeros;
    QWidget *tabGear;
    QPushButton *buttonGenerateGear;
    QPushButton *buttonAddGear;
    QListView *listViewGearList;
    QPushButton *buttonRemoveGear;
    QLabel *label_12;
    QComboBox *comboBoxSpec_3;
    QLabel *label_13;
    QComboBox *comboBoxClass_3;
    QLabel *labelGearInfo;
    QPushButton *buttonEditGear;
    QWidget *tabRelics;
    QPushButton *buttonGenerateRelic;
    QPushButton *buttonAddRelic;
    QPushButton *buttonRemoveRelic;
    QListView *listViewRelicList;
    QLabel *label_10;
    QComboBox *comboBoxSpec_2;
    QLabel *label_11;
    QComboBox *comboBoxClass_2;
    QLabel *labelRelicInfo;
    QPlainTextEdit *textEditAPL;
    QPushButton *buttonOutputFile;
    QTextEdit *textEditFileSave;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(833, 640);
        Dialog->setMinimumSize(QSize(833, 640));
        Dialog->setMaximumSize(QSize(833, 640));
        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 811, 241));
        tabTalents = new QWidget();
        tabTalents->setObjectName(QStringLiteral("tabTalents"));
        buttonGenerateTalents = new QPushButton(tabTalents);
        buttonGenerateTalents->setObjectName(QStringLiteral("buttonGenerateTalents"));
        buttonGenerateTalents->setGeometry(QRect(692, 170, 101, 32));
        label = new QLabel(tabTalents);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 60, 16));
        label_2 = new QLabel(tabTalents);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 60, 16));
        label_3 = new QLabel(tabTalents);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 70, 60, 16));
        label_4 = new QLabel(tabTalents);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 100, 60, 16));
        label_5 = new QLabel(tabTalents);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 130, 60, 16));
        label_6 = new QLabel(tabTalents);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 160, 60, 16));
        label_7 = new QLabel(tabTalents);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 190, 60, 16));
        comboBoxClass = new QComboBox(tabTalents);
        comboBoxClass->setObjectName(QStringLiteral("comboBoxClass"));
        comboBoxClass->setGeometry(QRect(690, 90, 100, 26));
        comboBoxSpec = new QComboBox(tabTalents);
        comboBoxSpec->setObjectName(QStringLiteral("comboBoxSpec"));
        comboBoxSpec->setGeometry(QRect(690, 140, 100, 26));
        label_8 = new QLabel(tabTalents);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(710, 70, 60, 16));
        label_9 = new QLabel(tabTalents);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(710, 120, 60, 16));
        checkBox1_1 = new QCheckBox(tabTalents);
        checkBox1_1->setObjectName(QStringLiteral("checkBox1_1"));
        checkBox1_1->setGeometry(QRect(80, 10, 175, 20));
        checkBox2_1 = new QCheckBox(tabTalents);
        checkBox2_1->setObjectName(QStringLiteral("checkBox2_1"));
        checkBox2_1->setGeometry(QRect(80, 40, 175, 20));
        checkBox3_1 = new QCheckBox(tabTalents);
        checkBox3_1->setObjectName(QStringLiteral("checkBox3_1"));
        checkBox3_1->setGeometry(QRect(80, 70, 175, 20));
        checkBox4_1 = new QCheckBox(tabTalents);
        checkBox4_1->setObjectName(QStringLiteral("checkBox4_1"));
        checkBox4_1->setGeometry(QRect(80, 100, 175, 20));
        checkBox5_1 = new QCheckBox(tabTalents);
        checkBox5_1->setObjectName(QStringLiteral("checkBox5_1"));
        checkBox5_1->setGeometry(QRect(80, 130, 175, 20));
        checkBox6_1 = new QCheckBox(tabTalents);
        checkBox6_1->setObjectName(QStringLiteral("checkBox6_1"));
        checkBox6_1->setGeometry(QRect(80, 160, 175, 20));
        checkBox7_1 = new QCheckBox(tabTalents);
        checkBox7_1->setObjectName(QStringLiteral("checkBox7_1"));
        checkBox7_1->setGeometry(QRect(80, 190, 175, 20));
        checkBox6_2 = new QCheckBox(tabTalents);
        checkBox6_2->setObjectName(QStringLiteral("checkBox6_2"));
        checkBox6_2->setGeometry(QRect(275, 160, 175, 20));
        checkBox3_2 = new QCheckBox(tabTalents);
        checkBox3_2->setObjectName(QStringLiteral("checkBox3_2"));
        checkBox3_2->setGeometry(QRect(275, 70, 175, 20));
        checkBox2_2 = new QCheckBox(tabTalents);
        checkBox2_2->setObjectName(QStringLiteral("checkBox2_2"));
        checkBox2_2->setGeometry(QRect(275, 40, 175, 20));
        checkBox1_2 = new QCheckBox(tabTalents);
        checkBox1_2->setObjectName(QStringLiteral("checkBox1_2"));
        checkBox1_2->setGeometry(QRect(275, 10, 175, 20));
        checkBox4_2 = new QCheckBox(tabTalents);
        checkBox4_2->setObjectName(QStringLiteral("checkBox4_2"));
        checkBox4_2->setGeometry(QRect(275, 100, 175, 20));
        checkBox5_2 = new QCheckBox(tabTalents);
        checkBox5_2->setObjectName(QStringLiteral("checkBox5_2"));
        checkBox5_2->setGeometry(QRect(275, 130, 175, 20));
        checkBox7_2 = new QCheckBox(tabTalents);
        checkBox7_2->setObjectName(QStringLiteral("checkBox7_2"));
        checkBox7_2->setGeometry(QRect(275, 190, 175, 20));
        checkBox5_3 = new QCheckBox(tabTalents);
        checkBox5_3->setObjectName(QStringLiteral("checkBox5_3"));
        checkBox5_3->setGeometry(QRect(470, 130, 200, 20));
        checkBox2_3 = new QCheckBox(tabTalents);
        checkBox2_3->setObjectName(QStringLiteral("checkBox2_3"));
        checkBox2_3->setGeometry(QRect(470, 40, 200, 20));
        checkBox4_3 = new QCheckBox(tabTalents);
        checkBox4_3->setObjectName(QStringLiteral("checkBox4_3"));
        checkBox4_3->setGeometry(QRect(470, 100, 200, 20));
        checkBox6_3 = new QCheckBox(tabTalents);
        checkBox6_3->setObjectName(QStringLiteral("checkBox6_3"));
        checkBox6_3->setGeometry(QRect(470, 160, 200, 20));
        checkBox1_3 = new QCheckBox(tabTalents);
        checkBox1_3->setObjectName(QStringLiteral("checkBox1_3"));
        checkBox1_3->setGeometry(QRect(470, 10, 200, 20));
        checkBox7_3 = new QCheckBox(tabTalents);
        checkBox7_3->setObjectName(QStringLiteral("checkBox7_3"));
        checkBox7_3->setGeometry(QRect(470, 190, 200, 20));
        checkBox3_3 = new QCheckBox(tabTalents);
        checkBox3_3->setObjectName(QStringLiteral("checkBox3_3"));
        checkBox3_3->setGeometry(QRect(470, 70, 200, 20));
        labelTalentsTabInfo = new QLabel(tabTalents);
        labelTalentsTabInfo->setObjectName(QStringLiteral("labelTalentsTabInfo"));
        labelTalentsTabInfo->setGeometry(QRect(690, 0, 100, 41));
        labelTalentsTabInfo->setAlignment(Qt::AlignCenter);
        labelTalentsTabInfo->setWordWrap(true);
        checkBoxIgnoreZeros = new QCheckBox(tabTalents);
        checkBoxIgnoreZeros->setObjectName(QStringLiteral("checkBoxIgnoreZeros"));
        checkBoxIgnoreZeros->setGeometry(QRect(694, 40, 91, 20));
        tabWidget->addTab(tabTalents, QString());
        tabGear = new QWidget();
        tabGear->setObjectName(QStringLiteral("tabGear"));
        buttonGenerateGear = new QPushButton(tabGear);
        buttonGenerateGear->setObjectName(QStringLiteral("buttonGenerateGear"));
        buttonGenerateGear->setGeometry(QRect(692, 170, 101, 32));
        buttonAddGear = new QPushButton(tabGear);
        buttonAddGear->setObjectName(QStringLiteral("buttonAddGear"));
        buttonAddGear->setGeometry(QRect(420, 60, 113, 32));
        listViewGearList = new QListView(tabGear);
        listViewGearList->setObjectName(QStringLiteral("listViewGearList"));
        listViewGearList->setGeometry(QRect(10, 10, 391, 192));
        buttonRemoveGear = new QPushButton(tabGear);
        buttonRemoveGear->setObjectName(QStringLiteral("buttonRemoveGear"));
        buttonRemoveGear->setGeometry(QRect(420, 20, 113, 32));
        label_12 = new QLabel(tabGear);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(710, 70, 60, 16));
        comboBoxSpec_3 = new QComboBox(tabGear);
        comboBoxSpec_3->setObjectName(QStringLiteral("comboBoxSpec_3"));
        comboBoxSpec_3->setGeometry(QRect(690, 140, 100, 26));
        label_13 = new QLabel(tabGear);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(710, 120, 60, 16));
        comboBoxClass_3 = new QComboBox(tabGear);
        comboBoxClass_3->setObjectName(QStringLiteral("comboBoxClass_3"));
        comboBoxClass_3->setGeometry(QRect(690, 90, 100, 26));
        labelGearInfo = new QLabel(tabGear);
        labelGearInfo->setObjectName(QStringLiteral("labelGearInfo"));
        labelGearInfo->setGeometry(QRect(690, 0, 100, 60));
        labelGearInfo->setAlignment(Qt::AlignCenter);
        labelGearInfo->setWordWrap(true);
        buttonEditGear = new QPushButton(tabGear);
        buttonEditGear->setObjectName(QStringLiteral("buttonEditGear"));
        buttonEditGear->setGeometry(QRect(420, 110, 113, 32));
        tabWidget->addTab(tabGear, QString());
        tabRelics = new QWidget();
        tabRelics->setObjectName(QStringLiteral("tabRelics"));
        buttonGenerateRelic = new QPushButton(tabRelics);
        buttonGenerateRelic->setObjectName(QStringLiteral("buttonGenerateRelic"));
        buttonGenerateRelic->setGeometry(QRect(692, 170, 101, 32));
        buttonAddRelic = new QPushButton(tabRelics);
        buttonAddRelic->setObjectName(QStringLiteral("buttonAddRelic"));
        buttonAddRelic->setGeometry(QRect(420, 60, 113, 32));
        buttonRemoveRelic = new QPushButton(tabRelics);
        buttonRemoveRelic->setObjectName(QStringLiteral("buttonRemoveRelic"));
        buttonRemoveRelic->setGeometry(QRect(420, 20, 113, 32));
        listViewRelicList = new QListView(tabRelics);
        listViewRelicList->setObjectName(QStringLiteral("listViewRelicList"));
        listViewRelicList->setGeometry(QRect(10, 10, 391, 192));
        label_10 = new QLabel(tabRelics);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(710, 70, 60, 16));
        comboBoxSpec_2 = new QComboBox(tabRelics);
        comboBoxSpec_2->setObjectName(QStringLiteral("comboBoxSpec_2"));
        comboBoxSpec_2->setGeometry(QRect(690, 140, 100, 26));
        label_11 = new QLabel(tabRelics);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(710, 120, 60, 16));
        comboBoxClass_2 = new QComboBox(tabRelics);
        comboBoxClass_2->setObjectName(QStringLiteral("comboBoxClass_2"));
        comboBoxClass_2->setGeometry(QRect(690, 90, 100, 26));
        labelRelicInfo = new QLabel(tabRelics);
        labelRelicInfo->setObjectName(QStringLiteral("labelRelicInfo"));
        labelRelicInfo->setGeometry(QRect(690, 0, 100, 60));
        labelRelicInfo->setAlignment(Qt::AlignCenter);
        labelRelicInfo->setWordWrap(true);
        tabWidget->addTab(tabRelics, QString());
        textEditAPL = new QPlainTextEdit(Dialog);
        textEditAPL->setObjectName(QStringLiteral("textEditAPL"));
        textEditAPL->setGeometry(QRect(10, 260, 811, 331));
        buttonOutputFile = new QPushButton(Dialog);
        buttonOutputFile->setObjectName(QStringLiteral("buttonOutputFile"));
        buttonOutputFile->setGeometry(QRect(710, 600, 113, 32));
        textEditFileSave = new QTextEdit(Dialog);
        textEditFileSave->setObjectName(QStringLiteral("textEditFileSave"));
        textEditFileSave->setGeometry(QRect(10, 600, 701, 31));

        retranslateUi(Dialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        buttonGenerateTalents->setText(QApplication::translate("Dialog", "Generate", 0));
        label->setText(QApplication::translate("Dialog", "Tier 15", 0));
        label_2->setText(QApplication::translate("Dialog", "Tier 30", 0));
        label_3->setText(QApplication::translate("Dialog", "Tier 45", 0));
        label_4->setText(QApplication::translate("Dialog", "Tier 60", 0));
        label_5->setText(QApplication::translate("Dialog", "Tier 75", 0));
        label_6->setText(QApplication::translate("Dialog", "Tier 90", 0));
        label_7->setText(QApplication::translate("Dialog", "Tier 100", 0));
        label_8->setText(QApplication::translate("Dialog", "Class", 0));
        label_9->setText(QApplication::translate("Dialog", "Spec", 0));
        checkBox1_1->setText(QApplication::translate("Dialog", "1", 0));
        checkBox2_1->setText(QApplication::translate("Dialog", "1", 0));
        checkBox3_1->setText(QApplication::translate("Dialog", "1", 0));
        checkBox4_1->setText(QApplication::translate("Dialog", "1", 0));
        checkBox5_1->setText(QApplication::translate("Dialog", "1", 0));
        checkBox6_1->setText(QApplication::translate("Dialog", "1", 0));
        checkBox7_1->setText(QApplication::translate("Dialog", "1", 0));
        checkBox6_2->setText(QApplication::translate("Dialog", "2", 0));
        checkBox3_2->setText(QApplication::translate("Dialog", "2", 0));
        checkBox2_2->setText(QApplication::translate("Dialog", "2", 0));
        checkBox1_2->setText(QApplication::translate("Dialog", "2", 0));
        checkBox4_2->setText(QApplication::translate("Dialog", "2", 0));
        checkBox5_2->setText(QApplication::translate("Dialog", "2", 0));
        checkBox7_2->setText(QApplication::translate("Dialog", "2", 0));
        checkBox5_3->setText(QApplication::translate("Dialog", "3", 0));
        checkBox2_3->setText(QApplication::translate("Dialog", "3", 0));
        checkBox4_3->setText(QApplication::translate("Dialog", "3", 0));
        checkBox6_3->setText(QApplication::translate("Dialog", "3", 0));
        checkBox1_3->setText(QApplication::translate("Dialog", "3", 0));
        checkBox7_3->setText(QApplication::translate("Dialog", "3", 0));
        checkBox3_3->setText(QApplication::translate("Dialog", "3", 0));
        labelTalentsTabInfo->setText(QApplication::translate("Dialog", "Select Class and spec", 0));
        checkBoxIgnoreZeros->setText(QApplication::translate("Dialog", "ignore 0s", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabTalents), QApplication::translate("Dialog", "Talents", 0));
        buttonGenerateGear->setText(QApplication::translate("Dialog", "Generate", 0));
        buttonAddGear->setText(QApplication::translate("Dialog", "Add Gear", 0));
        buttonRemoveGear->setText(QApplication::translate("Dialog", "Remove Gear", 0));
        label_12->setText(QApplication::translate("Dialog", "Class", 0));
        label_13->setText(QApplication::translate("Dialog", "Spec", 0));
        labelGearInfo->setText(QApplication::translate("Dialog", "Select Class and spec for Gear options", 0));
        buttonEditGear->setText(QApplication::translate("Dialog", "Edit Gear", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabGear), QApplication::translate("Dialog", "Gear", 0));
        buttonGenerateRelic->setText(QApplication::translate("Dialog", "Generate", 0));
        buttonAddRelic->setText(QApplication::translate("Dialog", "Add Relic", 0));
        buttonRemoveRelic->setText(QApplication::translate("Dialog", "Remove Relic", 0));
        label_10->setText(QApplication::translate("Dialog", "Class", 0));
        label_11->setText(QApplication::translate("Dialog", "Spec", 0));
        labelRelicInfo->setText(QApplication::translate("Dialog", "<html><head/><body><p>Select Class and spec for Relic options</p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabRelics), QApplication::translate("Dialog", "Relics", 0));
        textEditAPL->setPlainText(QApplication::translate("Dialog", "Please put base APL here", 0));
        buttonOutputFile->setText(QApplication::translate("Dialog", "Output File", 0));
        textEditFileSave->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Directory For File Here</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H

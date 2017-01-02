/********************************************************************************
** Form generated from reading UI file 'gearselection.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GEARSELECTION_H
#define UI_GEARSELECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GearSelection
{
public:
    QComboBox *comboBoxSlotSelection;
    QLineEdit *lineEditILvlMin;
    QLineEdit *lineEditILvlMax;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEditID;
    QLabel *label_5;
    QLineEdit *lineEditItemName;
    QLabel *label_6;
    QPushButton *buttonAddItem;
    QLineEdit *lineEditBonusIDs;
    QLabel *label_7;
    QLineEdit *lineEditGemID;
    QLabel *label_8;

    void setupUi(QWidget *GearSelection)
    {
        if (GearSelection->objectName().isEmpty())
            GearSelection->setObjectName(QStringLiteral("GearSelection"));
        GearSelection->resize(400, 300);
        comboBoxSlotSelection = new QComboBox(GearSelection);
        comboBoxSlotSelection->setObjectName(QStringLiteral("comboBoxSlotSelection"));
        comboBoxSlotSelection->setGeometry(QRect(90, 20, 104, 26));
        lineEditILvlMin = new QLineEdit(GearSelection);
        lineEditILvlMin->setObjectName(QStringLiteral("lineEditILvlMin"));
        lineEditILvlMin->setGeometry(QRect(90, 60, 113, 21));
        lineEditILvlMax = new QLineEdit(GearSelection);
        lineEditILvlMax->setObjectName(QStringLiteral("lineEditILvlMax"));
        lineEditILvlMax->setGeometry(QRect(90, 90, 113, 21));
        label = new QLabel(GearSelection);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 60, 16));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(GearSelection);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 60, 16));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(GearSelection);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 90, 60, 16));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(GearSelection);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 130, 60, 16));
        label_4->setAlignment(Qt::AlignCenter);
        lineEditID = new QLineEdit(GearSelection);
        lineEditID->setObjectName(QStringLiteral("lineEditID"));
        lineEditID->setGeometry(QRect(90, 130, 113, 21));
        label_5 = new QLabel(GearSelection);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 170, 71, 20));
        label_5->setAlignment(Qt::AlignCenter);
        lineEditItemName = new QLineEdit(GearSelection);
        lineEditItemName->setObjectName(QStringLiteral("lineEditItemName"));
        lineEditItemName->setGeometry(QRect(90, 170, 113, 21));
        label_6 = new QLabel(GearSelection);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(220, 30, 161, 121));
        label_6->setWordWrap(true);
        buttonAddItem = new QPushButton(GearSelection);
        buttonAddItem->setObjectName(QStringLiteral("buttonAddItem"));
        buttonAddItem->setGeometry(QRect(240, 250, 113, 32));
        lineEditBonusIDs = new QLineEdit(GearSelection);
        lineEditBonusIDs->setObjectName(QStringLiteral("lineEditBonusIDs"));
        lineEditBonusIDs->setGeometry(QRect(90, 210, 113, 21));
        label_7 = new QLabel(GearSelection);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 210, 71, 20));
        label_7->setAlignment(Qt::AlignCenter);
        lineEditGemID = new QLineEdit(GearSelection);
        lineEditGemID->setObjectName(QStringLiteral("lineEditGemID"));
        lineEditGemID->setGeometry(QRect(90, 240, 113, 21));
        label_8 = new QLabel(GearSelection);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 240, 71, 20));
        label_8->setAlignment(Qt::AlignCenter);

        retranslateUi(GearSelection);

        QMetaObject::connectSlotsByName(GearSelection);
    } // setupUi

    void retranslateUi(QWidget *GearSelection)
    {
        GearSelection->setWindowTitle(QApplication::translate("GearSelection", "Form", 0));
        label->setText(QApplication::translate("GearSelection", "Slot", 0));
        label_2->setText(QApplication::translate("GearSelection", "iLvl Min", 0));
        label_3->setText(QApplication::translate("GearSelection", "iLvl Max", 0));
        label_4->setText(QApplication::translate("GearSelection", "item ID", 0));
        label_5->setText(QApplication::translate("GearSelection", "Item Name", 0));
        label_6->setText(QApplication::translate("GearSelection", "This GUI is temporary and a work in progress.  Its mainly here to test funcitonality and a large revamp will come \"later\"", 0));
        buttonAddItem->setText(QApplication::translate("GearSelection", "Add Item", 0));
        lineEditBonusIDs->setText(QString());
        lineEditBonusIDs->setPlaceholderText(QApplication::translate("GearSelection", "Seperate with \",\"", 0));
        label_7->setText(QApplication::translate("GearSelection", "Bonus IDs", 0));
        label_8->setText(QApplication::translate("GearSelection", "Gem", 0));
    } // retranslateUi

};

namespace Ui {
    class GearSelection: public Ui_GearSelection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GEARSELECTION_H

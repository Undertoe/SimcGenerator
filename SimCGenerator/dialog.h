#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QCheckBox>
#include <QFileDialog>
#include <QDir>
#include <QStringListModel>
#include <QListView>
#include <QCoreApplication>


#include "generator.h"
#include "lookup.h"
#include "gearselection.h"
#include "databasehandler.h"


class GearSelection;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);

    ~Dialog();

    QList<SpecType> *getSpecInfo() const;
    void setSpecInfo(QList<SpecType> *value);

    void GrabGear(Gear g, GearSelection* gear);

private:
    Ui::Dialog *ui;
    QStringListModel *modelGear;
    QStringListModel *modelRelic;


    Lookup *lookup;
    Generator *generator;
    QString myClassType;
    QString mySpecType;
    QString myDirectory;
    DatabaseHandler *db;

    int CLASSID;
    int SPECID;

    QList<ClassType> *classTypeList;
    QList<SpecType> *specTypeList;

    QList<QCheckBox *> *checkBoxList;

    void Test();

    //UI INITIALIZATIONS
    void InitUI();
    void InitComboBoxes();
    void InitCheckBoxes();

    QStringList ReadAPL();
    QString GetOuputFileDirectory();

    void DebugMode();

    QList<Gear> gearList;

private slots:
    void GenerateGear();
    void GenerateRelics();
    void GenerateTalents();

    void GenerateFile();

    void ClassComboBoxIndexClick(int index);
    void SpecComboBoxIndexClicked(int index);

    void AddGearButtonClick();

};

#endif // DIALOG_H

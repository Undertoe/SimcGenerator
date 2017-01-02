#include "dialog.h"
#include "ui_dialog.h"

#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    this->db = new DatabaseHandler();

    lookup = new Lookup();
    this->classTypeList = new QList<ClassType>();
    this->specTypeList = new QList<SpecType>();
    this->myClassType = "";
    this->mySpecType = "";

    modelGear = new QStringListModel(this);
    modelRelic = new QStringListModel(this);


    this->ui->listViewGearList->setModel(modelGear);

    this->InitUI();


    connect(this->ui->comboBoxClass, SIGNAL(activated(int)),
            this, SLOT(ClassComboBoxIndexClick(int)));
    connect(this->ui->comboBoxClass_2, SIGNAL(activated(int)),
            this, SLOT(ClassComboBoxIndexClick(int)));
    connect(this->ui->comboBoxClass_3, SIGNAL(activated(int)),
            this, SLOT(ClassComboBoxIndexClick(int)));


    connect(this->ui->comboBoxSpec, SIGNAL(activated(int)),
            this, SLOT(SpecComboBoxIndexClicked(int)));
    connect(this->ui->comboBoxSpec_2, SIGNAL(activated(int)),
            this, SLOT(SpecComboBoxIndexClicked(int)));
    connect(this->ui->comboBoxSpec_3, SIGNAL(activated(int)),
            this, SLOT(SpecComboBoxIndexClicked(int)));


    connect(this->ui->buttonGenerateGear, SIGNAL(clicked(bool)),
            this, SLOT(GenerateGear()));
    connect(this->ui->buttonGenerateRelic, SIGNAL(clicked(bool)),
            this, SLOT(GenerateRelics()));
    connect(this->ui->buttonGenerateTalents, SIGNAL(clicked(bool)),
            this, SLOT(GenerateTalents()));

    connect(this->ui->buttonAddGear, SIGNAL(clicked(bool)),
            this, SLOT(AddGearButtonClick()));

    connect(this->ui->buttonOutputFile, SIGNAL(clicked(bool)),
            this, SLOT(GenerateFile()));


//    this->Test();

//    this->DebugMode();
}

Dialog::~Dialog()
{
    delete ui;
}

QList<SpecType> *Dialog::getSpecInfo() const
{
    return specTypeList;
}

void Dialog::setSpecInfo(QList<SpecType> *value)
{
    specTypeList = value;
}


///
///PRIVATE
///
void Dialog::InitUI()
{
    this->InitComboBoxes();
    this->InitCheckBoxes();
}

void Dialog::InitComboBoxes()
{

    this->ui->comboBoxClass->addItem("Select Class");
    this->ui->comboBoxClass_2->addItem("Select Class");
    this->ui->comboBoxClass_3->addItem("Select Class");

    this->ui->comboBoxSpec->addItem("Select Class");
    this->ui->comboBoxSpec_2->addItem("Select Class");
    this->ui->comboBoxSpec_3->addItem("Select Class");

    QStringList data = this->db->GetClasses();

    for(int i = 0; i < data.count(); i ++)
    {
        this->ui->comboBoxClass->addItem(data.at(i));
        this->ui->comboBoxClass_2->addItem(data.at(i));
        this->ui->comboBoxClass_3->addItem(data.at(i));
    }

//    for(auto key : lookup->classTypeLookup->keys())
//    {
//        this->ui->comboBoxClass->addItem(lookup->classTypeLookup->value(key).name);
//        this->ui->comboBoxClass_2->addItem(lookup->classTypeLookup->value(key).name);
//        this->ui->comboBoxClass_3->addItem(lookup->classTypeLookup->value(key).name);
//        this->classTypeList->append(key);
//    }
}

void Dialog::InitCheckBoxes()
{
    this->checkBoxList = new QList<QCheckBox*>();
    this->checkBoxList->append(this->ui->checkBox1_1);
    this->checkBoxList->append(this->ui->checkBox1_2);
    this->checkBoxList->append(this->ui->checkBox1_3);
    this->checkBoxList->append(this->ui->checkBox2_1);
    this->checkBoxList->append(this->ui->checkBox2_2);
    this->checkBoxList->append(this->ui->checkBox2_3);
    this->checkBoxList->append(this->ui->checkBox3_1);
    this->checkBoxList->append(this->ui->checkBox3_2);
    this->checkBoxList->append(this->ui->checkBox3_3);
    this->checkBoxList->append(this->ui->checkBox4_1);
    this->checkBoxList->append(this->ui->checkBox4_2);
    this->checkBoxList->append(this->ui->checkBox4_3);
    this->checkBoxList->append(this->ui->checkBox5_1);
    this->checkBoxList->append(this->ui->checkBox5_2);
    this->checkBoxList->append(this->ui->checkBox5_3);
    this->checkBoxList->append(this->ui->checkBox6_1);
    this->checkBoxList->append(this->ui->checkBox6_2);
    this->checkBoxList->append(this->ui->checkBox6_3);
    this->checkBoxList->append(this->ui->checkBox7_1);
    this->checkBoxList->append(this->ui->checkBox7_2);
    this->checkBoxList->append(this->ui->checkBox7_3);
    for(int i = 0; i < this->checkBoxList->count(); i ++)
    {
        this->checkBoxList->at(i)->setText("");
    }
}

QStringList Dialog::ReadAPL()
{
    QStringList retval = this->ui->textEditAPL->toPlainText().split('\n');
    qDebug() << retval.count();
    return retval;
}

QString Dialog::GetOuputFileDirectory()
{
    QString directory = QFileDialog::getExistingDirectory(this,
                                tr("Find Files"), QDir::currentPath());

//        if (!directory.isEmpty()) {
//            if (directoryComboBox->findText(directory) == -1)
//                directoryComboBox->addItem(directory);
//            directoryComboBox->setCurrentIndex(directoryComboBox->findText(directory));
//        }
    return directory;

}

void Dialog::DebugMode()
{
    this->ui->comboBoxClass->setCurrentIndex(2);
    this->ui->comboBoxSpec->setCurrentIndex(1);
    this->ui->tabWidget->setCurrentIndex(0);

    QFile f("/Users/terryn.fredrickson/Documents/simcbase.simc");
    QStringList staticStuff = QStringList();
    if(f.open(QIODevice::ReadWrite))
    {
        this->ui->textEditAPL->clear();
        this->ui->textEditFileSave->setText("/Users/terryn.fredrickson/Documents");
        QTextStream input(&f);
        bool cont = true;
        while(cont)
        {
            QString line = input.readLine();
            if(line.isNull())
                cont = false;
            else
                ui->textEditAPL->appendPlainText(line);
        }
    }
    else
    {
        qDebug() << "SHITS FUCKED";
    }

}

///
///SLOTS
///
void Dialog::GenerateGear()
{

}

void Dialog::GenerateRelics()
{

}

void Dialog::GrabGear(Gear g, GearSelection* gear)
{
    this->gearList.append(g);


    delete(gear);

    modelGear->insertRow(modelGear->rowCount());
    QModelIndex index = modelGear->index(modelGear->rowCount() -1);
    modelGear->setData(index, g.toString());

    //TODO add shit to the list view!!
}

void Dialog::GenerateTalents()
{
    if(this->mySpecType.length() > 0 && this->myClassType.length() > 0)
    {
        bool ignore0s = this->ui->checkBoxIgnoreZeros->isChecked();

        QStringList staticAPL = this->ReadAPL();
        QList<QList<int>> talents = QList<QList<int>>();
        QList<int> talentRow = QList<int>();

        talentRow.append(0);
        if(this->ui->checkBox1_1->isChecked())
            talentRow.append(1);
        if(this->ui->checkBox1_2->isChecked())
            talentRow.append(2);
        if(this->ui->checkBox1_3->isChecked())
            talentRow.append(3);
        if(talentRow.count() > 1 && ignore0s)
            talentRow.removeAt(0);
        talents.append(talentRow);
        talentRow.clear();

        talentRow.append(0);
        if(this->ui->checkBox2_1->isChecked())
            talentRow.append(1);
        if(this->ui->checkBox2_2->isChecked())
            talentRow.append(2);
        if(this->ui->checkBox2_3->isChecked())
            talentRow.append(3);
        if(talentRow.count() > 1 && ignore0s)
            talentRow.removeAt(0);
        talents.append(talentRow);
        talentRow.clear();

        talentRow.append(0);
        if(this->ui->checkBox3_1->isChecked())
            talentRow.append(1);
        if(this->ui->checkBox3_2->isChecked())
            talentRow.append(2);
        if(this->ui->checkBox3_3->isChecked())
            talentRow.append(3);
        if(talentRow.count() > 1 && ignore0s)
            talentRow.removeAt(0);
        talents.append(talentRow);
        talentRow.clear();

        talentRow.append(0);
        if(this->ui->checkBox4_1->isChecked())
            talentRow.append(1);
        if(this->ui->checkBox4_2->isChecked())
            talentRow.append(2);
        if(this->ui->checkBox4_3->isChecked())
            talentRow.append(3);
        if(talentRow.count() > 1 && ignore0s)
            talentRow.removeAt(0);
        talents.append(talentRow);
        talentRow.clear();

        talentRow.append(0);
        if(this->ui->checkBox5_1->isChecked())
            talentRow.append(1);
        if(this->ui->checkBox5_2->isChecked())
            talentRow.append(2);
        if(this->ui->checkBox5_3->isChecked())
            talentRow.append(3);
        if(talentRow.count() > 1 && ignore0s)
            talentRow.removeAt(0);
        talents.append(talentRow);
        talentRow.clear();

        talentRow.append(0);
        if(this->ui->checkBox6_1->isChecked())
            talentRow.append(1);
        if(this->ui->checkBox6_2->isChecked())
            talentRow.append(2);
        if(this->ui->checkBox6_3->isChecked())
            talentRow.append(3);
        if(talentRow.count() > 1 && ignore0s)
            talentRow.removeAt(0);
        talents.append(talentRow);
        talentRow.clear();

        talentRow.append(0);
        if(this->ui->checkBox7_1->isChecked())
            talentRow.append(1);
        if(this->ui->checkBox7_2->isChecked())
            talentRow.append(2);
        if(this->ui->checkBox7_3->isChecked())
            talentRow.append(3);
        if(talentRow.count() > 1 && ignore0s)
            talentRow.removeAt(0);
        talents.append(talentRow);
        talentRow.clear();

        QDir dir(this->ui->textEditFileSave->toPlainText() + "/" + "talents.simc");
        QString outputFileLocation = dir.path();
//        QString className = this->lookup->classTypeLookup->value(this->myClassType).name;
//        QString specName = this->lookup->specInfoMap->value(this->mySpecType).name;
        this->generator = new Generator(outputFileLocation, this->myClassType,
                                        this->mySpecType, db);
        this->generator->classID = this->CLASSID;
        this->generator->specID = this->SPECID;
        this->generator->lookup = this->lookup;
        generator->GenerateTalents(staticAPL, talents);
    }
    else
    {
        qDebug()  << "NO CLASS / SPEC CHOSEN";
    }
}

void Dialog::GenerateFile()
{
    myDirectory = this->GetOuputFileDirectory();
    this->ui->textEditFileSave->setText(myDirectory);
}

void Dialog::ClassComboBoxIndexClick(int index)
{
//    ClassType key;
    this->ui->comboBoxClass->setCurrentIndex(index);
    this->ui->comboBoxClass_2->setCurrentIndex(index);
    this->ui->comboBoxClass_3->setCurrentIndex(index);

//    if(index == 0)
//        this->myClassType = NOCLASS;
//    else
//    {
//        key = this->classTypeList->at(index-1);
//        this->myClassType = key;
//    }
    QStringList data = this->db->GetClasses();
    this->CLASSID = index;
    this->myClassType = this->db->GetClass(index);

    this->mySpecType = "";

    this->ui->comboBoxSpec->clear();
    this->ui->comboBoxSpec_2->clear();
    this->ui->comboBoxSpec_3->clear();
    this->ui->comboBoxSpec->addItem("Select Class");
    this->ui->comboBoxSpec_2->addItem("Select Class");
    this->ui->comboBoxSpec_3->addItem("Select Class");


    QStringList s = this->db->GetSpecsForClass(CLASSID);
    for(int i = 0; i < s.count(); i++)
    {
        this->ui->comboBoxSpec->addItem(s.at(i));
        this->ui->comboBoxSpec_2->addItem(s.at(i));
        this->ui->comboBoxSpec_3->addItem(s.at(i));
    }
//    QList<SpecInfo> s = this->lookup->specInfoLookup->value(key);
//    this->specTypeList->clear();
//    for(int i = 0; i < s.count(); i ++)
//    {
//        this->ui->comboBoxSpec->addItem(s.at(i).name);
//        this->ui->comboBoxSpec_2->addItem(s.at(i).name);
//        this->ui->comboBoxSpec_3->addItem(s.at(i).name);
//        this->specTypeList->append(s.at(i).type);
//    }

    for(int i = 0; i < this->checkBoxList->count(); i ++)
    {
        this->checkBoxList->at(i)->setText("");
    }
}

void Dialog::SpecComboBoxIndexClicked(int index)
{
//    SpecType type;
//    if(index == 0)
//        this->mySpecType = NOSPEC;

//    else
//    {
//        type = this->specTypeList->at(index - 1);
//        this->mySpecType = type;
//    }
    this->SPECID = index;
    this->mySpecType = this->db->GetSpecName(this->CLASSID, this->SPECID);


    this->ui->comboBoxSpec->setCurrentIndex(index);
    this->ui->comboBoxSpec_2->setCurrentIndex(index);
    this->ui->comboBoxSpec_3->setCurrentIndex(index);

    for(int i = 0; i < this->checkBoxList->count(); i ++)
    {
        this->checkBoxList->at(i)->setText("");
    }

    QList<QStringList> check = db->GetTalentsForSpec(this->CLASSID, this->SPECID);
    if(check.count() > 0)
    {
        if(check.at(0).count() > 0)
        {
            this->ui->checkBox1_1->setText(check.at(0).at(0));
            this->ui->checkBox1_2->setText(check.at(0).at(1));
            this->ui->checkBox1_3->setText(check.at(0).at(2));
            this->ui->checkBox2_1->setText(check.at(1).at(0));
            this->ui->checkBox2_2->setText(check.at(1).at(1));
            this->ui->checkBox2_3->setText(check.at(1).at(2));
            this->ui->checkBox3_1->setText(check.at(2).at(0));
            this->ui->checkBox3_2->setText(check.at(2).at(1));
            this->ui->checkBox3_3->setText(check.at(2).at(2));
            this->ui->checkBox4_1->setText(check.at(3).at(0));
            this->ui->checkBox4_2->setText(check.at(3).at(1));
            this->ui->checkBox4_3->setText(check.at(3).at(2));
            this->ui->checkBox5_1->setText(check.at(4).at(0));
            this->ui->checkBox5_2->setText(check.at(4).at(1));
            this->ui->checkBox5_3->setText(check.at(4).at(2));
            this->ui->checkBox6_1->setText(check.at(5).at(0));
            this->ui->checkBox6_2->setText(check.at(5).at(1));
            this->ui->checkBox6_3->setText(check.at(5).at(2));
            this->ui->checkBox7_1->setText(check.at(6).at(0));
            this->ui->checkBox7_2->setText(check.at(6).at(1));
            this->ui->checkBox7_3->setText(check.at(6).at(2));
        }
    }
    else
    {
        qDebug() << "NOT ALL TALENTS IMPORTED!!";
    }

//    QList<QList<Talents>> talents = this->lookup->talentLookup->value(type);
//    this->ui->checkBox1_1->setText(talents.at(0).at(0).name);
//    this->ui->checkBox1_2->setText(talents.at(0).at(1).name);
//    this->ui->checkBox1_3->setText(talents.at(0).at(2).name);
//    this->ui->checkBox2_1->setText(talents.at(1).at(0).name);
//    this->ui->checkBox2_2->setText(talents.at(1).at(1).name);
//    this->ui->checkBox2_3->setText(talents.at(1).at(2).name);
//    this->ui->checkBox3_1->setText(talents.at(2).at(0).name);
//    this->ui->checkBox3_2->setText(talents.at(2).at(1).name);
//    this->ui->checkBox3_3->setText(talents.at(2).at(2).name);
//    this->ui->checkBox4_1->setText(talents.at(3).at(0).name);
//    this->ui->checkBox4_2->setText(talents.at(3).at(1).name);
//    this->ui->checkBox4_3->setText(talents.at(3).at(2).name);
//    this->ui->checkBox5_1->setText(talents.at(4).at(0).name);
//    this->ui->checkBox5_2->setText(talents.at(4).at(1).name);
//    this->ui->checkBox5_3->setText(talents.at(4).at(2).name);
//    this->ui->checkBox6_1->setText(talents.at(5).at(0).name);
//    this->ui->checkBox6_2->setText(talents.at(5).at(1).name);
//    this->ui->checkBox6_3->setText(talents.at(5).at(2).name);
//    this->ui->checkBox7_1->setText(talents.at(6).at(0).name);
//    this->ui->checkBox7_2->setText(talents.at(6).at(1).name);
//    this->ui->checkBox7_3->setText(talents.at(6).at(2).name);
}

void Dialog::AddGearButtonClick()
{
    GearSelection* gear = new GearSelection();
    gear->Init(this);
    gear->show();
}

void Dialog::Test()
{
    //string trinket[] = { "Eyasus_Mulligan", "Shock_Baton", "Obelisk", "Imp_Generator", "Caged_Horror", "Fulmination_Charge", "Portable_Manacracker", "Oakhearts_Gnarled_Root", "Spiked_Tongue", "Moonlit_Prism", "Infernal_Writ", "Horn_of_Valor", "Figurehead_Naglfar", "Eye_of_Skovald", "Elementium_Bomb", "Corrupted_Starlight", "Chronoshard", "Orb_of_Voidsight", "Bough_of_Corruption", "Swarming_Plague", "Twisting_Wind", "Unstable_Horrorslime", "Wriggling_Sinew", "Padawsens_Unlucky_Charm", "Unstable_Arcanocrystal", "Darkmoon_Deck_Hellfire", "Alchemist_Stone", "WQuest", "PVP", "Mrrgria's_Favor", "Deteriorated_Construct_Core", "Aran's Relaxing Ruby" };
    //    int trinketID[] = { 141584, 140030, 137433, 131735, 136716, 137367, 137398, 137306, 137349, 137541, 137485, 133642, 137329, 133641, 137446, 137301, 137419, 133596, 139336, 139321, 139323, 138224, 139326, 141536, 141482, 128709, 127842, 134292, 135812, 135812, 142160, 142165, 142157 };

    QString file = "/Users/terryn.fredrickson/Documents/test.txt";
    Generator *g = new Generator(file, "warlock", "affliction", db);

    QFile f("/Users/terryn.fredrickson/Documents/simcbase.simc");
    QStringList staticStuff = QStringList();
    if(f.open(QIODevice::ReadWrite))
    {

        QTextStream input(&f);
        bool cont = true;
        while(cont)
        {
            QString line = input.readLine();
            if(line.isNull())
                cont = false;
            else
                staticStuff.append(line);
        }
        QList<int> ilvl = QList<int>();
        ilvl.append(890);
        ilvl.append(880);
        ilvl.append(870);

        //TestArtifactRelics
        int stdIlvl = 895;
        QString weaponLine = "main_hand=ulthalesh_the_deadwind_harvester,id=128942";
        QString baseArtifact = "artifact=39:137347:137544:137347:0:915:3:916:3:919:3:920:3:921:3:922:3:923:3:926:1:927:1:928:1:929:1:999:1:1353:1";
        QList<Relic> *relics = new QList<Relic>();

        Relic rel = Relic();
        rel.id.append(918);
        rel.name = "inherently_unstable";
        rel.ilvl = ilvl;
        relics->append(rel);

        rel = Relic();
        rel.id.append(920);
        rel.name = "perdition";
        rel.ilvl = ilvl;
        relics->append(rel);

        rel = Relic();
        rel.id.append(916);
        rel.name = "hideous_corruption";
        rel.ilvl = ilvl;
        relics->append(rel);

        g->GenerateArtifactRelics(staticStuff, weaponLine, relics, baseArtifact, stdIlvl);




        //TEST GENERATE GEAR
//        QList<Gear> *gearList = new QList<Gear>();
//        Gear ge = Gear();
//        ge.id = 141548;
//        ge.name = "Eyasus_Mulligan";
//        ge.slot = "trinket1";
//        ge.ilvl = {860, 870, 880};
//        gearList->append(ge);

//        ge = Gear();
//        ge.id = 140030;
//        ge.name = "Shock_Baton";
//        ge.slot = "trinket1";
//        ge.ilvl = {860, 870, 880, 895};
//        gearList->append(ge);

//        ge = Gear();
//        ge.id = 137433;
//        ge.name = "Obelisk";
//        ge.slot = "trinket1";
//        ge.ilvl = {880, 890, 895};
//        gearList->append(ge);

//        g->GenerateGear(staticStuff, gearList, ge.slot);


        //TEST GENERATE TALENTS
//        QList<QList<int>> talentRows = QList<QList<int>>();
//        QList<int> a = QList<int>();
//        a.append(1);
//        a.append(2);
//        a.append(3);
//        talentRows.append(a);
//        a.clear();
//        a.append(1);
//        talentRows.append(a);
//        talentRows.append(a);
//        talentRows.append(a);
//        talentRows.append(a);
//        talentRows.append(a);
////        a.clear();
////        a.append(1);
////        a.append(2);
////        a.append(3);
//        talentRows.append(a);

//        g->GenerateTalents(staticStuff, talentRows);
    }
    else
        qDebug() << "CANNOT FIND READ FILE";
}

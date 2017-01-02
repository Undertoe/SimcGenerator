#include "gearselection.h"
#include "ui_gearselection.h"

GearSelection::GearSelection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GearSelection)
{
    ui->setupUi(this);

    connect(this->ui->buttonAddItem, SIGNAL(clicked(bool)), this, SLOT(MakeGear()));


}

void GearSelection::Init(Dialog *dia)
{
    this->d = dia;
}

GearSelection::~GearSelection()
{
    delete ui;
}


void GearSelection::MakeGear()
{
    bool bailout = false;
    Gear g = Gear();
    //id and name
    if(!this->ui->lineEditID->text().isEmpty())
        g.id =  QString(this->ui->lineEditID->text()).toInt();
    else
    {
        qDebug() << "NO ITEM ID!!!!";
        //TODO add a fucking popup here and bail out;

        bailout = true;
    }
    if(!this->ui->lineEditItemName->text().isEmpty() && !bailout)
        g.name = QString(this->ui->lineEditItemName->text());
    else
    {
        qDebug() << "NO ITEM NAME!!!!";
        //TODO add a fucking popup here and bail out;

        bailout = true;
    }

    //ilvl range
    if(!this->ui->lineEditILvlMax->text().isEmpty() &&
            !this->ui->lineEditILvlMin->text().isEmpty() &&
            !bailout)
    {
        int min = QString(this->ui->lineEditILvlMin->text()).toInt();
        min += min%5;
        int max = QString(this->ui->lineEditILvlMax->text()).toInt();
        max += max%5;
        for(int i = min; i < max + 1; i += 5)
        {
            g.ilvl.append(i);
        }
        qDebug() << "ilvl count: " << g.ilvl.count();
    }
    else
    {
        qDebug() << "NO ITEMLEVEL!!!!";
        //TODO add a fucking popup here and bail out;
        bailout = true;
    }

    //Bonus IDs
    if(!this->ui->lineEditBonusIDs->text().isEmpty() && !bailout)
    {
        QString s = QString(this->ui->lineEditBonusIDs->text());
        QStringList split = s.split(',');
        for(int i = 0; i < split.count(); i ++)
        {
            g.bonuses.append(QString(split.at(i)).toInt());
        }
    }

    if(!this->ui->lineEditGemID->text().isEmpty() && !bailout)
    {
        int s = QString(this->ui->lineEditGemID->text()).toInt();
        g.gemIds.append(s);
    }



    if(!bailout)
        d->GrabGear(g, this);
}

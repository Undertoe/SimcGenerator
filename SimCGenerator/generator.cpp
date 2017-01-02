#include "generator.h"

Generator::Generator(QString filename, QString classname, QString spec, DatabaseHandler *db)
{
    this->generatedExtraStuff = new QList<QString>();
    this->formatedStuff = new QStringList();
    staticStuff = new QString();
    this->filename = new QString(filename);
    this->classname = classname;
    this->names = new QList<QString>();
    this->spec = spec;

    this->db = db;


    file = new QFile(filename);

    InitMaps();
}

void Generator::GenerateTalents(QStringList statics, /*QList<int> talentRows,*/
                                QList<QList<int>> talents)
{

    qDebug() << "GenerateTalents";
    this->formatedStuff = &statics;
    int base = 0;



    qDebug() << "Starting Loop";
    if(file->open(QIODevice::ReadWrite))
    {

        bool cont = true;
        for(int j = 0; j < formatedStuff->count() && cont; j ++)
        {
            QString test = formatedStuff->at(j);
            if(test.contains("talents"))
            {
                formatedStuff->removeAt(j);
                cont = false;
            }
        }
        qDebug() << "classname: " << classname;
        cont = true;
        for(int j = 0; j < formatedStuff->count() && cont; j ++)
        {
            QString test = formatedStuff->at(j);
            if(test.contains(classname))
            {
                formatedStuff->removeAt(j);
                cont = false;
            }
        }



        QList<int> tmp = QList<int>();

        //this should loop through 7 times
        for(int i = 0; i < talents.count(); i ++)
        {
            tmp.append(talents.at(i).count());
        }
        int A = 1;
        int B = 1;
        int C = 1;
        int D = 1;
        int E = 1;
        int F = 1;
        int G = 1;

        //now setup A - G
        A = tmp.at(0);
        B = tmp.at(1);
        C = tmp.at(2);
        D = tmp.at(3);
        E = tmp.at(4);
        F = tmp.at(5);
        G = tmp.at(6);


        qDebug() << "A: " << A << " B, " << B << " C, " << C << " D, " << D
                    << " E, " << E << " F, " << F << " G, " << G ;


        for(int a = 0; a < A; a ++)
        {
            for(int b = 0; b < B; b++)
            {
                for(int c = 0; c < C; c ++)
                {
                    for(int d = 0; d < D; d ++)
                    {
                        for(int e = 0; e < E; e ++)
                        {
                            for (int f = 0; f < F; f ++)
                            {
                                for(int g = 0; g < G; g ++)
                                {
                                    QString t = QString::number(talents.at(0).at(a)) +
                                            QString::number(talents.at(1).at(b)) +
                                            QString::number(talents.at(2).at(c)) +
                                            QString::number(talents.at(3).at(d)) +
                                            QString::number(talents.at(4).at(e)) +
                                            QString::number(talents.at(5).at(f)) +
                                            QString::number(talents.at(6).at(g));
//                                    QString name = this->GenrateNameFromTalentString(t);
                                    QString name = this->db->GetTalentStringName
                                            (this->classID, this->specID, t);
                                    QString str = "talents=" +  t;
                                    names->append(name);
                                    generatedExtraStuff->append(str);
                                }
                            }
                        }
                    }
                }
            }
        }

        qDebug() << "simc size: " << generatedExtraStuff->count();

        qDebug() << "loop finished";
        this->Output();
    }
    else
    {
        qDebug() << "FILE FUCKED";
    }
}

void Generator::GenerateGear(QStringList statics, QList<Gear> *gearlist, QString slot)
{
    this->formatedStuff = &statics;

    if(file->open(QIODevice::ReadWrite))
    {
        for(int i = 0 ; i < gearlist->count(); i ++)
        {
            Gear g = gearlist->at(i);
            QString SPLIT = ",";
            QString slot = g.slot + "=";
            QString name = g.name;
            QString id = "id=" + QString::number(g.id);
            QString enchant = "";
            if(g.enchantId > 0)
                enchant = "enchant_id=" + g.enchantId;
            QString bonuses = "";
            //setup ilvl stuff

            QString gem = "";
            if(g.gemIds.count() > 0)
            {
                gem += "gem_id=";
                for(int b = 0; b < g.gemIds.count(); b++)
                {
                    gem += g.gemIds.at(b) + "/";
                }
                gem.chop(1);
            }
            if(g.bonuses.count() > 0)
            {
                bonuses = "bonus_id=";
                for(int b = 0; b < g.bonuses.count(); b ++)
                {
                    bonuses += QString::number(g.bonuses.at(b));
                    bonuses += "/";
                }
                bonuses.chop(1);
                QString line = slot + name + SPLIT + id + enchant + bonuses + gem;
                generatedExtraStuff->append(line);
                names->append(name);

            }
            else if(g.ilvl.count() > 0)
            {
                for(int l = 0; l < g.ilvl.count(); l ++)
                {
                    int ilvl = g.ilvl.at(l);
                    QString iLevel = "ilevel=" + QString::number(ilvl);
                    name += "_" + QString::number(ilvl);
                    QString line = slot + name + SPLIT + id + enchant + bonuses + gem;
                    generatedExtraStuff->append(line);
                    names->append(name);
                }
            }
        }
        bool cont = true;
        for(int j = 0; j < formatedStuff->count() && cont; j ++)
        {
            QString test = formatedStuff->at(j);
            if(test.contains(slot))
            {
                formatedStuff->removeAt(j);
                cont = false;
            }
        }

        this->Output();

    }
    else
    {
        qDebug() << "FILE FUCKED";
    }

    //
}

void Generator::GenerateRotation(QStringList statics, QString staticAPL, QList<APL> *aplTest)
{
    this->formatedStuff = &statics;
    this->FormatStatic();

//    QFile file;
//    file(this->filename);
    if(file->open(QIODevice::ReadWrite))
    {
        for(int i = 0; i < aplTest->count(); i ++)
        {
            APL a = aplTest->at(i);
            QString apl = staticAPL;
            apl += "\n" + a.aplLine + "\n";
            QString name = a.name;
            generatedExtraStuff->append(apl);
            names->append(name);
        }

        this->Output();
    }
    else
    {
        qDebug() << "FILE IS FUCKED";
    }
}

void Generator::GenerateArtifactRanks(QStringList statics, QList<PremadeArtifact> *artifactList)
{
    this->formatedStuff = &statics;
    this->FormatStatic();

//    QFile file;
//    file(this->filename);
    if(file->open(QIODevice::ReadWrite))
    {
        for(int i = 0; i < artifactList->count(); i ++)
        {
            QString art = "artifact=";
            PremadeArtifact a = artifactList->at(i);
            art += a.artifact;
            names->append(a.name);
            art.chop(1);
        }


        this->Output();
    }
    else
    {
        qDebug() << "FILE IS FUCKED";
    }
}

void Generator::GenerateArtifactRelics(QStringList statics, QString weaponLine,
                                       QList<Relic> *relics, QString artifactLine, int stdIlvl)
{
    this->formatedStuff = &statics;
//    this->FormatStatic();

    if(file->open(QIODevice::ReadWrite))
    {
        QString tester = "";
        if (weaponLine.contains("main_hand"))
        {
            tester = "main_hand";
        }
        else
        {
            tester = "off_hand";
        }

        bool cont = true;
        for(int j = 0; j < formatedStuff->count() && cont; j ++)
        {
            QString test = formatedStuff->at(j);
            if(test.contains(tester))
            {
                formatedStuff->removeAt(j);
                cont = false;
            }
        }


        for(int i = 0; i < relics->count(); i ++)
        {
            Relic r = relics->at(i);

            for(int j = 0; j < r.ilvl.count(); j ++)
            {
                int ilvl = r.ilvl.at(j);
                int artiIlvl = this->artifactLookup->value(stdIlvl);
                int weapilvl = 750 + artiIlvl*2 + this->artifactLookup->value(ilvl);
                QString weaponline = weaponLine +  ",ilevel=" + QString::number(weapilvl);
                QString name = r.name + QString::number(ilvl);
                QString fullLine = "";
                for(int k = 0; k < r.id.count(); k++)
                {
                    fullLine = weaponline + "\n";
                    QString newArti = IncrementArtifact(artifactLine, r.id.at(k));
                    QString artiline = "artifact=" + newArti + "\n";
                    fullLine += artiline;

                }
                names->append(name);
                generatedExtraStuff->append(fullLine);
//                generatedExtraStuff->append(weaponline);
            }

        }
        this->Output();
    }
}


void Generator::FormatStatic()
{

}

void Generator::GenExtras()
{

}

void Generator::Output(bool write)
{
    QTextStream io(file);
    qDebug() << "names count: " << names->count();
    qDebug() << "generatedStuff count: " << generatedExtraStuff->count();

    for(int i = 0; i < names->count(); i ++)
    {
//        if(i == 0)
//            io << "warlock=\"" << names->at(i) << "\"" << endl;
//        else
//            io << "copy=\"" << names->at(i) << "\"" << endl;
        io << classname << "=\"" << names->at(i) << "\"" << endl;
//        io << "warlock=\"" << names->at(i) << "\"" << endl;
        for(int t = 0; t < formatedStuff->count(); t ++)
        {
            io << formatedStuff->at(t) << endl;
        }

        if(write)
        {
            io << generatedExtraStuff->at(i) << endl << endl;
//            qDebug() << "I: " <<i;
        }
    }

    file->resize(file->pos());

    file->close();
}

//Relic ilevel increase
//825 +36
//830 +37
//835 +39
//840 +40
//845 +42
//850 +43
//855 +45
//860 +46
//865 +48
//870 +49
//875 +51
//880 +52
//885 +53
//890 +55
//895 +56

void Generator::InitMaps()
{
    artifactLookup = new QMap<int, int>();
    artifactLookup->insert(825, 36);
    artifactLookup->insert(830, 37);
    artifactLookup->insert(835, 39);
    artifactLookup->insert(840, 40);
    artifactLookup->insert(845, 42);
    artifactLookup->insert(850, 43);
    artifactLookup->insert(855, 45);
    artifactLookup->insert(860, 46);
    artifactLookup->insert(865, 48);
    artifactLookup->insert(870, 49);
    artifactLookup->insert(875, 51);
    artifactLookup->insert(880, 52);
    artifactLookup->insert(885, 53);
    artifactLookup->insert(890, 55);
    artifactLookup->insert(895, 56);
}

QString Generator::IncrementArtifact(QString artifactLine, int rank)
{
    QString retval = "";

    QStringList l = artifactLine.split(':');
    bool cont = true;
    for(int i = 0; i < l.count() && cont; i ++)
    {
        QString s = l.at(i);
        if (rank == s.toInt())
        {
            QString t = l.at(i + 1);
            int r = t.toInt() + 1;
            l.replace(i+1, QString::number(r));
            cont = false;
        }
    }
    for(int i = 0; i < l.count(); i ++)
    {
        retval.append(l.at(i));
        retval.append(":");
    }
    retval.chop(1);
    return retval;
}

QString Generator::GenrateNameFromTalentString(QString talentString)
{
    QList<int> intlist = QList<int>();

    for(int i = 0; i < talentString.count(); i ++)
    {
        QString t = talentString.at(i);
        intlist.append(t.toInt());
    }

    QString retval = "";
    bool cont = true;

    for(int i = 0; i < intlist.count() & cont; i ++)
    {
        if(intlist.at(i) != 0)
        {
            qDebug() << "SPEC: " << this->spec;
            QString queryString = "SELECT abreviation FROM 'talent_pairs' where spec = \'"
                    + this->spec + "\' AND id = \'" + QString::number(intlist.at(i))
                    + "\' AND tier = \'" + QString::number(i) + "\';";

//            QSqlQuery query;
//            query.prepare(queryString);
//            bool check = query.exec();
//            QSqlQuery check = db.exec(queryString);
//            if(!query.lastError().isValid())
//            {
//                qDebug() << "FUCKED! Line: " + QString::number(i) + ":"
//                            + QString::number(intlist.at(i));

//                qDebug() << query.lastError().text();
//                qDebug() << check.lastError().text();
//                cont = false;
//            }
//            else
//            {
//                qDebug() << "test!";
//                QString res = query.value(0).toString();
//                QString res = check.record()
//                qDebug() << "got a name: " << res;

//                retval += res;

//                if(query.next())
//                {

//                }
//                else
//                {
//                    qDebug() << "???";
//                }
//            }


            retval += "-";
        }
    }
    if(cont)
        retval.chop(1);

    if(!cont)
        return "FUCKED";
    return retval;

}

#ifndef GENERATOR_H
#define GENERATOR_H

#include <QList>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QMap>
#include <QDebug>
#include <QDir>

#include "innards.h"
#include "lookup.h"
#include "databasehandler.h"


class Generator
{

public:
    Generator(QString filename, QString classname, QString spec, DatabaseHandler *db);

    Mode m_mode;
    QString *filename;
    Lookup *lookup;

    QFile *file;
    QString classname;
    QString spec;
    int classID;
    int specID;

    QList<QString> *generatedExtraStuff;
    QList<QString> *names;
    QString *staticStuff;
    QStringList *formatedStuff;

    QMap<int, int> *artifactLookup;

    void GenerateTalents(QStringList statics, QList<QList<int> > talents);
    void GenerateGear(QStringList statics, QList<Gear> *gearlist, QString slot);
    void GenerateRotation(QStringList statics, QString staticAPL, QList<APL> *aplTest);
    void GenerateArtifactRanks(QStringList statics, QList<PremadeArtifact> *artifactList);
    void GenerateArtifactRelics(QStringList statics, QString weaponLine, QList<Relic> *relics,
                                QString baseArtifact, int stdIlvl);


private:
    void FormatStatic();
    void GenExtras();
    void Output(bool write = true);
    void InitMaps();
    QString IncrementArtifact(QString artifactLine, int rank);
    QString GenrateNameFromTalentString(QString talentString);

    DatabaseHandler *db;

//    void GenGear();
//    void GenRotation();
//    void GenArtifactTraits();
};

#endif // GENERATOR_H

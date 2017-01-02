#ifndef INNARDS_H
#define INNARDS_H

#include <QString>
#include <QList>

enum Mode
{
    TALENT,
    GEAR,
    ROTATION,
    ARTIFACT_TRAITS
};

//bonus_id=604 is haste
//bonus_id=603 is crit
//bonus_id=605 is mastery
//bonus_id=607 is vers

struct Name
{
    QString unformated;
    QString formatted;

    Name(QString s)
    {
        unformated = s;
        //DO FORMATTING
    }
};

struct Gear
{
    int id;
    QList<int> ilvl;
    int enchantId;
    QList<int> bonuses;
    QList<int> gemIds;
    QString name;
    QString slot;

    Gear()
    {
        enchantId = 0;
        bonuses = QList<int>();
        gemIds = QList<int>();
    }

    QString toString()
    {
        QString retval = "";
        retval += name;
        retval += " " + QString::number(id);
        if(ilvl.count() > 0)
        {
            int low = ilvl.at(0);
            int high = ilvl.at(ilvl.count() - 1);
            retval += " " + QString::number(low) + "-" + QString::number(high);
        }
        return retval;
    }
};


struct Talents
{
    int row;
    int number;
    QString name;
};

struct APL
{
    QString aplLine;
    QString name;
};

struct Artifact
{
    int id;
    int val;
    bool gem;

    Artifact(bool g = false, int id = 0, int val = 0)
    {
        gem = g;
        this->id = id;
        this->val = val;
    }
};

struct PremadeArtifact
{
    QString artifact;
    QString name;
};

struct Relic
{
    QList<int> id;
    QList<int> ilvl;
    QString name;

    Relic()
    {
        id = QList<int>();
        ilvl = QList<int>();
    }
};


//////////////////////////////
/// class type stuff
//todo
enum ClassType
{
    NOCLASS,
    WARRIOR,
    WARLOCK
};

//todo
enum SpecType
{
    NOSPEC,
    AFFLICTION,
    DESTRUCTION,
    DEMONOLOGY,
    ARMS,
    FURY,
    PROTECTION
};


struct ClassInfo
{
    QString name;
    ClassType type;
};

struct SpecInfo
{
    QString name;
    ClassType classType;
    SpecType type;
};

//todo
enum ItemType
{
    TRINKET,
    WEAPON,
    HEALM
};


struct ArtifactRank
{
    Name name;
    int id;
    int maxrank;
};

struct Item
{
    ItemType type;
    int id;
    Name name;

};



struct ClassSpecInfo
{
    ClassInfo _class;
    SpecInfo _spec;
    QList<QList<Talents>> *talents;

    QList<ArtifactRank> *artifactRanks;

};


//int relicAffId[] = { 137465, 139718, 137363, 133687, 137350, 139260 };
//    string relicAffTrait[] = { "UA Crit", "Dot Crit DMG", "Shadow DMG", "Corruption DMG", "Agony DMG", "Drain Life DMG" };

#endif // INNARDS_H

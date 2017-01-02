#ifndef LOOKUP_H
#define LOOKUP_H

#include <QMap>
#include <QList>
#include "innards.h"


class Lookup
{
public:
    Lookup();


    ClassSpecInfo *info;

    QMap<SpecType, SpecInfo> *specInfoMap;
    QMap<ClassType, ClassInfo> *classTypeLookup;
    QMap<ClassType, QList<SpecInfo>> *specInfoLookup;
    QMap<SpecType, QList<QList<Talents>>> *talentLookup;


private:
    void SetWarlockTalents();
    void SetWarriorTalents();
};

#endif // LOOKUP_H

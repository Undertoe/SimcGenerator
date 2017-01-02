#include "lookup.h"

Lookup::Lookup()
{
    info = new ClassSpecInfo();
    classTypeLookup = new QMap<ClassType, ClassInfo>();
    specInfoLookup = new QMap<ClassType, QList<SpecInfo>>();
    talentLookup = new QMap<SpecType, QList<QList<Talents>>>();
    specInfoMap = new QMap<SpecType, SpecInfo>();

    //INIT LOOKUP TABLES
    classTypeLookup->insert(WARRIOR, {"Warrior", WARRIOR});
    classTypeLookup->insert(WARLOCK, {"Warlock", WARLOCK });



    QList<SpecInfo> specInfoList = QList<SpecInfo>();
    specInfoList.append({"Arms", WARRIOR, ARMS});
    specInfoList.append({"Fury", WARRIOR, FURY});
    specInfoList.append({"Protection", WARRIOR, PROTECTION});
    specInfoLookup->insert(WARRIOR, specInfoList);
    specInfoList.clear();
    specInfoList.append({"Affliction", WARLOCK, AFFLICTION});
    specInfoList.append({"Destruction", WARLOCK, DESTRUCTION});
    specInfoList.append({"Demonology", WARLOCK, DEMONOLOGY});
    specInfoLookup->insert(WARLOCK, specInfoList);

    specInfoMap->insert(AFFLICTION, {"Affliction", WARLOCK, AFFLICTION});
    specInfoMap->insert(AFFLICTION, {"Destruction", WARLOCK, DESTRUCTION});
    specInfoMap->insert(AFFLICTION, {"Demonology", WARLOCK, DEMONOLOGY});
    specInfoMap->insert(AFFLICTION, {"Arms", WARRIOR, ARMS});
    specInfoMap->insert(AFFLICTION, {"Fury", WARRIOR, FURY});
    specInfoMap->insert(AFFLICTION, {"Protection", WARRIOR, PROTECTION});


    this->SetWarlockTalents();
    this->SetWarriorTalents();


}


void Lookup::SetWarlockTalents()
{
    QList<QList<Talents>> talents = QList<QList<Talents>>();
    QList<Talents> t = QList<Talents>();
    t.append({1,1,"Haunt"});    //r1
    t.append({1,2,"Writhe in Agony"});
    t.append({1,3,"Drain Soul"});
    talents.append(t);
    t.clear();
    t.append({2,1,"Contagion"});    //r2
    t.append({2,2,"Absolute Corruption"});
    t.append({2,3,"Mana Tap"});
    talents.append(t);
    t.clear();
    t.append({3,1,"Demonic Circle"});    //r3
    t.append({3,2,"Mortal Coil"});
    t.append({3,3,"Howl of Terror"});
    talents.append(t);
    t.clear();
    t.append({4,1,"Siphon Life"});    //r4
    t.append({4,2,"Sow the Seeds"});
    t.append({4,3,"Soul Harvest"});
    talents.append(t);
    t.clear();
    t.append({5,1,"Demonic Circle"});    //r5
    t.append({5,2,"Burning Rush"});
    t.append({5,3,"Dark Pact"});
    talents.append(t);
    t.clear();
    t.append({6,1,"Grimoire of Supremacy"});    //r6
    t.append({6,2,"Grimoire of Service"});
    t.append({6,3,"Grimoire of Sacrifice"});
    talents.append(t);
    t.clear();
    t.append({7,1,"Soul Effigy"});    //r7
    t.append({7,2,"Phantom Singularity"});
    t.append({7,3,"Soul Conduit"});
    talents.append(t);
    talentLookup->insert(AFFLICTION, talents);
    talents.clear();
    t.clear();

    t.append({1,1,"Backdraft"});    //r1
    t.append({1,2,"Roaring Blaze"});
    t.append({1,3,"Shadowburn"});
    talents.append(t);
    t.clear();
    t.append({2,1,"Reverse Entropy"});    //r2
    t.append({2,2,"Cataclysm"});
    t.append({2,3,"Mana Tap"});
    talents.append(t);
    t.clear();
    t.append({3,1,"Demonic Circle"});    //r3
    t.append({3,2,"Mortal Coil"});
    t.append({3,3,"Howl of Terror"});
    talents.append(t);
    t.clear();
    t.append({4,1,"Eradication"});    //r4
    t.append({4,2,"Fire and Brimstone"});
    t.append({4,3,"Soul Harvest"});
    talents.append(t);
    t.clear();
    t.append({5,1,"Demonic Circle"});    //r5
    t.append({5,2,"Burning Rush"});
    t.append({5,3,"Dark Pact"});
    talents.append(t);
    t.clear();
    t.append({6,1,"Grimoire of Supremacy"});    //r6
    t.append({6,2,"Grimoire of Service"});
    t.append({6,3,"Grimoire of Sacrifice"});
    talents.append(t);
    t.clear();
    t.append({7,1,"Wreak Havoc"});    //r7
    t.append({7,2,"Channel Demonfire"});
    t.append({7,3,"Soul Conduit"});
    talents.append(t);
    talentLookup->insert(DESTRUCTION, talents);
    talents.clear();
    t.clear();

    t.append({1,1,"Shadowy Inspiration"});    //r1
    t.append({1,2,"Shadow Flame"});
    t.append({1,3,"Demonic Calling"});
    talents.append(t);
    t.clear();
    t.append({2,1,"Impending Doom"});    //r2
    t.append({2,2,"Improved Dreadstalkers"});
    t.append({2,3,"Implosion"});
    talents.append(t);
    t.clear();
    t.append({3,1,"Demonic Circle"});    //r3
    t.append({3,2,"Mortal Coil"});
    t.append({3,3,"Howl of Terror"});
    talents.append(t);
    t.clear();
    t.append({4,1,"Hand of Doom"});    //r4
    t.append({4,2,"Power Trip"});
    t.append({4,3,"Soul Harvest"});
    talents.append(t);
    t.clear();
    t.append({5,1,"Demonic Circle"});    //r5
    t.append({5,2,"Burning Rush"});
    t.append({5,3,"Dark Pact"});
    talents.append(t);
    t.clear();
    t.append({6,1,"Grimoire of Supremacy"});    //r6
    t.append({6,2,"Grimoire of Service"});
    t.append({6,3,"Grimoire of Synergy"});
    talents.append(t);
    t.clear();
    t.append({7,1,"Summon Darkglare"});    //r7
    t.append({7,2,"Demonbolt"});
    t.append({7,3,"Soul Conduit"});
    talents.append(t);
    talentLookup->insert(DEMONOLOGY, talents);
    talents.clear();
    t.clear();
}

void Lookup::SetWarriorTalents()
{
    QList<QList<Talents>> talents = QList<QList<Talents>>();
    QList<Talents> t = QList<Talents>();
    t.append({1,1,"Shockwave"});    //r1
    t.append({1,2,"Storm Bolt"});
    t.append({1,3,"War Bringer"});
    talents.append(t);
    t.clear();
    t.append({2,1,"Impending Victor"});    //r2
    t.append({2,2,"Inspiring Presence"});
    t.append({2,3,"Safeguard"});
    talents.append(t);
    t.clear();
    t.append({3,1,"Renewed Fury"});    //r3
    t.append({3,2,"Ultimatum"});
    t.append({3,3,"Avatar"});
    talents.append(t);
    t.clear();
    t.append({4,1,"Warlord's Challenge"});    //r4
    t.append({4,2,"Bounding Stride"});
    t.append({4,3,"Crackling Thunder"});
    talents.append(t);
    t.clear();
    t.append({5,1,"Best Served Cold"});    //r5
    t.append({5,2,"Never Surrender"});
    t.append({5,3,"Indomitable"});
    talents.append(t);
    t.clear();
    t.append({6,1,"Vengance"});    //r6
    t.append({6,2,"Into the Fray"});
    t.append({6,3,"Booming Voice"});
    talents.append(t);
    t.clear();
    t.append({7,1,"Anger Managment"});    //r7
    t.append({7,2,"Heavy Reprecussions"});
    t.append({7,3,"Ravager"});
    talents.append(t);
    talentLookup->insert(PROTECTION, talents);
    talents.clear();
    t.clear();

    t.append({1,1,"Dauntless"});    //r1
    t.append({1,2,"Overpower"});
    t.append({1,3,"Sweeping Strikes"});
    talents.append(t);
    t.clear();
    t.append({2,1,"Shockwave"});    //r2
    t.append({2,2,"Storm Bolt"});
    t.append({2,3,"War Bringer"});
    talents.append(t);
    t.clear();
    t.append({3,1,"Fervor of Battle"});    //r3
    t.append({3,2,"Rend"});
    t.append({3,3,"Avatar"});
    talents.append(t);
    t.clear();
    t.append({4,1,"Second Wind"});    //r4
    t.append({4,2,"Bounding Stride"});
    t.append({4,3,"Defensive Stance"});
    talents.append(t);
    t.clear();
    t.append({5,1,"For the Kill"});    //r5
    t.append({5,2,"Mortal Combo"});
    t.append({5,3,"Focused Rage"});
    talents.append(t);
    t.clear();
    t.append({6,1,"Deadly Calm"});    //r6
    t.append({6,2,"Trauma"});
    t.append({6,3,"Titanic Might"});
    talents.append(t);
    t.clear();
    t.append({7,1,"Anger Managment"});    //r7
    t.append({7,2,"Opportune Strikes"});
    t.append({7,3,"Ravager"});
    talents.append(t);
    talentLookup->insert(ARMS, talents);
    talents.clear();
    t.clear();

    t.append({1,1,"War Machine"});    //r1
    t.append({1,2,"Endless Rage"});
    t.append({1,3,"Fresh Meat"});
    talents.append(t);
    t.clear();
    t.append({2,1,"Shockwave"});    //r2
    t.append({2,2,"Storm Bolt"});
    t.append({2,3,"War Bringer"});
    talents.append(t);
    t.clear();
    t.append({3,1,"Wrecking Ball"});    //r3
    t.append({3,2,"Outburst"});
    t.append({3,3,"Avatar"});
    talents.append(t);
    t.clear();
    t.append({4,1,"Furious Charge"});    //r4
    t.append({4,2,"Bounding Stride"});
    t.append({4,3,"Warpaint"});
    talents.append(t);
    t.clear();
    t.append({5,1,"Massacre"});    //r5
    t.append({5,2,"Frothing Berserker"});
    t.append({5,3,"Carnage"});
    talents.append(t);
    t.clear();
    t.append({6,1,"Bloodbath"});    //r6
    t.append({6,2,"Frenzy"});
    t.append({6,3,"Inner Rage"});
    talents.append(t);
    t.clear();
    t.append({7,1,"Blade Storm"});    //r7
    t.append({7,2,"Reckless Abandon"});
    t.append({7,3,"Dragon Roar"});
    talents.append(t);
    talentLookup->insert(FURY, talents);
    talents.clear();
    t.clear();}

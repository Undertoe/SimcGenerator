#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QSqlError>

#include <QStringList>
#include <QList>

class DatabaseHandler
{
public:
    DatabaseHandler();
    ~DatabaseHandler();

    QString GetClass(int specID);
    QString GetSpecName(int classID, int specID);

    QStringList GetClasses();
    QStringList GetSpecsForClass(int classID);
    QList<QStringList> GetTalentsForSpec(int classID, int specID);

    QString GetTalentStringName(int classID, int specID, QString talentString);

private:
    QSqlDatabase db;

    QString Query(QString query);
    void open();
    void close();

};

#endif // DATABASEHANDLER_H

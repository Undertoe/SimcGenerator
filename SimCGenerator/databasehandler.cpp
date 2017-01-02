#include "databasehandler.h"

DatabaseHandler::DatabaseHandler()
{
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    QDir dir = QDir::current();
    qDebug() << dir.path();
#ifdef __APPLE__    // because apple says fuck you executables,
    dir.cdUp();     // you get to go 3 directories up.  because we're a
    dir.cdUp();     // bunch of cocks
    dir.cdUp();
#endif
    qDebug() << dir.path();
    qDebug() << dir.path() + "simcgendb.db";
    qDebug() << dir.absoluteFilePath("simcgendb.db");
    db.setDatabaseName(dir.absoluteFilePath("simcgendb.db"));
}

QString DatabaseHandler::GetClass(int specID)
{
    open();
    QString retval = "";
    QString q = "SELECT class_name FROM classes WHERE class_id = "
            + QString::number(specID) + ";";

    QSqlQuery query(db);
    if(!query.exec(q))
    {
        qDebug() << query.lastError().text();
        retval = "";
    }
    while(query.next())
    {
        QString t = query.value("class_name").toString();
        qDebug() << t;
        retval =  t;
    }
    close();

    return retval;
}


QString DatabaseHandler::GetSpecName(int classID, int specID)
{
    open();
    QString retval = "";
    QString q = "SELECT specname FROM specs WHERE class_id = " +
            QString::number(classID) + " AND spec_id = " +
            QString::number(specID) + ";";

    QSqlQuery query(db);
    if(!query.exec(q))
    {
        qDebug() << query.lastError().text();
        retval = "";
    }
    while(query.next())
    {
        QString t = query.value("specname").toString();
        qDebug() << t;
        retval =  t;
    }
    close();

    return retval;
//    QString q = "SELECT spec_name FROM specs WHERE class_id = " +
//            QString::number(classID) + " AND spec_id = " +
//            QString::number(specID) + ";";

//    return Query(q);
}


QStringList DatabaseHandler::GetClasses()
{
    QStringList retval = QStringList();
    open();
    QString q = "SELECT class_name FROM classes";
    int i = 0;

    QSqlQuery query(db);
//    query.prepare(q);
    if(!query.exec(q))
    {
//        qDebug() << "???";
        qDebug() << query.lastError().text();
    }
    while(query.next())
    {
//        qDebug() << "Search: " + QString::number(i++);
        QString t = query.value("class_name").toString();
        retval.append(t);
    }

//    for(int i = 1; i < 13; i ++)
//    {
//        QString q = "SELECT class_name FROM classes WHERE class_id = "
//                + QString::number(i);

//        QString s = Query(q);
//        retval.append(s);
//    }
    close();
    return retval;
}


QStringList DatabaseHandler::GetSpecsForClass(int classID)
{
    open();
    QStringList retval = QStringList();
    int t = 4;
    QString q = "SELECT specname FROM specs WHERE class_id = "
                            + QString::number(classID) + ";";

    QSqlQuery query(db);
    if(!query.exec(q))
    {
        qDebug() << query.lastError().text();
    }
    while(query.next())
    {
        QString t = query.value("specname").toString();
        retval.append(t);
    }

//    if(classID == 3)
//        t ++;
//    for(int i = 1; i < t; i ++)
//    {
//        QString q = "SELECT specname FROM specs WHERE class_id = "
//                + QString::number(classID) + " AND spec_id = " + QString::number(i);

//        QString s= Query(q);
//        retval.append(s);
//    }
    close();
    return retval;
}

QList<QStringList> DatabaseHandler::GetTalentsForSpec(int classID, int specID)
{
    QList<QStringList> retval = QList<QStringList>();
    bool failed = false;
    open();
    for(int i = 1; i < 8; i ++)
    {
        QString str = "SELECT name FROM talent_pairs WHERE class_id = "
                + QString::number(classID) + " AND spec_id = " + QString::number(specID)
                + " AND tier = " + QString::number(i) + ";";

        QSqlQuery q(db);
        if(!q.exec(str))
        {
            qDebug() << q.lastError().text();
            failed = true;
        }
        else
        {
            QStringList tmp = QStringList();
            while(q.next())
            {
                QString t = q.value("name").toString();
                tmp.append(t);
            }
            retval.append(tmp);
        }

    }

    if(failed)
        retval.clear();

    close();
    return retval;
}

QString DatabaseHandler::GetTalentStringName(int classID, int specID, QString talentString)
{
    QList<int> intlist = QList<int>();

    for(int i = 0; i < talentString.count(); i ++)
    {
        QString t = talentString.at(i);
        intlist.append(t.toInt());
    }


    open();
    QString str = "";
    QString retval = "";

    bool cont = true;
    for(int i = 0; i < talentString.count() && cont; i ++)
    {
        if(intlist.at(i) != 0)
        {
            str = "SELECT abreviation FROM 'talent_pairs' where spec_id = "
                                + QString::number(specID) + " AND class_id = "
                                + QString::number(classID) + " AND id = \'"
                                + QString::number(intlist.at(i))
                                + "\' AND tier = \'" + QString::number(i + 1) + "\';";

//            qDebug() << str;
            QSqlQuery q(db);

            if(!q.exec(str))
            {
                qDebug() << q.lastError().text();
                retval = "";
                cont = false;
            }
            else
            {
                while(q.next())
                {
                    QString t = q.value("abreviation").toString();
//                    qDebug() << t;
                    retval.append(t);
                    retval.append("-");
                }
            }
        }
    }

    retval.chop(1);

//    qDebug() << "Name: " << retval;

    close();
    return retval;
}


QString DatabaseHandler::Query(QString query)
{
    QString retval = "";
    open();
    QSqlQuery q = db.exec(query);
    if(q.lastError().isValid())
    {
        retval = q.value(0).toString();
        qDebug() << retval;
    }
    else
    {
        if(q.lastError().text() == " ")
        {
            retval = q.value(0).toString();
        }
        else
        {
            qDebug() << "Query Failed!";
            qDebug() << query;
            qDebug() << q.lastError().text();

            retval = "FAIL";
        }
    }
    close();
    return retval;
}

void DatabaseHandler::open()
{
    bool check = db.open();
    if(!check)
        qDebug() << "DB FAILED TO OPEN!";
//    else
//        qDebug() << "opened db";
}

void DatabaseHandler::close()
{
    db.close();
//    qDebug() << "db closed";
}

DatabaseHandler::~DatabaseHandler()
{
    db.close();
}

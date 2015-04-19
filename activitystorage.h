#ifndef ACTIVITYSTORAGE_H
#define ACTIVITYSTORAGE_H

#include <QObject>
#include <QFile>
#include <QStandardPaths>
#include <QStringList>
#include <QStringListModel>
#include "activity.h"


class ActivityStorage : public QObject {
    Q_OBJECT

    Q_PROPERTY(QStringList getModel READ getModel NOTIFY comboListChanged)

    QFile *file;
    QString path;
    QStringList activities;

    void loadActivities();

public:
    explicit ActivityStorage(QObject *parent = 0, const char *path = 0);
    ~ActivityStorage();

    void storeActivity(Activity *activity);
    QStringList getModel();
signals:

    void comboListChanged();
public slots:

};

#endif // ACTIVITYSTORAGE_H

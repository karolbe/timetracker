#ifndef TIMETRACKER_H
#define TIMETRACKER_H

#include <QObject>
#include <QtDebug>
#include "activitystorage.h"

class TimeTracker : public QObject {
    Q_OBJECT
    QString path;

public:
    explicit TimeTracker(QObject *parent = 0, ActivityStorage *storage = 0);
    ~TimeTracker();

    Q_INVOKABLE void saveActivity(QString activity, QString description, QString value);

    ActivityStorage *storage;
signals:

public slots:


};

#endif // TIMETRACKER_H

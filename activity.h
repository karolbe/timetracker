#ifndef ACTIVITY_H
#define ACTIVITY_H
#include <QString>

class Activity {
public:
    Activity(QString activityName, QString description, QString duration);
    ~Activity();
    QString toString();

    QString activityName;
    QString description;
    QString duration;
};

#endif // ACTIVITY_H

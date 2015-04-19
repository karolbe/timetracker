#include "activity.h"
#include <QDateTime>

Activity::Activity(QString activityName, QString description, QString duration) {
    this->activityName = activityName;
    this->description = description;
    this->duration = duration;
}

Activity::~Activity() {

}

QString Activity::toString() {
    QDateTime dateTime = QDateTime::currentDateTime();
    QString nowString = dateTime.toString("dd/MM/yyyy hh:mm:ss");
    QString csvRow = QString("%1;%2;%3;%4").arg(nowString, activityName, description, duration);
    return csvRow;
}

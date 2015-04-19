#include "timetracker.h"

TimeTracker::TimeTracker(QObject *parent, ActivityStorage *storage) : QObject(parent) {
    this->storage = storage;
}

TimeTracker::~TimeTracker() {
}

Q_INVOKABLE void TimeTracker::saveActivity(QString activity, QString description, QString value) {

    this->storage->storeActivity(new Activity(activity, description, value));
}

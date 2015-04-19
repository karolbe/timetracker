#include "activitystorage.h"
#include <QtDebug>

ActivityStorage::ActivityStorage(QObject *parent, const char *storageFileName) : QObject(parent)  {
    path = QString(storageFileName);
    path.prepend("/").prepend(QStandardPaths::writableLocation(QStandardPaths::HomeLocation));

    loadActivities();

    file = new QFile(path);
    file->open(QIODevice::Append);
    file->seek(file->size());
}

ActivityStorage::~ActivityStorage() {
    file->close();
}

void ActivityStorage::loadActivities() {
    QFile *file = new QFile(path);

    activities.clear();
    if(file->open(QIODevice::ReadOnly)) {
       QTextStream in(file);
       while (!in.atEnd()) {
          QString line = in.readLine();
          QString activityName = line.section(";", 1, 1);
          if(activities.indexOf(activityName) == -1) {
              activities << activityName;
          }
       }
    }
    file->close();
    qDebug() << "Loaded" << activities.length() << "activities";
}

QStringList ActivityStorage::getModel() {
    return activities;
}

void ActivityStorage::storeActivity(Activity *a) {
    qDebug() << a->duration;
    file->write(a->toString().toStdString().c_str());
    file->write("\n");
    file->flush();
}

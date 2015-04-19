#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQuickView>
#include "timetracker.h"
#include "activitystorage.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ActivityStorage *storage = new ActivityStorage(NULL, ".timetracker.csv");
    TimeTracker t(NULL, storage);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("timeTracker", &t);
    engine.rootContext()->setContextProperty("activityModel", QVariant::fromValue(storage->getModel()));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

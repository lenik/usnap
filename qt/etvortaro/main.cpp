#include <QtGui/QApplication>
#include <qdeclarative.h>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeEngine>
#include "qmlapplicationviewer.h"

#include "session.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));
    QmlApplicationViewer viewer;

    Session session;
    // session.load();
    viewer.engine()->rootContext()->setContextObject(&session);

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    // viewer.setSource(QUrl("qrc:///qml/main.qml"));
    viewer.setMainQmlFile(QString("qml/main.qml"));
    viewer.showExpanded();

    return app->exec();
}

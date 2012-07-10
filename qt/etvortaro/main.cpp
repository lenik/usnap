#include <QtGui/QApplication>
#include <qdeclarative.h>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeEngine>
#include "qmlapplicationviewer.h"

#include "session.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    qmlRegisterType<Dict>("Vortaro", 1, 0, "Dict");
    qmlRegisterType<Word>("Vortaro", 1, 0, "Word");

    QScopedPointer<QApplication> app(createApplication(argc, argv));
    QmlApplicationViewer viewer;
    QDeclarativeEngine *engine = viewer.engine();
    QDeclarativeContext *rootContext = engine->rootContext();

    // engine->addImportPath(QString("/opt/nokia/qtsdk/Simulator/Qt/gcc/imports"));

    Session session;
    session.load();
    rootContext->setContextObject(&session);

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationLockPortrait);
    viewer.setSource(QUrl("qrc:///qml/main.qml"));
    // viewer.setMainQmlFile(QString("qml/main.qml"));
    viewer.showExpanded();

    return app->exec();
}

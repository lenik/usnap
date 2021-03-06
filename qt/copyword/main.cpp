#include <QtGui/QApplication>
#include <qdeclarative.h>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeEngine>

#include "qmlapplicationviewer.h"
#include "session.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    qmlRegisterType<CsvFile>("Copyword", 1, 0, "CsvFile");

    QScopedPointer<QApplication> app(createApplication(argc, argv));
    QmlApplicationViewer viewer;

    Session session;
    viewer.engine()->rootContext()->setContextObject(&session);

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationLockPortrait);
    viewer.setSource(QUrl("qrc:///qml/main.qml"));
    viewer.showExpanded();

    return app->exec();
}

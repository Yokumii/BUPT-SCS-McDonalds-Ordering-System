#include "loginwindow.h"
#include "global.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "McDonald_GUI_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/anime/start.jpg"));
    splash->show();
    splash->showMessage(QObject::tr("load..."), Qt::AlignCenter, Qt::red);

    QDateTime time = QDateTime::currentDateTime();
    QDateTime currentTime = QDateTime::currentDateTime();
    while (time.secsTo(currentTime) <= 3)
    {
        a.processEvents();
        splash->showMessage(QObject::tr("load."), Qt::AlignCenter, Qt::red);
        QThread::msleep(200);
        splash->showMessage(QObject::tr("load.."), Qt::AlignCenter, Qt::red);
        QThread::msleep(200);
        splash->showMessage(QObject::tr("load..."), Qt::AlignCenter, Qt::red);
        QThread::msleep(200);
        currentTime = QDateTime::currentDateTime();

    };
    LoginWindow w;
    w.setWindowIcon(QIcon(":/button_icon/icon.jpg"));
    w.show();

    splash->finish(&w);
    delete splash;

    return a.exec();
}

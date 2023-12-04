#include "mainwindow.h"

#include <QApplication>
#include <QStyle>
#include <QScreen>
#include <QDesktopWidget>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow w;

    QList<QScreen*> screens = QGuiApplication::screens();
    if (!screens.isEmpty()) {
        QScreen *primaryScreen = screens.at(0);

        QSize desktopSize = primaryScreen->availableGeometry().size();
        QSize size(desktopSize.width() * 1, desktopSize.height() * 1);

        w.setGeometry(QStyle::alignedRect(
                          Qt::LeftToRight,
                          Qt::AlignCenter,
                          size,
                          primaryScreen->availableGeometry()
                      ));
    }

    w.init();
    w.show();

    return a.exec();
}

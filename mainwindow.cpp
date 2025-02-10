#include "mainwindow.h"
#include "xdgactivationv1.h"

#include <QPushButton>
#include <QTimer>
#include <QApplication>
#include <qpa/qplatformnativeinterface.h>

MainWindow::MainWindow()
    : QMainWindow()
    , m_startButton(new QPushButton(this))
    , m_xdgactivation(new XdgActivationV1)
{
    m_startButton->setText("start");
    setCentralWidget(m_startButton);
    connect(m_startButton, &QPushButton::clicked, this, &MainWindow::start);
}

void MainWindow::start()
{
    if (m_xdgactivation->isActive()) {
        disconnect(m_xdgactivation, &XdgActivationV1::activeChanged, this, &MainWindow::start);
        showMinimized();
        QTimer::singleShot(3000, this, [this] {
            auto pni = qApp->platformNativeInterface();
            if (!pni) {
                qWarning() << "Cannot get platform native interface.";
                return;
            }
            auto surface = static_cast<::wl_surface*>(pni->nativeResourceForWindow("surface", windowHandle()));
            if (surface) {
                qInfo() << "Get native wl surface" << surface;
            } else {
                qWarning() << "Cannot get native wl surface.";
            }
            m_xdgactivation->activate("", surface);
        });
    } else {
        connect(m_xdgactivation, &XdgActivationV1::activeChanged, this, &MainWindow::start);
    }
}

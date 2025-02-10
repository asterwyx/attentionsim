#pragma once

#include <QMainWindow>

class QPushButton;
class XdgActivationV1;
class MainWindow : public QMainWindow
{
public:
    MainWindow();

private Q_SLOTS:
    void start();
private:
    QPushButton *m_startButton;
    XdgActivationV1 *m_xdgactivation;
};

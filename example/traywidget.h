#ifndef TRAYWIDGET_H
#define TRAYWIDGET_H

#include <QWidget>

#ifdef Q_OS_MAC
#include "qsystemtrayiconmac.h"
#endif

#include <QSystemTrayIcon>

namespace Ui {
class TrayWidget;
}

class TrayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TrayWidget(QWidget *parent = 0);
    ~TrayWidget();

private slots:
    void trayIconActivated(QSystemTrayIcon::ActivationReason reason);

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::TrayWidget *ui;

#ifdef Q_OS_MAC
    QSystemTrayIconMac *_systemTrayIcon;
    int _showCounter;
#endif

#ifdef Q_OS_LINUX
    QSystemTrayIcon _systemTrayIcon;
#endif
};

#endif // TRAYWIDGET_H

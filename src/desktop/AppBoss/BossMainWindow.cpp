#include "BossMainWindow.h"

#include <QtCore/QDir>
#include <QtCore/QTimer>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>

#include <ActionManager>
#include <MdiGridWidget>

#include "EtcSubWinWidget.h"

BossMainWindow::BossMainWindow(QApplication *pApp)
    : MdiMainWindow(pApp)
{
    setObjectName("AppBoss:MainWindow");
    setWindowTitle("OttoCODE AppBoss");
    QTimer::singleShot(100, this, &BossMainWindow::setup);
}

BossMainWindow::~BossMainWindow()
{
}

void BossMainWindow::viewEtc()
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName();
    EtcSubWinWidget *pEtcWidget = new EtcSubWinWidget(QDir("/etc"), mdiArea());
    pEtcWidget->setup();
    mdiArea()->addSubWindow(pEtcWidget);
}

void BossMainWindow::aboutOttoCODE()
{
    QMessageBox::about(mdiArea(), "About OttoCODE", "<i>Otto</i><b>CODE</b>"
                       " Copyright (c) 1993-2022, Anthony Otto DBA OttoCODE."
                       " All rights reserved worldwide.");
}

void BossMainWindow::aboutAppBoss()
{
    QMessageBox::about(mdiArea(), "About AppBoss",
                       "<b>AppBoss</b> <i>*nix Menu & Icon Manager</i>"
                       " by <i>Otto</i><b>CODE</b>"
                       " Copyright (c) 1993-2022, Anthony Otto DBA OttoCODE.\n"
                       " All rights reserved worldwide.");
}

void BossMainWindow::setupActions()
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName();
    MdiMainWindow::setupActions();
    actions()->add("View/Etc");
    actions()->add("View/Exit");
    actions()->add("Help/AboutQt", "About &Qt6");
    actions()->add("Help/AboutOttoCode", "About &OttoCODE");
    actions()->add("Help/AppBoss", "&About AppBoss");
}

void BossMainWindow::setupMenus()
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName();

    addMenu("MainMenu50/View");
    QMenu * pViewMenu = menu("MainMenu50/View");
    pViewMenu->addAction(action("View/Etc"));
    pViewMenu->addSeparator();
    pViewMenu->addAction(action("View/Exit"));

    addMenu("MainMenu70/Window");
    QMenu * pWindowMenu = menu("MainMenu70/Window");
    pWindowMenu->addAction(action("Window/SubWindow"));
    pWindowMenu->addAction(action("Window/Tabbed"));

    addMenu("MainMenu90/Help");
    QMenu * pHelpMenu = menu("MainMenu90/Help");
    pHelpMenu->addAction(action("Help/AboutQt"));
    pHelpMenu->addAction(action("Help/AboutOttoCode"));
    pHelpMenu->addAction(action("Help/AppBoss"));
}

void BossMainWindow::setupConnections()
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName();
    MdiMainWindow::setupConnections();

    actions()->connectSlot("View/Etc", this, "viewEtc()");
    actions()->connectSlot("View/Exit", this, "exit()", true);
    actions()->connectSlot("Help/AboutQt", qApp, "aboutQt()");
    actions()->connectSlot("Help/AboutOttoCode", this, "aboutOttoCODE()");
    actions()->connectSlot("Help/AppBoss", this, "aboutAppBoss()");
}

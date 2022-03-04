#include "ExcelsiorMain.h"

#include <QtDebug>
#include <QApplication>
#include <QMenu>
#include <QTimer>

#include <ActionManager>
#include <ImageFileDialog>

ExcelsiorMain::ExcelsiorMain(QApplication *pApp)
    : MdiMainWindow(pApp)
{
    setObjectName("Excelsior:MainWindow");
    qDebug() << Q_FUNC_INFO;
    QTimer::singleShot(500, this, &ExcelsiorMain::setup);
}

void ExcelsiorMain::setupActions()
{
    actions()->add("Quit");
    actions()->add("File/OpenImage", "Open I&mage");
}

void ExcelsiorMain::setupConnections()
{
    actions()->connectSlot("Quit", qApp, "quit()", true);
    actions()->connectSlot("File/OpenImage", this, "openFileAction()");
}

void ExcelsiorMain::setupMenus()
{
    qDebug() << Q_FUNC_INFO << objectName();

    addMenu("MenuBar10/File");
    addMenu("MenuBar20/Edit");
    addMenu("MenuBar50/View");
    addMenu("MenuBar70/Window");
    addMenu("MenuBar90/Help");

    setupFileMenu();
    setupEditMenu();
    setupViewMenu();
    setupWindowMenu();
    setupHelpMenu();
}

void ExcelsiorMain::setupFileMenu()
{
    QMenu * pFileMenu = menu("MenuBar10/File");
    pFileMenu->addAction(action("File/OpenImage"));
    pFileMenu->addSeparator();
    pFileMenu->addAction(action("Quit"));
}

void ExcelsiorMain::setupEditMenu()
{

}

void ExcelsiorMain::setupViewMenu()
{

}

void ExcelsiorMain::setupWindowMenu()
{

}

void ExcelsiorMain::setupHelpMenu()
{

}

void ExcelsiorMain::openFileAction()
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName();
    ImageFileDialog *pOpenDialog = new ImageFileDialog(ImageFileDialog::OpenFile, this);
    Q_ASSERT(pOpenDialog);
    pOpenDialog->directory(mCurrentImageDir);
    pOpenDialog->defaultDirectory(mDefaultImageDir);
    if (pOpenDialog->exec())
    {
        openImageFile();
    }
}

void ExcelsiorMain::openImageFile()
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName();
    Q_ASSERT(false); // MUSTDO it

}

#pragma once

#include <MdiMainWindow>

#include <QQDir>
class QQFileInfo;

class ExcelsiorMain : public MdiMainWindow
{
    Q_OBJECT
public:
    ExcelsiorMain(QApplication *pApp);

public slots:

private slots:
    virtual void setupActions() override;
    virtual void setupConnections() override;
    virtual void setupMenus() override;

    void setupFileMenu();
    void setupEditMenu();
    void setupViewMenu();
    void setupWindowMenu();
    void setupHelpMenu();

    void openFileAction();

private:
    QQDir mCurrentImageDir;
    QQDir mDefaultImageDir;
};


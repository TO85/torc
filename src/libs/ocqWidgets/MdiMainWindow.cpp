#include "MdiMainWindow.h"

#include <ActionManager>

#include "MdiDocument.h"
#include "MdiGridWidget.h"

MdiMainWindow::MdiMainWindow(QApplication *pApp)
    : QQMainWindow(pApp)
    , mpMdiArea(new QQMdiArea(this))
{
    setObjectName("MdiMainWindow");
    setCentralWidget(mpMdiArea);
    mpMdiArea->setViewMode(QMdiArea::TabbedView);
}

QObject * MdiMainWindow::object()
{
    return qobject_cast<QObject *>(this);
}

QQMdiArea *MdiMainWindow::mdiArea() const
{
    Q_ASSERT(mpMdiArea);
    return mpMdiArea;
}

MdiSubWinWidget * MdiMainWindow::newSubWindow(const Key &key, const Qt::WindowFlags flags)
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << key;
    MdiSubWinWidget * result = new MdiSubWinWidget(key, mdiArea(), flags);
    add(result);
    qDebug() << result->objectName();
    return result;
}

void MdiMainWindow::add(const QQFileInfo &fi, MdiDocument *pDoc)
{
    Q_ASSERT(pDoc);
    qDebug() << Q_FUNC_INFO << objectName() << fi << pDoc->filePathName();
    Q_ASSERT(false); // MUSTDO it
}


void MdiMainWindow::add(MdiSubWinWidget *pSubWinWidget)
{
    Q_ASSERT(pSubWinWidget);
    qDebug() << Q_FUNC_INFO << objectName() << pSubWinWidget->objectName();
    mSubWinWidgetKeyMap.insert(pSubWinWidget->key(), pSubWinWidget);
}

void MdiMainWindow::setupActions()
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName();
    actions()->add("Window/SubWindow", "Sub &Window");
    actions()->add("Window/Tabbed", "&Tabbed");
}

void MdiMainWindow::setupConnections()
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << objectName();
    actions()->connectSlot("Window/SubWindow", this, "windowSubView()", true);
    actions()->connectSlot("Window/Tabbed", this, "windowTabbed()", true);
}


void MdiMainWindow::windowTabbed()
{
    Q_ASSERT(this);
    Q_ASSERT(mdiArea());
    qDebug() << Q_FUNC_INFO << objectName();
    mdiArea()->setViewMode(QMdiArea::TabbedView);
}

void MdiMainWindow::windowSubView()
{
    Q_ASSERT(this);
    Q_ASSERT(mdiArea());
    qDebug() << Q_FUNC_INFO << objectName();
    mdiArea()->setViewMode(QMdiArea::SubWindowView);
}

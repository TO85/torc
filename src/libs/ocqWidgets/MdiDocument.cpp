#include "MdiDocument.h"

#include <QtDebug>

#include "MdiMainWindow.h"

MdiDocument::MdiDocument(MdiMainWindow * parent)
    : QObject{parent->object()}
    , mpMainWindow(parent)
{
    setObjectName("MdiDocument");
}

MdiDocument::MdiDocument(const QQFileInfo &fi, MdiMainWindow *parent)
    : QObject{parent}
    , mpMainWindow(parent)
    , mFileInfo(fi)
{
    setObjectName("MdiDocument:"+mFileInfo.baseName());
    smFileInfoDocumentMap.insert(mFileInfo, this);
}

MdiDocument::~MdiDocument()
{
    smFileInfoDocumentMap.remove(mFileInfo);
}

void MdiDocument::load()
{
    Q_ASSERT(this);
    qDebug() << Q_FUNC_INFO << mFileInfo;
    if (mFileInfo.notExists()) return;                                  /* /====\ */
    QFile * pFile = new QFile(mFileInfo.filePath(), this);
    if (pFile->open(QIODevice::ReadOnly))
        mBytes = pFile->readAll();
    pFile->close();
    pFile->deleteLater();
    pFile = nullptr;
    emit fileLoad(mFileInfo, ! mBytes.isEmpty());
}

QQFileInfo MdiDocument::fileInfo(const QQFileInfo fi)
{
    mFileInfo = fi;
    emit fileInfoChanged(mFileInfo);
    return mFileInfo;
}

QMap<QQFileInfo, MdiDocument *> MdiDocument::smFileInfoDocumentMap;

#include "KeySeg.h"

#include "Key.h"
#include "Sortable.h"

KeySeg::KeySeg() {;}
KeySeg::KeySeg(const QString &qs) : mString(qs) {;}

bool KeySeg::startsWith(const KeySeg &stub) const
{
    return mString.startsWith(stub.toQString());
}

QString KeySeg::toQString() const
{
    return mString;
}

void KeySeg::clear()
{
    mString.clear();
}

/* ---------------------- static ---------------------- */

QList<KeySeg> KeySeg::split(const String segNames)
{
    const String tSimplified = segNames.simplified();
    const Key tKey = tSimplified.replaced(' ', '/');
    return tKey.list();
}

/* ---------------------- extern ---------------------- */


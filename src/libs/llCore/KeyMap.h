#pragma once
#include "llCore.h"

#include <QString>

#include "Key.h"
#include "Sortable.h"

template <typename T> class LLCORE_EXPORT KeyMap
{
public:
    KeyMap() {;}

public:
    bool contains(const Key &key) const { return mSortTMap.contains(Sortable(key)); }
    const T value(const Key &key) const { return mSortTMap.value(Sortable(key)); }

public:
    void insert(const Key &key, const T &t) { mSortTMap.insert(Sortable(key), t); }

private:
    QMap<Sortable, T> mSortTMap;
};


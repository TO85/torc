#pragma once

#include <QDir>

#include <QMetaType>

#include <String>

class QQDir : public QDir
{
public:
    QQDir(const QDir &other) : QDir(other) {;}
    QQDir(const String &pathName) : QDir(pathName) {;}
    QQDir() = default;
    ~QQDir() = default;
    QQDir(const QQDir &other) = default;
    QQDir &operator = (const QQDir &other) = default;

public:
    bool isNull() const;
    bool notNull() const { return ! isNull(); }
    String lastPath() const;

public: // static
    static QDir nullDir() { return smNullDir; }

private: // static
    static QDir smNullDir;
};

Q_DECLARE_METATYPE(QQDir);

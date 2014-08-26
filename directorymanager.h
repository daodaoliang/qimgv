#ifndef DIRECTORYMANAGER_H
#define DIRECTORYMANAGER_H

#include <QObject>
#include <QDir>
#include <QFile>
#include <QString>
#include <QSize>
#include <QDebug>
#include <QFileInfo>
#include "fileinfo.h"

class DirectoryManager : public QObject
{
    Q_OBJECT
public:
    DirectoryManager();
    fileType setFile(QString _path);
    void setCurrentDir(QString);
    void clearFileInfo();
    void next();
    void prev();
    FileInfo* getFile();
    QDir currentDir;
    QStringList fileList;
    QStringList filters;
    FileInfo *fileInfo;
    int currentPosition; // -1 = default (no file open)
signals:
    void directoryChanged(const QString &path);

};

#endif // DIRECTORYMANAGER_H
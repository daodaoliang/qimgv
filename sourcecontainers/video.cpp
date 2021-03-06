#include "video.h"
#include <time.h>

//use this one
Video::Video(QString _path) {
    path = _path;
    loaded = false;
    imageInfo = new ImageInfo(_path);
}

Video::Video(ImageInfo *_info) {
    loaded = true;
    imageInfo = _info;
    path = imageInfo->filePath();
}

Video::~Video() {
    delete imageInfo;
    delete clip;
}

void Video::load() {
    lock();
    if(!imageInfo) {
        imageInfo = new ImageInfo(path);
    }
    if(isLoaded()) {
        unlock();
        return;
    }
    clip = new Clip(path, imageInfo->extension());
    loaded = true;
    unlock();
}

void Video::save(QString destinationPath) {
    if(isLoaded()) {
        lock();
        clip->save(destinationPath);
        unlock();
    }
}

void Video::save() {
    if(isLoaded()) {
        lock();
        clip->save(path);
        unlock();
    }
}

QPixmap *Video::getPixmap() {
    qDebug() << "SOMETHING HAPPENED.";
    //TODO: find out some easy way to get frames from video source
    return NULL;
}

const QImage *Video::getImage() {
    qDebug() << "SOMETHING HAPPENED.";
    //TODO: find out some easy way to get frames from video source
    return NULL;
}

Clip *Video::getClip() {
    return clip;
}

int Video::height() {
    return isLoaded() ? clip->height() : 0;
}

int Video::width() {
    return isLoaded() ? clip->width() : 0;
}

QSize Video::size() {
    return isLoaded() ? clip->size() : QSize(0, 0);
}

void Video::rotate(int grad) {
    if (isLoaded()) {
        clip->rotate(grad);
    }
}

void Video::crop(QRect newRect) {
    if (isLoaded()) {
        clip->setFrame(newRect);
    }
}

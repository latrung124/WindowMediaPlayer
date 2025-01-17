/*
* File: MediaPlayerModel.h
* Author: trung.la
* Date: 01-17-2025
* Description: Implementation for Media Player Model
*/

#ifndef MEDIA_PLAYER_MODEL_H
#define MEDIA_PLAYER_MODEL_H

#include <QObject>

class MediaPlayerModel : public QObject
{
    Q_OBJECT

public:
    MediaPlayerModel(QObject *parent = nullptr);
    virtual ~MediaPlayerModel();

    void update();
};

#endif // MEDIA_PLAYER_MODEL_H
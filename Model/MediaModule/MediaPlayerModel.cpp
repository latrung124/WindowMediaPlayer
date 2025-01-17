/*
* File: MediaPlayerModel.cpp
* Author: trung.la
* Date: 01-17-2025
* Description: Implementation for Media Player Model
*/

#include "MediaModule/MediaPlayerModel.h"

#include <QDebug>

MediaPlayerModel::MediaPlayerModel(QObject *parent)
    : QObject(parent)
{
}

MediaPlayerModel::~MediaPlayerModel()
{
}

void MediaPlayerModel::update()
{
    // Update media player model here
    qDebug() << "Update media player model";
}
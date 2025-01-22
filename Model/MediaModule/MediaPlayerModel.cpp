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

void MediaPlayerModel::updateMediaInfo(const WindowServiceUtils::WMediaInfo &wMediaInfo)
{
    setTitle(QString::fromStdString(wMediaInfo.title));
    setArtist(QString::fromStdString(wMediaInfo.artist));
    setAlbumTitle(QString::fromStdString(wMediaInfo.albumTitle));
    setAlbumArtist(QString::fromStdString(wMediaInfo.albumArtist));
    setSubtitle(QString::fromStdString(wMediaInfo.subtitle));
    // setGenres(QString::fromStdString(wMediaInfo.genres));
    setTotalTracks(wMediaInfo.totalTracks);
    setTrackNumber(wMediaInfo.trackNumber);
}

QString MediaPlayerModel::title() const
{
    return m_title;
}

void MediaPlayerModel::setTitle(const QString &title)
{
    if (m_title != title)
    {
        m_title = title;
        emit titleChanged();
    }
}

QString MediaPlayerModel::artist() const
{
    return m_artist;
}

void MediaPlayerModel::setArtist(const QString &artist)
{
    if (m_artist != artist)
    {
        m_artist = artist;
        emit artistChanged();
    }
}

QString MediaPlayerModel::albumTitle() const
{
    return m_albumTitle;
}

void MediaPlayerModel::setAlbumTitle(const QString &albumTitle)
{
    if (m_albumTitle != albumTitle)
    {
        m_albumTitle = albumTitle;
        emit albumTitleChanged();
    }
}

QString MediaPlayerModel::albumArtist() const
{
    return m_albumArtist;
}

void MediaPlayerModel::setAlbumArtist(const QString &albumArtist)
{
    if (m_albumArtist != albumArtist)
    {
        m_albumArtist = albumArtist;
        emit albumArtistChanged();
    }
}

QString MediaPlayerModel::subtitle() const
{
    return m_subtitle;
}

void MediaPlayerModel::setSubtitle(const QString &subtitle)
{
    if (m_subtitle != subtitle)
    {
        m_subtitle = subtitle;
        emit subtitleChanged();
    }
}

QString MediaPlayerModel::genres() const
{
    return m_genres;
}

void MediaPlayerModel::setGenres(const QString &genres)
{
    if (m_genres != genres)
    {
        m_genres = genres;
        emit genresChanged();
    }
}

int MediaPlayerModel::totalTracks() const
{
    return m_totalTracks;
}

void MediaPlayerModel::setTotalTracks(int totalTracks)
{
    if (m_totalTracks != totalTracks)
    {
        m_totalTracks = totalTracks;
        emit totalTracksChanged();
    }
}

int MediaPlayerModel::trackNumber() const
{
    return m_trackNumber;
}

void MediaPlayerModel::setTrackNumber(int trackNumber)
{
    if (m_trackNumber != trackNumber)
    {
        m_trackNumber = trackNumber;
        emit trackNumberChanged();
    }
}

/*
* File: MediaPlayerModel.h
* Author: trung.la
* Date: 01-17-2025
* Description: Implementation for Media Player Model
*/

#ifndef MEDIA_PLAYER_MODEL_H
#define MEDIA_PLAYER_MODEL_H

#include "WindowMediaService/WindowServiceUtils.h"

#include <QObject>
#include <QString>
#include <QUrl>

class MediaPlayerModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString artist READ artist WRITE setArtist NOTIFY artistChanged)
    Q_PROPERTY(QString albumTitle READ albumTitle WRITE setAlbumTitle NOTIFY albumTitleChanged)
    Q_PROPERTY(QString albumArtist READ albumArtist WRITE setAlbumArtist NOTIFY albumArtistChanged)
    Q_PROPERTY(QString subtitle READ subtitle WRITE setSubtitle NOTIFY subtitleChanged)
    Q_PROPERTY(QString genres READ genres WRITE setGenres NOTIFY genresChanged)
    Q_PROPERTY(int totalTracks READ totalTracks WRITE setTotalTracks NOTIFY totalTracksChanged)
    Q_PROPERTY(int trackNumber READ trackNumber WRITE setTrackNumber NOTIFY trackNumberChanged)
    Q_PROPERTY(QUrl thumbnail READ thumbnail WRITE setThumbnail NOTIFY thumbnailChanged)
    Q_PROPERTY(bool isPlaying READ isPlaying WRITE setIsPlaying NOTIFY isPlayingChanged)
    Q_PROPERTY(bool isNextEnabled READ isNextEnabled WRITE setIsNextEnabled NOTIFY isNextEnabledChanged)
    Q_PROPERTY(bool isPreviousEnabled READ isPreviousEnabled WRITE setIsPreviousEnabled NOTIFY isPreviousEnabledChanged)
    Q_PROPERTY(bool isPauseEnabled READ isPauseEnabled WRITE setIsPauseEnabled NOTIFY isPauseEnabledChanged)
    Q_PROPERTY(bool isPlayEnabled READ isPlayEnabled WRITE setIsPlayEnabled NOTIFY isPlayEnabledChanged)
    Q_PROPERTY(bool isRepeatEnabled READ isRepeatEnabled WRITE setIsRepeatEnabled NOTIFY isRepeatEnabledChanged)
    Q_PROPERTY(bool isShuffleEnabled READ isShuffleEnabled WRITE setIsShuffleEnabled NOTIFY isShuffleEnabledChanged)

public:
    MediaPlayerModel(QObject *parent = nullptr);
    virtual ~MediaPlayerModel();

    QString title() const;
    void setTitle(const QString &title);

    QString artist() const;
    void setArtist(const QString &artist);

    QString albumTitle() const;
    void setAlbumTitle(const QString &albumTitle);

    QString albumArtist() const;
    void setAlbumArtist(const QString &albumArtist);

    QString subtitle() const;
    void setSubtitle(const QString &subtitle);
    QString genres() const;
    void setGenres(const QString &genres);

    int totalTracks() const;
    void setTotalTracks(int totalTracks);

    int trackNumber() const;
    void setTrackNumber(int trackNumber);

    QUrl thumbnail() const;
    void setThumbnail(const QUrl &thumbnail);

    bool isPlaying() const;
    void setIsPlaying(bool isPlaying);

    bool isNextEnabled() const;
    void setIsNextEnabled(bool isNextEnabled);

    bool isPreviousEnabled() const;
    void setIsPreviousEnabled(bool isPreviousEnabled);

    bool isPauseEnabled() const;
    void setIsPauseEnabled(bool isPauseEnabled);

    bool isPlayEnabled() const;
    void setIsPlayEnabled(bool isPlayEnabled);

    bool isRepeatEnabled() const;
    void setIsRepeatEnabled(bool isRepeatEnabled);

    bool isShuffleEnabled() const;
    void setIsShuffleEnabled(bool isShuffleEnabled);

    void updateMediaInfo(const WindowServiceUtils::WMediaInfo &wMediaInfo);
    void updatePlaybackInfo(const WindowServiceUtils::WPlaybackInfo &playbackInfo);

signals:
    void titleChanged();
    void artistChanged();
    void albumTitleChanged();
    void albumArtistChanged();
    void subtitleChanged();
    void genresChanged();
    void totalTracksChanged();
    void trackNumberChanged();
    void thumbnailChanged();
    void isPlayingChanged();
    void isNextEnabledChanged();
    void isPreviousEnabledChanged();
    void isPauseEnabledChanged();
    void isPlayEnabledChanged();
    void isRepeatEnabledChanged();
    void isShuffleEnabledChanged();

private:
    QString m_title;
    QString m_artist;
    QString m_albumTitle;
    QString m_albumArtist;
    QString m_subtitle;
    QString m_genres;
    int m_totalTracks = 0;
    int m_trackNumber = 0;
    QUrl m_thumbnail;
    bool m_isPlaying = false;
    bool m_isNextEnabled = false;
    bool m_isPreviousEnabled = false;
    bool m_isPauseEnabled = false;
    bool m_isPlayEnabled = false;
    bool m_isRepeatEnabled = false;
    bool m_isShuffleEnabled = false;
};

#endif // MEDIA_PLAYER_MODEL_H

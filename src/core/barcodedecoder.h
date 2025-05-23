/***************************************************************************
 barcodedecoder.h - BarcodeDecoder

 ---------------------
 begin                : 22.07.2022
 copyright            : (C) 2022 by Mathieu Pellerin
 email                : mathieu (at) opengis.ch
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef BARCODEDECODER_H
#define BARCODEDECODER_H

#include <QImage>
#include <QObject>
#include <QPointer>
#include <QThread>
#include <QVideoSink>

/**
 * \ingroup core
 */
class BarcodeDecoder : public QObject
{
    Q_OBJECT

    Q_PROPERTY( QVideoSink *videoSink READ videoSink WRITE setVideoSink NOTIFY videoSinkChanged )
    Q_PROPERTY( QString decodedString READ decodedString NOTIFY decodedStringChanged )

  public:
    explicit BarcodeDecoder( QObject *parent = nullptr );

    /**
     * Returns the last barcode decoded string.
     */
    QString decodedString() const { return mDecodedString; }

    /**
     * Clears the decoded string value and sets it to an empty string.
     */
    Q_INVOKABLE void clearDecodedString();

    /**
     * Scans a provided \a image for barcodes and if present sets the decoded string value.
     */
    void decodeImage( const QImage &image );

    QVideoSink *videoSink() const;
    void setVideoSink( QVideoSink *sink );

  public slots:
    void decodeVideoFrame( const QVideoFrame &frame );

  signals:
    void decodedStringChanged();
    void videoSinkChanged();

  private:
    QImage mImage;
    QString mDecodedString;
    QThread *mDecodingThread = nullptr;
    QPointer<QVideoSink> mVideoSink;
};

#endif // BARCODEDECODER_H

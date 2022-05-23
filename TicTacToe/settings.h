#ifndef SETTINGS_H
#define SETTINGS_H

#include <QPoint>
#include <QFont>
#include <QFontMetrics>
#include <QColor>

namespace Settings
{
const int TileSize = 100;

const QRect BoardRect = QRect(40, 110, TileSize * 3, TileSize * 3);

const QFont TileTextFont = QFont("Helvetica [Cronyx]", 10, QFont::Normal);
const QFontMetrics TileTextFontMetrics(TileTextFont);
const QColor TileTextColor = Qt::black;
}

#endif // SETTINGS_H

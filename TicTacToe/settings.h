#ifndef SETTINGS_H
#define SETTINGS_H

#include <QPoint>
#include <QFont>
#include <QFontMetrics>
#include <QColor>

namespace Settings
{
const QPoint BoardTopLeft = QPoint(0,0);

const int TileSize = 100;

const QFont TileTextFont = QFont("Helvetica [Cronyx]", 10, QFont::Normal);
const QFontMetrics TileTextFontMetrics(TileTextFont);
const QColor TileTextColor = Qt::black;
}

#endif // SETTINGS_H

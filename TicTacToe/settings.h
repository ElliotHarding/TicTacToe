#ifndef SETTINGS_H
#define SETTINGS_H

#include <QPoint>
#include <QFont>
#include <QFontMetrics>
#include <QColor>

namespace Settings
{
const int TileSize = 100;

const int BoardColRows = 3;
const int NumTiles = BoardColRows * BoardColRows;
const QRect BoardRect = QRect(40, 110, TileSize * BoardColRows, TileSize * BoardColRows);

const QFont TileTextFont = QFont("Helvetica [Cronyx]", 10, QFont::Normal);
const QFontMetrics TileTextFontMetrics(TileTextFont);
const QColor TileTextColor = Qt::black;
const QColor TileWinTextColor = Qt::red;

const QChar TileTextX = 'X';
const QChar TileTextO = 'O';
const QChar TileTextNull = ' ';

const int AiSearchDepth = 5;
}

//#define AI_TIMING_TEST

#endif // SETTINGS_H

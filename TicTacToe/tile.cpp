#include "tile.h"
#include "settings.h"

#include <QPainter>

Tile::Tile(QWidget *parent, const QString value, const QPoint& position) :
    QWidget(parent),
    m_value(value)
{
    setPosition(position);
}

void Tile::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    //Prep value text drawing
    painter.setPen(Settings::TileTextColor);
    painter.setFont(Settings::TileTextFont);
    const float textWidth = Settings::TileTextFontMetrics.horizontalAdvance(m_value);

    //Draw value text
    painter.drawText(QPoint(Settings::TileSize/2 - textWidth/2, Settings::TileSize/2 + Settings::TileTextFontMetrics.height()/4), m_value);
}

void Tile::setPosition(const QPoint& position)
{
    setGeometry(Settings::BoardRect.left() + position.x() * Settings::TileSize, Settings::BoardRect.top() + position.y() * Settings::TileSize, Settings::TileSize, Settings::TileSize);
    show();
}

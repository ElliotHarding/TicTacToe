#include "tile.h"
#include "settings.h"

#include <QPainter>

Tile::Tile(QWidget *parent, const QPoint& position) :
    QWidget(parent),
    m_value(Settings::TileTextNull),
    m_textColor(Settings::TileTextColor)
{
    setGeometry(Settings::BoardRect.left() + position.x() * Settings::TileSize, Settings::BoardRect.top() + position.y() * Settings::TileSize, Settings::TileSize, Settings::TileSize);
}

void Tile::setValue(const QChar &value)
{
    m_value = value;
    update();
}

QChar Tile::value() const
{
    return m_value;
}

bool Tile::hasValue() const
{
    return m_value != Settings::TileTextNull;
}

void Tile::reset()
{
    m_textColor = Settings::TileTextColor;
    setValue(Settings::TileTextNull);
}

void Tile::setWin()
{
    m_textColor = Settings::TileWinTextColor;
    update();
}

void Tile::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    //Prep value text drawing
    painter.setPen(m_textColor);
    painter.setFont(Settings::TileTextFont);
    const float textWidth = Settings::TileTextFontMetrics.horizontalAdvance(m_value);

    //Draw value text
    painter.drawText(QPoint(Settings::TileSize/2 - textWidth/2, Settings::TileSize/2 + Settings::TileTextFontMetrics.height()/4), m_value);
}

#ifndef TILE_H
#define TILE_H

#include <QWidget>

class Tile : public QWidget
{
    Q_OBJECT
public:
    explicit Tile(QWidget *parent, const QString value, const QPoint& position);

protected:
    void paintEvent(QPaintEvent* paintEvent) override;

private:
    QString m_value;

    void setPosition(const QPoint& position);

};

#endif // TILE_H

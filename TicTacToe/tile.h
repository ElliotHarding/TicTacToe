#ifndef TILE_H
#define TILE_H

#include <QWidget>

class Tile : public QWidget
{
    Q_OBJECT
public:
    explicit Tile(QWidget *parent, const QPoint& position);

    void setValue(const QChar& value);
    QString value() const;
    bool hasValue() const;

    void reset();

    void setWin();

protected:
    void paintEvent(QPaintEvent* paintEvent) override;

private:
    QChar m_value;
    QColor m_textColor;

};

#endif // TILE_H

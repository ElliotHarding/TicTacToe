#ifndef TILE_H
#define TILE_H

#include <QWidget>

class Tile : public QWidget
{
    Q_OBJECT
public:
    explicit Tile(QWidget *parent, const QPoint& position);

    void setValue(const QString& value);
    QString value() const;
    bool hasValue() const;

    void hide();

protected:
    void paintEvent(QPaintEvent* paintEvent) override;

private:
    QString m_value;

};

#endif // TILE_H

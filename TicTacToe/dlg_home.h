#ifndef DLG_HOME_H
#define DLG_HOME_H

#include "tile.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class DLG_Home; }
QT_END_NAMESPACE

class DLG_Home : public QMainWindow
{
    Q_OBJECT

public:
    DLG_Home(QWidget *parent = nullptr);
    ~DLG_Home();

protected:
    void mousePressEvent(QMouseEvent* mouseEvent) override;

private slots:
    void on_btn_reset_clicked();

private:
    ///UI
    Ui::DLG_Home *ui;
    QVector<QVector<Tile*>> m_tiles;

    ///Game control
    bool m_bSpawnX;
    bool m_bGameOver;
    void placeTile(const int& x, const int& y);
    void checkWinner(const int& xLast, const int& yLast);

    ///Reset/start
    void resetBoard();
    void deleteTiles();
    void createTiles();
};
#endif // DLG_HOME_H

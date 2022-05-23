#include "dlg_home.h"
#include "ui_dlg_home.h"
#include "settings.h"

#include <QMouseEvent>
#include <math.h>

DLG_Home::DLG_Home(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DLG_Home)
{
    resetBoard();
    ui->setupUi(this);
}

DLG_Home::~DLG_Home()
{
    deleteTiles();
    delete ui;
}

void DLG_Home::mousePressEvent(QMouseEvent* mouseEvent)
{
    //If mouse click in board
    if(Settings::BoardRect.contains(mouseEvent->pos()))
    {
        //Determin board x,y of mouseEvent
        const int xOffset = mouseEvent->pos().x() - Settings::BoardRect.x();
        const int yOffset = mouseEvent->pos().y() - Settings::BoardRect.y();
        const int x = floor(xOffset/100);
        const int y = floor(yOffset/100);

        //Check if tile already exists in location
        if(m_tiles[x][y] != nullptr)
        {
            return;
        }

        placeTile(x, y);
    }
}

void DLG_Home::placeTile(int x, int y)
{
    //Spawn new tile
    m_tiles[x][y] = new Tile(this, m_bSpawnX ? "X" : "O", QPoint(x,y));
    m_bSpawnX = !m_bSpawnX;
}

void DLG_Home::resetBoard()
{
    deleteTiles();

    m_tiles = QVector<QVector<Tile*>>(3, QVector<Tile*>(3, nullptr));

    m_bSpawnX = true;
}

void DLG_Home::deleteTiles()
{
    for(int x = 0; x < m_tiles.size(); x++)
    {
        for(int y = 0; y < m_tiles[x].size(); y++)
        {
            delete m_tiles[x][y];
        }
    }
}


void DLG_Home::on_btn_reset_clicked()
{
    resetBoard();
}

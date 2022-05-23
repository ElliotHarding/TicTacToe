#include "dlg_home.h"
#include "ui_dlg_home.h"
#include "settings.h"

#include <QMouseEvent>
#include <math.h>

DLG_Home::DLG_Home(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DLG_Home)
    , m_bSpawnX(true)
{
    createTiles();
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
        if(m_tiles[x][y]->hasValue())
        {
            return;
        }

        placeTile(x, y);
    }
}

void DLG_Home::placeTile(int x, int y)
{
    //Spawn new tile
    m_tiles[x][y]->setValue(m_bSpawnX ? "X" : "O");
    m_bSpawnX = !m_bSpawnX;
    checkWinner(x, y);
}

void DLG_Home::checkWinner(int xLast, int yLast)
{

}

void DLG_Home::resetBoard()
{
    m_bSpawnX = true;
    for(int x = 0; x < m_tiles.size(); x++)
    {
        for(int y = 0; y < m_tiles[x].size(); y++)
        {
            m_tiles[x][y]->setValue("");
        }
    }
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

void DLG_Home::createTiles()
{
    for(int x = 0; x < 3; x++)
    {
        m_tiles.push_back(QVector<Tile*>());
        for(int y = 0; y < 3; y++)
        {
            m_tiles[x].push_back(new Tile(this, QPoint(x,y)));
        }
    }
}


void DLG_Home::on_btn_reset_clicked()
{
    resetBoard();
}

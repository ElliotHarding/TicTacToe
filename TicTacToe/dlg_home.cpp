#include "dlg_home.h"
#include "ui_dlg_home.h"
#include "settings.h"

#include <QMouseEvent>
#include <math.h>
#include <QDebug>

DLG_Home::DLG_Home(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DLG_Home)
    , m_bSpawnX(true)
{
    ui->setupUi(this);
    createTiles();
}

DLG_Home::~DLG_Home()
{
    deleteTiles();
    delete ui;
}

void DLG_Home::mousePressEvent(QMouseEvent* mouseEvent)
{
    if(!m_bGameOver)
    {
        //If mouse click in board
        if(Settings::BoardRect.contains(mouseEvent->pos()))
        {
            //Determin board x,y of mouseEvent
            const int xOffset = mouseEvent->pos().x() - Settings::BoardRect.x();
            const int yOffset = mouseEvent->pos().y() - Settings::BoardRect.y();
            const int x = floor(xOffset/Settings::TileSize);
            const int y = floor(yOffset/Settings::TileSize);

            //Check if tile already exists in location
            if(m_tiles[x][y]->hasValue())
            {
                return;
            }

            placeTile(x, y);
        }
    }
}

void DLG_Home::placeTile(const int& x, const int& y)
{
    //Spawn new tile
    m_tiles[x][y]->setValue(m_bSpawnX ? Settings::TileTextX : Settings::TileTextO);
    m_bSpawnX = !m_bSpawnX;
    checkWinner(x, y);
}

void DLG_Home::checkWinner(const int& xLast, const int& yLast)
{
    //Check col
    if(m_tiles[xLast][0]->value() == m_tiles[xLast][1]->value() && m_tiles[xLast][0]->value() == m_tiles[xLast][2]->value())
    {
        m_tiles[xLast][0]->setWin();
        m_tiles[xLast][1]->setWin();
        m_tiles[xLast][2]->setWin();
        m_bGameOver = true;
        return;
    }

    //Check row
    if(m_tiles[0][yLast]->value() == m_tiles[1][yLast]->value() && m_tiles[0][yLast]->value() == m_tiles[2][yLast]->value())
    {
        m_tiles[0][yLast]->setWin();
        m_tiles[1][yLast]->setWin();
        m_tiles[2][yLast]->setWin();
        m_bGameOver = true;
        return;
    }

    //top left to bottom right diagonal
    if(xLast == yLast)
    {
        if(m_tiles[0][0]->value() == m_tiles[1][1]->value() && m_tiles[0][0]->value() == m_tiles[2][2]->value())
        {
            m_tiles[0][0]->setWin();
            m_tiles[1][1]->setWin();
            m_tiles[2][2]->setWin();
            m_bGameOver = true;
            return;
        }
    }

    //bottom left to top right diagonal
    if(xLast + yLast == Settings::BoardColRows-1)
    {
        if(m_tiles[0][2]->value() == m_tiles[1][1]->value() && m_tiles[2][0]->value() == m_tiles[1][1]->value())
        {
            m_tiles[0][2]->setWin();
            m_tiles[1][1]->setWin();
            m_tiles[2][0]->setWin();
            m_bGameOver = true;
            return;
        }
    }
}

void DLG_Home::resetBoard()
{
    m_bSpawnX = true;
    m_bGameOver = false;
    for(int x = 0; x < m_tiles.size(); x++)
    {
        for(int y = 0; y < m_tiles[x].size(); y++)
        {
            m_tiles[x][y]->reset();
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
    for(int x = 0; x < Settings::BoardColRows; x++)
    {
        m_tiles.push_back(QVector<Tile*>());
        for(int y = 0; y < Settings::BoardColRows; y++)
        {
            m_tiles[x].push_back(new Tile(this, QPoint(x,y)));
        }
    }
}


void DLG_Home::on_btn_reset_clicked()
{
    resetBoard();
}

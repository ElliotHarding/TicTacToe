#include "dlg_home.h"
#include "ui_dlg_home.h"

DLG_Home::DLG_Home(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DLG_Home)
{
    ui->setupUi(this);

    m_tiles = QVector<QVector<Tile*>>(3, QVector<Tile*>(3, nullptr));
    m_tiles[0][0] = new Tile(this, "X", QPoint(0,0));
}

DLG_Home::~DLG_Home()
{
    delete ui;
}


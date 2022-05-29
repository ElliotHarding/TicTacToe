#include "ai.h"
#include "settings.h"

#include <QDebug>

bool checkWinner(const QVector<QVector<QChar>>& board, const int& xLast, const int& yLast)
{
    //Check col
    if(board[xLast][0] == board[xLast][1] && board[xLast][0] == board[xLast][2])
    {
        return true;
    }

    //Check row
    if(board[0][yLast] == board[1][yLast] && board[0][yLast] == board[2][yLast])
    {
        return true;
    }

    //top left to bottom right diagonal
    if(xLast == yLast)
    {
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
        {
            return true;
        }
    }

    //bottom left to top right diagonal
    if(xLast + yLast == Settings::BoardColRows-1)
    {
        if(board[0][2] == board[1][1] && board[2][0] == board[1][1])
        {
            return true;
        }
    }

    return false;
}

void gameStateScore(const QVector<QVector<QChar>>& board, int& score, const int& depth, const QChar& aiLetter, const QChar& playerLetter, const QChar& turnLetter)
{
    for(int x = 0; x < Settings::BoardColRows; x++)
    {
        for(int y = 0; y < Settings::BoardColRows; y++)
        {
            if(board[x][y] == Settings::TileTextNull)
            {
                QVector<QVector<QChar>> moveBoard = board;
                moveBoard[x][y] = turnLetter;

                if(checkWinner(moveBoard, x, y))
                {
                    score += (turnLetter == aiLetter ? 1 : -1) * depth * depth;
                    continue;
                }

                if(depth == 1)
                    continue;

                gameStateScore(moveBoard, score, depth-1, aiLetter, playerLetter, turnLetter == aiLetter ? playerLetter : aiLetter);
            }
        }
    }
}

AI::AI()
{
}

QPoint AI::getBestMove(const QVector<QVector<QChar>>& board, const QChar& aiLetter, const QChar& playerLetter)
{
    QPoint bestMove;
    int highScore = -999999;
    QVector<QVector<QChar>> moveBoardMem = board;

    for(int x = 0; x < Settings::BoardColRows; x++)
    {
        for(int y = 0; y < Settings::BoardColRows; y++)
        {
            if(board[x][y] == Settings::TileTextNull)
            {
                moveBoardMem = board;
                moveBoardMem[x][y] = aiLetter;

                int score = 0;
                if(checkWinner(moveBoardMem, x, y))
                {
                    score = Settings::AiSearchDepth * Settings::AiSearchDepth;
                }
                else
                {
                    gameStateScore(moveBoardMem, score, Settings::AiSearchDepth, aiLetter, playerLetter, playerLetter);
                }

                if(score > highScore)
                {
                    highScore = score;
                    bestMove = QPoint(x,y);
                }
            }
        }
    }

    return bestMove;
}

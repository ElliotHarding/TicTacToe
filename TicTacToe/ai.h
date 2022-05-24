#ifndef AI_H
#define AI_H

#include <QPoint>
#include <QChar>

class AI
{
public:
    AI();

    QPoint getBestMove(const QVector<QVector<QChar>>& board, const QChar& aiLetter, const QChar& playerLetter);
};

#endif // AI_H

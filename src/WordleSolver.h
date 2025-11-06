#ifndef WORDLESOLVER_H
#define WORDLESOLVER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QSet>
#include <QMap>
#include <QList>

class WordleSolver : public QObject
{
    Q_OBJECT

public:
    explicit WordleSolver(QObject *parent = nullptr);
    
    void addGuess(const QString &guess, const QString &feedback);
    QStringList getSuggestions() const;
    void reset();

private:
    void initializeWordList();
    bool matchesCriteria(const QString &word) const;
    
    struct GuessInfo {
        QString word;
        QString feedback;
    };
    
    QStringList wordList;
    QList<GuessInfo> guesses;
    QSet<QChar> correctLetters;      // Letters that are in the word
    QSet<QChar> incorrectLetters;    // Letters that are not in the word
    QMap<int, QChar> correctPositions; // Position -> correct letter
    QMap<QChar, QSet<int>> wrongPositions; // Letter -> positions where it can't be
};

#endif // WORDLESOLVER_H

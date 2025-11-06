#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include "WordleSolver.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSolveClicked();

private:
    void setupUi();
    
    QLineEdit *guessInput;
    QLineEdit *feedbackInput;
    QPushButton *solveButton;
    QPushButton *resetButton;
    QTextEdit *suggestionsDisplay;
    
    WordleSolver *solver;
};

#endif // MAINWINDOW_H

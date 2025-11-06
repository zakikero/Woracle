#include "MainWindow.h"
#include <QLabel>
#include <QMessageBox>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , solver(new WordleSolver(this))
{
    setupUi();
    setWindowTitle("Woracle - Wordle Solver");
    resize(500, 400);
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUi()
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    
    // Title
    QLabel *titleLabel = new QLabel("Woracle - Wordle Solver", this);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(titleLabel);
    
    // Instructions
    QLabel *instructionsLabel = new QLabel(
        "Enter your guess and feedback to get word suggestions.\n"
        "Feedback format: 'g' = green (correct), 'y' = yellow (wrong position), 'b' = black (not in word)",
        this
    );
    instructionsLabel->setWordWrap(true);
    layout->addWidget(instructionsLabel);
    
    // Guess input
    QLabel *guessLabel = new QLabel("Your Guess:", this);
    layout->addWidget(guessLabel);
    guessInput = new QLineEdit(this);
    guessInput->setPlaceholderText("Enter 5-letter word (e.g., CRANE)");
    guessInput->setMaxLength(5);
    layout->addWidget(guessInput);
    
    // Feedback input
    QLabel *feedbackLabel = new QLabel("Feedback:", this);
    layout->addWidget(feedbackLabel);
    feedbackInput = new QLineEdit(this);
    feedbackInput->setPlaceholderText("Enter feedback (e.g., bbygg)");
    feedbackInput->setMaxLength(5);
    layout->addWidget(feedbackInput);
    
    // Buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    solveButton = new QPushButton("Get Suggestions", this);
    resetButton = new QPushButton("Reset", this);
    buttonLayout->addWidget(solveButton);
    buttonLayout->addWidget(resetButton);
    layout->addLayout(buttonLayout);
    
    // Suggestions display
    QLabel *suggestionsLabel = new QLabel("Suggestions:", this);
    layout->addWidget(suggestionsLabel);
    suggestionsDisplay = new QTextEdit(this);
    suggestionsDisplay->setReadOnly(true);
    layout->addWidget(suggestionsDisplay);
    
    setCentralWidget(centralWidget);
    
    // Connect signals
    connect(solveButton, &QPushButton::clicked, this, &MainWindow::onSolveClicked);
    connect(resetButton, &QPushButton::clicked, [this]() {
        guessInput->clear();
        feedbackInput->clear();
        suggestionsDisplay->clear();
        solver->reset();
    });
}

void MainWindow::onSolveClicked()
{
    QString guess = guessInput->text().toUpper();
    QString feedback = feedbackInput->text().toLower();
    
    // Validate input
    if (guess.length() != 5) {
        QMessageBox::warning(this, "Invalid Input", "Guess must be exactly 5 letters.");
        return;
    }
    
    if (feedback.length() != 5) {
        QMessageBox::warning(this, "Invalid Input", "Feedback must be exactly 5 characters.");
        return;
    }
    
    // Check feedback format
    for (QChar c : feedback) {
        if (c != 'g' && c != 'y' && c != 'b') {
            QMessageBox::warning(this, "Invalid Input", "Feedback must only contain 'g', 'y', or 'b'.");
            return;
        }
    }
    
    // Add guess to solver and get suggestions
    solver->addGuess(guess, feedback);
    QStringList suggestions = solver->getSuggestions();
    
    // Display suggestions
    if (suggestions.isEmpty()) {
        suggestionsDisplay->setPlainText("No suggestions available. Try resetting and starting over.");
    } else {
        QString displayText = "Suggested words:\n\n";
        for (int i = 0; i < qMin(10, suggestions.size()); ++i) {
            displayText += suggestions[i] + "\n";
        }
        if (suggestions.size() > 10) {
            displayText += QString("\n... and %1 more words").arg(suggestions.size() - 10);
        }
        suggestionsDisplay->setPlainText(displayText);
    }
}

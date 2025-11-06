#include "WordleSolver.h"

WordleSolver::WordleSolver(QObject *parent)
    : QObject(parent)
{
    initializeWordList();
}

void WordleSolver::initializeWordList()
{
    // Basic word list for demonstration
    // In a real application, this would be loaded from a file
    wordList = QStringList({
        "ABOUT", "ABOVE", "ABUSE", "ACTOR", "ACUTE", "ADMIT", "ADOPT", "ADULT", "AFTER", "AGAIN",
        "AGENT", "AGREE", "AHEAD", "ALARM", "ALBUM", "ALERT", "ALIGN", "ALIKE", "ALIVE", "ALLOW",
        "ALONE", "ALONG", "ALTER", "ANGEL", "ANGER", "ANGLE", "ANGRY", "APART", "APPLE", "APPLY",
        "ARENA", "ARGUE", "ARISE", "ARRAY", "ASIDE", "ASSET", "AUDIO", "AUDIT", "AVOID", "AWAKE",
        "AWARD", "AWARE", "BADLY", "BAKER", "BASES", "BASIC", "BASIS", "BEACH", "BEGAN", "BEGIN",
        "BEING", "BELOW", "BENCH", "BILLY", "BIRTH", "BLACK", "BLADE", "BLAME", "BLANK", "BLAST",
        "BLEED", "BLESS", "BLIND", "BLOCK", "BLOOD", "BLOOM", "BLUES", "BOARD", "BOOST", "BOOTH",
        "BOUND", "BRAIN", "BRAND", "BRASS", "BRAVE", "BREAD", "BREAK", "BREED", "BRIEF", "BRING",
        "BROAD", "BROKE", "BROWN", "BUILD", "BUILT", "BUYER", "CABLE", "CALIF", "CARRY", "CATCH",
        "CAUSE", "CHAIN", "CHAIR", "CHART", "CHASE", "CHEAP", "CHECK", "CHEST", "CHIEF", "CHILD",
        "CHINA", "CHOSE", "CIVIC", "CIVIL", "CLAIM", "CLASS", "CLEAN", "CLEAR", "CLICK", "CLOCK",
        "CLOSE", "COACH", "COAST", "COULD", "COUNT", "COURT", "COVER", "CRACK", "CRAFT", "CRANE",
        "CRASH", "CRAZY", "CREAM", "CRIME", "CROSS", "CROWD", "CROWN", "CRUDE", "CURVE", "CYCLE",
        "DAILY", "DANCE", "DATED", "DEALT", "DEATH", "DEBUT", "DELAY", "DELTA", "DENSE", "DEPTH",
        "DOING", "DOUBT", "DOZEN", "DRAFT", "DRAMA", "DRANK", "DRAWN", "DREAM", "DRESS", "DRILL",
        "DRINK", "DRIVE", "DROVE", "DYING", "EAGER", "EARLY", "EARTH", "EIGHT", "ELECT", "EMPTY",
        "ENEMY", "ENJOY", "ENTER", "ENTRY", "EQUAL", "ERROR", "EVENT", "EVERY", "EXACT", "EXIST",
        "EXTRA", "FAITH", "FALSE", "FAULT", "FIBER", "FIELD", "FIFTH", "FIFTY", "FIGHT", "FINAL",
        "FIRST", "FIXED", "FLASH", "FLEET", "FLESH", "FLOAT", "FLOOD", "FLOOR", "FOCUS", "FORCE",
        "FORTH", "FORTY", "FORUM", "FOUND", "FRAME", "FRANK", "FRAUD", "FRESH", "FRONT", "FRUIT",
        "FULLY", "FUNNY", "GIANT", "GIVEN", "GLASS", "GLOBE", "GLORY", "GRACE", "GRADE", "GRAND",
        "GRANT", "GRASS", "GRAVE", "GREAT", "GREEN", "GROSS", "GROUP", "GROWN", "GUARD", "GUESS",
        "GUEST", "GUIDE", "HAPPY", "HARRY", "HEART", "HEAVY", "HENCE", "HENRY", "HORSE", "HOTEL",
        "HOUSE", "HUMAN", "IDEAL", "IMAGE", "INDEX", "INNER", "INPUT", "ISSUE", "JAPAN", "JIMMY",
        "JOINT", "JONES", "JUDGE", "KNOWN", "LABEL", "LARGE", "LASER", "LATER", "LAUGH", "LAYER",
        "LEARN", "LEASE", "LEAST", "LEAVE", "LEGAL", "LEMON", "LEVEL", "LEWIS", "LIGHT", "LIMIT",
        "LINKS", "LIVES", "LOCAL", "LOGIC", "LOOSE", "LOWER", "LUCKY", "LUNCH", "LYING", "MAGIC",
        "MAJOR", "MAKER", "MARCH", "MARIA", "MATCH", "MAYBE", "MAYOR", "MEANT", "MEDIA", "METAL",
        "MIGHT", "MINOR", "MINUS", "MIXED", "MODEL", "MONEY", "MONTH", "MORAL", "MOTOR", "MOUNT",
        "MOUSE", "MOUTH", "MOVED", "MOVIE", "MUSIC", "NEEDS", "NEVER", "NEWLY", "NIGHT", "NOISE",
        "NORTH", "NOTED", "NOVEL", "NURSE", "OCCUR", "OCEAN", "OFFER", "OFTEN", "ORDER", "OTHER",
        "OUGHT", "PAINT", "PANEL", "PAPER", "PARTY", "PEACE", "PETER", "PHASE", "PHONE", "PHOTO",
        "PIECE", "PILOT", "PITCH", "PLACE", "PLAIN", "PLANE", "PLANT", "PLATE", "POINT", "POUND",
        "POWER", "PRESS", "PRICE", "PRIDE", "PRIME", "PRINT", "PRIOR", "PRIZE", "PROOF", "PROUD",
        "PROVE", "QUEEN", "QUICK", "QUIET", "QUITE", "RADIO", "RAISE", "RANGE", "RAPID", "RATIO",
        "REACH", "READY", "REFER", "RIGHT", "RIVAL", "RIVER", "ROBIN", "ROCKY", "ROGER", "ROMAN",
        "ROUGH", "ROUND", "ROUTE", "ROYAL", "RURAL", "SCALE", "SCENE", "SCOPE", "SCORE", "SENSE",
        "SERVE", "SEVEN", "SHALL", "SHAPE", "SHARE", "SHARP", "SHEET", "SHELF", "SHELL", "SHIFT",
        "SHINE", "SHIRT", "SHOCK", "SHOOT", "SHORT", "SHOWN", "SIGHT", "SINCE", "SIXTH", "SIXTY",
        "SIZED", "SKILL", "SLEEP", "SLIDE", "SMALL", "SMART", "SMILE", "SMITH", "SMOKE", "SOLID",
        "SOLVE", "SORRY", "SOUND", "SOUTH", "SPACE", "SPARE", "SPEAK", "SPEED", "SPEND", "SPENT",
        "SPLIT", "SPOKE", "SPORT", "STAFF", "STAGE", "STAKE", "STAND", "START", "STATE", "STEAM",
        "STEEL", "STICK", "STILL", "STOCK", "STONE", "STOOD", "STORE", "STORM", "STORY", "STRIP",
        "STUCK", "STUDY", "STUFF", "STYLE", "SUGAR", "SUITE", "SUPER", "SWEET", "TABLE", "TAKEN",
        "TASTE", "TAXES", "TEACH", "TEXAS", "THANK", "THEFT", "THEIR", "THEME", "THERE", "THESE",
        "THICK", "THING", "THINK", "THIRD", "THOSE", "THREE", "THREW", "THROW", "TIGHT", "TIMES",
        "TITLE", "TODAY", "TOPIC", "TOTAL", "TOUCH", "TOUGH", "TOWER", "TRACK", "TRADE", "TRAIN",
        "TREAT", "TREND", "TRIAL", "TRIBE", "TRICK", "TRIED", "TROOP", "TRUCK", "TRULY", "TRUST",
        "TRUTH", "TWICE", "UNDER", "UNDUE", "UNION", "UNITY", "UNTIL", "UPPER", "UPSET", "URBAN",
        "USAGE", "USUAL", "VALID", "VALUE", "VIDEO", "VIRUS", "VISIT", "VITAL", "VOCAL", "VOICE",
        "WASTE", "WATCH", "WATER", "WHEEL", "WHERE", "WHICH", "WHILE", "WHITE", "WHOLE", "WHOSE",
        "WOMAN", "WOMEN", "WORLD", "WORRY", "WORSE", "WORST", "WORTH", "WOULD", "WOUND", "WRITE",
        "WRONG", "WROTE", "YIELD", "YOUNG", "YOUTH"
    });
}

void WordleSolver::addGuess(const QString &guess, const QString &feedback)
{
    GuessInfo info;
    info.word = guess;
    info.feedback = feedback;
    guesses.append(info);
    
    // Process feedback
    for (int i = 0; i < 5; ++i) {
        QChar letter = guess[i];
        QChar fb = feedback[i];
        
        if (fb == 'g') {
            // Green: correct letter in correct position
            correctPositions[i] = letter;
            correctLetters.insert(letter);
        } else if (fb == 'y') {
            // Yellow: correct letter in wrong position
            correctLetters.insert(letter);
            wrongPositions[letter].insert(i);
        } else if (fb == 'b') {
            // Black: letter not in word (unless we know it's elsewhere)
            if (!correctLetters.contains(letter)) {
                incorrectLetters.insert(letter);
            }
        }
    }
}

QStringList WordleSolver::getSuggestions() const
{
    QStringList suggestions;
    
    for (const QString &word : wordList) {
        if (matchesCriteria(word)) {
            suggestions.append(word);
        }
    }
    
    return suggestions;
}

bool WordleSolver::matchesCriteria(const QString &word) const
{
    // Check incorrect letters
    for (QChar c : incorrectLetters) {
        if (word.contains(c)) {
            return false;
        }
    }
    
    // Check correct positions
    for (auto it = correctPositions.constBegin(); it != correctPositions.constEnd(); ++it) {
        if (word[it.key()] != it.value()) {
            return false;
        }
    }
    
    // Check that all correct letters are present
    for (QChar c : correctLetters) {
        if (!word.contains(c)) {
            return false;
        }
    }
    
    // Check wrong positions
    for (auto it = wrongPositions.constBegin(); it != wrongPositions.constEnd(); ++it) {
        QChar letter = it.key();
        const QSet<int> &positions = it.value();
        
        for (int pos : positions) {
            if (word[pos] == letter) {
                return false;
            }
        }
    }
    
    return true;
}

void WordleSolver::reset()
{
    guesses.clear();
    correctLetters.clear();
    incorrectLetters.clear();
    correctPositions.clear();
    wrongPositions.clear();
}

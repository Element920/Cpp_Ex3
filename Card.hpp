#ifndef CARD_H
#define CARD_H

#include <string>

// Base class for development cards
class Card {
protected:
    std::string cardType;

public:
    Card(const std::string& type);
    virtual ~Card();

    virtual void useCard() = 0;
    std::string getCardType() const;
};

// Specific development card classes

class ProgressCard : public Card {
public:
    ProgressCard(const std::string& type);
    virtual void useCard() override;
};

class KnightCard : public Card {
public:
    KnightCard(const std::string& type);
    virtual void useCard() override;
};

class VictoryPointCard : public Card {
public:
    VictoryPointCard(const std::string& type);
    virtual void useCard() override;
};

#endif // CARD_H

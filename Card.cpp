#include <string>

class Card {
public:
    virtual std::string getType() const = 0;
};

class VictoryPointCard : public Card {
public:
    std::string getType() const override {
        return "Victory Point";
    }
};

class KnightCard : public Card {
public:
    std::string getType() const override {
        return "Knight";
    }
};

class MonopolyCard : public Card {
public:
    std::string getType() const override {
        return "Monopoly";
    }
};

class RoadBuildingCard : public Card {
public:
    std::string getType() const override {
        return "Road Building";
    }
};

class YearOfPlentyCard : public Card {
public:
    std::string getType() const override {
        return "Year of Plenty";
    }
};

#pragma once
#include "Deck.h"
#include <vector>
#include <iostream>
#include <memory>
class Player
{
public:
	Player(bool human = false):
	human(human)
	{

	}

	void TakeCard(std::unique_ptr<Deck::Card> card) {

		hand.push_back(std::move(card));

	}

	void PrintHand() {
		
		for (int i = 0; i < hand.size(); i ++) {
		std::cout << hand[i]->GetName() << std::endl;
		}
	}
	void PrintHandSize() {
		std::cout << hand.size();
	}
private:
	bool human;
	std::vector<std::shared_ptr<Deck::Card>> hand;
};


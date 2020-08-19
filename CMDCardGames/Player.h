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
			hand[i]->PrintName();
		}
	}
	void PrintHandSize() {
		std::cout << hand.size();
	}
	void CheckForPairs() {
		
		for (int i = 0; i < hand.size();) {
			int count = 0;
			std::vector<int> indexs;
			for (int j = 0; j < hand.size(); j++) {
				if (hand[i]->GetValue() == hand[j]->GetValue()) {
					count++;
					indexs.push_back(j);
				}
			}
			if (count == 4) {
				for (int j = indexs.size()-1; j >= 0; j--) {
					hand.erase(hand.begin() + indexs[j]);
					
				}
				matches++;
			}
			else {
				i++;
			}
		}
	}
	int GetMatches() {
		return matches;
	}
private:
	int matches = 0;
	bool human;
	std::vector<std::unique_ptr<Deck::Card>> hand;
};


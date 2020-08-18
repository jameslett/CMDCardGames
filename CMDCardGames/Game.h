#pragma once
#include "Player.h"
#include "Deck.h"
#include <vector>
class Game
{

public:
	Game(int numPlayer, int numCards, int numDecks = 1 )
		:deck(Deck(numDecks))
	
	{
		AddPlayers(numPlayer);
		std::cout << "There are " << numPlayer << " players" << std::endl;
		Deal(numCards);
		std::cout << "Dealing " << numCards << " cards" << std::endl;

	}

	void AddPlayers(int numPlayers) {
		for (int i = 0; i < numPlayers; i++) {
			if (i == 0) {
				players.push_back(std::make_shared<Player>(true));
			}
			else {
				players.push_back(std::make_shared<Player>());
			}
		}
	}
	Deck& GetDeck() {
		return deck;
	}
	void shuffle() {
		deck.Shuffle();
	}
	void DealCard(std::shared_ptr<Player> player) {
		player->TakeCard(deck.Draw());
	}
	void Deal(int numCards) {
		for (auto p : players) {
			for (int i = 0; i < numCards; i++) {
				DealCard(p);
			}
		}
	}

private:
	Deck deck;
	std::vector<std::shared_ptr<Player>> players;
};


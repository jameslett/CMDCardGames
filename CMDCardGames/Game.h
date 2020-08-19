#pragma once
#include "Player.h"
#include "Deck.h"
#include <vector>
class Game
{

public:
	Game(int numPlayer, int numCards, int numDecks = 1)
		:deck(Deck(numDecks)),
		numCards(numCards),
		numPlayer(numPlayer)
	
	{
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

	void Go() {
		AddPlayers(numPlayer);
		std::cout << "There are " << numPlayer << " players" << std::endl;
		deck.Shuffle();
		Deal(numCards);
		std::cout << "Dealing " << numCards << " cards" << std::endl;
		players[0]->CheckForPairs();
		players[0]->PrintHand();
		std::cout << players[0]->GetMatches();

	}

private:
	int numPlayer;
	int numCards;
	int SelectedPlayer = 0;
	Deck deck;
	std::vector<std::shared_ptr<Player>> players;
};


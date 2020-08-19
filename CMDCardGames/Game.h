#pragma once
#include "Player.h"
#include "Deck.h"
#include <vector>
#include <Windows.h>
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
				players.push_back(std::make_shared<Player>(i,true));
			}
			else {
				players.push_back(std::make_shared<Player>(i,false));
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
		while (playing) {
			do {
				std::cout << "Player " << selectedPlayer << "s turn" << std::endl;
				if (players[selectedPlayer]->isHuman()) {
					players[selectedPlayer]->PrintHand();



					do {
						std::cout << "Which player would you like to ask for a card" << std::endl;
						std::cin >> playerNum;
						playerInvalid = playerNum < 1 || playerNum >= players.size();
						if (playerInvalid) {
							std::cout << "Please select a valid player number." << std::endl;
							if (playerNum == 0) {
								std::cout << "You're player 0." << std::endl;
							}
						}
					} while (playerInvalid);
					do {
						std::cout << "Which card would you like to ask for?" << std::endl;
						std::cin >> cardIndex;
						cardInvalid = cardIndex < 0 || cardIndex >= players[selectedPlayer]->GetHandSize();
						if (cardInvalid) {
							std::cout << "Please select a valid card number" << std::endl;
						}
					} while (cardInvalid);
					
				}	
				else {
								
					cardIndex = players[selectedPlayer]->SelectRandomCard();
					playerNum = players[selectedPlayer]->SelectRandomPlayer(numPlayer);
				}
				
				std::cout << "Player  " << players[playerNum]->GetPlayerNum() << " do you have any " << players[selectedPlayer]->CardName(cardIndex) << "'s" << std::endl;
				stillTurn = players[selectedPlayer]->AskForCard(cardIndex, players[playerNum]);
				players[selectedPlayer]->CheckForPairs();
				
				if (players[selectedPlayer]->GetHandSize() <= 0) {
					playing = false;
					}
			} while (stillTurn);
			players[selectedPlayer]->TakeCard(deck.Draw());
			players[selectedPlayer]->CheckForPairs();
			if (selectedPlayer < players.size()-1) {
				selectedPlayer++;
			}
			else {
				selectedPlayer = 0;
			}

		}
	}
	void PrintPlayerNumbers() {
		for (auto p : players) {
			std::cout << "Player number " << p->GetPlayerNum() << "." << std::endl;
		}
	}

private:
	bool stillTurn = true;
	bool playing = true;
	int playerNum;
	int cardIndex;
	int selectedPlayer = 0;
	bool playerInvalid = false;
	bool cardInvalid = false;
	int numPlayer;
	int numCards;

	Deck deck;
	std::vector<std::shared_ptr<Player>> players;
};


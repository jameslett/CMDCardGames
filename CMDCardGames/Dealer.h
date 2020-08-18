#pragma once
#include"Deck.h"
#include "Player.h"
#include <memory>
#include <vector>

class Dealer
{ public:
	Dealer(std::vector<std::shared_ptr<Player>> players_in, int decks= 1) 
		:
		d(Deck(decks))
	{
		for (int i = 0; i < players_in.size(); i++){
			players.push_back(players_in[i]);
		}
		
	}

	void Deal(int numCards) {
		for (auto n : players) {
			for (int i = 0; i < numCards; i++) {
				n->Draw(d.Draw());
			}
		}

	}
	std::shared_ptr<Player> GetPlayer(int playerNum) {
		
		std::shared_ptr<Player> p = players[playerNum];

		return p;

		
		
	}
	Deck deck() {
		return d;
	}
	void printDeck(){
		d.PrintDeck();
	}
	void Shuffle() {

		d.shuffle();
	}
private:
	Deck d;
	std::vector<std::shared_ptr<Player>> players;
	

};


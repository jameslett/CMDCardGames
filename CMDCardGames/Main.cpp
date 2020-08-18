// CMDCardGames.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Main.h"
int main()
{
	AddPlayers(4);
	Dealer dealer(players);
	dealer.Shuffle();
	dealer.printDeck();
	dealer.Deal(7);
	std::cout << "Player 1" << std::endl;
	dealer.GetPlayer(1)->PrintHand();

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

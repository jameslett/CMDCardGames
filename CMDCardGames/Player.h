#pragma once
#include "Deck.h"
#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
#include <random>
#include <ctime>
class Player
{
public:
	Player(int playerNum,bool human = false) :
		human(human),
		playerNum(playerNum)
	{

	}

	void TakeCard(std::unique_ptr<Deck::Card> card) {

		hand.push_back(std::move(card));

	}


	void PrintHand() {
		if (hand.size() > 0) {
			for (int i = 0; i < hand.size(); i++) {
				std::cout << i << " ";
				hand[i]->PrintName();
			}
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
				for (int j = indexs.size() - 1; j >= 0; j--) {
					hand.erase(hand.begin() + indexs[j]);

				}
				matches++;
			}
			else {
				i++;
			}
		}
	}
	bool AskForCard(int index,std::shared_ptr<Player> player) {


		int count = 0;
		std::vector<int> indexs;
		
		for (int j = 0; j < player->hand.size(); j++) {
			if (hand[index]->GetValue() == player->hand[j]->GetValue()) {
				count++;
				indexs.push_back(j);
				
			}
			
		}
		if (count > 0) {
			for (int j = indexs.size() - 1; j >= 0; j--) {
				
				hand.push_back(std::move(player->hand[indexs[j]]));
				player->hand.erase(player->hand.begin() + indexs[j]);
				

			}
			std::cout << "Player " << player->playerNum << " has " << count << " " << hand[index]->GetValueStr() << "('s)." << std::endl;
			return true;
		}
		else {
			std::cout << "Go Fish" << std::endl;
			return false;
		}
		
		
		
	
	}



	int GetMatches() {
		return matches;

	}
	int GetHandSize() {
		return hand.size();
	}
	int GetPlayerNum() {
		return playerNum;
	}
	std::string CardName(int index) {
		return hand[index]->GetValueStr();

	}
	bool isHuman() {
		return human;
	}
	int SelectRandomCard() {
		srand((unsigned)time(0));
		int randomNumber = rand()% hand.size();
		return randomNumber;
	}
	int SelectRandomPlayer(int numPlayers) {
		int randomNumber;
		srand((unsigned)time(0));
		do {
			randomNumber = rand() % numPlayers;
		} while (randomNumber == playerNum);
		return randomNumber;
	}
private:
	int playerNum;
	int matches = 0;
	bool human;
	std::vector<std::unique_ptr<Deck::Card>> hand;
};


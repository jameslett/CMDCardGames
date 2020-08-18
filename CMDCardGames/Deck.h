#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
class Deck
{	public:

	class Card{
	public:
		enum class Suit
		{
			Hearts,
			Clubs,
			Diamonds,
			Spades

		};
		enum class Value {
			Ace,Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King
		};
		Card(int in_id)
			:
		id(in_id)
		{
			switch (id / 13) {
			case 0:

				suit = Suit::Hearts;
				break;
			case 1:

				suit = Suit::Clubs;
				break;
			case 2:

				suit = Suit::Spades;
				break;
			case 3:

				suit = Suit::Diamonds;
				break;
			
				
			}
			switch (id % 13) {
			case 1:

				value = Value::Two;
				break;
			case 2:

				value = Value::Three;
				break;
			case 3:

				value = Value::Four;
				break;
			case 4:

				value = Value::Five;
				break;
			case 5:

				value = Value::Six;
				break;
			case 6:

				value = Value::Seven;
				break;
			case 7:

				value = Value::Eight;
				break;
			case 8:

				value = Value::Nine;
				break;
			case 9:

				value = Value::Ten;
				break;
			case 10:

				value = Value::Jack;
				break;
			case 11:

				value = Value::Queen;
				break;
			case 12:

				value = Value::King;
				break;
			case 0:

				value = Value::Ace;
				break;
			}
		}

		Card(const Card& old) {
			value = old.value;
			id = old.id;
			suit = old.suit;
		}
		Card& operator=(const Card& other)
		{
			
			return *this;
		}



		Suit GetSuit() {
			return suit;
	}
		Value GetValue() {
			return value;
		}
		std::string GetName() {
			std::string suitstr = suits[int(suit)];
			std::string valuestr = values[int(value)];
			std::string out = valuestr + " of " + suitstr;
			return out;
		}

	
	
	private:
		std::string suits[4] = {
			"Hearts",
			"Clubs",
			"Diamonds",
			"Spades" };

		std::string values[13] = {
			 "Ace","Two", "Three", "Four", "Five", "Six", "Seven","Eight", "Nine", "Ten", "Jack", "Queen", "King"
		};
		Suit suit;
		Value value;
		int id;
	};

	public:
		Deck(int numDecks = 1) {
			for (int i = 0; i < 52 * numDecks; i++) {
		
				cards.push_back(std::make_shared<Card>(i * numDecks));
			}
		}
		std::shared_ptr<Card> Draw() {
			int index = cards.size() - 1;
			std::shared_ptr<Card> c = cards[index];
			cards.pop_back();

		 return c;
		

			
			

			
		}
		int CardsRemaining() {
			return cards.size();
		}
		void PrintDeck() {
			for (auto n : cards) {
				std::cout << n->GetName() << std::endl;
			}
		}
		void shuffle() {
			std::srand(std::time(0));
			std::random_shuffle(cards.begin(), cards.end());
		}
	private:
	std::vector<std::shared_ptr<Card>> cards;

};

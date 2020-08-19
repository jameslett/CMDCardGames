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




	

		Card(Card&& other) noexcept // move constructor
			:suit(other.suit),
			value(other.value),
			id(other.id)
		{
			}



		Card& operator=(Card&& other) noexcept // move assignment
		{
			if (&other!= this)
			{
				suit = other.suit;
				value = other.value;
				id = other.id;

				
			}
			return *this;
		}


		Card(const Card& other) // copy constructor
			: suit(other.suit),
			value(other.value),
			id(other.id)
		{}

		Card& operator=(const Card& other) // copy assignment
		{
			return *this = Card(other);
		}

		Suit GetSuit() {
			return suit;
	}
		Value GetValue() {
			return value;
		}

	
	
	




		std::vector<std::string> suits  {
			"Hearts",
			"Clubs",
			"Diamonds",
			"Spades" };

		std::vector<std::string> values {
			 "Ace","Two", "Three", "Four", "Five", "Six", "Seven","Eight", "Nine", "Ten", "Jack", "Queen", "King"
		};
		Suit suit;
		Value value;
		int id;


		public:
			void PrintName() {

				std::string out = values[int(value)] + " of " + suits[int(suit)];
				std::cout << out << std::endl;
			}


	};

	public:
	Deck(int numDecks = 1) {
			for (int i = 0; i < 52 * numDecks; i++) {
		
				cards.push_back(std::make_unique<Card>(i * numDecks));
			}
	}
		std::unique_ptr<Card> Draw() {

			std::unique_ptr<Card> c = std::move(cards[0]);
			cards.erase(cards.begin());
			return std::move(c);
		

			
			

			
		}
		int CardsRemaining() {
			return cards.size();
		}
		void PrintDeck() {
			for (auto& c : cards) {
				c->PrintName();

			}
		}
		void Shuffle() {
			std::srand(std::time(0));
			std::random_shuffle(cards.begin(), cards.end());
		}


	private:

		

	std::vector<std::unique_ptr<Card>> cards;

};


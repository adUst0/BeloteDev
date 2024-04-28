#pragma once

#include <stdint.h>
#include "SFML/Graphics.hpp"

enum class Suit : int8_t
{
	Clubs = 0,
	Diamonds,
	Hearts,
	Spades,
	Num
};

const std::string& stringFromSuit(Suit suit);

enum class Rank : int8_t
{
	Ace = 0,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Num
};

const std::string& stringFromRank(Rank rank);

class Card
{
public:
	Card(Suit suit, Rank rank);

	Suit							getSuit() const { return m_suit; }
	Rank							getRank() const { return m_rank; }

	const std::string&				toString() const { return m_toString; }

	int								getScore(bool isTrump) const;

private:
	Suit							m_suit;
	Rank							m_rank;
	std::string						m_toString;
};
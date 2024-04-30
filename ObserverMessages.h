#pragma once

class Player;
class Card;
class Contract;
class Trick;
class Round;

struct NotifyCardDealing
{
	const Player& m_player;
	const Card& m_card;
};

struct NotifyContractVote
{
	const Player& m_player;
	const Contract& m_contract;
};

struct NotifyCardAboutToBePlayed
{
	const Player& m_player;
	const Card& m_card;
};


struct NotifyEndOfTrick
{
	const Trick& m_trick;
};

struct NotifyEndOfRound
{
	const Round& m_round;
};
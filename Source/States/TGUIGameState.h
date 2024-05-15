#pragma once
#include "StateMachine.h"
#include <TGUI/Backend/SFML-Graphics.hpp>
#include "Belote.h"
#include "TGUI/Widgets/Label.hpp"
#include "Observer.h"

class NotifyCardDealing;
class NotifyContractVote;
class NotifyCardAboutToBePlayed;
class NotifyEndOfTrick;
class NotifyEndOfRound;
class NotifyNewRound;
class NotifyContractVoteRequired;

using LabelPtr = tgui::Label::Ptr;

class TGUIGameState 
	: public BaseState
	, public Observer<NotifyCardDealing>
	, public Observer<NotifyContractVoteRequired>
	, public Observer<NotifyContractVote>
	, public Observer<NotifyCardAboutToBePlayed>
	, public Observer<NotifyEndOfTrick>
	, public Observer<NotifyEndOfRound>
	, public Observer<NotifyNewRound>
{
public:
	TGUIGameState(StateMachine& stateMachine);

	void							createDeck();
	void							createPlayerNames();
	void							createInfoPanel();
	void							createContractVoteLabel();

	void							updateInfoPanel();
	void							updateActivePlayerLabel(const Player* player = nullptr);
	void							updateContractVoteLabel(const Contract* contractVote = nullptr);

	tgui::Layout2d					getCardPositionInDeck(size_t cardIndex);
	tgui::Layout2d					getCardPositionInPlayer(const Player& player, size_t cardIndex);
	tgui::Layout2d					getCardPositionOnTable(const Player& player);
	tgui::Layout2d					getPlayerNamePosition(const Player& player, float offsetX = 0, float offsetY = 0);
	tgui::Layout2d					getContractVoteLabelPosition(const Player& player);

	virtual void					handleInput() override;
	virtual void					update(float /*dtSeconds*/) override;
	virtual void					draw() override;

	virtual void					notify(const NotifyCardDealing& data) override;
	virtual void					notify(const NotifyContractVoteRequired& data) override;
	virtual void					notify(const NotifyContractVote& data) override;
	virtual void					notify(const NotifyCardAboutToBePlayed& data) override;
	virtual void					notify(const NotifyEndOfTrick& data) override;
	virtual void					notify(const NotifyEndOfRound& data) override;
	virtual void					notify(const NotifyNewRound& data) override;

	void							delayGame(float seconds);
	void							togglePause();
private:
	void							testWidgetPositions();


	tgui::Gui						m_gui;

	LabelPtr						m_contractVoteLabel;

	LabelPtr						m_scoreLabel;
	LabelPtr						m_contractLabel;
	LabelPtr						m_contractCallerLabel;

	LabelPtr						m_pauseLabel;

	std::vector<LabelPtr>			m_playerNameLabels;
	
	Belote							m_belote;

	float							m_delayGameSeconds = 0.f;
	bool							m_shouldPauseGame = false;
};



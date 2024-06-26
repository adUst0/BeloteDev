#include "SplashState.h"
#include "Application.h"
#include "GameState.h"

SplashState::SplashState(StateMachine& stateMachine)
	: UIState(stateMachine)
{
	getOrCreateComponent("background")->addSprite("assets/background.jpg");

	UIComponent* startButton = getOrCreateComponent("start_button");
	startButton->addSprite("assets/button.png", {1.f, 1.f});
	startButton->setText("New Game", sf::Color::Black, 36);
	startButton->setOriginCenter(true);
	startButton->setPosition((sf::Vector2f)Application::getInstance()->getWindow().getSize() / 2.f);
	startButton->onMouseLeftClick([this]() { m_stateMachine.pushState(std::make_unique<GameState>(m_stateMachine)); });
	
	// Test
	//startButton->onMouseOn([]() { std::cout << "MouseON" << std::endl; });
	//startButton->onMouseOff([]() { std::cout << "MouseOff" << std::endl; });
	//startButton->onMouseLeftClick([startButton]() { startButton->markForDestruction(); });

	std::unique_ptr<UIComponent> startButtonHover = std::make_unique<UIComponent>("background_hover");
	startButtonHover->addSprite("assets/button_hover.png", { 1.f, 1.f });
	startButtonHover->setText("New Game", sf::Color::Black, 36);
	startButtonHover->setOriginCenter(true);
	startButtonHover->setPosition((sf::Vector2f)Application::getInstance()->getWindow().getSize() / 2.f);

	startButton->setHoverState(std::move(startButtonHover));

	UIComponent* title = getOrCreateComponent("title");
	title->setText("Belote (Bulgarian rules)", sf::Color(3, 23, 8), 72);
	title->setOriginCenter(true);
	title->setPosition({Application::getInstance()->getWindow().getSize().x / 2.f, 100.f});

	UIComponent* author = getOrCreateComponent("author");
	author->setText("Author: Boris Ivanov", sf::Color::Black, 30);
	author->setOriginCenter(true);
	author->setPosition({ Application::getInstance()->getWindow().getSize().x / 2.f, 150.f });
}
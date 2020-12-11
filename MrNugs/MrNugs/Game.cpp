#include "pch.h"
#include "Game.h"


Game::Game()
{
}

void Game::beginGame() {
	Battle battle;
	Campaign controller;

	while (h->getPosInStory() < gameLength) {
		controller.progress(h);
	}
}

void Game::saveGame() {

}

void Game::loadGame() {

}


Game::~Game()
{
}

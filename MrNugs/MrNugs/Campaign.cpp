#include "pch.h"
#include "Campaign.h"


Campaign::Campaign()
{
}

bool Campaign::progress(Player *h) {
	Battle battle;
	Shop shop;
	int pos = h->getPosInStory();
	Unit *playerCharacter = new Warrior(h);



	//vector<unique_ptr<Unit>> goodUnits
	if (h->getCharacterClass() == "Warrior") {
		playerCharacter = new Warrior(h);
	}
	switch (pos) {
	case 0:
		//Dialogue test
		cout << "Mr. Nugs was a man who loved to eat chicken nuggets." << endl;
		cout << "Insert story here" << endl << endl;
		Sleep(2000);
		break;

	case 1:
		cout << "2 Nugget Guards wish to engage in the fisticuffs with you." << endl;
		//Battle test
		goodUnits.emplace_back(playerCharacter);
		//goodUnits.emplace_back(new FriendlyNuggetGuard(10));
		badUnits.emplace_back(new NuggetGuard(1));
		badUnits.emplace_back(new NuggetGuard(1));

		playerDead = battle.requestBattle(move(goodUnits), move(badUnits));
		break;

	case 2:
		//Shop test
		shop.requestShop(h);

		break;

	case 3:
		cout << "A Dino Nugget Rider wishes to avenge their fallen comrades!" << endl;
		goodUnits.emplace_back(new Warrior(h));
		
		badUnits.emplace_back(new DinoNuggetRider(1));
		badUnits.emplace_back(new NuggetGuard(2));

		playerDead = battle.requestBattle(move(goodUnits), move(badUnits));
		break;

	default:
		cout << "Broke game";
	}

	goodUnits.clear();
	badUnits.clear();

	//Don't progress game if player died.
	if (playerDead) {
		playerDead = false;
		return false;
	}
	else {
		pos++;
		h->setPosInStory(pos);
		return true;
	}

	

}

Campaign::~Campaign()
{
}

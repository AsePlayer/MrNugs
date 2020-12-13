#include "pch.h"
#include "Campaign.h"


Campaign::Campaign()
{
}

void Campaign::progress(Player *h) {
	Battle battle;
	int pos = h->getPosInStory();
	switch (pos) {
	case 0:
		//Dialogue test
		cout << "Mr. Nugs was a man who loved to eat chicken nuggets." << endl;
		Sleep(2000);
		cout << "2 Nugget Guards wish to engage in the fisticuffs with you." << endl;
		break;

	case 1:
		//Battle test
		goodUnits.emplace_back(new Warrior(h));
		//goodUnits.emplace_back(new FriendlyNuggetGuard(10));
		badUnits.emplace_back(new NuggetGuard(1));
		badUnits.emplace_back(new NuggetGuard(1));

		battle.requestBattle(move(goodUnits), move(badUnits));
		break;

	case 2:
		//Shop test
		shop.requestShop(h);

		break;

	case 3:
		cout << "2 Slightly Better Nugget Guards wish to avenge their fallen comrades." << endl;
		goodUnits.emplace_back(new Warrior(h));
		
		badUnits.emplace_back(new NuggetGuard(3));
		badUnits.emplace_back(new NuggetGuard(2));

		battle.requestBattle(move(goodUnits), move(badUnits));
		break;

	default:
		cout << "Broke game";
	}

	goodUnits.clear();
	badUnits.clear();

	pos++;
	h->setPosInStory(pos);


}

Campaign::~Campaign()
{
}

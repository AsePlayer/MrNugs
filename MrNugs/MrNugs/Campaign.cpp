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
	else if (h->getCharacterClass() == "Mage") {
		playerCharacter = new Mage(h);
	}
	else if (h->getCharacterClass() == "Thief") {
		playerCharacter = new Thief(h);
	}
	else if (h->getCharacterClass() == "Archer") {
		playerCharacter = new Archer(h);
	}
	switch (pos) {
	case 0:
		//Dialogue test
		cout << "Mr. Nugs was a man who loved to eat chicken nuggets." << endl << endl;
		Sleep(2500);
		cout << "He ate so many chicken nuggets, that he was considered a threat to all of Nugget-kind." << endl << endl;
		Sleep(2500);
		cout << "One day, he ate one chicken nugget too many... and King Nugget of Nuggetville the III had enough." << endl << endl;
		Sleep(2500);
		cout << "That night, the King cast a spell upon Mr. Nugs... and turned him into a chicken nugget!" << endl << endl;
		Sleep(2500);
		cout << "King Nugget of Nuggetville the III: \"You will be put on trial for your crimes against all of Nugget-kind,\" he declared." << endl << endl;
		Sleep(2500);
		cout << "Mr. Nugs simply rolled his eyes." << endl << endl;
		Sleep(2000);
		cout << "Mr. Nugs: \"Bring it.\"" << endl << endl;
		Sleep(2500);
		cout << "He spent that night in a cold and lonely cell in Nugget Jail. The next morning, Mr. Nugs had his day in court." << endl << endl;
		Sleep(2500);
		cout << "Judge: \"The defendant Mr. Nugs is being charged with 90,621 counts of first-degree murder. How do you plead?\"" << endl << endl;
		Sleep(2500);
		cout << "Mr. Nugs looked around at the room full of angry Nuggets. To them, you were an evil monster. To you, they were delicious." << endl << endl;
		Sleep(2500);
		cout << "Judge: \"Well? What will it be?\"" << endl << endl;
		Sleep(2500);
		cout << "Mr. Nugs: \"Trial by Combat.\"" << endl << endl;
		Sleep(2500);
		cout << "Judge: \"Unfortuantely for you, only the King can approve a Trial by Combat request. And there's no way he'd ev-\"" << endl << endl;
		Sleep(2500);
		cout << "King Nugget of Nuggetville III: \"I accept.\"" << endl << endl;
		Sleep(2500);
		cout << "The Judge raised his eyebrow, before sighing and smacking his gavel down." << endl << endl;
		Sleep(2500);
		cout << "Judge: \"Fine. For a crime this severe, you will be required to clear 10 waves in the Arena to be let off the hook.\"" << endl << endl;
		Sleep(2500);
		cout << "Mr. Nugs: \"So... what? Am I supposed to fend everyone off with my fists and nothing else?\"" << endl << endl;
		Sleep(2500);
		cout << "King Nugget of Nuggetville III: \"You will be permitted to buy items and weapons in the shop after each wave. Survive all 10 waves, and I will pardon your crimes against Nugganity.\"" << endl << endl;
		Sleep(2500);
		cout << "And so it was decided. Mr. Nugs was to begin the challenge immediately." << endl << endl << endl;
		cout << "[1] Continue" << endl;
		cin >> placeholder;
		cout << endl << endl;
		break;

	case 1:
		cout << endl << "2 shaky Nugget Guards enter the ring.";
		Sleep(1500);
		cout << endl << "King Nugget of Nuggetville III: \"We'll start off simple. Can you handle the 2 novice Nugget Guards before you?\"" << endl;
		Sleep(1500);
		//Battle test
		goodUnits.emplace_back(playerCharacter);
		goodUnits.emplace_back(new FriendlyNuggetGuard(10));
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

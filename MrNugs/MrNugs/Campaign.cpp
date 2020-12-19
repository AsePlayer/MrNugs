//Ryan Scott
//CST - 210 : Fantasy Fighting Game
//This file and project are my own work
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
		cout << "King Nugget of Nuggetville III: \"I accept. I've been itching for some good entertainment for a while now.\"" << endl << endl;
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
		cout << endl << "2 slightly more confident Nugget Guards enter the ring.";
		Sleep(1500);
		cout << endl << "King Nugget of Nuggetville III: \"I hope that was easy, because things are just getting started.\"" << endl;
		Sleep(1500);
		goodUnits.emplace_back(playerCharacter);
		
		badUnits.emplace_back(new NuggetGuard(3));
		badUnits.emplace_back(new NuggetGuard(2));

		playerDead = battle.requestBattle(move(goodUnits), move(badUnits));
		break;
	case 4:
		shop.requestShop(h);
		break;
	case 5:
		cout << endl << "A burly nugget lumbered into the arena, towering over you.";
		Sleep(1500);
		cout << endl << "King Nugget of Nuggetville III: \"It's clear my novice Nugget Guards are no match for you. Bring on the Nugget Executioner!\"" << endl;
		Sleep(1500);
		goodUnits.emplace_back(playerCharacter);

		badUnits.emplace_back(new NuggetExecutioner(1));

		playerDead = battle.requestBattle(move(goodUnits), move(badUnits));
		break;
	case 6:
		shop.requestShop(h);
		break;
	case 7:
		cout << endl << "A powerful and threatening trio strut into the arena with a smug look on their face.";
		Sleep(1500);
		cout << endl << "King Nugget of Nuggetville III: \"I tire of this boring Nugget-to-Nugget combat. Let's have an intermission, imported straight from Mexico! Give it up for Chips, Salsa and Guac!\"" << endl;
		Sleep(1500);
		goodUnits.emplace_back(playerCharacter);

		badUnits.emplace_back(new ChipperChip(3));
		badUnits.emplace_back(new SalsaSam(4));
		badUnits.emplace_back(new GuacamoleGuru(4));

		playerDead = battle.requestBattle(move(goodUnits), move(badUnits));
		break;
	case 8:
		shop.requestShop(h);
		break;
	case 9:
		cout << endl << "Another Nugget Executioner?! This time he's not alone...";
		Sleep(1500);
		cout << endl << "King Nugget of Nuggetville III: \"And now back to our regularly scheduled programming. Let's see how you handle a Nugget Executioner with backup!\"" << endl;
		Sleep(1500);
		goodUnits.emplace_back(playerCharacter);

		badUnits.emplace_back(new NuggetExecutioner(3));
		badUnits.emplace_back(new NuggetGuard(4));

		playerDead = battle.requestBattle(move(goodUnits), move(badUnits));
		break;
	case 10:
		shop.requestShop(h);
		break;
	case 11:
		cout << endl << "This foe is unlike anything you've seen prior...";
		Sleep(1500);
		cout << endl << "King Nugget of Nuggetville III: \"Let's see if you can defeat both man and beast. Bring on the Dino Nugget Rider!\"" << endl;
		Sleep(1500);
		goodUnits.emplace_back(playerCharacter);

		badUnits.emplace_back(new DinoNuggetRider(4));

		playerDead = battle.requestBattle(move(goodUnits), move(badUnits));
		break;
	case 12:
		shop.requestShop(h);
		break;
	case 13:
		cout << endl << "Another group of non-Nugget foes enter the arena.";
		Sleep(1500);
		cout << endl << "King Nugget of Nuggetville III: \"How about another intermission? Imported straight from Canada, you will be facing the MaxGames team!\"" << endl;
		Sleep(1500);
		goodUnits.emplace_back(playerCharacter);

		badUnits.emplace_back(new JasonWhitHAM(5));
		badUnits.emplace_back(new BrockoliWhite(5));
		badUnits.emplace_back(new DexMex(4));
		badUnits.emplace_back(new AlanGrahamcracker(4));

		playerDead = battle.requestBattle(move(goodUnits), move(badUnits));
		break;
	case 14:
		shop.requestShop(h);
		break;
	case 15:
		cout << endl << "A large group of enemies enter the ring.";
		Sleep(1500);
		cout << endl << "King Nugget of Nuggetville III: \"I haven't tried overwhelming you with numbers yet... let's try that!\"" << endl;
		Sleep(1500);
		goodUnits.emplace_back(playerCharacter);

		badUnits.emplace_back(new NuggetGuard(7));
		badUnits.emplace_back(new NuggetGuard(7));
		badUnits.emplace_back(new NuggetGuard(6));
		badUnits.emplace_back(new NuggetGuard(6));
		badUnits.emplace_back(new NuggetGuard(5));
		badUnits.emplace_back(new NuggetGuard(4));
		badUnits.emplace_back(new NuggetGuard(4));

		playerDead = battle.requestBattle(move(goodUnits), move(badUnits));
		break;
	case 16:
		shop.requestShop(h);
		break;
	case 17:
		cout << endl << "All of your past Nugget foes step into the ring for one final bout.";
		Sleep(1500);
		cout << endl << "King Nugget of Nuggetville III: \"It would be pretty anticlimatic if you died here, so like, don't do that.\"" << endl;
		Sleep(1500);
		goodUnits.emplace_back(playerCharacter);

		badUnits.emplace_back(new NuggetGuard(7));
		badUnits.emplace_back(new NuggetGuard(7));
		badUnits.emplace_back(new NuggetExecutioner(4));
		badUnits.emplace_back(new DinoNuggetRider(5));


		playerDead = battle.requestBattle(move(goodUnits), move(badUnits));
		break;
	case 18:
		shop.requestShop(h);
		break;
	case 19:
		cout << endl << "A hungry Chicken wanders into the Arena.";
		Sleep(1500);
		cout << endl << "King Nugget of Nuggetville III: \"It's time for the final bout. Meet your maker!\"" << endl;
		Sleep(1500);
		goodUnits.emplace_back(playerCharacter);

		badUnits.emplace_back(new Chicken(1));
	   
		playerDead = battle.requestBattle(move(goodUnits), move(badUnits));
		break;
	case 20:
		cout << endl << "You should spend all your money now. Wink wink. ;)" << endl;
		shop.requestShop(h);
		break;
	case 21:
		cout << endl << "King Nugget of Nuggetville III: \"Very well, Mr. Nugs. It seems you have bested the arena after all.\"" << endl;
		Sleep(1500);
		cout << endl << "King Nugget of Nuggetville III: \"I'll turn you back into a hu-\"" << endl;
		Sleep(1500);
		cout << endl << "*THUD THUD*" << endl;
		Sleep(1500);
		cout << endl << "King Nugget of Nuggetville III: \"What's that noi- AAAAAH\"" << endl;
		Sleep(1500);
		cout << endl << "Suddenly, King Nugget of Nuggetville III was grabbed by an enormous hand!" << endl;
		Sleep(1500);
		cout << endl << "Is that a... HUMAN ? !" << endl;
		Sleep(2000);
		cout << endl << "Nugget Guards: \"DESTROY THIS BEAST OR DIE TRYING! FOR THE KING!!!\"" << endl;
		Sleep(1500);
		cout << endl << "Join forces with the brave Nugget Guards to defeat the threat to the King so you can be turned back into a human!" << endl;
		Sleep(2000);
		goodUnits.emplace_back(playerCharacter);
		goodUnits.emplace_back(new FriendlyNuggetGuard(8));
		goodUnits.emplace_back(new FriendlyNuggetGuard(8));
		goodUnits.emplace_back(new FriendlyNuggetGuard(8));
		goodUnits.emplace_back(new FriendlyNuggetGuard(8));
		goodUnits.emplace_back(new FriendlyNuggetGuard(8));
		goodUnits.emplace_back(new FriendlyNuggetGuard(8));

		badUnits.emplace_back(new Human(1));

		playerDead = battle.requestBattle(move(goodUnits), move(badUnits));
		break;
	case 22:
		cout << endl << "The battle was over and the dust had settled. It was over... or so everyone thought." << endl;
		Sleep(2000);
		cout << endl << "However, it was not meant to be. The Human got back up, and ran away with the King in his clutches." << endl;
		Sleep(2000);
		cout << endl << "Mr. Nugs: \"NOOOOO! How am I supposed to turn back into a human now?\"" << endl;
		Sleep(2000);
		cout << endl << "Mysterious Mage: \"I can help.\"" << endl;
		Sleep(2000);
		cout << endl << "Mr. Nugs: \"Huh? How? Only the King has the power to do that, right?\"" << endl;
		Sleep(2000);
		cout << endl << "Mysterious Mage: \"Oh, I can't turn you back into a Human.\"" << endl;
		Sleep(2000);
		cout << endl << "Mr. Nugs: \"Then why are you wasting my time?\"" << endl;
		Sleep(2000);
		cout << endl << "Mysterious Mage: \"Because... while I can't turn you into a Human, I can turn you into a Human-sized Nugget.\"" << endl;
		Sleep(2000);
		cout << endl << endl << "TO BE CONTINUED" << endl << endl;
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

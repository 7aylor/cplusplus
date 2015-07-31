/*
	Battle Simulator between Nazis and Zombies. Really simple. Just creates a set number of nazis and a set number
	of zombies and makes them fight to the death. Demonstrates how to use random numbers, while loops, and incrementing
	numbers.
*/

#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

//checks to see if input is within a certain bounds
void checkNum(int &choice, int upperBound, int lowerBound);

int main()
{
	default_random_engine randomGenerator(time(NULL));
	uniform_real_distribution<float> attack(0.0f, 1.0f);

	//attack damage
	int naziAttack = 10;
	int zombieAttack = 5;

	//chance of hitting
	float naziPercent = 0.5f;
	float zombiePercent = 0.66f;

	//health per person
	int naziHealth = 15;
	int zombieHealth = 20;

	//person at the front line health
	int currentNaziHealth = naziAttack;
	int currentZombieHealth = zombieHealth;

	//total number of nazis and zombies
	int naziNum;
	int zombieNum;

	//determines who attacks first
	int start = 1;

	int naziDeaths = 0;
	int zombieDeaths = 0;

	int upperBound = 10000;
	int lowerBound = 1;

	string nazi = "Nazi";
	string zombie = "Zombie";

	cout << "***NAZIS vs. ZOMBIES***\n\n";

	cout << "Starting Nazi Health: " << naziHealth << endl;
	cout << "Starting Zombie Health: " << zombieHealth << endl;

	cout << "Starting Nazi damage: " << naziAttack << endl;
	cout << "Starting Zombie damage: " << zombieAttack << endl << endl;

	cout << "Input the number of Nazis (1-10000): ";
	cin >> naziNum;

	checkNum(naziNum, upperBound, lowerBound);

	cout << "Input the number of Zombies (1-10000): ";
	cin >> zombieNum;

	checkNum(zombieNum, upperBound, lowerBound);

	cout << "FIGHT!\n\n";
	
	//ascii battle art!
	cout << "                  Y" << endl;;
	cout << "                  |      ." << endl;
	cout << "                  +._ O /" << endl;
	cout << "                  |  `#'" << endl;
	cout << "                  |  / \"" << endl;
	cout << "                     ())" << endl;
	cout << "                     d b" << endl;
	cout << endl;
	cout << "                       p" << endl;
	cout << "                    .-/-o" << endl;
	cout << "                   / /'" << endl;
	cout << "              .--./ /     --------<" << endl;
	cout << "                  O'-._" << endl;
	cout << "                       `" << endl;

	//makes the nazis and zombies fight each other until one army is completely dead
	while ((zombieNum > 0) && (naziNum > 0)){
		float zombieAtt = attack(randomGenerator);
		float naziAtt = attack(randomGenerator);

		if (start == 1){
			//half of the time, nazi hits a zombie for 10 damage
			if (naziAtt > naziPercent){
				currentZombieHealth = currentZombieHealth - naziAttack;

				//if zombie health is zero, kill and update
				if (currentZombieHealth <= 0){
					zombieNum--;
					zombieDeaths++;
					currentZombieHealth = zombieHealth;
				}
			}
			//changes the attacker for the next round
			start = start * -1;
		}
		else{
			//two thirds of the time, zombie hits a nazi for 5 damage
			if (zombieAtt < zombiePercent){
				currentNaziHealth = currentNaziHealth - zombieAttack;

				//if nazi health is zero, kill and update
				if (currentNaziHealth <= 0){
					naziNum--;
					naziDeaths++;
					currentNaziHealth = naziHealth;
				}
			}
			//changes the attacker for the next round
			start = start * -1;
		}
	}

	if (zombieNum > 0){
		cout << "Zombies win!\n\n";
	}
	else{
		cout << "Nazis win!\n\n\n";
	}

	cout << "Nazi Casualties: " << naziDeaths << endl;
	cout << "Remaining Nazis: " << naziNum << endl << endl;

	cout << "Zombie Casualties: " << zombieDeaths << endl;
	cout << "Remaining Zombies: " << zombieNum << endl << endl;
	

	system("PAUSE");
	return 0;
}


void checkNum(int &choice, int upperBound, int lowerBound){
	//check the choice to make sure it is within bounds and if its not, make
	//the user try again
	while (cin.fail() || choice > upperBound || choice < lowerBound)
	{
		cin.clear();
		cin.ignore(999, '\n');
		cout << "Please pick an integer between " << lowerBound << " and " << upperBound << ": ";
		cin >> choice;
	}
}
/*
	==================================================
	Workshop #5 (Part-1):
	==================================================
	Name   : Devang Ramubhai Ahir Ahir
	ID     : 153484209
	Email  : drahir-ahir@myseneca.ca
	Section: NBB
*/
#define _CRT_SECURE_NO_WARNINGS
#define PATHLENGHTS 35
#include<stdio.h>


struct PlayerInfo { //player's information
	int lives;
	char character;
};

struct GameInfo {
	int moves;
	int pathlenght;
	int bomb[PATHLENGHTS];
	int treasure[PATHLENGHTS];
};

int main()
{
	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n\n");

	printf("PLAYER Configuration\n");
	printf("--------------------\n");
	
	struct PlayerInfo player;
	printf("Enter a single character to represent the player: "); // asking player for a gamer tag
	scanf(" %c", &player.character);

	int IsValid;
	do// this do is for player's info
	{
		IsValid = 1;
		printf("Set the number of lives: "); // asking the player for number of lifes
		scanf("%d", &player.lives);
		if (player.lives < 1 || player.lives > 10)
		{
			printf("     Must be between 1 and 10!\n");
			IsValid = 0;
		}
	} while (IsValid == 0);
	printf("Player configuration set-up is complete\n\n");

	printf("GAME Configuration\n");
	printf("------------------\n");

	struct GameInfo game;
	do// this do is for pathlenght in game's information
	{
		IsValid = 1;
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf("%d", &game.pathlenght);
		int path_length;
		path_length = game.pathlenght % 5;
		if (10 > game.pathlenght || game.pathlenght > 70 || path_length != 0)
		{
			printf("     Must be a multiple of 5 and between 10-70!!!\n");
			IsValid = 0;
		}
	} while (IsValid == 0);

	do
	{
		IsValid = 1;
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &game.moves);
		if (game.moves < 3 || game.moves > 26)
		{
			printf("    Value must be between 3 and 26\n");
			IsValid = 0;
		}
	} while (IsValid == 0);
	printf("\n");
	int i;
	printf("BOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
	printf("   Positions [ 1- 5]: ");
	scanf("%d %d %d %d %d", &game.bomb[0], &game.bomb[1], &game.bomb[2], &game.bomb[3], &game.bomb[4]);
	
	printf("   Positions [ 6-10]: ");
	scanf("%d %d %d %d %d", &game.bomb[5], &game.bomb[6], &game.bomb[7], &game.bomb[8], &game.bomb[9]);

	printf("   Positions [11-15]: ");
	scanf("%d %d %d %d %d", &game.bomb[10], &game.bomb[11], &game.bomb[12], &game.bomb[13], &game.bomb[14]);

	printf("   Positions [16-20]: ");
	scanf("%d %d %d %d %d", &game.bomb[15], &game.bomb[16], &game.bomb[17], &game.bomb[18], &game.bomb[19]);

	printf("   Positions [21-25]: ");
	scanf("%d %d %d %d %d", &game.bomb[20], &game.bomb[21], &game.bomb[22], &game.bomb[23], &game.bomb[24]);

	printf("   Positions [26-30]: ");
	scanf("%d %d %d %d %d", &game.bomb[25], &game.bomb[26], &game.bomb[27], &game.bomb[28], &game.bomb[29]);

	printf("   Positions [31-35]: ");
	scanf("%d %d %d %d %d", &game.bomb[30], &game.bomb[31], &game.bomb[32], &game.bomb[33], &game.bomb[34]);
	printf("BOMB placement set\n\n");

	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
	printf("   Positions [ 1- 5]: ");
	scanf("%d %d %d %d %d", &game.treasure[0], &game.treasure[1], &game.treasure[2], &game.treasure[3], &game.treasure[4]);

	printf("   Positions [ 6-10]: ");
	scanf("%d %d %d %d %d", &game.treasure[5], &game.treasure[6], &game.treasure[7], &game.treasure[8], &game.treasure[9]);

	printf("   Positions [11-15]: ");
	scanf("%d %d %d %d %d", &game.treasure[10], &game.treasure[11], &game.treasure[12], &game.treasure[13], &game.treasure[14]);

	printf("   Positions [16-20]: ");
	scanf("%d %d %d %d %d", &game.treasure[15], &game.treasure[16], &game.treasure[17], &game.treasure[18], &game.treasure[19]);

	printf("   Positions [21-25]: ");
	scanf("%d %d %d %d %d", &game.treasure[20], &game.treasure[21], &game.treasure[22], &game.treasure[23], &game.treasure[24]);

	printf("   Positions [26-30]: ");
	scanf("%d %d %d %d %d", &game.treasure[25], &game.treasure[26], &game.treasure[27], &game.treasure[28], &game.treasure[29]);

	printf("   Positions [31-35]: ");
	scanf("%d %d %d %d %d", &game.treasure[30], &game.treasure[31], &game.treasure[32], &game.treasure[33], &game.treasure[34]);
	printf("TREASURE placement set\n\n");

	printf("GAME configuration set-up is complete...\n\n");
	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", player.character);
	printf("   Lives      : %d\n", player.lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n\n");

	printf("Game:\n");
	printf("   Path Length: 35\n");
	printf("   Bombs      : ");
	for (i = 0; i < PATHLENGHTS; i++)
	{
		printf("%d", game.bomb[i]);
	}

	printf("\n   Treasure   : ");
	for (i = 0; i < PATHLENGHTS; i++)
	{
		printf("%d", game.treasure[i]);
	}
	printf("\n\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");
	return 0;
}

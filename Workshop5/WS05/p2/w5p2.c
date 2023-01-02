/*
	==================================================
	Workshop #5 (Part-2):
	==================================================
	Name   : Devang Ramubhai Ahir Ahir
	ID     : 153484209
	Email  : drahir-ahir@myseneca.ca
	Section: NBB
*/
#define _CRT_SECURE_NO_WARNINGS
#define PATHLENGHTS 70
#include<stdio.h>


struct PlayerInfo { //player's information
	int lives;
	char character;
	int TreasureFound;
	int gameplay[PATHLENGHTS];
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

	int IsValid, i;
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

	for (i = 0; i < PATHLENGHTS; i++)
	{
		player.gameplay[i] = 0;
	}

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
		if (game.moves < 3 || game.moves > 15)
		{
			printf("    Value must be between 3 and 15\n");
			IsValid = 0;
		}
	} while (IsValid == 0);
	printf("\n");
	
	printf("BOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are 20 to set!\n");
	printf("   Positions [ 1- 5]: ");
	scanf("%d %d %d %d %d", &game.bomb[0], &game.bomb[1], &game.bomb[2], &game.bomb[3], &game.bomb[4]);

	printf("   Positions [ 6-10]: ");
	scanf("%d %d %d %d %d", &game.bomb[5], &game.bomb[6], &game.bomb[7], &game.bomb[8], &game.bomb[9]);

	printf("   Positions [11-15]: ");
	scanf("%d %d %d %d %d", &game.bomb[10], &game.bomb[11], &game.bomb[12], &game.bomb[13], &game.bomb[14]);

	printf("   Positions [16-20]: ");
	scanf("%d %d %d %d %d", &game.bomb[15], &game.bomb[16], &game.bomb[17], &game.bomb[18], &game.bomb[19]);
	printf("BOMB placement set\n\n");

	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are 20 to set!\n");
	printf("   Positions [ 1- 5]: ");
	scanf("%d %d %d %d %d", &game.treasure[0], &game.treasure[1], &game.treasure[2], &game.treasure[3], &game.treasure[4]);

	printf("   Positions [ 6-10]: ");
	scanf("%d %d %d %d %d", &game.treasure[5], &game.treasure[6], &game.treasure[7], &game.treasure[8], &game.treasure[9]);

	printf("   Positions [11-15]: ");
	scanf("%d %d %d %d %d", &game.treasure[10], &game.treasure[11], &game.treasure[12], &game.treasure[13], &game.treasure[14]);

	printf("   Positions [16-20]: ");
	scanf("%d %d %d %d %d", &game.treasure[15], &game.treasure[16], &game.treasure[17], &game.treasure[18], &game.treasure[19]);
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
	printf("   Path Length: %d\n", game.pathlenght);
	printf("   Bombs      : ");
	for (i = 0; i < game.pathlenght; i++)
	{
		printf("%d", game.bomb[i]);
	}

	printf("\n   Treasure   : ");
	for (i = 0; i < game.pathlenght; i++)
	{
		printf("%d", game.treasure[i]);
	}
	printf("\n\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");
	
	const char undiscovered = '-', bomb = '!', treasure = '$', bothbat = '&', neitherbat = '.';
	int k = 1, nextMove = 1, temp = 0, flag = 0;
	
	player.TreasureFound = 0;
	while (1)
	{
		if (temp == 0) 
		{
			++temp;
		}
		else
		{
			printf("\n  ");
			for (i = 0; i <= game.pathlenght; i++)
			{
				if (player.gameplay[i] == 1 && i == (nextMove - 1))
				{
					printf("%c", player.character);
		 		}
				else
					printf(" ");
			}
		}
		printf("\n  ");
		for (i = 0; i < game.pathlenght; i++)
		{
			if (player.gameplay[i] == 0)
			{
				printf("%c", undiscovered);
			}
			else if (game.bomb[i] == 1 && game.treasure[i] == 1)
			{
				printf("%c", bothbat);
			}
			else if (game.bomb[i] == 1)
			{
				printf("%c", bomb);
			}
			else if (game.treasure[i] == 1)
			{
				printf("%c", treasure);
			}
			else
				printf("%c", neitherbat);
		}
		printf("\n  ");
		for (i = 0; i < game.pathlenght; i++)
		{
			if ((i + 1) % 10 == 0)
			{
				++flag;
				printf("%d", flag);

			}
			else
				printf("|");
		}
		flag = 0;
		printf("\n  ");
		for (i = 0; i < game.pathlenght; i++)
		{
			if ((i + 1) % 10 == 0)
			{
				printf("0");
				k = 1;
			}
			else
				printf("%d", k++);
		}
		printf("\n");
		printf("+---------------------------------------------------+\n");
		printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.TreasureFound, game.moves);
		printf("+---------------------------------------------------+\n");
		if (player.lives == 0 || game.moves == 0) {
			break;
		}
		while (1)
		{
			printf("Next Move [1-%d]: ", game.pathlenght);
			scanf("%d", &nextMove);
			if (nextMove < 1 || nextMove > game.pathlenght)
				printf("  Out of Range!!!\n");
			else
				break;
		}
		if (player.gameplay[nextMove - 1] == 1)
		{
			printf("\n===============> Dope! You've been here before!\n");
		}
		else
		{
			player.gameplay[nextMove - 1] = 1;
			game.moves -= 1;
			if (game.bomb[nextMove - 1] == 1 && game.treasure[nextMove - 1] == 1)
			{
				player.lives = player.lives - 1;
				player.TreasureFound = player.TreasureFound + 1;
				printf("\n===============> [%c] !!! BOOOOOM !!! [&]", bothbat);
				printf("\n===============> [%c] $$$ Life Insurance Payout!!![&]\n", bothbat);
				if (player.lives == 0)
				
				{
					printf("\nNo more LIVES remaining!\n");
				}
				else if (game.moves == 0)
				{
					printf("\nNo more MOVES remaining!\n");
				}
			}
			else if (game.bomb[nextMove - 1] == 1)
			{
				player.lives = player.lives - 1;
				printf("\n===============> [%c] !!! BOOOOOM !!! [!]\n", bomb);
				if (player.lives == 0)
				{
					printf("\nNo more LIVES remaining!\n");
				}
				else if (game.moves == 0)
				{
					printf("\nNo more MOVES remaining!\n");
				}
			}
			else if (game.treasure[nextMove - 1] == 1)
			{
				player.TreasureFound = player.TreasureFound + 1;
				printf("\n===============> [%c] $$$ Found Treasure! $$$ [$]\n", treasure);
				if (player.lives == 0)
				{
					printf("\nNo more LIVES remaining!\n");
				}
				else if (game.moves == 0)
				{
					printf("\nNo more MOVES remaining!\n");
				}
			}
			else
			{
				printf("\n===============> [%c] ...Nothing found here... [.]\n", neitherbat);
			}
		}
	}
	printf("\n##################\n");
	printf("# Game over! #\n");
	printf("##################\n");
	printf("\nYou should play again and try to beat your score!\n");
	
	return 0;
}


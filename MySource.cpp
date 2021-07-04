#include <iostream>
#include <ctime>


void PrintIntroduction(int Difficulty)
{

	std::cout << "\n\nYou are a hacker breaking into a level " << Difficulty;
	std::cout << " secure server room..\nEnter the correct codes to continue..\n\n";

}


bool PlayGame(int Difficulty)
{
	//Intro Print statement
	PrintIntroduction(Difficulty);
	//Declare 3 number code
	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	//Print sum and product

	std::cout << std::endl;
	std::cout << "> There are 3 numbers in the code ";
	std::cout << "\n> The codes add upto: " << CodeSum;
	std::cout << "\n> The codes multiply to give: " << CodeProduct << std::endl;

	//store player guess
	int GuessA, GuessB, GuessC;
	std::cin >> GuessA >> GuessB >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;


	//Check if the guess is correct or not
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "\n**Well done,you have decrypted a file,Keep going**";
		return true;
	}
	else
	{
		std::cout << "\n**You have entered the wrong code, Try again**";
		return false;
	}

}


int main()
{
	srand(time(NULL)); //creates new random sequences based on the time of day
	
	int LevelDifficulty = 1;
	int const MaxDifficulty = 5;

	while (LevelDifficulty <= MaxDifficulty) //Loop the game until all levels are completed
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		
		std::cin.clear(); //clears any errors
		std::cin.ignore(); //discard the buffer if any bad characters is entered
		if (bLevelComplete)
		{
			++LevelDifficulty;
		}
	}
	std::cout << "Congratulations!! you are a professional hacker!!! ";
	return 0;
	
}
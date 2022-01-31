// Easy Systems


#include "WilsonsAlgorithmPen.h"

void AWilsonsAlgorithmPen::Generate()
{ //create a starting cell
	int x = SeedValue.RandRange(2, width - 1);
	int z = SeedValue.RandRange(2, depth - 1);
	map.Add(FVector2D(x, z), 2);

	SeedValue = FRandomStream(SeedForRandomMap);
	loopcount = 0;
	//TODO fix the need for loopcount.
	//The problem ties down to it adding things with a square it can't connect to the maze from
	//	Basically if it has a valid start square, but that square can't go anywhere without having too many connections, then it's in an infinite loop.
	// Loopcount is dodging this issue, would be better to actually encase the code properly, but may be pointless as there are better methods coming up.
	while (GetAvailableCells() > 1 && loopcount < 80)
	{
		loopcount++;
		RandomWalk();
		}
}

int AWilsonsAlgorithmPen::GetAvailableCells()
{
	notUsed.Empty();
	for (int z = 1; z < depth - 1; z++)
		for (int x = 1; x < width - 1; x++)
		{
			if (CountSquareMazeNeighbours(x, z) == 0)
			{
				notUsed.Add(FVector2D(x, z));
			}
		}

	return notUsed.Num() -1;
	
}

int AWilsonsAlgorithmPen::CountSquareMazeNeighbours(int x, int z)
{
	int count = 0;
	for (int d = 0; d < directions.Num()-1; d++)
	{
		int nx = x + directions[d].X;
		int nz = z + directions[d].Y;
		if (map.FindRef(FVector2D(nx, nz)) == 2)
		{
			count++;
		}
	}

	return count;
}

void AWilsonsAlgorithmPen::RandomWalk()
{
 	TArray<FVector2D> inWalk;
 	int cx;
 	int cz;
 	int rstartIndex = SeedValue.RandRange(0, notUsed.Num()-1);

 	cx = notUsed[rstartIndex].X;
 	cz = notUsed[rstartIndex].Y;
 
 	inWalk.Add(FVector2D(cx, cz));
 
 	int loop = 0;
 	bool validPath = false;
 	while (cx > 0 && cx < width - 1 && cz > 0 && cz < depth - 1 && loop < 1000 && !validPath)
 	{

		loop++;
 		map.Add(FVector2D(cx, cz), 0);
 		if (CountSquareMazeNeighbours(cx, cz) > 1)
 			break;

		int rd = SeedValue.RandRange(0, directions.Num()-1);
		int nx = cx + directions[rd].X;
		int nz = cz + directions[rd].Y;
		if (CountSquareNeighbours(nx, nz) < 2)
		{
			cx = nx;
			cz = nz;
			inWalk.Add(FVector2D(cx, cz));
		}

		validPath = CountSquareMazeNeighbours(cx, cz) == 1;

	}

	if (validPath)
	{
		map.Add(FVector2D(cx, cz),0);
		UE_LOG(LogTemp, Warning, TEXT("Path found"))

			for (int i = 0; i < inWalk.Num() - 1; i++)
			{
				map.Add(inWalk[i], 2);
			}

		inWalk.Empty();
	}
	else
 	{
		for (int i = 0; i < inWalk.Num() - 1; i++)
		{
			map.Add(inWalk[i], 1);
		}


 		inWalk.Empty();
 	}

}

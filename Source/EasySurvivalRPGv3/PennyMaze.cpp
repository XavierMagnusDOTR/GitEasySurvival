// Easy Systems


#include "PennyMaze.h"

// Sets default values
APennyMaze::APennyMaze()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void APennyMaze::BeginPlay()
{
	Super::BeginPlay();

}

void APennyMaze::InitialiseMap()
{
    SeedValue = FRandomStream(SeedForRandomMap);
	UE_LOG(LogTemp, Warning, TEXT(" Initialize called"))
	for (int z = 0; z < depth; z++)
		for (int x = 0; x < width; x++)
		{
		map.Add(FVector2D(x, z), 1);     //1 = wall  0 = corridor
		}
}



void  APennyMaze::Generate()
{
 		for (int z = 0; z < depth; z++)
 			for (int x = 0; x < width; x++)
 			{
 				if (SeedValue.RandRange(0, 100) < 50)
 				map.Add(FVector2D(x,z), 0); //1 = wall  0 = corridor
 			}
}



bool APennyMaze::Search2D(int c, int r, TArray<int> pattern)
{
	//counts matches with pattern
	int count = 0;
	//position tested
	int pos = 0;

	// 1,-1   1,0   1,1
	// 0,-1   0,0   0,1
	//-1,-1  -1,0  -1,1
	for (int y = 1; y > -2; y--)
	{
		for (int x = -1; x < 2; x++)
		{
			if (pattern[pos] == 5 || pattern[pos] == map.FindRef(FVector2D(c + x, r + y)))
			{
				UE_LOG(LogTemp, Warning, TEXT("Value of pattern pos: %i"), pattern[pos])
				UE_LOG(LogTemp, Warning, TEXT("Value of map location: %i"), map.FindRef(FVector2D(c + x, r + y)))
				//match found
				count++;
				
				UE_LOG(LogTemp, Warning, TEXT("Count up to %i"), count)
			}
			//increasing position
			pos++;
			UE_LOG(LogTemp, Warning, TEXT("Pos up to %i"), pos)
		}
	}
	return (count == 9);// this just says if it matches the pattern coming in
	
}

int  APennyMaze::CountSquareNeighbours(int x, int z)
{
 		int count = 0;
		if (x <= 0 || x >= width - 1 || z <= 0 || z >= depth - 1) return 5;
		if (map.FindRef(FVector2D(x - 1, z)) == 0) count++;
		if (map.FindRef(FVector2D(x + 1, z)) == 0) count++;
		if (map.FindRef(FVector2D(x, z + 1)) == 0) count++;
		if (map.FindRef(FVector2D(x, z - 1)) == 0) count++;
 		return count;
}

int  APennyMaze::CountDiagonalNeighbours(int x, int z)
 {
 		int count = 0;
		if (x <= 0 || x >= width - 1 || z <= 0 || z >= depth - 1) return 5;
		if (map.FindRef(FVector2D(x - 1, z - 1)) == 0) count++;
		if (map.FindRef(FVector2D(x + 1, z + 1)) == 0) count++;
		if (map.FindRef(FVector2D(x - 1, z + 1)) == 0) count++;
		if (map.FindRef(FVector2D(x + 1, z - 1)) == 0) count++;
 		return count;
}

int  APennyMaze::CountAllNeighbours(int x, int z)
{
		return CountSquareNeighbours(x, z) + CountDiagonalNeighbours(x, z);
}

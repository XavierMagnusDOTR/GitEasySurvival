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

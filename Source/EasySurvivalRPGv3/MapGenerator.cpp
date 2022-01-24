// Easy Systems


#include "MapGenerator.h"

// Sets default values
AMapGenerator::AMapGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AMapGenerator::BeginPlay()
{
	Super::BeginPlay();
}

void AMapGenerator::InitializeMap(int mapWidthX, int mapLengthY)
{
	for(int i= 0; i< mapWidthX; i++)
	{UE_LOG(LogTemp, Warning, TEXT("The value of i is: %i"), i) ;
		for(int j = 0; j < mapLengthY; j++)
		{
			currentmap.Add(FVector2D(i, j), 1);
		
		}
		
	}
	mapX = mapWidthX;
	mapY = mapLengthY;
	GenerateMapVariations();
}


void AMapGenerator::GenerateMapVariations()
{	

	FRandomStream SeedValue = FRandomStream(SeedForRandomMap);
	if (UseHorizontalCrawler)
	{	
	for(int i = 0; i< HorizontalCrawlerCount;i++)
	{HorizontalCrawler(FVector2D(mapX/2, mapY/2), FVector2D(0, 0), FVector2D(mapX, mapY), SeedValue);}
	}
	if (UseVerticalCrawler)
	{
	for(int i = 0; i < VerticalCrawlerCount; i++)
	{VerticalCrawler(FVector2D(mapX / 2, mapY / 2), FVector2D(0, 0), FVector2D(mapX, mapY), SeedValue); }
	}
}

void AMapGenerator::HorizontalCrawler(FVector2D startingposition, FVector2D boundarymin, FVector2D boundarymax, FRandomStream seed)
{	

	bool done = false;
	int loopcount = 0;
	while (!done)
	{

		UE_LOG(LogTemp, Warning, TEXT("Seed value is: %i"), seed.GetCurrentSeed())
		currentmap.Add(startingposition, 0);
		loopcount++;
		float x = seed.RandRange(0,1);
		if(x > HCrawlerDeviationChance)
		{startingposition.X += seed.RandRange(-1, 1);}
		else{startingposition.Y += seed.RandRange(-1, 1);}

		done = (startingposition.X < boundarymin.X || startingposition.Y  < boundarymin.Y || startingposition.X > boundarymax.X || startingposition.Y > boundarymax.Y || loopcount > maxSteps);
	}
}

void AMapGenerator::VerticalCrawler(FVector2D startingposition, FVector2D boundarymin, FVector2D boundarymax, FRandomStream seed)
{

	bool done = false;
	int loopcount = 0;
	while (!done)
	{

		UE_LOG(LogTemp, Warning, TEXT("Seed value is: %i"), seed.GetCurrentSeed())
		currentmap.Add(startingposition, 0);
		loopcount++;
		float x = seed.RandRange(0, 1);
		if (x > VCrawlerDeviationChance)
		{
			startingposition.Y += seed.RandRange(-1, 1);
		}
		else { startingposition.X += seed.RandRange(-1, 1); }

		done = (startingposition.X < boundarymin.X || startingposition.Y  < boundarymin.Y || startingposition.X > boundarymax.X || startingposition.Y > boundarymax.Y || loopcount > maxSteps);
	}
}

TMap<FVector2D, int> AMapGenerator::GetMap()
{
	return currentmap;
}


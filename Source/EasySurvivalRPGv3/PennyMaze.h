// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/Vector2D.h"
#include "Kismet/KismetMathLibrary.h"
#include "PennyMaze.generated.h"

UCLASS()
class EASYSURVIVALRPGV3_API APennyMaze : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APennyMaze();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	UPROPERTY(EditAnywhere)
    int width = 30; //x length
	UPROPERTY(EditAnywhere)
	int depth = 30; //z length

	//byte[, ] map;
	TMap<FVector2D, int> map;
	UPROPERTY(EditAnywhere)
	int scale = 600;


	UFUNCTION(BlueprintCallable)
	TMap<FVector2D, int> GetMap(){return map;};

	UPROPERTY(EditAnywhere)
	int SeedForRandomMap = -1;
	FRandomStream SeedValue;

	UFUNCTION(BlueprintCallable)
	void InitialiseMap();

	UFUNCTION(BlueprintCallable)
	virtual void Generate();

	int CountSquareNeighbours(int x, int z);
	int CountDiagonalNeighbours(int x, int z);
	int CountAllNeighbours(int x, int z);
};

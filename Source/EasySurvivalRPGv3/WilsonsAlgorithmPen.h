// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "PennyMaze.h"
#include "WilsonsAlgorithmPen.generated.h"

/**
 * 
 */
UCLASS()
class EASYSURVIVALRPGV3_API AWilsonsAlgorithmPen : public APennyMaze
{
	GENERATED_BODY()


public:
    

virtual void Generate() override;

int GetAvailableCells();

int CountSquareMazeNeighbours(int x, int z);
void RandomWalk();

UPROPERTY(EditAnywhere)
int loopcount;

TArray<FVector2D> directions = {FVector2D(1,0),FVector2D(0,1),FVector2D(-1,0), FVector2D(0,-1)};
TArray<FVector2D> notUsed;

};

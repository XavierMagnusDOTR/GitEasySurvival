// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "PennyMaze.h"
#include "RecursiveMaze.generated.h"

/**
 * 
 */
UCLASS()
class EASYSURVIVALRPGV3_API ARecursiveMaze : public APennyMaze
{
	GENERATED_BODY()

public:
  virtual void Generate() override;
  void Generate(int x, int y);
  void ShuffleArray(TArray<FVector2D>& ArrayToShuffle);
};

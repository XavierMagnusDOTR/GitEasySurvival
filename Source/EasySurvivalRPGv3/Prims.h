// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "PennyMaze.h"
#include "Prims.generated.h"

/**
 * 
 */
UCLASS()
class EASYSURVIVALRPGV3_API APrims : public APennyMaze
{
	GENERATED_BODY()

public:

    virtual void Generate() override;


    TArray<FVector2D> walls;
};

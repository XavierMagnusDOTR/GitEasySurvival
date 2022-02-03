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

	TArray<FVector2D> directions = { FVector2D(1,0),FVector2D(0,1),FVector2D(-1,0), FVector2D(0,-1) };

	UFUNCTION(BlueprintCallable)
	void InitialiseMap();

	UFUNCTION(BlueprintCallable)
	virtual void Generate();

	///C is column, R is row, pattern in array around the position
	UFUNCTION(BlueprintCallable)
	bool Search2D(int c, int r, TArray<int> pattern);
	int CountSquareNeighbours(int x, int z);
	int CountDiagonalNeighbours(int x, int z);
	int CountAllNeighbours(int x, int z);

	//PatternsForPlaceDetection 
// 8 5 2                   
// 7 4 1
// 6 3 0                   BR,CR,TR,BC,CC,TC,BL,CL,T
//                          0, 1, 2, 3, 4, 5, 6, 7, 8
	UPROPERTY(BlueprintReadOnly, Category = "PatternsforSearch", DisplayName = "V_Tunnel")
	TArray<int> V_TunnelPatt = { 5, 5, 5, 5, 5, 5, 5, 5, 5 };
//	TArray<int> V_TunnelPatt = { 5, 0, 5, 1, 1, 1, 5, 0, 5 };
	//                         BR,CR,TR,BC,CC,TC,BL,CL,TL
	//                          0, 1, 2, 3, 4, 5, 6, 7, 8
	UPROPERTY(BlueprintReadOnly, Category = "PatternsforSearch", DisplayName = "H_Tunnel")
	TArray<int> H_TunnelPatt = { 5, 2, 5, 1, 2, 1, 5, 2, 5 };
	//                         BR,CR,TR,BC,CC,TC,BL,CL,TL
	//                          0, 1, 2, 3, 4, 5, 6, 7, 8
	UPROPERTY(BlueprintReadOnly, Category = "PatternsforSearch", DisplayName = "RU_Corner")
	TArray<int> RU_CornerPatt = { 5, 2, 1, 1, 2, 2, 5, 1, 5 };
	//                         BR,CR,TR,BC,CC,TC,BL,CL,TL
	//                          0, 1, 2, 3, 4, 5, 6, 7, 8
	UPROPERTY(BlueprintReadOnly, Category = "PatternsforSearch", DisplayName = "RD_Corner")
	TArray<int> RD_CornerPatt = { 1, 2, 5, 2, 2, 1, 5, 1, 5 };
	//                         BR,CR,TR,BC,CC,TC,BL,CL,TL
	//                          0, 1, 2, 3, 4, 5, 6, 7, 8
	UPROPERTY(BlueprintReadOnly, Category = "PatternsforSearch", DisplayName = "LD_Corner")
	TArray<int> LD_CornerPatt = { 5, 1, 5, 2, 2, 1, 1, 2, 5 };
	//                         BR,CR,TR,BC,CC,TC,BL,CL,TL
	//                          0, 1, 2, 3, 4, 5, 6, 7, 8
	UPROPERTY(BlueprintReadOnly, Category = "PatternsforSearch", DisplayName = "LU_Corner")
	TArray<int> LU_CornerPatt = { 5, 1, 5, 1, 2, 2, 5, 2, 1 };
	//                         BR,CR,TR,BC,CC,TC,BL,CL,TL
	//                          0, 1, 2, 3, 4, 5, 6, 7, 8
	UPROPERTY(BlueprintReadOnly, Category = "PatternsforSearch", DisplayName = "3way_Up")
	TArray<int> ThreeWayUpPatt = { 5, 2, 1, 1, 2, 2, 5, 2, 1 };
	//                         BR,CR,TR,BC,CC,TC,BL,CL,TL
	//                          0, 1, 2, 3, 4, 5, 6, 7, 8
	UPROPERTY(BlueprintReadOnly, Category = "PatternsforSearch", DisplayName = "3way_Down")
	TArray<int> ThreeWayDownPatt = { 1, 2, 5, 2, 2, 1, 1, 2, 5 };
	//                         BR,CR,TR,BC,CC,TC,BL,CL,TL
	//                          0, 1, 2, 3, 4, 5, 6, 7, 8
	UPROPERTY(BlueprintReadOnly, Category = "PatternsforSearch", DisplayName = "3way_Right")
	TArray<int> ThreeWayRightPatt = { 1, 2, 1, 2, 2, 2, 5, 1, 5 };
	//                         BR,CR,TR,BC,CC,TC,BL,CL,TL
	//                          0, 1, 2, 3, 4, 5, 6, 7, 8
	UPROPERTY(BlueprintReadOnly, Category = "PatternsforSearch", DisplayName = "3Way_Left")
	TArray<int> ThreeWayLeftPatt = { 5, 1, 5, 2, 2, 2, 1, 2, 1 };
	//                         BR,CR,TR,BC,CC,TC,BL,CL,TL
	//                          0, 1, 2, 3, 4, 5, 6, 7, 8
	UPROPERTY(BlueprintReadOnly, Category = "PatternsforSearch", DisplayName = "4Way")
	TArray<int> FourWayPatt = { 1, 2, 1, 2, 2, 2, 1, 2, 1 };
	//                         BR,CR,TR,BC,CC,TC,BL,CL,TL
	//                          0, 1, 2, 3, 4, 5, 6, 7, 8
	UPROPERTY(BlueprintReadOnly, Category = "PatternsforSearch", DisplayName = "DeadEnd_Up")
	TArray<int> DeadEndUpPatt = { 5, 1, 5, 2, 2, 1, 5, 1, 5 };
	//                         BR,CR,TR,BC,CC,TC,BL,CL,TL
	//                          0, 1, 2, 3, 4, 5, 6, 7, 8
	UPROPERTY(BlueprintReadOnly, Category = "PatternsforSearch", DisplayName = "DeadEnd_Down")
	TArray<int> DeadEndDownPatt = { 5, 1, 5, 1, 2, 2, 5, 1, 5 };
	//                         BR,CR,TR,BC,CC,TC,BL,CL,TL
	//                          0, 1, 2, 3, 4, 5, 6, 7, 8
	UPROPERTY(BlueprintReadOnly, Category = "PatternsforSearch", DisplayName = "DeadEnd_Left")
	TArray<int> DeadEndLeftPatt = { 5, 1, 5, 1, 2, 1, 5, 2, 5 };
	//                         BR,CR,TR,BC,CC,TC,BL,CL,TL
	//                          0, 1, 2, 3, 4, 5, 6, 7, 8
	UPROPERTY(BlueprintReadOnly, Category = "PatternsforSearch", DisplayName = "DeadEnd_Right")
	TArray<int> DeadEndRightPatt = { 5, 2, 5, 1, 2, 1, 5, 1, 5 };
};

// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/Vector2D.h"
#include "Kismet/KismetMathLibrary.h"
#include "MapGenerator.generated.h"

UCLASS()
class EASYSURVIVALRPGV3_API AMapGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMapGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	UFUNCTION(BlueprintCallable)
	void InitializeMap(int mapWidthX, int mapLengthY);
	int mapX, mapY;
	UFUNCTION(BlueprintCallable)
	void GenerateMapVariations();
	UFUNCTION(BlueprintCallable)
	void HorizontalCrawler(FVector2D startingposition, FVector2D boundarymin, FVector2D boundarymax, FRandomStream seed);

	UFUNCTION(BlueprintCallable)
	void VerticalCrawler(FVector2D startingposition, FVector2D boundarymin, FVector2D boundarymax, FRandomStream seed);
	UPROPERTY(EditAnywhere)
	TMap<FVector2D, int> currentmap;



	UPROPERTY(EditAnywhere)
	int SeedForRandomMap = -1;

	UPROPERTY(EditAnywhere)
	int maxSteps = 60;

	UFUNCTION(BlueprintCallable)
	TMap<FVector2D, int> GetMap();

	UPROPERTY(EditAnywhere)
	bool UseHorizontalCrawler = false;
	UPROPERTY(EditAnywhere)
	int HorizontalCrawlerCount = 2;
	UPROPERTY(EditAnywhere)
	float HCrawlerDeviationChance = .7; 


	UPROPERTY(EditAnywhere)
	bool UseVerticalCrawler = false;
	UPROPERTY(EditAnywhere)
	int VerticalCrawlerCount = 2;
	UPROPERTY(EditAnywhere)
	float VCrawlerDeviationChance = .7;
};

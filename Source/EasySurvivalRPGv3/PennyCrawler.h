// Easy Systems

#pragma once

#include "CoreMinimal.h"
#include "PennyMaze.h"
#include "PennyCrawler.generated.h"

/**
 * 
 */
UCLASS()
class EASYSURVIVALRPGV3_API APennyCrawler : public APennyMaze
{
	GENERATED_BODY()
	

public:
 virtual void Generate() override;


 UPROPERTY(EditAnywhere)
 int VerticalCrawlerCount;
 UPROPERTY(EditAnywhere)
 int HorizontaCrawlerCount;


 

 void CrawlV();
 void CrawlH();
};

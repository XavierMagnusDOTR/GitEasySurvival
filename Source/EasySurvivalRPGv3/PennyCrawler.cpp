// Easy Systems


#include "PennyCrawler.h"





void APennyCrawler::Generate()
{
	for (int i = 0; i < VerticalCrawlerCount; i++)
	       CrawlV();

	for (int i = 0; i < HorizontaCrawlerCount; i++)
		    CrawlH();
}

void APennyCrawler::CrawlV()
{

	//TODO appears to generate too wide, odds are random range gap of 2 is the source, investigate later.
	bool done = false;
	int x = SeedValue.RandRange(1, width - 1);
	int z = 1;

	while (!done)
	{
		map.Add(FVector2D(x, z), 0);
		if (SeedValue.RandRange(0, 100) < 50)
			x += SeedValue.RandRange(-1, 2);
		else
			z += SeedValue.RandRange(0, 2);
		done |= (x < 1 || x >= width - 1 || z < 1 || z >= depth - 1);
	}
}

void APennyCrawler::CrawlH()
{

	//TODO appears to generate too wide, odds are random range gap of 2 is the source, investigate later.
	bool done = false;
	int x = 1;
	int z = SeedValue.RandRange(1, depth - 1);

	while (!done)
	{
		map.Add(FVector2D(x, z), 0);
		if  (SeedValue.RandRange(0, 100) < 50)
			x += SeedValue.RandRange(0, 2);
		else
			z += SeedValue.RandRange(-1, 2);
		done |= (x < 1 || x >= width - 1 || z < 1 || z >= depth - 1);
	}

}

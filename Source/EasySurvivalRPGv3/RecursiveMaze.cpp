// Easy Systems


#include "RecursiveMaze.h"

void ARecursiveMaze::Generate()
{
  Generate(SeedValue.RandRange(1, width), SeedValue.RandRange(1, depth));
}	

void ARecursiveMaze::Generate(int x, int y)
{
	if(CountSquareNeighbours(x, y) >=2)
	{return; }

	map.Add((FVector2D(x,y) ) , 0);

	ShuffleArray(directions);
	Generate(x+directions[0].X, y+directions[0].Y);
	Generate(x + directions[1].X, y+directions[1].Y);
	Generate(x + directions[2].X, y + directions[2].Y);
	Generate(x+directions[3].X, y + directions[3].Y);

}

void ARecursiveMaze::ShuffleArray(TArray<FVector2D>& ArrayToShuffle)
{
	if (ArrayToShuffle.Num() > 0)
	{
		int lastIndex = ArrayToShuffle.Num() - 1;
		for (int i = 0; i < lastIndex; ++i)
		{
			int Index = SeedValue.RandRange(i, lastIndex);
			if (i != Index)
			{
				ArrayToShuffle.Swap(i, Index);
			}
		}
	}

}

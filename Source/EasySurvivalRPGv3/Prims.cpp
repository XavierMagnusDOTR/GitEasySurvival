// Easy Systems


#include "Prims.h"

void APrims::Generate()
{
		int x = 2;
		int y = 2;

		map.Add(FVector2D(x,y),0);
		
		walls.Add(FVector2D(x + 1, y));
		walls.Add(FVector2D(x - 1, y));
		walls.Add(FVector2D(x, y + 1));
		walls.Add(FVector2D(x, y - 1));

		int countloops = 0;
		while (walls.Num() > 0 && countloops < 5000)
		{
			int rwall = SeedValue.RandRange(0, walls.Num()-1);
			x = walls[rwall].X;
			y = walls[rwall].Y;
			walls.RemoveAt(rwall);
			if (CountSquareNeighbours(x, y) == 1)
			{

				map.Add(FVector2D(x, y), 0); 
				walls.Add(FVector2D(x + 1, y));
				walls.Add(FVector2D(x - 1, y));
				walls.Add(FVector2D(x, y + 1));
				walls.Add(FVector2D(x, y - 1));
			}

			countloops++;
		}
	
}

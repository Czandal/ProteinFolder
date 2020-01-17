#include "Map.h"
int Map::findPos(int x, int y)
{
	for (size_t i = 0; i < points.size(); i++)
	{
		if (points[i].x == x && points[i].y == y)
		{
			return i;
		}
	}
	return -67666;
}
void Map::calcExtremes()
{
	if (!this->points.empty())
	{
		switch (points.size())
		{
		case 1:
		{
			this->maxX = points[0].x;
			this->minX = points[0].x;
			this->minY = points[0].y;
			this->maxY = points[0].y;
			break;
		}
		case 2:
		{
			if (points[0].x > points[1].x)
			{
				this->maxX = points[0].x;
				this->minX = points[1].x;
			}
			else
			{
				this->maxX = points[1].x;
				this->minX = points[0].x;
			}
			if (points[0].y > points[1].y)
			{
				this->maxY = points[0].y;
				this->minY = points[1].y;
			}
			else
			{
				this->maxY = points[1].y;
				this->minY = points[0].y;
			}
			break;
		}
		default:
		{
			Map a, b;
			for (size_t i = 0; i < points.size(); i++)
			{
				if (i <= points.size() / 2)
				{
					a.points.push_back(points[i]);
				}
				else
				{
					b.points.push_back(points[i]);
				}
			}
			a.calcExtremes();
			b.calcExtremes();
			if (a.maxX > b.maxX)
			{
				this->maxX = a.maxX;
			}
			else
			{
				this->maxX = b.maxX;
			}
			if (a.maxY > b.maxY)
			{
				this->maxY = a.maxY;
			}
			else
			{
				this->maxY = b.maxY;
			}
			if (a.minX < b.minX)
			{
				this->minX = a.minX;
			}
			else
			{
				this->minX = b.minX;
			}
			if (a.minY < b.minY)
			{
				this->minY = a.minY;
			}
			else
			{
				this->minY = b.minY;
			}
			break;
		}
		}

	}
}
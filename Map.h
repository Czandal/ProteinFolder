#pragma once
#include <vector>
class point
{
public:
	int x, y;
	bool Hydrophobic;
};

class Map
{
public:
	std::vector<point> points;
	int score;
	int maxX;
	int minX;
	int maxY;
	int minY;
	Map() :score(0), maxX(1), maxY(1), minX(1), minY(1) {}
	int findPos(int x, int y);
	void calcExtremes();
};


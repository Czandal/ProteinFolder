#include "Global.h"

point TemplateP = { 1,1,0 };

Map TemplateM;

std::vector<Map>branches;

std::string input;

bool finished;


time_point<system_clock> start;
time_point<system_clock> end;

//funkcja rysujaca do naszej tekstury, ktora potem w main.cpp jest zapisywana do pliku
void project(sf::RenderTexture& texture, Map m)
{
	int width = 50 * (m.maxX - m.minX + 1);
	int height = 50 * (m.maxY - m.minY + 1);
	float R = 50 / 6.0;
	texture.create(width, height);
	sf::CircleShape c;
	c.setRadius(R);
	c.setPointCount(45);
	c.setOutlineThickness(2);
	c.setOutlineColor(sf::Color::Black);
	// Kolor tla
	texture.clear(sf::Color::White);

	sf::Vertex line[2];
	line[0].color = sf::Color::Black;
	line[1].color = sf::Color::Black;
	for (size_t i = 0; i < m.points.size() - 1; i++)
	{
		line[0].position = sf::Vector2f(25 + (m.points[i].x - m.minX) * 50.0, 25 + (m.points[i].y - m.minY) * 50.0);
		line[1].position = sf::Vector2f(25 + (m.points[i + 1].x - m.minX) * 50.0, 25 + (m.points[i + 1].y - m.minY) * 50.0);
		texture.draw(line, 2, sf::Lines);
	}

	for (size_t i = 0; i < m.points.size(); i++)
	{
		c.setPosition(25+(m.points[i].x-m.minX)*50 - R,25+ (m.points[i].y - m.minY ) * 50 - R);
		if (m.points[i].Hydrophobic)
		{
			c.setFillColor(sf::Color::Black);
		}
		else
		{
			c.setFillColor(sf::Color::White);
		}
		texture.draw(c);
	}
}

bool propability(float p)
{
	if (p >= 100)
	{
		return 1;
	}
	else if (p <= 0)
	{
		return 0;
	}
	else
	{
		return (rand() % 100 < p);
	}
}

void extend(std::vector<Map>&maps)
{
	for (size_t i = 2; i < input.length(); i++)
	{
		std::vector<Map> new_gen;
		if (input[i]=='H')
		{
			int best = 0;
			float average = 0.0;
			int count = 0;
			for (size_t q = 0; q < maps.size(); q++)
			{
				TemplateM = maps[q];
				if (!Hpush_mapD(TemplateM))
				{
					if (TemplateM.score>best)
					{
						best = TemplateM.score;
						new_gen.push_back(TemplateM);
						average = average * count + TemplateM.score;
						count++;
						average /= count;
					}
					else if (TemplateM.score == best)
					{
						new_gen.push_back(TemplateM);
						average = average * count + TemplateM.score;
						count++;
						average /= count;
					}
					else if (TemplateM.score>=average)
					{
						if (!propability(P2))
						{
							new_gen.push_back(TemplateM);
							average = average * count + TemplateM.score;
							count++;
							average /= count;
						}
					}
					else
					{
						if (!propability(P1))
						{
							new_gen.push_back(TemplateM);
							average = average * count + TemplateM.score;
							count++;
							average /= count;
						}
					}
				}
				TemplateM = maps[q];
				if (!Hpush_mapU(TemplateM))
				{
					if (TemplateM.score > best)
					{
						best = TemplateM.score;
						new_gen.push_back(TemplateM);
						average = average * count + TemplateM.score;
						count++;
						average /= count;
					}
					else if (TemplateM.score == best)
					{
						new_gen.push_back(TemplateM);
						average = average * count + TemplateM.score;
						count++;
						average /= count;
					}
					else if (TemplateM.score >= average)
					{
						if (!propability(P2))
						{
							new_gen.push_back(TemplateM);
							average = average * count + TemplateM.score;
							count++;
							average /= count;
						}
					}
					else
					{
						if (!propability(P1))
						{
							new_gen.push_back(TemplateM);
							average = average * count + TemplateM.score;
							count++;
							average /= count;
						}
					}
				}
				TemplateM = maps[q];
				if (!Hpush_mapL(TemplateM))
				{
					if (TemplateM.score > best)
					{
						best = TemplateM.score;
						new_gen.push_back(TemplateM);
						average = average * count + TemplateM.score;
						count++;
						average /= count;
					}
					else if (TemplateM.score == best)
					{
						new_gen.push_back(TemplateM);
						average = average * count + TemplateM.score;
						count++;
						average /= count;
					}
					else if (TemplateM.score >= average)
					{
						if (!propability(P2))
						{
							new_gen.push_back(TemplateM);
							average = average * count + TemplateM.score;
							count++;
							average /= count;
						}
					}
					else
					{
						if (!propability(P1))
						{
							new_gen.push_back(TemplateM);
							average = average * count + TemplateM.score;
							count++;
							average /= count;
						}
					}
				}
				TemplateM = maps[q];
				if (!Hpush_mapR(TemplateM))
				{
					if (TemplateM.score > best)
					{
						best = TemplateM.score;
						new_gen.push_back(TemplateM);
						average = average * count + TemplateM.score;
						count++;
						average /= count;
					}
					else if (TemplateM.score == best)
					{
						new_gen.push_back(TemplateM);
						average = average * count + TemplateM.score;
						count++;
						average /= count;
					}
					else if (TemplateM.score >= average)
					{
						if (!propability(P2))
						{
							new_gen.push_back(TemplateM);
							average = average * count + TemplateM.score;
							count++;
							average /= count;
						}
					}
					else
					{
						if (!propability(P1))
						{
							new_gen.push_back(TemplateM);
							average = average * count + TemplateM.score;
							count++;
							average /= count;
						}
					}
				}
			}
		}
		else
		{
			for (size_t q = 0; q < maps.size(); q++)
			{
				TemplateM = maps[q];
				if (!Ppush_mapD(TemplateM))
				{
					new_gen.push_back(TemplateM);
				}
				TemplateM = maps[q];
				if (!Ppush_mapU(TemplateM))
				{
					new_gen.push_back(TemplateM);
				}
				TemplateM = maps[q];
				if (!Ppush_mapL(TemplateM))
				{
					new_gen.push_back(TemplateM);
				}
				TemplateM = maps[q];
				if (!Ppush_mapR(TemplateM))
				{
					new_gen.push_back(TemplateM);
				}
			}
		}
		maps = new_gen;
	}
}

void extractBest(const std::vector<Map>&maps,Map&best)
{
	int record = 0;
	for (size_t i = 1; i < maps.size(); i++)
	{
		if (maps[record].score<maps[i].score)
		{
			record = i;
		}
	}
	best = maps[record];
}

bool Hpush_mapR(Map& m)
{
	int pos = 0;
	TemplateP.Hydrophobic = 1;
	TemplateP.x = m.points.back().x + 1;
	TemplateP.y = m.points.back().y;
	if (m.findPos(TemplateP.x, TemplateP.y) == -67666)
	{
		if (m.points.back().Hydrophobic)
		{
			m.score += 1;
		}
		pos = m.findPos(TemplateP.x + 1, TemplateP.y);
		if (pos != -67666 && m.points[pos].Hydrophobic)
		{
			m.score += 1;
		}
		pos = m.findPos(TemplateP.x, TemplateP.y + 1);
		if (pos != -67666 && m.points[pos].Hydrophobic)
		{
			m.score += 1;
		}
		pos = m.findPos(TemplateP.x, TemplateP.y - 1);
		if (pos != -67666 && m.points[pos].Hydrophobic)
		{
			m.score += 1;
		}
		m.points.push_back(TemplateP);
		return 0;
	}
	return 1;
}
bool Hpush_mapL(Map& m)
{
	int pos = 0;
	TemplateP.Hydrophobic = 1;
	TemplateP.x = m.points.back().x - 1;
	TemplateP.y = m.points.back().y;
	if (m.findPos(TemplateP.x, TemplateP.y) == -67666)
	{
		if (m.points.back().Hydrophobic)
		{
			m.score += 1;
		}
		pos = m.findPos(TemplateP.x - 1, TemplateP.y);
		if (pos != -67666 && m.points[pos].Hydrophobic)
		{
			m.score += 1;
		}
		pos = m.findPos(TemplateP.x, TemplateP.y + 1);
		if (pos != -67666 && m.points[pos].Hydrophobic)
		{
			m.score += 1;
		}
		pos = m.findPos(TemplateP.x, TemplateP.y - 1);
		if (pos != -67666 && m.points[pos].Hydrophobic)
		{
			m.score += 1;
		}
		m.points.push_back(TemplateP);
		return 0;
	}
	return 1;
}
bool Hpush_mapD(Map& m)
{
	int pos = 0;
	TemplateP.Hydrophobic = 1;
	TemplateP.x = m.points.back().x;
	TemplateP.y = m.points.back().y - 1;
	if (m.findPos(TemplateP.x, TemplateP.y) == -67666)
	{
		if (m.points.back().Hydrophobic)
		{
			m.score += 1;
		}
		pos = m.findPos(TemplateP.x + 1, TemplateP.y);
		if (pos != -67666 && m.points[pos].Hydrophobic)
		{
			m.score += 1;
		}
		pos = m.findPos(TemplateP.x - 1, TemplateP.y);
		if (pos != -67666 && m.points[pos].Hydrophobic)
		{
			m.score += 1;
		}
		pos = m.findPos(TemplateP.x, TemplateP.y - 1);
		if (pos != -67666 && m.points[pos].Hydrophobic)
		{
			m.score += 1;
		}
		m.points.push_back(TemplateP);
		return 0;
	}
	return 1;
}
bool Hpush_mapU(Map& m)
{
	int pos = 0;
	TemplateP.Hydrophobic = 1;
	TemplateP.x = m.points.back().x;
	TemplateP.y = m.points.back().y + 1;
	if (m.findPos(TemplateP.x, TemplateP.y) == -67666)
	{
		if (m.points.back().Hydrophobic)
		{
			m.score += 1;
		}
		pos = m.findPos(TemplateP.x + 1, TemplateP.y);
		if (pos != -67666 && m.points[pos].Hydrophobic)
		{
			m.score += 1;
		}
		pos = m.findPos(TemplateP.x - 1, TemplateP.y);
		if (pos != -67666 && m.points[pos].Hydrophobic)
		{
			m.score += 1;
		}
		pos = m.findPos(TemplateP.x, TemplateP.y + 1);
		if (pos != -67666 && m.points[pos].Hydrophobic)
		{
			m.score += 1;
		}
		m.points.push_back(TemplateP);
		return 0;
	}
	return 1;
}

bool Ppush_mapR(Map& m)
{
	TemplateP.Hydrophobic = 0;
	TemplateP.x = m.points.back().x + 1;
	TemplateP.y = m.points.back().y;
	if (m.findPos(TemplateP.x, TemplateP.y) == -67666)
	{
		m.points.push_back(TemplateP);
		return 0;
	}
	return 1;
}
bool Ppush_mapL(Map& m)
{
	TemplateP.Hydrophobic = 0;
	TemplateP.x = m.points.back().x - 1;
	TemplateP.y = m.points.back().y;
	if (m.findPos(TemplateP.x, TemplateP.y) == -67666)
	{
		m.points.push_back(TemplateP);
		return 0;
	}
	return 1;
}
bool Ppush_mapD(Map& m)
{
	TemplateP.Hydrophobic = 0;
	TemplateP.x = m.points.back().x;
	TemplateP.y = m.points.back().y - 1;
	if (m.findPos(TemplateP.x, TemplateP.y) == -67666)
	{
		m.points.push_back(TemplateP);
		return 0;
	}
	return 1;
}
bool Ppush_mapU(Map& m)
{
	TemplateP.Hydrophobic = 0;
	TemplateP.x = m.points.back().x;
	TemplateP.y = m.points.back().y + 1;
	if (m.findPos(TemplateP.x, TemplateP.y) == -67666)
	{
		m.points.push_back(TemplateP);
		return 0;
	}
	return 1;
}

void calculateScore(void* data)
{
	Map* m = (Map*)data;
	
	if (!m->points.empty())
	{
		m->score = 0;
		int pos = 0;
		for (size_t i = 0; i < m->points.size(); i++)
		{
			end= system_clock::now();
			if (duration_cast<milliseconds>(end - start).count() > 28500)
			{
				finished = 1;
				break;
			}
			if (m->points[i].Hydrophobic)
			{
				pos = m->findPos(m->points[i].x + 1, m->points[i].y);
				if (pos != -67666 && m->points[pos].Hydrophobic)
				{
					m->score++;
				}
				pos = m->findPos(m->points[i].x - 1, m->points[i].y);
				if (pos != -67666 && m->points[pos].Hydrophobic)
				{
					m->score++;
				}
				pos = m->findPos(m->points[i].x, m->points[i].y + 1);
				if (pos != -67666 && m->points[pos].Hydrophobic)
				{
					m->score++;
				}
				pos = m->findPos(m->points[i].x, m->points[i].y - 1);
				if (pos != -67666 && m->points[pos].Hydrophobic)
				{
					m->score++;
				}
			}
		}
		m->score /= 2;
	}
	else
	{
		m->score = 0;
	}
}
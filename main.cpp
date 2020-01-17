#include "Global.h"
#include "Map.h"



int main(int argc, char*argv[])
{
	std::cin >> input;
	//poczatek liczenia czasu
	start = system_clock::now();
	srand(time(nullptr));

	Map best;
	best.score = -1;
	std::vector<Map>maps;
	{
		TemplateP.Hydrophobic = (input[0] == 'H');
		TemplateP.x = 1;
		TemplateP.y = 1;
		TemplateM.points.push_back(TemplateP);
		TemplateP.Hydrophobic = (input[1] == 'H');
		TemplateP.x = 1;
		TemplateP.y = 2;
		TemplateM.points.push_back(TemplateP);
		maps.push_back(TemplateM);
	}
	extend(maps);
	extractBest(maps, best);
	best.calcExtremes();
	sf::RenderTexture texture;
	project(texture, best);
	
	texture.getTexture().copyToImage().saveToFile("output.png");
	//calculateScore(&best);
	std::cout <<"\n"<< best.score * -1;
	return 0;
}


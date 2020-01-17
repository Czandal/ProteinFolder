#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <SFML/Main.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <vector>
#include "Map.h"

#define P1 99.0
#define P2 79.0

using namespace std::chrono;

//nasz limit czasowy, dla ktorego staramy sie wykonac zadanie
const std::chrono::seconds maxT(29);

extern point TemplateP;

extern Map TemplateM;

extern std::vector<Map> branches;

extern std::string input;

extern time_point<system_clock> start;
extern time_point<system_clock> end;

extern bool finished;

void project(sf::RenderTexture& texture, Map m);

bool propability(float p);

bool Hpush_mapR(Map& m);
bool Hpush_mapL(Map& m);
bool Hpush_mapD(Map& m);
bool Hpush_mapU(Map& m);
bool Ppush_mapR(Map& m);
bool Ppush_mapL(Map& m);
bool Ppush_mapD(Map& m);
bool Ppush_mapU(Map& m);

void extend(std::vector<Map>&maps);
void extractBest(const std::vector<Map>&maps,Map&best);
void calculateScore(void* data);
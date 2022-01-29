#pragma once
#include <vector>
#include "Chromosome.h"

using namespace std;


class Population
{
private:
	vector<Chromosome*> individus  ;
	
	vector<Chromosome*> crossoverAll(vector<Chromosome*>);
	void sortByFitness(); //trie individus ordre croissant fitness
	vector<Chromosome*> elitism();

public:
	Population( vector<Chromosome*>);
	double bestFitness(string);
	Population nextpopulation();
};


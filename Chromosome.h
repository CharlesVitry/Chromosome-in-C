#pragma once
#include <string>
#include "Parameter.h"
using namespace std;

class Chromosome
{
private:
	string genes; //represente mot meme longueur que celui à trouver
	double fitness;

public:
	Chromosome(string = "");
	void mutate(); // mutation du chromosome
	double evalFitness(string);
	pair<Chromosome*, Chromosome*> crossover(Chromosome); //croisement avec un autre chromosome pour 2 new chromosomes
	void randomCreate(int n); //créé aléatoire chromosome
	// évalue performance chromosome


	double getFitness();
	friend ostream& operator<<(ostream&, Chromosome);


};


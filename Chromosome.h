#pragma once
#include <string>
#include "Parameter.h"
using namespace std;

class Chromosome
{
private:
	string genes; //represente mot meme longueur que celui � trouver
	double fitness;

public:
	Chromosome(string = "");
	void mutate(); // mutation du chromosome
	double evalFitness(string);
	pair<Chromosome*, Chromosome*> crossover(Chromosome); //croisement avec un autre chromosome pour 2 new chromosomes
	void randomCreate(int n); //cr�� al�atoire chromosome
	// �value performance chromosome


	double getFitness();
	friend ostream& operator<<(ostream&, Chromosome);


};


#include "Population.h"
#include <algorithm>
#include <iostream>
#include <ostream>


bool smallerByFitness(Chromosome* c1, Chromosome* c2)
{
	return (c1->getFitness()) <= (c2->getFitness());
}

void Population::sortByFitness()
{
	std::sort(individus.begin(), individus.end(), smallerByFitness);
	//
}

vector<Chromosome*> Population::elitism()
{
	vector<Chromosome*> selection;
	for (int i = 0; i < TAILLE_POPULATION * TAUX_ELITISME; i++) {
		
		
			selection.push_back(individus[i]);
		
		
	}
	return selection;
}

Population::Population( vector<Chromosome*> chromes)
{

	this->individus = chromes;
}



double Population::bestFitness(string cible)
{
	for (Chromosome* chrom : individus)
		chrom->evalFitness(cible);
	sortByFitness();
	cout << "The best : " << *individus[0] << endl;

	return individus[0]->getFitness();
}

Population Population::nextpopulation()
{
	vector<Chromosome*> nextIndiv = elitism();
	nextIndiv = crossoverAll(nextIndiv);
	return Population(nextIndiv);


}

vector<Chromosome*> Population::crossoverAll(vector<Chromosome*> indiv)
{
	for(int i = 0 ; i<TAILLE_POPULATION   *(1-TAUX_ELITISME)/2; i++)
	{
		int i1 = rand() % (TAILLE_POPULATION / 2);
		int i2 = rand() % (TAILLE_POPULATION / 2);

		pair<Chromosome*, Chromosome*> children = individus[i1]->crossover(*individus[i2]);
		if (rand() < RAND_MAX * TAUX_MUTATION)
			children.first->mutate();

		if (rand() < RAND_MAX * TAUX_MUTATION)
			children.second->mutate();

		indiv.push_back(children.first);
		indiv.push_back(children.second);
	}
	return indiv;

}

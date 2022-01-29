#include <time.h>
#include <iostream>
#include "Population.h"
#include "Parameter.h"

using namespace std;

int main() {
	
	//cout << rand() %100 <<  endl;

	cout << "Cible : ";
	string cible;
	cin >> cible;

	srand(time(NULL)); //initialise générateur nbre aléatoire
	vector<Chromosome*> init;

	for (int i = 0; i < TAILLE_POPULATION; i++)
	{
		Chromosome* chrom = new Chromosome();
		chrom->randomCreate(cible.size());
		init.push_back(chrom);



	}
	Population p(init);
	int bestFitness = p.bestFitness(cible);
	for(int i = 0; i < NB_ITERATION && bestFitness != 0; i++)
	{
		p = p.nextpopulation();
		bestFitness = p.bestFitness(cible);

	}





}
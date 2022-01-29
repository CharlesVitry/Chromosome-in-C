#include "Chromosome.h"

#include <iostream>

Chromosome::Chromosome(string s)
{
	genes = s;
	fitness = 0;
}

void Chromosome::mutate()
{
	//on prend une lettre au hasard

	// choisit un emplacement au hasard dans le gene et on y remplace le gène
	genes[rand() % genes.size()] = (65 + rand() % 190);
}

double Chromosome::evalFitness(string cible)
{
	int count = 0;
	for (int i = 0; i < cible.size(); i++)
		if (genes[i] != cible[i])
			count += 1;

	fitness = count;
	return fitness;
}

pair<Chromosome*, Chromosome*> Chromosome::crossover(Chromosome autre)
{
	int c = rand() % genes.size();
	//on coupe la chaine en deux
	Chromosome* chrom1 = new Chromosome (genes.substr(0, c) + autre.genes.substr(c, genes.size() - c));
	Chromosome* chrom2 = new Chromosome(autre.genes.substr(0, c) + genes.substr(c, genes.size() - c));

	return pair<Chromosome*, Chromosome*>(chrom1,chrom2);
}

void Chromosome::randomCreate(int n) //n longueur mot à trouver
{
	genes = "";
	for (int i = 0; i < n; i++)
		genes += 65 + rand() % 190;
}

double Chromosome::getFitness()
{
	return fitness;
}


ostream& operator<<(ostream& out, Chromosome chrom)
{
	cout << chrom.genes << " " << chrom.fitness;
	return out;
}



;


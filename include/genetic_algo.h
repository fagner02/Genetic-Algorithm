#include <iostream>
#include <algorithm>
#include <random>
#include <set>
#include <point.h>

#pragma once

typedef std::vector<int> Instance;

class GeneticAlgorithm {
public:
    const int instanceLimit = 9;
    const int spaceSize = 9;
    const float elitismRatio = 0.1;
    const float mutationRate = 0.01;
    std::vector<Instance> instances;
    std::vector<std::vector<int>> dMatrix;
    std::vector<std::vector<int>> fMatrix;

    GeneticAlgorithm();

    void generateInstances();

    void generateMatrixes();

    float calculateFitness(Instance& instance);

    void getFittest();

    Instance tournamentSelection();

    Instance rouletteSelection();

    Instance halvedCrossover(Instance parent1, Instance parent2);

    Instance intertwinedCrossover(Instance parent1, Instance parent2);

    Instance swapMutate(Instance instance);

    Instance invertMutate(Instance instance);

    void ratioElitism(std::vector<Instance> oldInstances, std::vector<Instance> offspring);

    void rankedElitism(std::vector<Instance> oldInstances, std::vector<Instance> offspring);

    void nextGeneration();

    std::vector<float> getAllInstancesFitness();
};
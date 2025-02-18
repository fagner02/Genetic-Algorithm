#include <iostream>
#include <constants.h>
#include <algorithm>
#include <random>

#pragma once

class GeneticAlgorithm {
public:
    const int instanceLimit = 5;
    const int spaceSize = 3;
    std::vector<std::vector<int>> instances;
    std::vector<std::vector<int>> dMatrix;
    std::vector<std::vector<int>> fMatrix;

    GeneticAlgorithm();

    void generateInstances();

    void generateMatrixes();

    float calculateFitness(std::vector<int>& instance);

    void getFittest();

    std::vector<float> getAllInstancesFitness();
};
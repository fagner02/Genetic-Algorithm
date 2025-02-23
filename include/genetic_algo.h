#include <iostream>
#include <algorithm>
#include <random>
#include <set>
#include <point.h>
#include <functional>
#include <fstream>
#include <optional>
#include <cfloat>
#include <sstream>

#pragma once

typedef std::vector<int> Instance;

enum SelectionMethod {
    TOURNAMENT,
    ROULETTE
};

enum CrossoverMethod {
    HALVED,
    INTERTWINED
};

enum MutationMethod {
    SWAP,
    INVERT
};

enum ElitismMethod {
    RATIO,
    RANKED
};

struct InputMatrixes {
    std::vector<std::vector<int>> dMatrix;
    std::vector<std::vector<int>> fMatrix;
};

int stringToEnum(std::string str);

class GeneticAlgorithm {
public:
    const int generations = 600;
    const int instanceLimit = 20;
    int spaceSize = 9;
    float elitismRatio = 0.1;
    const float mutationRate = 0.01;
    std::vector<Instance> instances;
    std::vector<std::vector<int>> dMatrix;
    std::vector<std::vector<int>> fMatrix;

    std::function<Instance()> selectionMethod;
    std::function<Instance(Instance, Instance)> crossoverMethod;
    std::function<Instance(Instance)> mutationMethod;
    std::function<void(std::vector<Instance>, std::vector<Instance>)> elitismMethod;

    int selectionMethodIndex;
    int crossoverMethodIndex;
    int mutationMethodIndex;
    int elitismMethodIndex;

    GeneticAlgorithm(
        int selectionMethod,
        int crossoverMethod,
        int mutationMethod,
        int elitismMethod,
        int spaceSize = 9,
        std::optional<InputMatrixes> matrixes = std::nullopt
    );

    void generateInstances();

    static InputMatrixes generateMatrixes(int spaceSize);

    static InputMatrixes readMatrixes(std::string file);

    std::string matrixesToString();

    static void writeMatrixes(std::string file, InputMatrixes matrixes);

    std::string generateLog();

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

    void run(int generations);

    std::vector<float> getAllInstancesFitness();
};
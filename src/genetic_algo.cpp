
#include <genetic_algo.h>

GeneticAlgorithm::GeneticAlgorithm(
    int selectionMethod,
    int crossoverMethod,
    int mutationMethod,
    int elitismMethod,
    std::optional<InputMatrixes> matrixes
) {
    if (matrixes.has_value()) {
        dMatrix = matrixes->dMatrix;
        fMatrix = matrixes->fMatrix;
        spaceSize = dMatrix.size();
    } else {
        InputMatrixes matrixes = generateMatrixes(spaceSize);
        dMatrix = matrixes.dMatrix;
        fMatrix = matrixes.fMatrix;
    }
    generateInstances();
    this->selectionMethod = [selectionMethod, this]() {
        return selectionMethod == 0 ? tournamentSelection() : rouletteSelection();
        };
    this->crossoverMethod = [crossoverMethod, this](std::vector<int> parent1, std::vector<int> parent2) {
        return crossoverMethod == 0 ? halvedCrossover(parent1, parent2) : intertwinedCrossover(parent1, parent2);
        };
    this->mutationMethod = [mutationMethod, this](std::vector<int> instance) {
        return mutationMethod == 0 ? swapMutate(instance) : invertMutate(instance);
        };
    this->elitismMethod = [elitismMethod, this](std::vector<Instance> oldInstances, std::vector<Instance> offspring) {
        return elitismMethod == 0 ? ratioElitism(oldInstances, offspring) : rankedElitism(oldInstances, offspring);
        };
}

void GeneticAlgorithm::generateInstances() {
    for (int i = 0; i < instanceLimit; i++) {
        Instance instance;
        for (int j = 0; j < spaceSize; j++) {
            instance.push_back(j);
        }
        std::shuffle(instance.begin(), instance.end(), std::mt19937(std::random_device()()));
        instances.push_back(instance);
    }
}

InputMatrixes GeneticAlgorithm::readMatrixes(std::string file) {
    std::ifstream input(file);
    std::vector<std::vector<int>> dMatrix;
    std::vector<std::vector<int>> fMatrix;
    int spaceSize;
    input >> spaceSize;
    for (int i = 0; i < spaceSize; i++) {
        dMatrix.push_back(std::vector<int>(spaceSize, 0));
        fMatrix.push_back(std::vector<int>(spaceSize, 0));
    }

    for (int i = 0; i < spaceSize; i++) {
        for (int j = i + 1; j < spaceSize; j++) {
            input >> dMatrix[i][j];
            dMatrix[j][i] = dMatrix[i][j];
            input >> fMatrix[i][j];
            fMatrix[j][i] = fMatrix[i][j];
        }
    }
    input.close();

    return InputMatrixes{ dMatrix, fMatrix };
}

void GeneticAlgorithm::writeMatrixes(std::string file, InputMatrixes matrixes) {
    std::ofstream output(file);
    output << matrixes.fMatrix.size() << "\n";
    for (int i = 0; i < matrixes.fMatrix.size(); i++) {
        for (int j = i + 1; j < matrixes.fMatrix.size(); j++) {
            output << matrixes.dMatrix[i][j] << " ";
            output << matrixes.fMatrix[i][j] << " ";
        }
    }
    output.close();
}

InputMatrixes GeneticAlgorithm::generateMatrixes(int spaceSize) {
    std::vector<std::vector<int>> newdMatrix;
    std::vector<std::vector<int>> newfMatrix;
    for (int i = 0; i < spaceSize; i++) {
        newdMatrix.push_back(std::vector<int>(spaceSize, 0));
        newfMatrix.push_back(std::vector<int>(spaceSize, 0));
    }

    for (int i = 0; i < spaceSize; i++) {
        for (int j = i + 1; j < spaceSize; j++) {
            const int size = 900;
            point a = { std::rand() % size, std::rand() % size };
            point b = { std::rand() % size, std::rand() % size };
            newdMatrix[i][j] = newdMatrix[j][i] = round(sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
            newfMatrix[i][j] = newfMatrix[j][i] = std::rand() % (spaceSize * 2) + 1;
        }
    }

    return InputMatrixes{ newdMatrix, newfMatrix };
}

float GeneticAlgorithm::calculateFitness(Instance& instance) {
    float fitness = 0;
    for (int j = 0; j < spaceSize; j++) {
        for (int k = j + 1; k < spaceSize; k++) {
            fitness += fMatrix[instance[j]][instance[k]] * dMatrix[j][k];
        }
    }
    return fitness;
}

std::vector<float> GeneticAlgorithm::getAllInstancesFitness() {
    std::vector<float> fitnesses;
    for (auto& instance : instances) {
        fitnesses.push_back(calculateFitness(instance));
    }
    return fitnesses;
}

void GeneticAlgorithm::getFittest() {
    Instance fittest = instances[0];
    for (int i = 1; i < instanceLimit; i++) {
        if (calculateFitness(instances[i]) < calculateFitness(fittest)) {
            fittest = instances[i];
        }
    }
}

Instance GeneticAlgorithm::halvedCrossover(Instance parent1, Instance parent2) {
    std::set<int> child;
    child.insert(parent1.begin(), parent1.begin() + parent1.size() / 2);
    child.insert(parent2.begin(), parent2.end());
    return Instance(child.begin(), child.end());
}

Instance GeneticAlgorithm::intertwinedCrossover(Instance parent1, Instance parent2) {
    std::set<int> child;
    int i = 0;
    int j = 0;
    while (child.size() == parent1.size()) {
        while (i < parent1.size() && child.find(parent1[i]) != child.end()) {
            i++;
        }
        if (i < parent1.size()) {
            child.insert(parent1[i]);
        }
        while (j < parent2.size() && child.find(parent2[j]) != child.end()) {
            j++;
        }
        if (j < parent1.size()) {
            child.insert(parent1[j]);
        }
    }

    return Instance(child.begin(), child.end());
}

void GeneticAlgorithm::ratioElitism(std::vector<Instance> oldInstances, std::vector<Instance> offspring) {
    std::vector<float> oldFitnesses = getAllInstancesFitness();
    std::vector<std::pair<float, Instance>> oldFitnessInstances;
    for (int i = 0; i < oldInstances.size(); i++) {
        oldFitnessInstances.push_back({ oldFitnesses[i], oldInstances[i] });
    }

    std::sort(oldFitnessInstances.begin(), oldFitnessInstances.end(), [](
        auto& i, auto& j
        ) {
            return i.first < j.first;
        }
    );

    for (int i = 0; i < oldFitnessInstances.size(); i++) {
        std::cout << oldFitnessInstances[i].first << " ";
    }
    std::cout << "\n";

    std::vector<Instance> newInstances;
    const int k = oldFitnessInstances.size() * elitismRatio;
    for (int i = 0; i < k; i++) {
        newInstances.push_back(oldFitnessInstances[i].second);
    }
    for (int i = 0; i < offspring.size(); i++) {
        newInstances.push_back(offspring[i]);
    }

    newInstances.resize(instanceLimit);
    instances = newInstances;
}

void GeneticAlgorithm::rankedElitism(std::vector<Instance> oldInstances, std::vector<Instance> offspring) {
    std::vector<std::pair<float, Instance>> fitnessInstances;
    for (int i = 0; i < oldInstances.size(); i++) {
        fitnessInstances.push_back({ calculateFitness(oldInstances[i]), oldInstances[i] });
    }

    for (int i = 0; i < offspring.size(); i++) {
        fitnessInstances.push_back({ calculateFitness(offspring[i]), offspring[i] });
    }

    std::sort(fitnessInstances.begin(), fitnessInstances.end(), [&](
        auto& i, auto& j
        ) {
            return i.first < j.first;
        }
    );

    fitnessInstances.resize(instanceLimit);
    std::vector<Instance> newInstances;
    for (auto& fitnessInstance : fitnessInstances) {
        newInstances.push_back(fitnessInstance.second);
    }

    instances = newInstances;
}

Instance GeneticAlgorithm::tournamentSelection() {
    Instance instance1 = instances[std::rand() % instanceLimit];
    Instance instance2 = instances[std::rand() % instanceLimit];
    Instance fittestInstance = calculateFitness(instance1) < calculateFitness(instance2) ? instance1 : instance2;
    return fittestInstance;
}

Instance GeneticAlgorithm::rouletteSelection() {
    std::vector<float> fitnesses = getAllInstancesFitness();
    float totalFitness = 0;
    for (auto& fitness : fitnesses) {
        totalFitness += fitness;
    }

    for (int i = 0; i < fitnesses.size(); i++) {
        fitnesses[i] = totalFitness / fitnesses[i];
    }

    float sum = 0;
    for (int i = 0; i < fitnesses.size(); i++) {
        sum += fitnesses[i];
    }

    for (int i = 0; i < fitnesses.size(); i++) {
        fitnesses[i] = fitnesses[i] / sum;
    }

    float random = std::rand() / RAND_MAX;
    sum = 0;
    for (int i = 0; i < instanceLimit; i++) {
        sum += fitnesses[i];
        if (sum > random) {
            return instances[i];
        }
    }
    return instances[0];
}

Instance GeneticAlgorithm::swapMutate(Instance instance) {
    int i = std::rand() % instance.size();
    int j = std::rand() % instance.size();
    std::iter_swap(instance.begin() + i, instance.begin() + j);
    return instance;
}

Instance GeneticAlgorithm::invertMutate(Instance instance) {
    int i = std::rand() % instance.size();
    int j = std::rand() % instance.size();
    if (i > j) {
        std::swap(i, j);
    }
    std::reverse(instance.begin() + i, instance.begin() + j);
    return instance;
}

void GeneticAlgorithm::nextGeneration() {
    std::cout << "next generation\n";
    std::vector<Instance> offspring;
    const int k = instanceLimit * (elitismRatio);
    for (int i = 0; i < instanceLimit - k; i++) {
        Instance parent1 = selectionMethod();
        Instance parent2 = selectionMethod();
        Instance child = crossoverMethod(parent1, parent2);
        if (float(rand()) / float(RAND_MAX) < mutationRate) {
            child = mutationMethod(child);
        }
        offspring.push_back(child);
    }
    elitismMethod(instances, offspring);
}
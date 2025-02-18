
#include <genetic_algo.h>

GeneticAlgorithm::GeneticAlgorithm() {
    generateInstances();
    generateMatrixes();
}

void GeneticAlgorithm::generateInstances() {
    for (int i = 0; i < instanceLimit; i++) {
        std::vector<int> instance;
        for (int j = 0; j < spaceSize; j++) {
            instance.push_back(j);
        }
        std::shuffle(instance.begin(), instance.end(), std::mt19937(std::random_device()()));
        instances.push_back(instance);
    }
}

void GeneticAlgorithm::generateMatrixes() {
    dMatrix.clear();
    fMatrix.clear();
    for (int i = 0; i < spaceSize; i++) {
        dMatrix.push_back(std::vector<int>(spaceSize, 0));
        fMatrix.push_back(std::vector<int>(spaceSize, 0));
    }

    for (int i = 0; i < spaceSize; i++) {
        for (int j = i + 1; j < spaceSize; j++) {
            const int size = 900;
            point a = { std::rand() % size, std::rand() % size };
            point b = { std::rand() % size, std::rand() % size };
            dMatrix[i][j] = dMatrix[j][i] = round(sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
            fMatrix[i][j] = fMatrix[j][i] = std::rand() % (spaceSize * 2) + 1;
        }
    }
}

float GeneticAlgorithm::calculateFitness(std::vector<int>& instance) {
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
    std::vector<int> fittest = instances[0];
    for (int i = 1; i < instanceLimit; i++) {
        if (calculateFitness(instances[i]) > calculateFitness(fittest)) {
            fittest = instances[i];
        }
    }
}

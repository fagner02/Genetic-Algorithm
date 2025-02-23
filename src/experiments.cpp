#include <experiments.h>

void experiment1(std::string output_file) {
    std::ofstream file(output_file);
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo log.csv\n";
        return;
    }
    file << "iteration,instanceLimit,spaceSize,elitismRatio,mutationRate,selectionMethod,crossoverMethod,mutationMethod,elitismMethod,highestFitness,lowestFitness,averageFitness\n";

    InputMatrixes matrixes = GeneticAlgorithm::generateMatrixes(10);
    for (int i = 0; i < 20; i++) {
        GeneticAlgorithm ga(SelectionMethod::ROULETTE, CrossoverMethod::INTERTWINED, MutationMethod::SWAP, ElitismMethod::RANKED, 10, matrixes);
        ga.run(150);
        GeneticAlgorithm ga2(SelectionMethod::TOURNAMENT, CrossoverMethod::INTERTWINED, MutationMethod::SWAP, ElitismMethod::RANKED, 10, matrixes);
        ga2.run(150);
        std::cout << "instance " << i << " done\n";
        file << i << "," << ga.generateLog();
        file << i << "," << ga2.generateLog();
    }

    file.close();
}

void experiment2(std::string output_file) {
    std::ofstream file(output_file);
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo log.csv\n";
        return;
    }
    file << "iteration,instanceLimit,spaceSize,elitismRatio,mutationRate,selectionMethod,crossoverMethod,mutationMethod,elitismMethod,highestFitness,lowestFitness,averageFitness\n";

    InputMatrixes matrixes = GeneticAlgorithm::generateMatrixes(10);
    for (int i = 0; i < 20; i++) {
        GeneticAlgorithm ga(SelectionMethod::ROULETTE, CrossoverMethod::INTERTWINED, MutationMethod::SWAP, ElitismMethod::RANKED, 10, matrixes);
        ga.run(150);
        GeneticAlgorithm ga2(SelectionMethod::ROULETTE, CrossoverMethod::HALVED, MutationMethod::SWAP, ElitismMethod::RANKED, 10, matrixes);
        ga2.run(150);
        std::cout << "instance " << i << " done\n";
        file << i << "," << ga.generateLog();
        file << i << "," << ga2.generateLog();
    }

    file.close();
}

void experiment3(std::string output_file) {
    std::ofstream file(output_file);
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo log.csv\n";
        return;
    }

    file << "iteration,instanceLimit,spaceSize,elitismRatio,mutationRate,selectionMethod,crossoverMethod,mutationMethod,elitismMethod,highestFitness,lowestFitness,averageFitness\n";

    InputMatrixes matrixes = GeneticAlgorithm::generateMatrixes(10);
    for (int i = 0; i < 20; i++) {
        GeneticAlgorithm ga(SelectionMethod::ROULETTE, CrossoverMethod::INTERTWINED, MutationMethod::SWAP, ElitismMethod::RANKED, 10, matrixes);
        ga.run(150);
        GeneticAlgorithm ga2(SelectionMethod::ROULETTE, CrossoverMethod::INTERTWINED, MutationMethod::SWAP, ElitismMethod::RATIO, 10, matrixes);
        ga2.run(150);
        std::cout << "instance " << i << " done\n";
        file << i << "," << ga.generateLog();
        file << i << "," << ga2.generateLog();
    }
    file.close();
}

void experiment4(std::string output_file) {
    std::ofstream file(output_file);
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo log.csv\n";
        return;
    }

    file << "iteration,instanceLimit,spaceSize,elitismRatio,mutationRate,selectionMethod,crossoverMethod,mutationMethod,elitismMethod,highestFitness,lowestFitness,averageFitness\n";

    InputMatrixes matrixes = GeneticAlgorithm::generateMatrixes(10);
    for (int i = 0; i < 20; i++) {
        GeneticAlgorithm ga(SelectionMethod::ROULETTE, CrossoverMethod::INTERTWINED, MutationMethod::SWAP, ElitismMethod::RANKED, 10, matrixes);
        ga.run(150);
        GeneticAlgorithm ga2(SelectionMethod::ROULETTE, CrossoverMethod::INTERTWINED, MutationMethod::INVERT, ElitismMethod::RANKED, 10, matrixes);
        ga2.run(150);
        std::cout << "instance " << i << " done\n";
        file << i << "," << ga.generateLog();
        file << i << "," << ga2.generateLog();
    }

    file.close();
}

void experiment5(std::string output_file, Parameters parameters[4]) {
    std::ofstream file(output_file);
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo log.csv\n";
        return;
    }

    file << "spaceSize,alg1,alg2,alg3,alg4\n";
    int n = 10;
    while (true) {
        std::stringstream ss;
        file << n << ",";
        InputMatrixes matrixes = GeneticAlgorithm::generateMatrixes(n);
        long highestTime = 0;
        for (int i = 0; i < 4; i++) {
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            GeneticAlgorithm ga(parameters[i].selectionMethod, parameters[i].crossoverMethod, parameters[i].mutationMethod, parameters[i].elitismMethod, n, matrixes);
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            long elapsed_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
            file << elapsed_milliseconds << ",";
            if (elapsed_milliseconds > highestTime) {
                highestTime = elapsed_milliseconds;
            }
        }
        file << "\n";
        if (highestTime > 12000) {
            break;
        }
        n += 5;
    }

    std::ofstream out("experiment5_random_input.txt");

    out.close();
    file.close();
}
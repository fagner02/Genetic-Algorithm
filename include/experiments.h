#include <fstream>
#include <iostream>
#include <structures.h>
#include <chrono>
#include <genetic_algo.h>

#pragma once

struct Parameters {
    int selectionMethod;
    int crossoverMethod;
    int mutationMethod;
    int elitismMethod;
};

void experiment1(std::string output_file);
void experiment2(std::string output_file);
void experiment3(std::string output_file);
void experiment4(std::string output_file);
void experiment5(std::string output_file, Parameters parameters[4]);
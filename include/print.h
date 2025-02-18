#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <chrono>
#include <thread>
#include <structures.h>

#pragma once

void setBlockColors(
    std::vector<std::vector<block>> blocks,
    bool& shouldDraw,
    point next = { -1,-1 }
);

std::string generate_log(
    point start,
    point target,
    int visited_qty,
    int generated_qty,
    std::string algorithm,
    int cost_id,
    int heuristic_id,
    float cost,
    std::vector<int> order = { 0, 1, 2, 3 },
    std::set<point> constraints = {}
);

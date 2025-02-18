#include <SFML/Graphics.hpp>
#include <rectshape.h>
#include <functional>
#include <constants.h>
#include <set>
#include <node.h>

#pragma once

struct block {
    sf::RoundedRectangleShape shape;
    sf::Text text;
    visited_info info;
};

void fill_blocks(std::vector<std::vector<block>> blocks, std::set<point> constraints = {}, point start = { -1,-1 }, point target = { -1,-1 });

void set_block_data(std::vector<std::vector<block>> blocks, node n);

struct label_data {
    sf::Text text;
    sf::RoundedRectangleShape box;
    bool visible = true;
};

struct button {
    label_data* _label;
    std::function<void()> fn;
    bool pressed = false;
};
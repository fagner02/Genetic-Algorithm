#include <SFML/Graphics/Color.hpp>
#include <algorithm>
#include <cmath>

#pragma once

const double D_EPSILON = 0.00000000000001;

struct HSL {
    double Hue;
    double Saturation;
    double Luminance;

    HSL();
    HSL(int H, int S, int L);

    sf::Color TurnToRGB();

private:

    double HueToRGB(double arg1, double arg2, double H);

};

HSL TurnToHSL(const sf::Color& C);
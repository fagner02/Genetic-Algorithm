#include <print.h>

// usado para animar o caminho
void  setBlockColors(
    std::vector<std::vector<block>> blocks,
    bool& shouldDraw,
    point next
) {
    for (int i = 0; i < blocks.size(); i++) {
        for (int j = 0; j < blocks.size(); j++) {
            // if (i == next.x && j == next.y) {
            //     blocks[i][j].shape.setFillColor(sf::Color(255, 0, 0));
            // } else if (blocks[i][j].info.label == "G") {
            //     blocks[i][j].shape.setFillColor(sf::Color(0, 100, 0));
            // } else if (blocks[i][j].info.label == "S") {
            //     blocks[i][j].shape.setFillColor(sf::Color(10, 10, 105));
            // } else if (blocks[i][j].info.label == "T") {
            //     blocks[i][j].shape.setFillColor(sf::Color(230, 150, 15));
            // } else if (blocks[i][j].info.is_path) {
            //     blocks[i][j].shape.setFillColor(sf::Color(100, 100, 200));
            // } else if (blocks[i][j].info.cost != -1) {
            //     blocks[i][j].shape.setFillColor(sf::Color(100, 200, 100));
            // } else {
            //     blocks[i][j].shape.setFillColor(sf::Color(100, 100, 100));
            // }
        }
    }
    shouldDraw = true;

    std::this_thread::sleep_for(std::chrono::milliseconds(10));

}

/// @brief gera um log contendo informações sobre a execução do algoritmo de busca
/// @param start ponto inicial da busca
/// @param target ponto final da busca
/// @param visited_qty quantidade de nós visitados durante a busca
/// @param generated_qty quantidade de nós gerados durante a busca
/// @param algorithm algoritmo de busca utilizado
/// @param cost_id id da função de custo utilizado
/// @param heuristic_id id da função de heuristica utilizado
/// @param cost função de custo
/// @param path caminho encontrado
/// @param order ordem de busca
/// @param constraints posições das farmácias
/// @return string formatada contendo os dados do log
std::string generate_log(
    point start,
    point target,
    int visited_qty,
    int generated_qty,
    std::string algorithm,
    int cost_id,
    int heuristic_id,
    float cost,
    std::vector<int> order,
    std::set<point> constraints
) {
    std::stringstream ss;
    ss << algorithm << "," << visited_qty << "," << generated_qty << ",";

    ss << "[" << start.x << " " << start.y << "], [" << target.x << " " << target.y << "],";
    ss << cost_id << "," << heuristic_id << ",";

    if (cost == -1) {
        ss << "null,";
    } else {
        ss << cost << ",";
    }

    ss << "[" << order[0];
    for (int i = 1; i < 4; i++) {
        ss << " " << order[i];
    }
    ss << "],";
    ss << "[";
    for (auto& p : constraints) {
        ss << "[" << p.x << " " << p.y << "] ";
    }
    ss << "]";
    return ss.str();
}
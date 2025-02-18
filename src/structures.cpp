#include <structures.h>

/// @brief preenche os blocos com as informações iniciais
/// @param blocks parâmetro para animação
/// @param constraints pontos representando as farmácias(ou restrições)
/// @param start ponto inicial da busca
/// @param target ponto final da busca
void fill_blocks(
    std::vector<std::vector<block>> blocks,
    std::set<point> constraints,
    point start,
    point target
) {
    // itera sobre toda a grade de blocos
    for (int i = 0; i < blocks.size(); i++) {
        for (int j = 0; j < blocks.size(); j++) {
            // inicializa as informações do bloco
            // verifica se o bloco é uma restrição
            // if (constraints.find(point{ i, j }) != constraints.end()) {
            //     blocks[i][j].info.label = "G";
            // }
            // // verifica se o bloco é o ponto inicial
            // if (start == point{ i,j }) {
            //     blocks[i][j].info.label = "S";
            // }
            // // verifica se o bloco é o ponto final
            // if (target == point{ i,j }) {
            //     blocks[i][j].info.label = "T";
            // }
        }
    }
}

/// @brief preenche os dados de um bloco com as informações de um nó
/// @param blocks parâmetro para animação
/// @param n nó cujas informações serão utilizadas para preencher o bloco
void set_block_data(std::vector<std::vector<block>> blocks) {
    // atualiza as informações do bloco de acordo com os dados do nó n
    // blocks[n.pos.x][n.pos.y].info.cost = n.data.cost;
    // blocks[n.pos.x][n.pos.y].info.heuristic = n.data.heuristic;
    // blocks[n.pos.x][n.pos.y].info.step = n.data.step;
    // blocks[n.pos.x][n.pos.y].info.from = n.data.from;
}
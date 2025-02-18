#include <experiments.h>

// experimento 1 - busca em largura vs Busca em profundidade vs Busca de custo uniforme(Dijkstra) 
// entrada aleatória
void experiment1(std::string output_file) {
    std::vector<std::vector<block>> blocks;
    bool shouldDraw = false;
    fill_blocks(blocks);
    std::ofstream file(output_file);
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo log.csv\n";
        return;
    }
    file << "algorithm,visited_qty,generated_qty,path_size,path,start,target,cost_id,heuristic_id,cost,order,pharmacies\n";
    std::ofstream out("experiment1_random_input.txt");
    out << "50\n";
    srand((unsigned)time(NULL));


    out.close();
    file.close();
}

// experimento 1 - busca em largura vs Busca em profundidade vs Busca de custo uniforme(Dijkstra) 
// entrada do arquivo .txt
void experiment1(
    std::vector<point> start_points,
    std::vector<point> target_points,
    std::function<void(std::wstring)> toastText,
    std::string output_file
) {
    if (start_points.size() != 50 || target_points.size() != 50) {
        toastText(L"A entrada do experimento 1 deve ter 50 instâncias\n");
        return;
    }
    std::vector<std::vector<block>> blocks;
    bool shouldDraw = false;
    fill_blocks(blocks);
    std::ofstream file(output_file);
    if (!file.is_open()) {
        toastText(L"Erro ao abrir o arquivo log.csv\n");
        return;
    }
    file << "algorithm,visited_qty,generated_qty,path_size,path,start,target,cost_id,heuristic_id,cost,order,pharmacies\n";

    file.close();
}

// experimento 2 - busca de custo uniforme(Dijkstra) vs A*
// entrada aleatória
void experiment2(std::string output_file) {
    std::vector<std::vector<block>> blocks;
    bool shouldDraw = false;
    fill_blocks(blocks);
    std::ofstream file(output_file);
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo log.csv\n";
        return;
    }
    std::ofstream out("experiment2_random_input.txt");
    file << "algorithm,visited_qty,generated_qty,path_size,path,start,target,cost_id,heuristic_id,cost,order,pharmacies\n";

    srand((unsigned)time(NULL));

    out << "50\n";

    out.close();
    file.close();
}

// experimento 2 - busca de custo uniforme(Dijkstra) vs A*
// entrada do arquivo .txt
void experiment2(
    std::vector<point> start_points,
    std::vector<point> target_points,
    std::function<void(std::wstring)> toastText,
    std::string output_file
) {
    if (start_points.size() != 50 || target_points.size() != 50) {
        toastText(L"A entrada do experimento 2 deve ter 50 instâncias\n");
        return;
    }
    std::vector<std::vector<block>> blocks;
    bool shouldDraw = false;
    fill_blocks(blocks);
    std::ofstream file(output_file);
    if (!file.is_open()) {
        toastText(L"Erro ao abrir o arquivo log.csv\n");
        return;
    }
    file << "algorithm,visited_qty,generated_qty,path_size,path,start,target,cost_id,heuristic_id,cost,order,pharmacies\n";

    file.close();
}

// experimento 3 - busca gulosa vs A*
// entrada aleatória
void experiment3(std::string output_file) {
    std::vector<std::vector<block>> blocks;
    bool shouldDraw = false;
    fill_blocks(blocks);
    std::ofstream file(output_file);
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo log.csv\n";
        return;
    }

    file << "algorithm,visited_qty,generated_qty,path_size,path,start,target,cost_id,heuristic_id,cost,order,pharmacies\n";

    srand((unsigned)time(NULL));

    std::ofstream out("experiment3_random_input.txt");
    out << "50\n";

    out.close();
    file.close();
}

// experimento 3 - busca gulosa vs A*
// entrada do arquivo .txt
void experiment3(
    std::vector<point> start_points,
    std::vector<point> target_points,
    std::function<void(std::wstring)> toastText,
    std::string output_file
) {
    if (start_points.size() != 50 || target_points.size() != 50) {
        toastText(L"A entrada do experimento 3 deve ter 50 instâncias\n");
        return;
    }
    std::vector<std::vector<block>> blocks;
    bool shouldDraw = false;
    fill_blocks(blocks);
    std::ofstream file(output_file);
    if (!file.is_open()) {
        toastText(L"Erro ao abrir o arquivo log.csv\n");
        return;
    }

    file << "algorithm,visited_qty,generated_qty,path_size,path,start,target,cost_id,heuristic_id,cost,order,pharmacies\n";

    srand((unsigned)time(NULL));

    file.close();
}

// experimento 4 - busca em largura vs Busca em profundidade vs Busca em profundidade com randomização da vizinhança
// entrada do arquivo aleatória
void experiment4(std::string output_file) {
    std::vector<std::vector<block>> blocks;
    bool shouldDraw = false;
    fill_blocks(blocks);
    std::ofstream file(output_file);
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo log.csv\n";
        return;
    }

    file << "algorithm,visited_qty,generated_qty,path_size,path,start,target,cost_id,heuristic_id,cost,order,pharmacies\n";

    srand((unsigned)time(NULL));

    std::ofstream out("experiment4_random_input.txt");
    out << "20\n";

    out.close();
    file.close();
}

// experimento 4 - busca em largura vs Busca em profundidade vs Busca em profundidade com randomização da vizinhança
// entrada do arquivo .txt
void experiment4(
    std::vector<point> start_points,
    std::vector<point> target_points,
    std::vector<std::vector<int>> orders,
    std::function<void(std::wstring)> toastText,
    std::string output_file
) {
    if (start_points.size() != 20 || target_points.size() != 20 || orders.size() != 20) {
        toastText(L"A entrada do experimento 4 deve ter 20 instâncias\n");
        return;
    }
    std::vector<std::vector<block>> blocks;
    bool shouldDraw = false;
    fill_blocks(blocks);
    std::ofstream file(output_file);
    if (!file.is_open()) {
        toastText(L"Erro ao abrir o arquivo log.csv\n");
        return;
    }

    file << "algorithm,visited_qty,generated_qty,path_size,path,start,target,cost_id,heuristic_id,cost,order,pharmacies\n";


    file.close();
}

// experimento 5 - caminho mínimo com uma parada a mais
// entrada do arquivo aleatória
void experiment5(std::string output_file) {
    std::vector<std::vector<block>> blocks;
    bool shouldDraw = false;
    fill_blocks(blocks);
    std::ofstream file(output_file);
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo log.csv\n";
        return;
    }

    file << "algorithm,visited_qty,generated_qty,path_size,path,start,target,cost_id,heuristic_id,cost,order,pharmacies\n";

    srand((unsigned)time(NULL));

    std::ofstream out("experiment5_random_input.txt");
    out << "25\n";

    out.close();
    file.close();
}

// experimento 5 - caminho mínimo com uma parada a mais
// entrada do arquivo .txt
void experiment5(
    std::vector<point> start_points,
    std::vector<point> target_points,
    std::vector<std::vector<int>> orders,
    std::vector<std::set<point>> constraints,
    std::function<void(std::wstring)> toastText,
    std::string output_file
) {
    if (start_points.size() != 25 || target_points.size() != 25 || orders.size() != 25 || constraints.size() != 25) {
        toastText(L"A entrada do experimento 5 deve ter 25 instâncias\n");
        return;
    }
    std::vector<std::vector<block>> blocks;
    bool shouldDraw = false;
    fill_blocks(blocks);
    std::ofstream file(output_file);
    if (!file.is_open()) {
        toastText(L"Erro ao abrir o arquivo log.csv\n");
        return;
    }

    file << "algorithm,visited_qty,generated_qty,path_size,path,start,target,cost_id,heuristic_id,cost,order,pharmacies\n";

    file.close();
}

#include <iostream>
#include <algorithm>
#include <fstream>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <unordered_set>

int main() {
    std::ifstream my_file("input.txt");
    std::string buff;
    std::map<int, std::vector<int>> btf, ftb;
    
    // Read the ordering rules
    while (getline(my_file, buff)) {
        if (buff.empty()) break;
        int first = (buff[0] - '0') * 10 + (buff[1] - '0');
        int second = (buff[3] - '0') * 10 + (buff[4] - '0');
        btf[first].push_back(second);
    }

    int part_1_res = 0;
    int part_2_res = 0;

    while (my_file >> buff) {
        std::vector<int> temp;
        for (int i = 0; i < buff.size(); i += 3) {
            temp.push_back((buff[i] - '0') * 10 + (buff[i + 1] - '0'));
        }

        // Check if the update is in the correct order
        bool correct = true;
        for (int i = 0; i < temp.size(); i++) {
            for (int j = i + 1; j < temp.size(); j++) {
                if (std::find(btf[temp[j]].begin(), btf[temp[j]].end(), temp[i]) != btf[temp[j]].end()) {
                    correct = false;
                    break;
                }
            }
            if (!correct) break;
        }

        if (correct) {
            part_1_res += temp[temp.size() / 2];
        } else {
            // Reorder using topological sort
            std::map<int, int> in_degree;
            std::map<int, std::vector<int>> adj_list;
            std::unordered_set<int> nodes(temp.begin(), temp.end());

            // Build adjacency list and in-degree for nodes in temp
            for (int node : nodes) {
                in_degree[node] = 0;
            }
            for (int node : nodes) {
                for (int neighbor : btf[node]) {
                    if (nodes.count(neighbor)) {
                        adj_list[node].push_back(neighbor);
                        in_degree[neighbor]++;
                    }
                }
            }

            // Perform topological sort
            std::queue<int> q;
            for (const auto& [node, degree] : in_degree) {
                if (degree == 0) q.push(node);
            }

            std::vector<int> sorted;
            while (!q.empty()) {
                int current = q.front();
                q.pop();
                sorted.push_back(current);

                for (int neighbor : adj_list[current]) {
                    in_degree[neighbor]--;
                    if (in_degree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }

            part_2_res += sorted[sorted.size() / 2];
        }
    }

    std::cout << "Part 1: " << part_1_res << std::endl;
    std::cout << "Part 2: " << part_2_res << std::endl;
}


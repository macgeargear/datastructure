#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

map<int, int> score;
map<int, set<pai<int, in>>> board_score;
map<int, multiset<int>> player_boards;

void increase_score(int player_id, int score) {
    for (auto board_id : player_boards[player_id]) {
        auto it =
            board_score[board_id].find(make_pair(score[player_id], player_id));
    }
}
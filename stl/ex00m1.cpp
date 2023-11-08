#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Chef {
    int finish_time;
    int seat_number;
};

struct CompareChef {
    bool operator()(const Chef& c1, const Chef& c2) {
        return c1.finish_time > c2.finish_time;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> chef_times(N);
    for (int i = 0; i < N; ++i) {
        cin >> chef_times[i];
    }

    priority_queue<Chef, vector<Chef>, CompareChef> available_seats;

    for (int i = 0; i < N; ++i) {
        available_seats.push({0, i});
    }

    vector<int> seating_times(M);

    for (int i = 0; i < M; ++i) {
        Chef chef = available_seats.top();
        available_seats.pop();

        int seating_time =
            max(chef.finish_time, i < N ? 0 : seating_times[i - N]);
        int finish_time = seating_time + chef_times[chef.seat_number];

        seating_times[i] = seating_time;
        available_seats.push({finish_time, chef.seat_number});
    }

    for (int i = 0; i < M; ++i) {
        cout << seating_times[i] << endl;
    }

    return 0;
}

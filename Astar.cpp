#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using GameState = vector<vector<int>>;

using Coord = pair<int, int>;

int manhattenDistance(Coord p1, Coord p2)
{
    return (abs(p1.first - p2.first) + abs(p1.second - p2.second));
}

void printAllState(GameState state)
{
    for (const auto &row : state)
    {
        for (auto cell : row)
        {
            cout << cell << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

vector<GameState> A_star(GameState start, GameState goal)
{
    vector<Coord> movements = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // create a queue to add the states
    priority_queue<pair<int, GameState>, vector<pair<int, GameState>>, greater<pair<int, GameState>>> openSet;

    // create a parent->child relation;
    map<GameState, GameState> predicessor;

    // create a map to map the gscore to state;
    map<GameState, int> gscore;

    // push the start state with h(n);
    openSet.push({manhattenDistance({0, 0}, {2, 2}), start});
    gscore[start] = 0;

    while (!openSet.empty())
    {
        GameState current = openSet.top().second;
        openSet.pop();

        // if goal state is reached
        if (current == goal)
        {
            vector<GameState> final;
            while (current != start)
            {
                final.push_back(current);
                current = predicessor[current];
            }

            final.push_back(current);
            reverse(final.begin(), final.end());
            return final;
        }

        Coord emptyCell;

        for (int i = 0; i < current.size(); i++)
        {
            for (int j = 0; j < current[i].size(); ++j)
            {
                if (current[i][j] == 0)
                {
                    emptyCell = {i, j};
                    break;
                }
            }
        }

        for (auto movement : movements)
        {
            int newRow = emptyCell.first + movement.first;
            int newCol = emptyCell.second + movement.second;

            if (newRow >= 0 && newCol >= 0 && newRow < current.size() && newCol < current[0].size())
            {
                // make a copy of current and make changes;
                GameState neighbour = current;

                // swap the empty cell with the new coordinates;
                swap(neighbour[newRow][newCol], neighbour[emptyCell.first][emptyCell.second]);

                // calculate the temporary gscore;
                int gScore = gscore[current] + 1;

                // Check if the gscore already exists
                if (gscore.find(neighbour) == gscore.end() || gScore < gscore[neighbour])
                {
                    gscore[neighbour] = gScore;

                    predicessor[neighbour] = current;

                    int fscore = gScore + manhattenDistance({newRow, newCol}, {2, 2});
                    openSet.push({fscore, neighbour});
                }
            }
        }
    }

    return {};
}

int main()
{
    GameState start = {{8, 7, 6}, {5, 4, 3}, {2, 1, 0}};
    GameState goal = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    // GameState start = {{1, 2, 3}, {8, 0, 4}, {7, 6, 5}};
    // GameState goal = {{2, 8, 1}, {0, 4, 3}, {7, 6, 5}};

    vector<GameState> final = A_star(start, goal);

    if (final.size() == 0)
    {
        cout << "No Possible Path Found\n";
    }
    else
    {
        for (const auto &state : final)
        {
            printAllState(state);
        }
    }
}

// f(n) = g(n) + h(n);
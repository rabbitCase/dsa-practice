//Leetcode Easy 733
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor == color) return image; // Avoid infinite loop

        queue<pair<int, int>> q;
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), 0));
        recurfill(image, q, sr, sc, visited, originalColor);

        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            image[x.first][x.second] = color;
        }
        return image;
    }

    void recurfill(vector<vector<int>>& image, queue<pair<int, int>>& q, int sr, int sc,
                   vector<vector<int>>& visited, int originalColor) {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()) return;
        if (visited[sr][sc] == 1 || image[sr][sc] != originalColor) return;

        visited[sr][sc] = 1;
        q.push({sr, sc});

        recurfill(image, q, sr - 1, sc, visited, originalColor);
        recurfill(image, q, sr + 1, sc, visited, originalColor);
        recurfill(image, q, sr, sc - 1, visited, originalColor);
        recurfill(image, q, sr, sc + 1, visited, originalColor);
    }
};
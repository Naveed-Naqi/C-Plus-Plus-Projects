#include <queue>
#include <iostream>
#include <vector>
#include <queue>

struct Node
{
    const int row_;
    const int col_;

    Node(int row, int col) : row_(row), col_(col) {}
    Node() : row_(-1), col_(-1) {} 
};

bool isValid(Node* next_pos, const std::vector<std::vector<bool> > &visited, const std::vector<std::vector<int> > &maze)
{
    const int MAX_ROWS = maze.size();
    const int MAX_COLS = maze[0].size();

    return (next_pos->row_ >= 0 && next_pos->col_ >= 0 && next_pos->row_ < MAX_ROWS && next_pos->col_ < MAX_COLS && maze[next_pos->row_][next_pos->col_] != 2 && !visited[next_pos->row_][next_pos->col_]);
}

Node* checkDirection(const Node *curr_pos, const Node &direction)
{
    Node* next_pos = new Node(curr_pos->row_ + direction.row_, curr_pos->col_ + direction.col_);
    return next_pos;
}

int shortestPath(std::vector<std::vector<int> > &maze, int source_x, int source_y, int dest_x, int dest_y)
{
    if(source_x == dest_x && source_y == dest_y)
    {
        return 0;
    }

    int counter = 1;

    const int MAX_ROWS = maze.size();
    const int MAX_COLS = maze[0].size();

    std::vector<std::vector<bool> > visited (MAX_ROWS, std::vector<bool>(MAX_COLS, false));
    std::queue<Node*> curr_path;

    Node LEFT(-1, 0);
    Node RIGHT(1, 0);
    Node UP(0, 1);
    Node DOWN(0, -1);

    Node directions[4] = {LEFT, RIGHT, UP, DOWN};

    while(!curr_path.empty())
    {
        Node* curr_pos = curr_path.front();
        bool found_direction = false;

        for(int i = 0; i < 4; i++)
        {
            Node* next_pos = checkDirection(curr_pos, directions[i]);

            if(isValid(next_pos, visited, maze))
            {
                curr_path.push(next_pos);
                visited[next_pos->row_][next_pos->col_] = true;
                found_direction = true;
                counter++;
            }
        }

        if(!found_direction)
        {
            curr_path.pop();
        }
    }
}
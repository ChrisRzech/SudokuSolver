#include "Sudoku.hpp"

void Sudoku::setValue(int row, int col, int value)
{
    board[row][col] = value;
}

std::optional<int> Sudoku::getValue(int row, int col) const
{
    return board[row][col];
}
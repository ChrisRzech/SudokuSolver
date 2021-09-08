#include "Sudoku.hpp"

void Sudoku::setValue(int row, int col, int value)
{
    if(0 < value && value <= Sudoku::BOARD_SIZE)
        m_board[row][col] = value;
}

std::optional<int> Sudoku::getValue(int row, int col) const
{
    return m_board[row][col];
}
#pragma once
#include <array>
#include <optional>

class Sudoku
{
public:
    static constexpr int BOARD_SIZE = 9;
    static constexpr int BOX_SIZE = 3;
    
    void setValue(int row, int col, int value);
    std::optional<int> getValue(int row, int col) const;

private:
    std::array<std::array<std::optional<int>, BOARD_SIZE>, BOARD_SIZE> board;
};
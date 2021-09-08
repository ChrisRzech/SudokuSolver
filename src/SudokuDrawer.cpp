#include "SudokuDrawer.hpp"
#include <iostream>

SudokuDrawer::SudokuDrawer(const Sudoku& sudoku)
    : m_sudoku{sudoku}
{
    //Do nothing
}

SudokuDrawer::SudokuDrawer(const Sudoku& sudoku, sf::Vector2f position, sf::Vector2u size)
    : m_sudoku{sudoku}, position{position}, size{size}
{
    //Do nothing
}

std::pair<int, int> SudokuDrawer::convertPointToCell(sf::Vector2f point) const
{
    float spacingX = size.x / Sudoku::BOARD_SIZE;
    float spacingY = size.y / Sudoku::BOARD_SIZE;
    
    point -= position;
    
    return std::make_pair(point.x / spacingX, point.y / spacingY);
}

void SudokuDrawer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::VertexArray lines(sf::Lines, (Sudoku::BOARD_SIZE - 1) * 2);
    float spacingX = size.x / Sudoku::BOARD_SIZE;
    float spacingY = size.y / Sudoku::BOARD_SIZE;
    float startingX = spacingX + position.x;
    float startingY = spacingY + position.y;
    
    for(int i = 0; i < Sudoku::BOARD_SIZE - 1; i++)
    {
        sf::Color color = (i % Sudoku::BOX_SIZE == Sudoku::BOX_SIZE - 1 ? sf::Color::White : sf::Color{50, 50, 50});
        
        /* Vertical line */
        lines.append(sf::Vertex{sf::Vector2f{startingX + spacingX * i, position.y}, color});
        lines.append(sf::Vertex{sf::Vector2f{startingX + spacingX * i, position.y + size.y}, color});
        
        /* Horizontal line */
        lines.append(sf::Vertex{sf::Vector2f{position.x, startingY + spacingY * i}, color});
        lines.append(sf::Vertex{sf::Vector2f{position.x + size.x, startingY + spacingY * i}, color});
    }
    
    target.draw(lines);
}
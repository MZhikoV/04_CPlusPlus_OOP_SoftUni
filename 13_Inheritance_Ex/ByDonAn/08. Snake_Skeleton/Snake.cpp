#include "Snake.h"

using namespace std;

        Snake::Snake(const int fieldRows, const int fieldCols, const Point & startPos) :
        _FIELD_ROWS(fieldRows), _FIELD_COLS(fieldCols), _currPos(startPos), _snakeNodes(1,startPos) {};

        Snake::~Snake() {};

        std::deque<Point> & Snake::getSnakeNodes() {
            return _snakeNodes;
        };


        bool updateSnakePosition(Direction dir, int ySize, int xSize, Point & point, const vector<Point> & obstacles) {
            
            //update snake position
            switch (dir)
                {
                case Direction::UP:     point.row--;    break;
                case Direction::DOWN:   point.row++;    break;
                case Direction::LEFT:   point.col--;    break;
                case Direction::RIGHT:  point.col++;    break;
                }

            //check if the snake is still in the field
            if(point.row>=ySize || point.col>=xSize || point.row<0 || point.col<0) {
                return false; //snake is dead /out of field
            };

            //check if the snake head hits an obstacle
            for(auto a:obstacles) {
                if (a==point) {
                    return false; //snake is dead
                };
            };

            return true; //position of the snake head is correct
        };

        //chak function to see if the snake has eaten a powerUp
        bool eatenPowerUp(vector<Point> & powerUps, const Point & newHead) {
            for (auto p=powerUps.begin(); p!=powerUps.end(); p++) {
                if (*p==newHead) {
                    //a power up is eaten
                    powerUps.erase(p);
                    return true;
                };
            };
            return false;
        };





        StatusCode Snake::move(const Direction dir, const std::vector<Point> & obstacles, std::vector<Point> & powerUps) {
            
            if (!updateSnakePosition(dir, _FIELD_ROWS, _FIELD_COLS, _currPos ,obstacles)) {
                return StatusCode::SNAKE_DEAD;
            };

            _snakeNodes.push_front(_currPos); //at this time the body length of the snake is temporarly longer with one element

            //check if the snake bites its body
            for (auto a=_snakeNodes.begin()+1; a!=_snakeNodes.end(); a++) {
                if (*a==_currPos) {
                    return StatusCode::SNAKE_DEAD;
                }
            };

            if (eatenPowerUp(powerUps, _currPos)) {
                return StatusCode::SNAKE_GROWING;
            }
            else {
                _snakeNodes.pop_back(); //the last element of the body position is deleted, ex. the tail is moving after the snake, no power up eaten
            };

            return StatusCode::SNAKE_MOVING;
        };




/*
    private:
        const int         _FIELD_ROWS;
        const int         _FIELD_COLS;

        Point             _currPos;

        std::deque<Point> Snake::_snakeNodes; //holds snake head + body nodel
*/
#pragma once

#include <queue>
#include <memory>
#include <vector>

class Entity; // forward declaration

/**
 * @brief Manages turn order of entities during combat
 * 
 * This class stores entities in a FIFO queue and provides methods
 * which initalizes, retrieves and chekcs the turn order
 */


class TurnQueue {

    private:

    // queue holding entities in the order of their turns
    std::queue<std::shared_ptr<Entity>> m_queue;

    public:

    // Initializes the turn queue with given participants
    void initalize(const std::vector<std::shared_ptr<Entity>>& participants);
    
    // Return next entity in the queue and moves to the back
    std::shared_ptr<Entity> next();

    //Checks if turn queue is empty
    bool isEmpty() const;
};

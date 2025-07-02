/**
 * queue_turn.cpp
 * 
 * Implementation of TurnQueue class which is responsible for the turn order managment.
 * 
 * Author: Schmablo
 * Date: 2025-06-28
 */

#include "combat_system/queue_turn.hpp" 

/**
 * Initializes turn queue with the given participants
 * (they are added in the order they appear in vector)
 */

void TurnQueue::initalize(const std::vector<std::shared_ptr<Entity>>& participants) {
    
    for (const auto& participant : participants){
        m_queue.push(participant);
    }
}

/**
 * Returns next entity in the turn order and moves it to the back
 * IF empty returns nullptr
 * 
 * @param tq - turn queue shortcut
 */
std::shared_ptr<Entity> TurnQueue::next(){

    if (m_queue.empty()) return nullptr;
    else 
    {
        auto tq = m_queue.front();
        m_queue.push(tq);
        m_queue.pop();
        return tq;
    }
}

/**
 * Checks if queue is empty - if so returns ture, otherwise false (quite obvious)
 */
bool TurnQueue::isEmpty() const {

    if (m_queue.empty()) return true;
    else return false;
}
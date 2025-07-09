/**
 * combat_manager.cpp
 * 
 * Implementation of CombatManager class which is responsible for main combat logic
 * 
 * Author: Schmablo
 * Date: 2025-07-06 - . . .
 * Status: In Progress
 */

#include "combat_system/combat_manager.hpp"

// Constructor initializes CombatManager with a TurnQueue and sets combat as inactive
CombatManager::CombatManager(std::unique_ptr<TurnQueue> turnQueue) 
: m_turnQueue(std::move(turnQueue)), m_active(false) {};

/**
 * =========== Methods for combat logic ===========
 */


/**
 * Stars combat by initializing TurnQueue with provided participants
 * and marking the combat as ACTIVE.
 */
void CombatManager::startCombat(std::vector<std::shared_ptr<Entity>> participants) {
    
    m_turnCount = 0; // !!! for testing !!!
    m_turnQueue->initalize(participants);
    m_active = true;
}

/**
 * Executes a single turn in the combat.
 * If combat has ended or queue is empty - combat ends.
 * Otheriwse - advances to the next entity in FIFO queue.
 * 
 * !!! m_turnCount and m_maxTurns is just for testing !!!
 */
void CombatManager::executeTurn() {

    if(!m_active || m_turnQueue->isEmpty() || m_turnCount >= m_maxTurns)
    {
        endCombat();
        return;
    }

    m_turnQueue->next(); // ... and next entity goes
    m_turnCount++; // !!! for testing (again...)!!!
}

// End the combat by setting the active flag to FALSE
void CombatManager::endCombat() {

    m_active = false;
}

void CombatManager::runCombatLoop(std::vector<std::shared_ptr<Entity>> participants) {

    startCombat(participants);

    while (isActive()) { executeTurn(); }
};


/**
 * Checks if combat is still active
 * 
 * @return true if combat ongoing - false if not.
 */
bool CombatManager::isActive() const {

    return m_active;
}
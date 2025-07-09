#pragma once

#include <memory>

#include "queue_turn.hpp"
#include "observer/observer.hpp"

/**
 * CombatManager is the main orchestrator of combat-related operations.
 * It manages turn order (via TurnQueue), combat lifecycle (start/end),
 * and provides interface to execute single turns.
 */
class CombatManager {

    private:

    // Pointer to turn queue manager (controls order of participants)
    std::unique_ptr<TurnQueue> m_turnQueue;

    // Combat state flag (true if combat is ongoing)
    bool m_active;

    // Placeholders for testing
    int m_maxTurns = 5;
    int m_turnCount = 0;

    public:
    /**
     * Constructor of CombatManager with provided TurnQueue
     * 
     * @param turnQueue = unique_ptr to an instance of TurnQueue
     */
    CombatManager(std::unique_ptr<TurnQueue> turnQueue);

    /**
     * Starts the combat loop and initializes TurnQueue
     * 
     * @param participants = list of entities participating in the combat
     */
    void startCombat(std::vector<std::shared_ptr<Entity>> participants);
    
    /**
     * Execs a single turn of combat.
     * If queue = empty or combat ended - triggers endCombat().
     */
    void executeTurn();

    // End combat and marks it as inactive
    void endCombat();

    // Runs combat loop until combat is marked as INACTIVE
    void runCombatLoop(std::vector<std::shared_ptr<Entity>> participants);

    // Returns true if combat active, false otherwise.
    bool isActive() const;
};


/**
 * PLAN
 * 
 * startCombat(participants)
 * 
 * while(!isCombatOver()) {
 *     exectueTurn()
 * }
 * 
 * notify("combat_ended", "Combat has ended")
 */
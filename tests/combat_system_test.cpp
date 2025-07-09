#include <gtest/gtest.h>
#include "combat_system/combat_manager.hpp"
#include "combat_system/queue_turn.hpp"
#include "entity.hpp"

TEST(CombatManagerTest, RunCombatLoopEndsCorrectly) {

    //create TurnQueue and CombatManager
    auto turnQueue = std::make_unique<TurnQueue>();
    CombatManager cm(std::move(turnQueue));

    //create entities
    auto e1 = std::make_shared<Entity>("Dog", 100);
    auto e2 = std::make_shared<Entity>("Cat", 80);

    std::vector<std::shared_ptr<Entity>> participants = {e1, e2};

    // Run combat

    cm.runCombatLoop(participants);

    // After combat loop finishes, combat should be inactive
    EXPECT_FALSE(cm.isActive());
}

//Checking what happens when runCombatLoop() runs with empty vector
TEST(CombatManagerTest, RunCombatLoopWithNoParticipantsEndsImmediatly) {
    auto turnQueue = std::make_unique<TurnQueue>();
    CombatManager cm(std::move(turnQueue));

    std::vector<std::shared_ptr<Entity>> participants = {}; // no entities

    cm.runCombatLoop(participants);

    EXPECT_FALSE(cm.isActive());
}
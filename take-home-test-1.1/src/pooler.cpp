//Copyright 2K Games, Engineering Graduate Program. All rights reserved. DO NOT redistribute.

#include "pooler.h"
#include <algorithm>  // For std::remove

// sets initial number of enemies on the pool
Pooler::Pooler(size_t initialPoolSize) {
    for (size_t i = 0; i < initialPoolSize; ++i) {
        allEnemies.push_back(new Enemy());
    }
}

// destructor method - clears pool
Pooler::~Pooler() {
    for (Enemy *enemy : allEnemies) {
        delete enemy;
    }
    allEnemies.clear();
}

// clear all inactive enemies
void Pooler::Clear() {
    for (Enemy *enemy : allEnemies) {
        enemy->Deactivate();
    }
    activeEnemies.clear();
}

// activates inactive enemy from the pool to be used on the grid, or else creates a new one
Enemy *Pooler::SpawnEnemy(const Vector2D &position) {
    for (Enemy *enemy : allEnemies) {
        if (!enemy->IsActive()) {
            enemy->Activate(position);
            activeEnemies.push_back(enemy);
            return enemy;
        }
    }

    Enemy *newEnemy = new Enemy();
    newEnemy->Activate(position);
    allEnemies.push_back(newEnemy);
    activeEnemies.push_back(newEnemy);
    return newEnemy;
}

// despawn an enemy (active) and makes it inactive to recycle if needed
void Pooler::DespawnEnemy(Enemy *enemy) {
    if (enemy->IsActive()) {
        enemy->Deactivate();
        activeEnemies.erase(std::remove(activeEnemies.begin(), activeEnemies.end(), enemy), activeEnemies.end());
    }
}


std::vector<Enemy *> Pooler::GetActiveEnemies() const {
    return activeEnemies;
}

size_t Pooler::PoolSize() const {
    return activeEnemies.size();
}
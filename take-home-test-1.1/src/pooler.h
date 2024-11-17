//Copyright 2K Games, Engineering Graduate Program. All rights reserved. DO NOT redistribute.

#pragma once

#include <vector>
#include "enemy.h"

class Pooler {
public:
    explicit Pooler(size_t initialPoolSize = 100);
    ~Pooler();

    size_t PoolSize() const;

    void Clear();
    Enemy *SpawnEnemy(const Vector2D &position);
    void DespawnEnemy(Enemy *enemy);
    std::vector<Enemy *> GetActiveEnemies() const;

private:
    std::vector<Enemy *> allEnemies;
    std::vector<Enemy *> activeEnemies;
};

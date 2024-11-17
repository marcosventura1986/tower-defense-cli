//Copyright 2K Games, Engineering Graduate Program. All rights reserved. DO NOT redistribute.

#pragma once

#include <vector>
#include "vector2d.h"
#include "bullet.h"
#include "enemy.h"
#include "texture.h"

class Tower {
private:


    bool autoFire;      // sets auto fire on or off
    int rateOfFire;     // frequency of shots

public:
    Texture texture;    // Tower's visual representation
    Vector2D position;  // Tower position on the grid

    Tower(int x, int y, int fireRate);

    void Update(const std::vector<Enemy *> &enemies, std::vector<Bullet> &bullets) const;
    void ManualFire(const std::vector<Enemy *> &enemies, std::vector<Bullet> &bullets);

    void SetAutoFire(bool enable);
    bool GetAutoFire() const;

    Vector2D GetPosition() const;
    const Texture &GetTexture() const;

private:
    void FireBullet(const Vector2D &target, std::vector<Bullet> &bullets) const;
};

//Copyright 2K Games, Engineering Graduate Program. All rights reserved. DO NOT redistribute.

#include "tower.h"

//render tower at a random position on the screen
Tower::Tower(int x, int y, int fireRate)
    : position(x, y), texture('T', Color::YELLOW), autoFire(false), rateOfFire(fireRate) {}


void Tower::Update(const std::vector<Enemy *> &enemies, std::vector<Bullet> &bullets) const {
    if (!autoFire) return; // skip if auto-fire is disabled

    if (!enemies.empty()) {
        // finds the closest enemy to shoot
        Enemy* closestEnemy = enemies.front();
        FireBullet(closestEnemy->GetPosition(), bullets);
    }
}

// Allow manual control for firing
void Tower::ManualFire(const std::vector<Enemy *> &enemies, std::vector<Bullet> &bullets) {
    if (!enemies.empty()) {
        FireBullet(enemies.front()->GetPosition(), bullets);
    }
}

// Set whether the tower should auto-fire
void Tower::SetAutoFire(bool enable) {
    autoFire = enable;
}

// Get the auto-fire status
bool Tower::GetAutoFire() const {
    return autoFire;
}

// Get the tower's position
Vector2D Tower::GetPosition() const {
    return position;
}

// Get the tower's texture for rendering
const Texture &Tower::GetTexture() const {
    return texture;
}

// Create and fire a bullet toward a target
void Tower::FireBullet(const Vector2D &target, std::vector<Bullet> &bullets) const {
    bullets.emplace_back(GetPosition(), target); // Create a new bullet at the tower's position
}

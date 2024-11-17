//Copyright 2K Games, Engineering Graduate Program. All rights reserved. DO NOT redistribute.

#include "bullet.h"
#include <cmath>

// start bullet at tower's position and set direction and velocity
Bullet::Bullet(Vector2D startPos, Vector2D targetPos)
    : bullet_position(startPos), velocity(BULLET_VELOCITY) {
    // Calculate the direction vector (target - start)
    double deltaX = targetPos.x - startPos.x;
    double deltaY = targetPos.y - startPos.y;

    // Calculate magnitude (distance between start and target)
    double magnitude = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    // Normalize direction (make it unit length)
    direction.x = deltaX / magnitude;
    direction.y = deltaY / magnitude;
}

// get position
Vector2D Bullet::GetPosition() const {
    return bullet_position;
}

// get direction
Vector2D Bullet::GetDirection() const {
    return direction;
}

// update position
void Bullet::Update() {
    // Move the bullet in the direction of its target
    bullet_position.x += direction.x * velocity;
    bullet_position.y += direction.y * velocity;
}
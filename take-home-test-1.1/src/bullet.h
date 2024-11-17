//Copyright 2K Games, Engineering Graduate Program. All rights reserved. DO NOT redistribute.

#ifndef BULLET_H
#define BULLET_H

#include "color.h"
#include "constants.h"
#include "vector2d.h"
#include "texture.h"

// A class to represent a bullet in the game.
//
// This class manages the state of a bullet, including its position, direction,
// and movement. Rendering of bullets is handled by the game's rendering system.
class Bullet {
public:
    // Visual representation of the bullet
    Texture texture = Texture('o', Color::BLUE);

    // Constructor: Initialize a bullet with starting position and target position
    Bullet(Vector2D startPos, Vector2D targetPos);

    // Get the current position of the bullet
    Vector2D GetPosition() const;

    // Get the direction of the bullet
    Vector2D GetDirection() const;

    // Update the bullet's position
    void Update();

private:
    Vector2D bullet_position;    // Current position of the bullet
    Vector2D direction;   // Normalized direction the bullet moves in
    double velocity;      // Speed of the bullet
};

#endif  // BULLET_H

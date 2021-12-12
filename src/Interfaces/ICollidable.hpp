#pragma once
#ifndef _COLLIDABLE_INTERFACE_
#define _COLLIDABLE_INTERFACE_

/**
 * @brief Unused interface for collisionsystem
 *
 */
class ICollidable {
public:
    enum EntityType {
        character,
        projectile,
        tile,

    };
    // we use these function to retrieve collision relevant information
    // virtual sf::Vector2f GetPosition() = 0; // objects have position
    virtual sf::FloatRect GetBoundingBox() = 0; // objects have a size

    // using this function, we notify the object that it collided with something else
    virtual void ProcessCollision(ICollidable* other) = 0;

    virtual EntityType GetEntityType() = 0;

    virtual ~ICollidable() {};
};

#endif

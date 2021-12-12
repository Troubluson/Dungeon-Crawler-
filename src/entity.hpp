#pragma once

#ifndef _ENTITY_CLASS_
#define _ENTITY_CLASS_
class Entity {
public:
    /**
     * @brief Construct a new game Entity
     *
     * @param    spriteLocation       path to the sprite
     * @param    xPos                 x-choord for left side
     * @param    yPos                 y-choord for top
     * @param    spriteDims           !scaling of sprite!
     */
    Entity(const std::string& spriteLocation, float xPos, float yPos, sf::Vector2f spriteDims);
    Entity(const std::string& spirteLocation, sf::Vector2f pos, sf::Vector2f spriteDims);
    Entity(sf::Sprite& sprite, float xPos, float yPos);
    Entity(sf::Sprite& sprite, sf::Vector2f pos);

    virtual ~Entity() {};

    /**
     * @brief Get the entity's sprite
     *
     * @return const sf::Sprite&
     */
    const sf::Sprite& GetSprite() const { return sprite_; };

    /**
     * @brief Get the entity position as a Vector2f
     *
     * @return const sf::Vector2f&
     */
    const sf::Vector2f& GetPos() const { return pos_; }

    /**
     * @brief Get the entity postions
     *
     * @return const sf::Vector2i
     */
    const sf::Vector2i GetPosI() { return sf::Vector2i(pos_); }

    /**
     * @brief Get the position of the entitys sprite
     *
     * @return sf::Vector2f
     */
    sf::Vector2f GetSpritePosition() const { return sprite_.getPosition(); } // might be unnecessary, because sprite pos should be same as that returned of GetPos()

    /**
     * @brief Get the position of the entitys sprite center
     *
     * @return sf::Vector2f
     */
    sf::Vector2f GetSpriteCenter() const;

    /**
     * @brief Get the position of the Enitys position during the last game tick
     *
     * @return const sf::Vector2f&
     */
    const sf::Vector2f& GetOldPosition() const;

    sf::FloatRect GetSpriteBounds() const;
    sf::FloatRect GetBaseBoxAt(sf::Vector2f pos) const;

    /**
     * @brief Function to set the position and sprite position of the entity
     *
     * @param pos the new position
     */
    void SetPos(sf::Vector2f pos);

    /**
     * @brief Function to set both the oldPos_, pos_ and sprite position of the entity
     *
     * @param pos the new position
     */
    void SetPosAndOldPos(sf::Vector2f pos);

    virtual void Render(sf::RenderTarget* target);

protected:
    void initSprite(const std::string& spriteLocation, sf::Vector2f spriteDims);

    sf::Vector2f pos_;
    sf::Vector2f oldPos_;
    sf::Sprite sprite_;
    sf::Texture texture_;
};
#endif

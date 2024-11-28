#include "Block.h"

class IndestructibleBrick : public Block{
    public:
        IndestructibleBrick();
        void beingHit(const sf::FloatRect& bounds, sf::Vector2f& position);
};
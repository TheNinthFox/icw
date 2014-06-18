#include "lib/components/DefaultGraphicComponent.hpp"
#include "lib/GameObject.hpp"

DefaultGraphicComponent::DefaultGraphicComponent() :
mShape()
{
    this->setType("DefaultGraphicComponent");

    mShape.setFillColor(sf::Color::White);
    mShape.setOutlineColor(sf::Color::Black);
    mShape.setOutlineThickness(1.f);
}

DefaultGraphicComponent::DefaultGraphicComponent(sf::Vector2f position, sf::Vector2f size) : DefaultGraphicComponent()
{
    mShape.setPosition(position);
    mShape.setSize(size);
    mShape.setOrigin(size.x/2.f, size.y/2.f);
}

void DefaultGraphicComponent::update(GameObject& object, sf::Time dt)
{
    mShape.setPosition(object.getPosition());
    mShape.setSize(object.getSize());
    mShape.setRotation(object.getRotation());
}

void DefaultGraphicComponent::render(sf::RenderTarget& target, sf::Time dt) const
{
    target.draw(mShape);
}

#include "GameObject.h"

GameObject::GameObject() {

}

GameObject::GameObject(Shader* shader, unsigned int texID, float pos_x, float pos_y, float dim_x, float dim_y) {
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	this->dim_x  =dim_x;
	this->dim_y = dim_y;
	this->shader = shader;
	this->sprite = new Sprite(1.0f, 1.0f);
	this->texID = texID;
	this->init();
}


GameObject::~GameObject()
{
}

void GameObject::Move(float pos_x, float pos_y,double timer)
{
	this->pos_x += pos_x * timer;
	this->pos_y += pos_y;

	if (this->pos_x < 0) {
;		this->pos_x = 800.0f;
	}

	this->sprite->setPosition(glm::vec3(this->pos_x, this->pos_y, 0.0));

}

void GameObject::Draw()
{
	this->sprite->draw();
}

void GameObject::Update(double timer)
{
	this->sprite->update(timer);
}

void GameObject::Destroy()
{
}

void GameObject::init()
{
	this->sprite->setPosition(glm::vec3(this->pos_x, this->pos_y, 0.0));
	this->sprite->setDimension(glm::vec3(this->dim_x, this->dim_y, 1.0f));
	this->sprite->setShader(this->shader);
	this->sprite->setTexture(this->texID);
}

bool GameObject::collision(GameObject* one)
{
	bool collisionX = one->getPosX() >= this->getPosX() &&
		this->getPosX() >= one->getPosX();
	// collision y-axis?
	bool collisionY = one->getPosY() >= this->getPosY() &&
		this->getPosY() + this->getPosY() >= this->getPosY();
	// collision only if on both axes
	return collisionX && collisionY;
}

float GameObject::getPosX()
{
	return this->pos_x;
}

float GameObject::getPosY()
{
	return this->pos_y;
}


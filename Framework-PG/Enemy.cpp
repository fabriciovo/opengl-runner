#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(Shader* shader, unsigned int texID)
{
	this->pos_x = 800.0f;
	this->pos_y = 120.0f;
	this->dim_x = 100.0f;
	this->dim_y = 100.0f;
	this->shader = shader;
	this->sprite = new Sprite(1.0f, 1.0f);
	this->texID = texID;
	this->init();
}

Enemy::~Enemy()
{
}

void Enemy::Update(double timer)
{
	this->sprite->update(timer);
}


void Enemy::Move(double timer) {
	this->pos_x += 1.0f * timer;

	if (this->pos_x < 0) {
		this->pos_x = 800.0f;
	}

	this->sprite->setPosition(glm::vec3(this->pos_x, this->pos_y, 0.0));
}
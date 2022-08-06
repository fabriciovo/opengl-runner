#include "Player.h"

Player::Player()
{
}

Player::Player(Shader* shader, unsigned int texID)
{
	this->pos_x = 70.0f;
	this->pos_y = 120.0f;
	this->dim_x = 50.0f;
	this->dim_y = 50.0f;
	this->shader = shader;
	this->sprite = new Sprite(8.0f,2.0f);
	this->texID = texID;
	this->init();
}

Player::~Player()
{
}

void Player::Update(double timer)
{
	this->sprite->update(timer);
	if (this->pos_y > 120.0f) {
		this->pos_y += 0.3f * timer;
	}

	this->sprite->setPosition(glm::vec3(this->pos_x, this->pos_y, 0.0));
	this->sprite->animation(timer);
}

void Player::Move(float pos_x, float pos_y, double timer)
{
	if(this->pos_y <= 120.0f){
		this->pos_y -= pos_y * timer ;
	}
	//this->sprite->setPosition(glm::vec3(this->pos_x, this->pos_y, 0.0));
}

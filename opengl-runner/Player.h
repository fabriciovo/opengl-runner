#ifndef PLAYER_H
#define PLAYER_H
#include "GameObject.h"

class Player : public GameObject
{

public:
	Player();
	Player(Shader* shader, unsigned int texID);
	virtual ~Player();


	void Move(float pos_x, float pos_y, double timer);
	void Update(double timer);
};

#endif PLAYER_H
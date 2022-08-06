#ifndef ENEMY_H
#define ENEMY_H
#include "GameObject.h"
class Enemy :
    public GameObject
{

public:
	Enemy();
	Enemy(Shader* shader, unsigned int texID);
	virtual ~Enemy();

	void Update(double timer);
	void Move(double timer);
};

#endif
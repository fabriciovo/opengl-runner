#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Sprite.h"
#include "Shader.h"

class GameObject
{

public:
	GameObject();
	GameObject(Shader* shader, unsigned int texID, float pos_x, float pos_y, float dim_x, float dim_y);
	virtual ~GameObject();

	virtual void Move(float pos_x, float pos_y, double timer);
	virtual void Draw();
	virtual void Update(double timer);
	virtual void Destroy();
	virtual void init();
	bool collision(GameObject *one);
	float getPosX();
	float getPosY();

protected:
	float pos_x;
	float pos_y;
	float dim_x;
	float dim_y;
	bool keys[1024];
	unsigned int texID;

	Sprite* sprite;
	Shader* shader;


};

#endif
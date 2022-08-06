#include "Sprite.h"

Sprite::Sprite()
{
	initialize();
}

Sprite::Sprite(float size_x, float size_y)
{
	this->size_x = size_x;
	this->size_y = size_y;
	this->frameCount = 60;
	initialize();


}


void Sprite::initialize()
{
	//Por enquanto trabalharemos apenas com sprites retangulares
	//com cor e textura -- e por enquanto sem spritesheet
	
	this->offsetx = 1.0f / this->size_x;
	this->offsety = 1.0f / this->size_y;

	float l = 0;
	float c = 0;

	float vertices[] = {
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,    offsetx + c * offsetx, offsety + l * offsety, // top right
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,    offsetx + c * offsetx, 0.0f + l * offsety, // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,    0.0f + c * offsetx,  0.0f + l * offsety, // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f +  c * offsetx, offsety + l * offsety// top left 
	};
	unsigned int indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};
	unsigned int VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// texture coord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);


	transform = glm::mat4(1); //matriz identidade
	texID = -1; //ainda não temos
	offsetx = 1.0f;
	offsety = 1.0f;
	shader = NULL; //ainda não temos
	pos = glm::vec3(0.0f, 0.0f, 0.0f);
	scale = glm::vec3(1.0f, 1.0f, 1.0f);
	angle = 0.0f;



}

void Sprite::setTexture(int texID)
{
	this->texID = texID;
}

void Sprite::setRotation(float angle, glm::vec3 axis, bool reset)
{
	if (reset) transform = glm::mat4(1);
	transform = glm::rotate(transform, angle, axis);
}

void Sprite::setTranslation(glm::vec3 displacements, bool reset)
{
	if (reset) transform = glm::mat4(1);
	transform = glm::translate(transform, displacements);
}

void Sprite::setScale(glm::vec3 scaleFactors, bool reset)
{
	if (reset) transform = glm::mat4(1);
	transform = glm::scale(transform, scaleFactors);
	scale = scaleFactors;
}

void Sprite::draw()
{
	glBindTexture(GL_TEXTURE_2D, texID);
	glUniform1i(glGetUniformLocation(shader->ID, "ourTexture1"), 0);

	glBindVertexArray(VAO);

	glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Sprite::update(double timer)
{
	//Por enquanto o update é basicamente pedir para atualizar no shader 
	//a matriz de transformação

	setTranslation(pos);
	setRotation(angle, glm::vec3(0.0f, 0.0f, 1.0f), false);
	setScale(scale, false);

	GLint transformLoc = glGetUniformLocation(shader->ID, "model");

	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
	glUniform1f(glGetUniformLocation(shader->ID, "offsetx"), offsetx / this->size_x);
	glUniform1f(glGetUniformLocation(shader->ID, "offsety"), offsety / this->size_y);

}

void Sprite::animation(double timer)
{
	if (this->frameCount <= 0) {
		offsetx++;
		this->frameCount = 60;
	}
	
	
	std::cout << this->frameCount << std::endl;
	if (offsetx >= 6) {
		offsetx = 0;
	}
	this->frameCount += timer;
}


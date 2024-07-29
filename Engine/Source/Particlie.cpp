#include "Particlie.h"

void Particle::Update(float dt)
{
	if (m_lifespan != 0) {
		m_lifespan -= dt;
	}
	if (m_lifespan <= 0) {
		isActive = false;
	}
	position = position + (velocity * dt);
}

void Particle::Draw(Renderer& renderer) const
{
	if (m_lifespan >= 0) {
		renderer.DrawRect(position.x, position.y, 4.0f, 4.0f);  
		
	}
}

void Particle::Initialize(const Data& data)
{
	position = data.position;
	velocity = data.velocity;
	m_lifespan = data.m_lifespan;
	red = data.red;
	blue = data.blue;
	green = data.green;
	alpha = data.alpha;

	isActive = true;
}

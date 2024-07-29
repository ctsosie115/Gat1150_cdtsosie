#pragma once
#include "Particlie.h"

#include <vector>

class ParticleSystem
{
public:
	ParticleSystem(int max_size = 1000)
	{
		m_particles.resize(max_size);
	}
	void Update(float dt);
	void Draw(Renderer& renderer);
	void AddParticle(const Particle::Data& data);

private:
	Particle* GetFreeParticle();

private:
	std::vector<Particle> m_particles; //post of particles
};
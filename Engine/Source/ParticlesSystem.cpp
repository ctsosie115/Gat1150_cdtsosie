#include "ParticlesSystem.h"

void ParticleSystem::Update(float dt)
{
	for (auto& particles : m_particles)
	{
		if (particles.isActive)
		{
			particles.Update(dt);
		}
	}
}

void ParticleSystem::Draw(Renderer& renderer)
{
	for (auto& particles : m_particles)
	{
		if (particles.isActive)
		{
			particles.Draw(renderer);
		}
	}
}

void ParticleSystem::AddParticle(const Particle::Data& data)
{
	Particle* particle = GetFreeParticle();
	if (particle)
	{
		if (!particle) {

		}
	}
}

Particle* ParticleSystem::GetFreeParticle()
{
	//find first inactive particles
	for (auto& particles : m_particles)
	{
		if (!particles.isActive) {
			return &particles;
		}
	}
	return nullptr;
}

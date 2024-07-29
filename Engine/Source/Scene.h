#pragma once
#include "Particlie.h"

#include <list>
#include <string>
#include <vector>
#include <memory>

class Renderer;
class Actor;

class DragonGame;
class Scene
{
public:
	Scene() = default;

	void Update(float dt);
	void Draw(Renderer& renderer);

	void AddActor(std::unique_ptr<Actor> actor);
	void RemoveAll();

	template<typename T> // always in header
	T* GetActor();

	std::vector<Particle> GetParticles() { return m_particles; }

	int SetScore(int score) const { return m_score; }
	int GetScore() const { return m_score; }
	std::string GetStringScore() { return std::to_string(m_score); } 

protected:
	int m_score = 0;
	std::list<std::unique_ptr<Actor>> m_actors;
	std::vector<Particle> m_particles;
	 
};

template<typename T> // always in header
T* Scene::GetActor()
{
	for (auto& actor : m_actors)
	{
		T* result = dynamic_cast<T*>(actor.get());
		if (result) return result;
	}
	return nullptr;
}
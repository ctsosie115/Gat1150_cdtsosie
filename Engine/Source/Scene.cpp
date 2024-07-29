#include "Scene.h"
#include "Actor.h"
#include "Model.h"
#include "Random.h"
#include "Vector2.h"
#include <algorithm>
#include <iostream>
#include <chrono>
#include <map>


void Scene::Update(float dt)
{
	//Update
	for (auto& actor : m_actors)
	{
		actor->Update(dt);
	}

	for (Particle& particle : m_particles)
	{
		particle.Update(dt);
		if (particle.position.x > 1000) particle.position.x = 0;
		if (particle.position.x < 0) particle.position.x = 1000;

	}

	//destory
	m_actors.erase(std::remove_if(m_actors.begin(), m_actors.end(), [](auto& actor) { return actor->m_destoryed; }), m_actors.end()); 

	//collsion
	for (auto& actor1 : m_actors)
	{
		for (auto& actor2 : m_actors)
		{
			//Checks if actors are desstoryed
			if (actor1 == actor2 || (actor1->IsDestoryed()) || (actor2->IsDestoryed())) continue;

			//Checks if the actors are near each other
			Vector2 direction = actor1->GetTransform().position - actor2->GetTransform().position;
			float distance = direction.Length();

			float radius = actor1->m_model->GetRadius() + actor2->m_model->GetRadius(); 

			//If the two actors are close to each other
			if (distance <= radius)
			{

				//If it is a normal bullet hitting a enemy create a particles right before they collide. And getting the postion of the enemy of the point of the expolision
				if (actor1->GetTag() == "Enemy" && actor2->GetTag() == "Bullet")
				{

					//Adding particles that exploded in a circle
					for (int i = 0; i < 25; i++)
					{
						m_particles.push_back(Particle{ actor2->m_transfrom.position, randomOnUnitCircle().Rotate(1 / 25) * 25.0f, randomF(3.0f,4.0f), random(0,255), random(0,255), random(0,255), random(0,255)});

					}

				}

				//Where the collison happens 
				actor1->OnColliison(actor2.get());
				actor2->OnColliison(actor1.get());

			}
		}
	}


}

void Scene::Draw(Renderer& renderer)
{
	for (auto& actor : m_actors)
	{
		actor->Draw(renderer); 
	}
	for (Particle particleses : m_particles)
	{
		renderer.SetColor(particleses.red, particleses.green, particleses.blue, particleses.alpha);
		particleses.Draw(renderer);
	}
}

void Scene::AddActor(std::unique_ptr<Actor> actor)
{
	actor.get()->m_scene = this;
	m_actors.push_back(std::move(actor)); 
	
}


void Scene::RemoveAll()
{
	m_actors.clear();
}

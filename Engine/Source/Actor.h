#pragma once
#include "Transformation.h"
#include <string>


class Model;
class Renderer;
class Scene;

class Actor
{
public:
	Actor() = default;
	
	Actor(const Transform& tranfrom) : m_transfrom{ tranfrom } {}
	Actor(const Transform& tranfrom, Model* model) :
		m_transfrom{ tranfrom },
		m_model{ model }
	{}

	virtual void Update(float dt);
	virtual void Draw(Renderer& renderer);
	virtual void OnColliison(Actor* actor) {};

	void SetDampling(float damping) { m_dampling = damping; }
	void SetLifespan(float lifespan) { m_lifespan = lifespan; }

	const Transform& GetTransform() { return m_transfrom; }
	bool IsDestoryed() const { return m_destoryed; }
	void SetDestroyed(bool isDestroyed) { m_destoryed = isDestroyed; }

	//float GetRadius() { return (m_model) ? m_model->GetRadius() * m_transfrom.scale : 0; } 

	void SetTag(const std::string& tag) { m_tag = tag; }
	const std::string& GetTag() { return m_tag; }

	friend class Scene;

	bool m_destoryed = false;
protected:

	std::string m_tag;
	
	float m_lifespan = 0;

	Transform m_transfrom{ {0,0} };
	Vector2 m_velocity{ 0, 0 };
	float m_dampling{ 0 };

	Model* m_model{ nullptr };
	Scene* m_scene{ nullptr };
};
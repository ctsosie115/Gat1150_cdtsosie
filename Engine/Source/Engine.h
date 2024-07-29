#pragma once
#include "Render.h"
#include "Audio.h"
#include "Input.h"

#include "CTime.h"

#include "Vector2.h"
#include "MathUTIS.h"
#include "Random.h"

#include "Particlie.h"
#include "ParticlesSystem.h"
#include "Model.h"
#include "Transformation.h"

#include <SDL.h>
#include <fmod.hpp>
#include <memory>

class Engine {

public:
	Engine() = default;
	~Engine() = default;

	bool Initialize();
	void Shutdown() const;

	void Update();

	Renderer GetRenderer() const { return *m_renderer; }
	Input GetInput() const { return *m_input; }
	Audio GetAudio() const { return *m_audio; }
	Time GetTime() const { return *m_time; }
	ParticleSystem& GetPS() const { return *m_particlesystem; }
	bool IsQuit() const { return quit; }

public:
	bool quit{ false };
	std::unique_ptr<Time> m_time;

	std::unique_ptr<Renderer> m_renderer;
	std::unique_ptr<Input> m_input;
	std::unique_ptr<Audio> m_audio;

	std::unique_ptr<ParticleSystem> m_particlesystem;
}; 

Engine extern g_engine;

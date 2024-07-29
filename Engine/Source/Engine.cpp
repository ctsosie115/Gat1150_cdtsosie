#include "Engine.h"
 
extern Engine g_engine;

bool Engine::Initialize()
{
    m_renderer = std::make_unique<Renderer>() ;
    m_input = std::make_unique<Input>() ;
    m_audio = std::make_unique<Audio>() ;

    m_renderer->Iitialize();
    m_renderer->CreateWindow("Game Engine", 1000, 800);
   
    m_input->Initialize();
    m_audio->Initialize();

    m_time = std::make_unique<Time>();

    m_particlesystem = std::make_unique<ParticleSystem>();
    return true;
}

void Engine::Shutdown() const
{
    m_renderer->Shutdown();
    m_input->Shutdown();
    m_audio->Shutdown();
}


void Engine::Update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            quit = true;
        }
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
        {
            quit = true;
        }
    }
    m_time.get()->Tick();
    m_input->Update();
    m_audio->Update();
    m_particlesystem->Update(m_time->GetDeltaTime());
}

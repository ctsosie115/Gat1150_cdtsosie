#include "Engine.h"
#include "Scene.h"

#include <iostream>
#include <cstdlib>
#include <vector>


Engine g_engine;
int main(int argc, char* argv[])
{
	//Initialize()
	g_engine.Initialize();

	//Background Music
	g_engine.GetAudio().PlaySound("dragon_background_music.wav");

	//music timer
	float music_time = 0.0f;

	while (!g_engine.IsQuit())
	{
		//Update
		g_engine.Update();

		//Begin Frame
		g_engine.GetRenderer().SetColor(0, 0, 0, 0);
		g_engine.GetRenderer().BeginFrame();

		//Music Loop
		music_time += 0.01f;
		if (music_time >= 12.5f) {
			g_engine.GetAudio().PlaySound("dragon_background_music.wav");
			music_time = 0;
		}
		//Draw
		g_engine.GetPS().Draw(*g_engine.m_renderer);

		//End Frame
		g_engine.GetRenderer().EndFrame();
	}
	g_engine.Shutdown();

	return 0;
}
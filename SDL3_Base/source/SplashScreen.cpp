#include "SplashScreen.h"
#include "InputManager.h"
#include "TextObject.h"
#include "RenderManager.h"
#include "SceneManager.h"
#include "Audio/AudioManager.h"

void SplashScreen::OnEnter()
{
	AM->HaltAudio();
	AM->PlaySoundLooping("resources/audio/music/MenuSong.wav");

	TextObject* title = new TextObject("NYENYACE",
		Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2), Vector2::One * 8, {255, 255, 255, 0xFF});
	TextObject* pressClickText = new TextObject("PRESS CLICK",
		Vector2(RM->WINDOW_WIDTH / 2, RM->WINDOW_HEIGHT / 2 + 100), Vector2::One * 4, { 255, 255, 255, 0xFF });
	
	_ui.push_back(title);
	_ui.push_back(pressClickText);
}

void SplashScreen::Update() 
{
	Scene::Update();

	if (IM->GetLeftClick())
	{
		assert(SM.SetNextScene("MainMenu"));
	}
}

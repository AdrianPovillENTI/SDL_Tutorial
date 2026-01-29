#include "MainMenu.h"
#include "UI/Button.h"
#include "TextObject.h"
#include "Spawner.h"
#include "SceneManager.h"

void MainMenu::OnEnter() 
{
	Button* level1Button = new Button([]()
		{
			assert(SM.SetNextScene("Level1"));
		}, Vector2(200.f, 100.f)
			);
	TextObject* level1Text = new TextObject(" Start Game ",
		level1Button->GetTransform()->position + Vector2(-60, 75), Vector2::One * 2);

	Button* highScoresButton = new Button([]()
		{
			assert(SM.SetNextScene("Leaderboard"));
		}, Vector2(200.f, 300.f)
			);
	TextObject* highScoresText = new TextObject(" High Scores ",
		highScoresButton->GetTransform()->position + Vector2(-60, 75), Vector2::One * 2);

	Button* quitGameButton = new Button([]()
		{

			std::cout << "ExitGame" << std::endl;
	exit(0);
		}, Vector2(200.f, 500.f)
			);
	TextObject* quitGameText = new TextObject(" Quit Game ",
		quitGameButton->GetTransform()->position + Vector2(-60, 75), Vector2::One * 2);

	_ui.push_back(level1Button);
	_ui.push_back(highScoresButton);
	_ui.push_back(quitGameButton);

	_ui.push_back(level1Text);
	_ui.push_back(highScoresText);
	_ui.push_back(quitGameText);

}
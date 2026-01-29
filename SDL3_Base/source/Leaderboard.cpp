#include <algorithm>
#include "Leaderboard.h"
#include "Score/ScoreManager.h"
#include "Score/ScoreData.h"

void Leaderboard::OnEnter()
{
	std::vector<int> scores = SD->Load();

	if (scores.empty())
		scores.push_back(10000);

	TextObject* scoreLabel = new TextObject("LEADERBOARD", 
		Vector2(RM->WINDOW_WIDTH / 2, 100), Vector2::One * 4);

	_ui.push_back(scoreLabel);

	for (int i = 1; i < 11; i++)
	{
		string scoreString = i + "Score: " + scores[i - 1];

		TextObject* scoreText = new TextObject(scoreString,
			Vector2(RM->WINDOW_WIDTH / 2, 100 + scoreSpacing * i), Vector2::One * 2);

		_ui.push_back(scoreText);
	}

	Button* backButton = new Button([]()
		{
			assert(SM.SetNextScene("MainMenu"));
		}, Vector2(200.f, 500.f)
			);
	TextObject* backText = new TextObject(" backToMenu ",
		backButton->GetTransform()->position + Vector2(-60, 75), Vector2::One * 2);

	_ui.push_back(backButton);
	_ui.push_back(backText);
}

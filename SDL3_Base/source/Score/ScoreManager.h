#pragma once
#include <functional>

#define SCR ScoreManager::Instance()

class ScoreManager
{
private:
	ScoreManager() = default;
	ScoreManager(ScoreManager&) = delete;
	ScoreManager& operator =(const ScoreManager&) = delete;

	int score = 0;

public:
	static ScoreManager& Instance()
	{
		static ScoreManager instance;
		return instance;
	}

	std::function<void(int)> onScoreChanged;

	void AddScore(int plus);
	int GetScore();
	void RestartScore();
};
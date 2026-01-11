#pragma once

#define SCR ScoreManager::Instance()

class ScoreManager
{
private:
	ScoreManager() = default;
	ScoreManager(ScoreManager&) = delete;
	ScoreManager& operator =(const ScoreManager&) = delete;

public:
	static ScoreManager& Instance()
	{
		static ScoreManager instance;
		return instance;
	}

	void AddScore(int plus);
	int GetScore();
	void RestartScore();
private:
	int score;
}
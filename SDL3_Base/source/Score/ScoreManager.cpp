#include "ScoreManager.h"

void ScoreManager::AddScore(int plus)
{
	score += plus;
	if (onScoreChanged)
		onScoreChanged(score);
}

int ScoreManager::GetScore()
{
	return score;
}

void ScoreManager::RestartScore() 
{
	score = 0;
	if (onScoreChanged)
		onScoreChanged(score);
}
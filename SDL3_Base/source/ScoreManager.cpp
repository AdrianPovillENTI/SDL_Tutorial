#include "ScoreManager.h"
#include "UI/UIManager.h"

ScoreManager::AddScore(int plus)
{
	score += plus;
	UIM->UpdateScore(score);
}

ScoreManager::GetScore()
{
	return score;
}

ScoreManager::RestartScore() 
{
	score = 0;
	UIM->UpdateScore(score);
}
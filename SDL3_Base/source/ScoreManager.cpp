#include "ScoreManager.h"
#include "UI/UIManager.h"

void ScoreManager::AddScore(int plus)
{
	score += plus;
	UIM->UpdateScore(score);
}

int ScoreManager::GetScore()
{
	return score;
}

void ScoreManager::RestartScore() 
{
	score = 0;
	UIM->UpdateScore(score);
}
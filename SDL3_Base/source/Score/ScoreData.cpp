#include "ScoreData.h"
#include "ScoreManager.h"
#include <tinyxml2.h>
#include <algorithm>
#include <functional>

using namespace tinyxml2;

std::vector<int> ScoreData::Load() const {
	std::vector<int> scores;

	XMLDocument doc;
	if (doc.LoadFile(FILE_NAME.c_str()) != XML_SUCCESS)
		return scores;

	XMLElement* root = doc.FirstChildElement("Leaderboard");
	if (!root) return scores;

	for (XMLElement* e = root->FirstChildElement("Entry"); e; e = e->NextSiblingElement("Entry"))
	{
		int s = 0;
		if (e->QueryIntAttribute("score", &s) == XML_SUCCESS)
			scores.push_back(s);
	}

	return scores;
}

bool ScoreData::SaveNewScore() const {
	std::vector <int> scores = Load();

	scores.push_back(SCR.GetScore());

	std::sort(scores.begin(), scores.end(), std::greater<int>());

	XMLDocument doc;
	XMLElement* root = doc.NewElement("Leaderboard");
	doc.InsertFirstChild(root);

	for (int s : scores)
	{
		XMLElement* entry = doc.NewElement("Entry");
		entry->SetAttribute("score", s);
		root->InsertEndChild(entry);
	}

	return doc.SaveFile(FILE_NAME.c_str()) == XML_SUCCESS;
}
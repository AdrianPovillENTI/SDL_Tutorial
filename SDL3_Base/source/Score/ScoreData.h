#pragma once
#include <string>
#include <vector>

#define SD ScoreData::GetInstance()

class ScoreData
{
private:
    const std::string FILE_NAME = "Leaderboard.xml";

    ScoreData ( ) = default;
    ScoreData ( ScoreData & ) = delete;
    ScoreData & operator=( const ScoreData & ) = delete;
    ~ScoreData ( ) = default;

public:
    static ScoreData * GetInstance ( )
    {
        static ScoreData instance;
        return &instance;
    }

    std::vector<int> Load ( ) const;
    bool SaveNewScore ( ) const;
};

#include "ScoreData.h"
#include "ScoreManager.h"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"

std::vector<int> ScoreData::Load ( ) const
{
    std::vector<int> scores;

    std::ifstream file ( FILE_NAME.c_str ( ) , std::ios::binary );
    if ( !file.is_open ( ) )
        return scores;

    std::stringstream buffer;
    buffer << file.rdbuf ( );
    file.close ( );

    std::string content ( buffer.str ( ) );
    if ( content.empty ( ) )
        return scores;

    rapidxml::xml_document<> doc;
    doc.parse<0> ( &content [ 0 ] );

    rapidxml::xml_node<> * root = doc.first_node ( "Leaderboard" );
    if ( !root )
        return scores;

    for ( rapidxml::xml_node<> * entry = root->first_node ( "Entry" );
          entry != 0;
          entry = entry->next_sibling ( "Entry" ) )
    {
        rapidxml::xml_attribute<> * attr = entry->first_attribute ( "score" );
        if ( attr != 0 )
        {
            int value = std::atoi ( attr->value ( ) );
            scores.push_back ( value );
        }
    }

    return scores;
}

bool ScoreData::SaveNewScore ( ) const
{
    std::vector<int> scores = Load ( );
    scores.push_back ( SCR.GetScore ( ) );

    std::sort ( scores.begin ( ) , scores.end ( ) , std::greater<int> ( ) );

    rapidxml::xml_document<> doc;

    rapidxml::xml_node<> * decl = doc.allocate_node ( rapidxml::node_declaration );
    decl->append_attribute ( doc.allocate_attribute ( "version" , "1.0" ) );
    decl->append_attribute ( doc.allocate_attribute ( "encoding" , "utf-8" ) );
    doc.append_node ( decl );

    // <Leaderboard>
    rapidxml::xml_node<> * root = doc.allocate_node ( rapidxml::node_element , "Leaderboard" );
    doc.append_node ( root );

    for ( size_t i = 0; i < scores.size ( ); ++i )
    {
        rapidxml::xml_node<> * entry = doc.allocate_node ( rapidxml::node_element , "Entry" );

        std::stringstream ss;
        ss << scores [ i ];
        std::string scoreStr = ss.str ( );

        char * value = doc.allocate_string ( scoreStr.c_str ( ) );
        entry->append_attribute ( doc.allocate_attribute ( "score" , value ) );

        root->append_node ( entry );
    }

    std::ostringstream oss;
    oss << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
    oss << "<Leaderboard>\n";
    for ( size_t i = 0; i < scores.size ( ); ++i )
    {
        oss << "  <Entry score=\"" << scores [ i ] << "\"/>\n";
    }
    oss << "</Leaderboard>\n";

    // Guardar
    std::ofstream out ( FILE_NAME.c_str ( ) , std::ios::binary );
    if ( !out.is_open ( ) )
        return false;

    out << oss.str ( );
    return out.good ( );
}
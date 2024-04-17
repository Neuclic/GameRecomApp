#pragma once
#include "utility.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

struct Game {
    int id; // Unique identifier，由平台和游戏名称共同确定
    std::string title;
    double ign_score;
    double user_score; // an average of user scores
    std::string score_phrase;
    std::string platform;
    std::string genre;
    int release_year;
    int release_month;
    int release_day;
};


class game_db {
public:
    void add_game(const Game& game);     //添加新的游戏
    void del_game(int game);    //删除游戏
    void change_name(int game,std::string name);    //修改游戏名字
    void change_genre(int game,int genre);    //修改游戏类别
    void change_year(int game,int year);    //修改游戏发行年份
    void change_year(int game,int month);    //修改游戏发行月份
    void change_year(int game, int day);    //修改游戏发行日
    void change_score_phrase(int game, int phrase);    //修改游戏的评分等级
    void change_platform(int game, int platform);    //修改游戏所在平台
    void change_ign_score(int game, double score); //修改ign的分数
    void change_user_score(int game, double score); //修改玩家分数

};

//哈希表定义
//筛选功能包括：平台、类别、发行年份筛选、评分等级
myMap<int, Game> game_database; // Using game ID as the key
myMap<std::string, mySet<int>> games_by_platform; // Index for platform
myMap<int, std::string> genre_db; // Index for genre
myMap<int, int> games_by_genre;//index for genre
myMap<int, mySet<int>> games_by_release_year;
myMap<int, std::string> games_by_phrase;




//排序功能包括：发行日期、ign评分、名称、玩家评分
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include"speaker.h"
#include<algorithm>
#include<ctime>
#include<functional>
#include<fstream>
using namespace std;
class manage
{
public:
	//构造函数
	manage();
	//初始化容器
	void initcontainer();
	//打印菜单
	void printmenu();
	//创建成员
	void creatmem();
	//退出系统
	void exitsystem();
	//记录第一轮比赛选手编号
	vector<int>v1;
	//记录第二轮比赛选手编号
	vector<int>v2;
	//记录前三名选手编号
	vector<int>victory;
	//记录选手编号和姓名的对应信息
	map<int, speaker>m_speaker;
	//记录比赛轮数
	int index;
	//创建选手
	void creatspeaker();
	//开始比赛
	void startspeech();
	//保存比赛记录
	void savespeech();
	//读取比赛记录
	void loadRecord();
	//判断文件是否有效
	bool fileisEmpty;
	map<int, vector<string>>m_Record;//由于存放往届记录
	//显示往届记录
	void showRecord();
	//清空文件
	void clearRecord();
	//析构函数
	~manage();
};
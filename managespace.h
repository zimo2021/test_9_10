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
	//���캯��
	manage();
	//��ʼ������
	void initcontainer();
	//��ӡ�˵�
	void printmenu();
	//������Ա
	void creatmem();
	//�˳�ϵͳ
	void exitsystem();
	//��¼��һ�ֱ���ѡ�ֱ��
	vector<int>v1;
	//��¼�ڶ��ֱ���ѡ�ֱ��
	vector<int>v2;
	//��¼ǰ����ѡ�ֱ��
	vector<int>victory;
	//��¼ѡ�ֱ�ź������Ķ�Ӧ��Ϣ
	map<int, speaker>m_speaker;
	//��¼��������
	int index;
	//����ѡ��
	void creatspeaker();
	//��ʼ����
	void startspeech();
	//���������¼
	void savespeech();
	//��ȡ������¼
	void loadRecord();
	//�ж��ļ��Ƿ���Ч
	bool fileisEmpty;
	map<int, vector<string>>m_Record;//���ڴ�������¼
	//��ʾ�����¼
	void showRecord();
	//����ļ�
	void clearRecord();
	//��������
	~manage();
};
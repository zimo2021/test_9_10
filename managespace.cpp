#include<iostream>
using namespace std;
#include"managespace.h"
void manage::printmenu()
{
	cout << "***************************************" << endl;
	cout << "*****      ��ӭ�μ��ݽ�����       *****" << endl;
	cout << "************1.��ʼ�ݽ�����*************" << endl;
	cout << "************2.�鿴���������¼*********" << endl;
	cout << "************3.��ձ�����¼*************" << endl;
	cout << "************0.�˳���������*************" << endl;
	cout << "***************************************" << endl;
}
class person
{
public:
	int num;
};
void manage::creatmem()
{
	string seeds = "ABCDEFGHIJKL";

}
void manage::exitsystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	exit(0);
}
void manage::initcontainer()
{
	this->v1.clear();
	this->v2.clear();
	this->victory.clear();
	this->m_speaker.clear();
	this->index = 1;
	this->m_Record.clear();
}
manage::~manage()
{
	
}

manage::manage()
{
	this->initcontainer();
	this->creatspeaker();
	this->loadRecord();
}
void manage::creatspeaker()
{
	string nameseed = "ABCDEFGHIJKL";
	int i;
	for (i = 0; i < (int)nameseed.size(); i++)
	{
		string name = "ѡ��";
		name += nameseed[i];
		speaker sp;
		sp.m_name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}
		this->v1.push_back(1001 + i);
		this->m_speaker.insert(make_pair(i + 1001, sp));
	}
}
void print(int val)
{
	cout << val << " ";
}
void manage::startspeech()
{
	vector<int>vp1;//ʢ�ŵ�һ��ѡ�ֱ��
	vector<int>vp2;//ʢ�ŵڶ���ѡ�ֱ��
	vector<double>vs1;//ʢ�ŵ�һ�����
	vector<double>vs2;//ʢ�ŵڶ������
	/*vp1.resize(this->v1.size() / 2);
	vp2.resize(this->v1.size() / 2);*///û��Ҫ
	cout << "��<<" << this->index << ">>�ֱ������ڳ�ǩ" << endl;
	cout << "------------------------------" << endl;
	cout << "��ǩ������£�" << endl;
	if (this->index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = this->v1.begin(); it != this->v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
		for (int i = 0; i < (int)(this->v1.size() / 2); i++)
		{
			vp1.push_back(v1[i]);
			vp2.push_back(v1[i + (this->v1.size() / 2)]);
		}
		cout << "��һ�飺" << " ";
		for_each(vp1.begin(), vp1.end(), print);
		cout << endl;
		cout << "�ڶ��飺" << " ";
		for_each(vp2.begin(), vp2.end(), print);
		cout << endl;
		cout << "------------------------------" << endl;
		cout << "����λ��ί���" << endl;
		system("pause");
		cout << "��һ����ί��ֽ�����£�" << endl;
		srand((unsigned int)time(NULL));
		double sum1 = 0;
		double sum2 = 0;
		for (int j = 0; j < (int)(this->v1.size() / 2); j++)
		{
			sum1 = 0;
			sum2 = 0;
			for (int i = 0; i < 3; i++)
			{
				double num1 = (rand() % 401 + 600) / 10.f;
				sum1 += num1;
				double num2 = (rand() % 401 + 600) / 10.f;
				sum2 += num2;
			}
			/*this->m_speaker[vp1[j]].m_score[this->index - 1] = (sum1 / 3);
			this->m_speaker[vp2[j]].m_score[this->index - 1] = (sum2 / 3);*/
			vs1.push_back(sum1);
			vs2.push_back(sum2);
		}
		sort(vs1.begin(), vs1.end(), greater<double>());
		sort(vs2.begin(), vs2.end(), greater<double>());
		for (int i = 0; i < (int)(this->v1.size() / 2); i++)
		{
			this->m_speaker[vp1[i]].m_score[this->index - 1] = vs1[i]/3;
			this->m_speaker[vp2[i]].m_score[this->index - 1] = vs2[i]/3;
		}
		cout << "��һ��" << endl;
		for (int i = 0; i < (int)(this->v1.size() / 2); i++)
		{
			cout << "��ţ�" << vp1[i] << " ������" << this->m_speaker[vp1[i]].m_name << " ������" << this->m_speaker[vp1[i]].m_score[index - 1] << endl;
		}
		cout << endl;
		cout << "�ڶ���" << endl;
		for (int i = 0; i < (int)(this->v1.size() / 2); i++)
		{
			cout << "��ţ�" << vp2[i] << " ������" << this->m_speaker[vp2[i]].m_name << " ������" << this->m_speaker[vp2[i]].m_score[index - 1] << endl;
		}
		//��ÿ��ǰ��������v2��
		for (int i = 0; i < 3; i++)
		{
			this->v2.push_back(vp1[i]);
			this->v2.push_back(vp2[i]);
		}
		cout << "---------------------------- ��<<" << this->index << ">>�ֱ������------------------------------" << endl;
		cout << "��һ�ֱ��������������:" << endl;
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << "��ţ�" << *it << " ������" << this->m_speaker[*it].m_name << " ������" << this->m_speaker[*it].m_score[index - 1] << endl;
		}
		cout << "--------------------------------------------------------------------" << endl;
		this->index++;
	}
	else
	{
		vector<double>vs3;//����ʢ�ŵڶ�����ί���
		random_shuffle(v2.begin(), v2.end());
		cout << endl;
		cout << "����λ��ί���" << endl;
		system("pause");
		cout << "�ڶ�����ί��ֽ�����£�" << endl;
		srand((unsigned int)time(NULL));
		double sum1 = 0;
		double sum2 = 0;
		for (int j = 0; j < (int)v2.size(); j++)
		{
			sum1 = 0;
			sum2 = 0;
			for (int i = 0; i < 3; i++)
			{
				double num1 = (rand() % 401 + 600) / 10.f;
				sum1 += num1;
			}
			vs3.push_back(sum1/3);
		}
		sort(vs3.begin(), vs3.end(), greater<double>());
		for (int i = 0; i < (int)vs3.size(); i++)
		{
			this->m_speaker[this->v2[i]].m_score[this->index - 1] = vs3[i];
		}
		cout << "��ί��ֽ�����£�" << endl;
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << "��ţ�" << *it << " ������" << this->m_speaker[*it].m_name << " ������" << this->m_speaker[*it].m_score[this->index - 1] << endl;
		}
		for (int i = 0; i < 3; i++)
		{
			this->victory.push_back(v2[i]);
		}
		cout << "---------------------------- ��<<" << this->index << ">>�ֱ������------------------------------" << endl;
		cout << "�ڶ��ֱ��������������:" << endl;
		for (vector<int>::iterator it = this->victory.begin(); it != this->victory.end(); it++)
		{
			cout << "��ţ�" << *it << " ������" << this->m_speaker[*it].m_name << " ������" << this->m_speaker[*it].m_score[index - 1] << endl;
		}
		cout << "--------------------------------------------------------------------" << endl;
	}
	system("pause");
}
void manage::savespeech()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//����appΪappend:׷�ӵ���˼
	for (vector<int>::iterator it = this->victory.begin(); it != this->victory.end(); it++)
	{
		ofs << *it << "," << this->m_speaker[*it].m_score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "��¼�Ѿ����棡" << endl;//����Ӧ���ļ����лᴴ��һ��csv�ļ� ������excel�д�
	system("pause");
}

void manage::loadRecord()
{
	ifstream ifs;
	ifs.open("speech.csv", ios::in);
	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		this->fileisEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		this->fileisEmpty = true;
		ifs.close();
		return;
	}
	//�ļ���Ч
	this->fileisEmpty = false;
	ifs.putback(ch);//���������ڲ��Ե�ch������
	string data;
	int num = 0;
	while (ifs >> data)
	{
		vector<string>v;//���ڴ�Ž�ȡ���ַ��� ����������λ�� ��������ظ������ݱ�����
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				//û���ҵ������
				break;
			}
			else 
			{
				string temp = data.substr(start, pos-start);
				v.push_back(temp);
				start = pos + 1;
			}
		}
		this->m_Record.insert(make_pair(num, v));
		num++;
	}
	ifs.close();
	cout << endl;
}

void manage::showRecord()
{
	int i;
	for (i = 0; i < (int)this->m_Record.size(); i++)
	{
		cout << "��<<" << i+1 << ">>�������¼��" << endl;
		cout << " �ھ���ţ�" << this->m_Record[i][0] << " �ɼ� ��" << this->m_Record[i][1]
			<< " �Ǿ���ţ�" << this->m_Record[i][2] << " �ɼ� ��" << this->m_Record[i][3]
			<< " ������ţ�" << this->m_Record[i][4] << " �ɼ� ��" << this->m_Record[i][5] << endl;
	}
}
void manage::clearRecord()
{
	int choice;
	cout << "ȷ�������" << endl;
	cout << "1.��" << endl;
	cout << "2.��" << endl;
	cin >> choice;
	if (choice == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);//ios::trunc ���ǰ���ļ��������� �����ȫ������ ���Ҵ���һ���µ��ļ�
		ofs.close();
		//�����ļ�
		this->initcontainer();
		//�����µ�ѡ��
		this->creatspeaker();
		//��������
		this->loadRecord();
		cout << "��ճɹ�" << endl;
	}
	else
	{
		cout << "��ȡ����" << endl;
	}
}












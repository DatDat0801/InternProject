#include "ScoreMng.h"
#include "GameObject/Shader.h"
#include "GameObject/Texture.h"
#include "GameObject/Model.h"
#include "GameObject/Camera.h"
#include "GameObject/Font.h"
#include "GameObject/Sprite2D.h"
#include "GameObject/Sprite3D.h"
#include "GameObject/Text.h"
#include <fstream>
#include <string>
using namespace std;
ScoreMng::ScoreMng()
{
	std::string dataPath = "..\\Data\\";
}

ScoreMng::~ScoreMng()
{
}
void ScoreMng::SaveScoreMax()
{

}

int ScoreMng::GetHeighScore()
{
	fstream fin;
	fin.open("..\\Data\\Score.txt", ios::in);
	string data;
	getline(fin, data);
	fin.close();

	int tmp = stoi(data);
	if (m_score > tmp)
	{
		fstream fout;
		fout.open("..\\Data\\Score.txt", ios::out | ios::trunc);
		std::string tmps2 = std::to_string(m_score);
		fout << tmps2;
		fout.close();
		return m_score;
	}
	else return tmp;

}



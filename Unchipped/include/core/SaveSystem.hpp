#pragma once
#include<fstream>
#include"core/Debug.hpp"
#include"core/Utility.hpp"

struct SaveStructure
{
	std::string name;
	int level;
	int points;
	float hp;
	int ammo;
};

class SaveSystem
{
public:
	SaveSystem();
	SaveSystem(SaveStructure saveData);
	~SaveSystem();


	void Write();

	void Load();

	void Delete();

	SaveStructure getCurrentSaveData();

private:
	SaveStructure saveData;
};


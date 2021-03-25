#include "SaveSystem.hpp"

SaveSystem::SaveSystem()
{
    Debug::log("SaveStructure not loaded. Please load the save structure in the SaveSystem Constructor", Debug::ERROR);
}

SaveSystem::SaveSystem(SaveStructure saveData)
{
	this->saveData = saveData;
}

SaveSystem::~SaveSystem()
{
}

void SaveSystem::Write()
{
    std::string save;
    save = saveData.name + ";";
    save += std::to_string(saveData.level) + ";";
    save += std::to_string(saveData.points) + ";";
    save += std::to_string(saveData.hp) + ";";
    save += std::to_string(saveData.ammo) + ";";
    util::encrypt(save);
    std::ofstream savefile;
    savefile.open("data/saves/save.sv");
    savefile << save;

    savefile.close();
}

void SaveSystem::Load()
{
    std::string save;
    std::ifstream savefile;
    savefile.open("data/saves/save.sv");
    std::getline(savefile, save);
    util::decrypt(save);
    int sidx = 0;
    int dataidx = 0;
    for (int i = 0; i < save.length(); i++)
    {
        if (save[i] == ';')
        {
            std::string newstr = "";
            for (int j = sidx; j < i; j++)
            {
                newstr += save[j];
            }

            switch (dataidx)
            {
            case 0:
                saveData.name = newstr;
                break;
            case 1:
                saveData.level = std::stoi(newstr);
                break;
            case 2:
                saveData.points = std::stoi(newstr);
                break;
            case 3:
                saveData.hp = std::stof(newstr);
                break;
            case 4:
                saveData.ammo = std::stoi(newstr);
                break;
            default:
                break;
            }
            sidx = i + 1;
            dataidx++;
        }
    }
    savefile.close();
}

void SaveSystem::Delete()
{
    std::ofstream savefile;
    savefile.open("data/saves/save.sv");
    savefile << "";
    savefile.close();
}

SaveStructure SaveSystem::getCurrentSaveData()
{
	return saveData;
}

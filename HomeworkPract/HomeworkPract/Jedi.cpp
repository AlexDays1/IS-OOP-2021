#include "Jedi.hpp"

void CopyText1(char* firstText, const char* secondText)
{
	int i;

	for (i = 0; i < strlen(secondText); i++)
	{
		firstText[i] = secondText[i];
	}

	firstText[i] = '\0';
}

char* EnumTocharArray(JediRank rank)
{
	char rankType[16];

	if (rank == JediRank::GrandMaster)
	{
		CopyText1(rankType, "GrandMaster");
		return rankType;
	}
	else if (rank == JediRank::Master)
	{
		CopyText1(rankType, "Master");
		return rankType;
	}
	else
	{
		CopyText1(rankType, "Padawan");
		return rankType;
	}
}


Jedi::Jedi()
{
	this->name = nullptr;
	this->rank = JediRank::Padawan;
	this->midichlorian = 0.0;
	this->spicies = nullptr;
	this->militaryRank = nullptr;
}

Jedi::Jedi(const Jedi& otherJedi)
{
	this->name = new char[strlen(otherJedi.name) + 1];
	CopyText1(this->name, otherJedi.name);
	this->rank = otherJedi.rank;
	this->planet = otherJedi.planet;
	this->spicies = new char[strlen(otherJedi.spicies) + 1];
	CopyText1(this->spicies, otherJedi.spicies);
	this->militaryRank = new char[strlen(otherJedi.militaryRank) + 1];
	CopyText1(this->militaryRank, otherJedi.militaryRank);
}

Jedi& Jedi::operator=(const Jedi& otherJedi)
{
	if (this != &otherJedi)
	{
		delete[] name;
		midichlorian = 0.0;
		delete[] spicies;
		delete[] spicies;
		delete[] militaryRank;
	}

	this->name = new char[strlen(otherJedi.name) + 1];
	CopyText1(this->name, otherJedi.name);
	this->rank = otherJedi.rank;
	this->planet = otherJedi.planet;
	this->spicies = new char[strlen(otherJedi.spicies) + 1];
	CopyText1(this->spicies, otherJedi.spicies);
	this->militaryRank = new char[strlen(otherJedi.militaryRank) + 1];
	CopyText1(this->militaryRank, otherJedi.militaryRank);

	return *this;
}

Jedi::Jedi(const char* _name, const JediRank _rank, const float _midichlorian, const Planet _planet, const char* _spicies, const char* _militaryRank)
{
	CopyText1(this->name, _name);
	this->rank = _rank;
	this->midichlorian = _midichlorian;
	this->planet = _planet;
	CopyText1(this->spicies, _spicies);
	CopyText1(this->militaryRank, _militaryRank);
}

Jedi::~Jedi()
{
	delete[] name;
	midichlorian = 0.0;
	delete[] spicies;
	delete[] militaryRank;
}

void Jedi::Print()
{
	std::cout << "Jedi " << this->name <<
		"with rank: " << EnumTocharArray(this->rank) <<
		" with midichlorian: " << this->midichlorian <<
		" from " << this->planet.GetName() <<
		"with spicies: " << this->spicies <<
		" with militaryRank: " << this->militaryRank << std::endl;
}

void Jedi::SetName(const char* _name)
{
	CopyText1(this->name, _name);
}

void Jedi::SetRank(const JediRank _rank)
{
	this->rank = _rank;
}

void Jedi::SetMidichlorian(const float _midichlorian)
{
	this->midichlorian = _midichlorian;
}

void Jedi::SetPlanet(const Planet _planet)
{
	this->planet = _planet;
}

void Jedi::SetSpicies(const char* _spicies)
{
	CopyText1(this->spicies, _spicies);
}

void Jedi::SetMilitaryRank(const char* _militaryRank)
{
	CopyText1(this->militaryRank, _militaryRank);
}

char* Jedi::GetName()
{
	return this->name;
}

JediRank Jedi::GetRank()
{
	return this->rank;
}

float Jedi::GetMidichlorian()
{
	return this->midichlorian;
}

Planet Jedi::GetPlanet()
{
	return this->planet;
}

char* Jedi::GetSpicies()
{
	return this->spicies;
}

char* Jedi::GetMilitaryRank()
{
	return this->militaryRank;
}

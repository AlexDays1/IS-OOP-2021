#include "Planet.h"
#include <cstring>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable:4996)

char* EnumToCharArray(PlanetType type, char* planetType)
{
	if (type == PlanetType::CarbonPlanet)
	{
		strcpy(planetType, "CarbonPlanet");
		return planetType;
	}
	else if (type == PlanetType::ChthonianPlanet)
	{
		strcpy(planetType, "ChthonianPlanet");
		return planetType;
	}
	else if (type == PlanetType::CorelessPlanet)
	{
		strcpy(planetType, "CorelessPlanet");
		return planetType;
	}
	else if (type == PlanetType::DesertPlanet)
	{
		strcpy(planetType, "DesertPlanet");
		return planetType;
	}
	else if (type == PlanetType::GasDwarf)
	{
		strcpy(planetType, "GasDwarf");
		return planetType;
	}
	else if (type == PlanetType::GasGiant)
	{
		strcpy(planetType, "GasGiant");
		return planetType;
	}
	else if (type == PlanetType::HeliumPlanet)
	{
		strcpy(planetType, "HeliumPlanet");
		return planetType;
	}
	else if (type == PlanetType::IceGiant)
	{
		strcpy(planetType, "IceGiant");
		return planetType;
	}
	else if (type == PlanetType::IcePlanet)
	{
		strcpy(planetType, "IcePlanet");
		return planetType;
	}
	else if (type == PlanetType::IronPlanet)
	{
		strcpy(planetType, "IronPlanet");
		return planetType;
	}
	else if (type == PlanetType::LavaPlanet)
	{
		strcpy(planetType, "LavaPlanet");
		return planetType;
	}
	else if (type == PlanetType::OceanPlanet)
	{
		strcpy(planetType, "OceanPlanet");
		return planetType;
	}
	else if (type == PlanetType::ProtoPlanet)
	{
		strcpy(planetType, "ProtoPlanet");
		return planetType;
	}
	else if (type == PlanetType::PuffyPlanet)
	{
		strcpy(planetType, "PuffyPlanet");
		return planetType;
	}
	else if (type == PlanetType::SilicatePlanet)
	{
		strcpy(planetType, "SilicatePlanet");
		return planetType;
	}
	else
	{
		strcpy(planetType, "TerrestricalPlanet");
		return planetType;
	}
}

Planet::Planet()
{
	this->name = nullptr;
	this->planetSystem = nullptr;
	this->republic = nullptr;
	this->planetType = PlanetType::TerrestricalPlanet;
}

Planet::Planet(const Planet& otherPlanet)
{
	this->name = new char[strlen(otherPlanet.name) + 1];
	strcpy(this->name, otherPlanet.name);
	this->planetSystem = new char[strlen(otherPlanet.planetSystem) + 1];
	strcpy(this->planetSystem, otherPlanet.planetSystem);
	this->republic = new char[strlen(otherPlanet.republic) + 1];
	strcpy(this->republic, otherPlanet.republic);
	this->planetType = otherPlanet.planetType;
}

Planet& Planet::operator=(const Planet& otherPlanet)
{
	if (this != &otherPlanet)
	{
		delete[] name;
		delete[] planetSystem;
		delete[] republic;
	}

	this->name = new char[strlen(otherPlanet.name) + 1];
	strcpy(this->name, otherPlanet.name);
	this->planetSystem = new char[strlen(otherPlanet.planetSystem) + 1];
	strcpy(this->planetSystem, otherPlanet.planetSystem);
	this->republic = new char[strlen(otherPlanet.republic) + 1];
	strcpy(this->republic, otherPlanet.republic);
	this->planetType = otherPlanet.planetType;

	return *this;
}

Planet::Planet(const char* otherName, const char* otherPlanetSystem, const char* otherRepublic, const PlanetType _planetType)
{
	this->SetName(otherName);
	this->SetPlanetSystem(otherPlanetSystem);
	this->SetRepublic(otherRepublic);
	this->SetPlanetType(_planetType);
}

Planet::~Planet()
{
	delete[] this->name;
	delete[] this->planetSystem;
	delete[] this->republic;
}

void Planet::Print()
{
	char* type = new char[16];
	type = EnumToCharArray(this->planetType, type);

	std::cout << "Planet " << this->name << " from " << this->planetSystem << " belongs to republic " << this->republic << "Planet Type:: " << type << std::endl;

	delete[] type;
}

void Planet::SetName(const char* _name)
{
	if (this->name == nullptr)
	{
		delete[] this->name;
	}

	this->name = new char[strlen(_name) + 1];
	strcpy(this->name, _name);
}

void Planet::SetPlanetSystem(const char* _planetSystem)
{
	if (this->planetSystem == nullptr)
	{
		delete[] this->planetSystem;
	}

	this->planetSystem = new char[strlen(_planetSystem) + 1];
	strcpy(this->planetSystem, _planetSystem);
}

void Planet::SetRepublic(const char* _republic)
{
	if (this->republic == nullptr)
	{
		delete[] this->republic;
	}

	this->republic = new char[strlen(_republic) + 1];
	strcpy(this->republic, _republic);
}

void Planet::SetPlanetType(PlanetType _planetType)
{
	this->planetType = _planetType;
}

char* Planet::GetName() const
{
	return this->name;
}

char* Planet::GetPlanetSystem() const
{
	return this->planetSystem;
}

char* Planet::GetRepublic() const
{
	return this->republic;
}

PlanetType Planet::GetPlanetType() const
{
	return this->planetType;
}

std::ostream& operator<<(std::ostream& out, const Planet& planet)
{
	out << "Name: " << planet.GetName()
		<< " from " << planet.GetPlanetSystem()
		<< " belongs to republic " << planet.GetRepublic()
		<< " type ";

	if (planet.GetPlanetType() == PlanetType::CarbonPlanet)
	{
		out << "CarbonPlanet" << std::endl;
	}
	else if (planet.GetPlanetType() == PlanetType::ChthonianPlanet)
	{
		out << "ChthonianPlanet" << std::endl;
	}
	else if (planet.GetPlanetType() == PlanetType::CorelessPlanet)
	{
		out << "CorelessPlanet" << std::endl;
	}
	else if (planet.GetPlanetType() == PlanetType::DesertPlanet)
	{
		out << "DesertPlanet" << std::endl;
	}
	else if (planet.GetPlanetType() == PlanetType::GasDwarf)
	{
		out << "GasDwarf" << std::endl;
	}
	else if (planet.GetPlanetType() == PlanetType::GasGiant)
	{
		out << "GasGiant" << std::endl;
	}
	else if (planet.GetPlanetType() == PlanetType::HeliumPlanet)
	{
		out << "HeliumPlanet" << std::endl;
	}
	else if (planet.GetPlanetType() == PlanetType::IceGiant)
	{
		out << "IceGiant" << std::endl;
	}
	else if (planet.GetPlanetType() == PlanetType::IcePlanet)
	{
		out << "IcePlanet" << std::endl;
	}
	else if (planet.GetPlanetType() == PlanetType::IronPlanet)
	{
		out << "IronPlanet" << std::endl;
	}
	else if (planet.GetPlanetType() == PlanetType::LavaPlanet)
	{
		out << "LavaPlanet" << std::endl;
	}
	else if (planet.GetPlanetType() == PlanetType::OceanPlanet)
	{
		out << "OceanPlanet" << std::endl;
	}
	else if (planet.GetPlanetType() == PlanetType::ProtoPlanet)
	{
		out << "ProtoPlanet" << std::endl;
	}
	else if (planet.GetPlanetType() == PlanetType::PuffyPlanet)
	{
		out << "PuffyPlanet" << std::endl;
	}
	else if (planet.GetPlanetType() == PlanetType::SilicatePlanet)
	{
		out << "SilicatePlanet" << std::endl;
	}
	else
	{
		out << "TerrestricalPlanet" << std::endl;
	}

	return out;
}
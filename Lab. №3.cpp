#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

class track
{
private:
	int track_number;
	int max_people_amount;
	int people_amount;
	int* peoples_ages;
public:
	track()
	{
		track_number = 0;
		max_people_amount = 10;
		people_amount = 0;
		peoples_ages = new int[max_people_amount];
		for (int i = 0; i < max_people_amount; i++)
		{
			peoples_ages[i] = 0;
		}
	}
	track(int _track_number, int _max_people_amount, int _people_amount)
	{
		if (_track_number >= 0)
		{
			track_number = _track_number;
		}
		else
		{
			track_number = 0;
		}
		if (_max_people_amount >= 1)
		{
			max_people_amount = _max_people_amount;
		}
		else
		{
			max_people_amount = 10;
		}
		if (_people_amount <= max_people_amount && _people_amount >= 0)
		{
			people_amount = _people_amount;
		}
		else
		{
			people_amount = 0;
		}
		peoples_ages = new int[max_people_amount];
		for (int i = 0; i < max_people_amount; i++)
		{
			peoples_ages[i] = 0;
		}
	}
	track(const track& src_object)
	{
		track_number = src_object.track_number;
		people_amount = src_object.people_amount;
		max_people_amount = src_object.max_people_amount;
		peoples_ages = new int[max_people_amount];
		for (int i = 0; i < people_amount; i++)
		{
			peoples_ages[i] = src_object.peoples_ages[i];
		}
	}
	~track()
	{
		delete[]peoples_ages;
	}
	int get_track_number() const { return track_number; }
	int get_max_people_amount() const { return max_people_amount; }
	int max_people_amount() const { return people_amount; }
	void set_track_number(int _settable_track_number)
	{
		if (_settable_track_number >= 0)
		{
			track_number = _settable_track_number;
		}
		else
		{
			track_number = 0;
		}
	}
};

class childrens_track : public track
{
public:
	childrens_track() : track() { }
	childrens_track(int _track_number, int _max_peoples_amount, int _peoples_amount) : track(_track_number, _max_peoples_amount, _peoples_amount) { }
	childrens_track(const childrens_track& src_object) : track(src_object) { }
	~childrens_track() { }
};

class adults_track : public track
{
public:
	adults_track() : track() { }
	adults_track(int _track_number, int _max_peoples_amount, int _peoples_amount) : track(_track_number, _max_peoples_amount, _peoples_amount) { }
	adults_track(const adults_track& src_object) : track(src_object) { }
	~adults_track() { }
};

class swimming_pool
{
private:

public:

};

class sport_complex
{
private:

public:

};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	return 0;
}
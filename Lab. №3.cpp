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
	int get_people_amount() const { return people_amount; }
	int get_human_age_by_index(int _human_age_index) const
	{
		int human_age = 0;
		if (_human_age_index < people_amount)
		{
			human_age = peoples_ages[_human_age_index];
		}
		return (human_age);
	}
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
	bool add_human_age(int _human_age)
	{
		bool result = false;
		if (people_amount < max_people_amount)
		{
			peoples_ages[people_amount] = _human_age;
			people_amount++;
			result = true;
		}
		return (result);
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
	int swimming_pool_number;
	int max_childrens_tracks_amount;
	int childrens_tracks_amount;
	childrens_track** childrens_tracks;
	int max_adults_tracks_amount;
	int adults_tracks_amount;
	adults_track** adults_tracks;
	double max_depth;
	double lenght;
public:
	swimming_pool()
	{
		int i = 0;
		swimming_pool_number = 0;
		max_childrens_tracks_amount = 2;
		childrens_tracks_amount = 2;
		childrens_tracks = new childrens_track * [max_childrens_tracks_amount];
		for (i = 0; i < max_childrens_tracks_amount; i++)
		{
			childrens_tracks[i] = new childrens_track(i + 1, 10, 0);
		}
		max_adults_tracks_amount = 3;
		adults_tracks_amount = 3;
		adults_tracks = new adults_track * [max_adults_tracks_amount];
		for (i = 0; i < max_adults_tracks_amount; i++)
		{
			adults_tracks[i] = new adults_track(i + 1, 10, 0);
		}
		max_depth = 5.0;
		lenght = 25.0;
	}
	swimming_pool(int _swimming_pool_number, int _max_childrens_tracks_amount, int _childrens_tracks_amount, int _max_adults_tracks_amount, int _adults_tracks_amount, double _max_depth, double _lenght)
	{
		int i = 0;
		if (_swimming_pool_number >= 0)
		{
			swimming_pool_number = _swimming_pool_number;
		}
		else
		{
			swimming_pool_number = 0;
		}
		if (_max_childrens_tracks_amount >= 1)
		{
			max_childrens_tracks_amount = _max_childrens_tracks_amount;
		}
		else
		{
			max_childrens_tracks_amount = 2;
		}
		if (_childrens_tracks_amount <= _max_childrens_tracks_amount && _childrens_tracks_amount >= 1)
		{
			childrens_tracks_amount = _childrens_tracks_amount;
		}
		else
		{
			childrens_tracks_amount = 0;
		}
		childrens_tracks = new childrens_track * [max_childrens_tracks_amount];
		for (i = 0; i < max_childrens_tracks_amount; i++)
		{
			childrens_tracks[i] = new childrens_track(i + 1, 10, 0);
		}
		if (_max_adults_tracks_amount >= 1)
		{
			max_adults_tracks_amount = _max_adults_tracks_amount;
		}
		else
		{
			max_adults_tracks_amount = 3;
		}
		if (_adults_tracks_amount <= _max_adults_tracks_amount && _adults_tracks_amount >= 1)
		{
			adults_tracks_amount = _adults_tracks_amount;
		}
		else
		{
			adults_tracks_amount = 3;
		}
		adults_tracks = new adults_track * [max_adults_tracks_amount];
		for (i = 0; i < max_adults_tracks_amount; i++)
		{
			adults_tracks[i] = new adults_track(i + 1, 10, 0);
		}
	}
	swimming_pool(swimming_pool& src_object)
	{
		int i = 0;
		int j = 0;
		swimming_pool_number = src_object.swimming_pool_number;
		max_childrens_tracks_amount = src_object.max_childrens_tracks_amount;
		childrens_tracks_amount = src_object.childrens_tracks_amount;
		childrens_tracks = new childrens_track * [max_childrens_tracks_amount];
		for (i = 0; i < childrens_tracks_amount; i++)
		{
			childrens_tracks[i] = new childrens_track(*(src_object.childrens_tracks[i]));
		}
		max_adults_tracks_amount = src_object.max_adults_tracks_amount;
		adults_tracks_amount = src_object.adults_tracks_amount;
		adults_tracks = new adults_track * [max_adults_tracks_amount];
		for (i = 0; i < adults_tracks_amount; i++)
		{
			adults_tracks[i] = new adults_track(*(src_object.adults_tracks[i]));
		}
		max_depth = src_object.max_depth;
		lenght = src_object.lenght;
	}
	~swimming_pool()
	{
		int i = 0;
		for (i = 0; i < max_childrens_tracks_amount; i++)
		{
			delete childrens_tracks[i];
		}
		delete[]childrens_tracks;
		for (i = 0; i < max_adults_tracks_amount; i++)
		{
			delete adults_tracks[i];
		}
		delete[]adults_tracks;
	}
	int get_swimming_pool_number() const { return swimming_pool_number; }
	int get_max_childrens_tracks_amount() const { return max_childrens_tracks_amount; }
	int get_childrens_tracks_amount() const { return childrens_tracks_amount; }
	int get_max_adults_tracks_amount() const { return max_adults_tracks_amount; }
	int get_adults_tracks_amount() const { return adults_tracks_amount; }
	double get_max_depth() const { return max_depth; }
	double get_lenght() const { return lenght; }
};

class sport_complex
{
private:
	string name_sport_complex;
	int max_swimming_pools_amount;
	int swimming_pools_amount;
	swimming_pool** swimming_pools;
public:
	sport_complex()
	{
		name_sport_complex = "Не определено";
		max_swimming_pools_amount = 5;
		swimming_pools_amount = 5;
		swimming_pools = new swimming_pool * [max_swimming_pools_amount];
		for (int i = 0; i < max_swimming_pools_amount; i++)
		{
			swimming_pools[i] = new swimming_pool(i + 1, 2, 2, 3, 3, 5, 25);
		}
	}
	sport_complex(string _name_sport_complex, int _max_swimming_pools_amount, int _swimming_pools_amount)
	{
		if (_name_sport_complex != "")
		{
			name_sport_complex = _name_sport_complex;
		}
		else
		{
			name_sport_complex = "Не определено";
		}
		if (_max_swimming_pools_amount >= 1)
		{
			max_swimming_pools_amount = _max_swimming_pools_amount;
		}
		else
		{
			max_swimming_pools_amount = 5;
		}
		if (_swimming_pools_amount <= _max_swimming_pools_amount && swimming_pools_amount >= 1)
		{
			swimming_pools_amount = _swimming_pools_amount;
		}
		else
		{
			swimming_pools_amount = 5;
		}
		swimming_pools = new swimming_pool * [max_swimming_pools_amount];
		for (int i = 0; i < max_swimming_pools_amount; i++)
		{
			swimming_pools[i] = new swimming_pool(i + 1, 2, 2, 3, 3, 5, 25);
		}
	}
	sport_complex(sport_complex& src_object)
	{
		int j = 0;
		name_sport_complex = src_object.name_sport_complex;
		max_swimming_pools_amount = src_object.max_swimming_pools_amount;
		swimming_pools_amount = src_object.swimming_pools_amount;
		swimming_pools = new swimming_pool * [max_swimming_pools_amount];
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			swimming_pools[i] = new swimming_pool(*(src_object.swimming_pools[i]));
		}
	}
	~sport_complex()
	{
		for (int i = 0; i < max_swimming_pools_amount; i++)
		{
			delete swimming_pools[i];
		}
		delete[]swimming_pools;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	return 0;
}
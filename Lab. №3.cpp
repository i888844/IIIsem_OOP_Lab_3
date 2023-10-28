﻿#include <iostream>
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
		return result;
	}
	bool remove_human_age(int _human_age_index)
	{
		bool result = false;
		if (_human_age_index >= 0 && _human_age_index < people_amount)
		{
			for (int i = _human_age_index; i < people_amount; i++)
			{
				peoples_ages[i] = peoples_ages[i + 1];
			}
			people_amount--;
			result = true;
		}
		return result;
	}
	bool remove_all_humans_age()
	{
		bool result = false;
		if (people_amount > 0)
		{
			for (int i = 0; i < people_amount; i++)
			{
				peoples_ages[i] = 0;
			}
			people_amount = 0;
			result = true;
		}
		return result;
	}
	void output_track()
	{
		cout << "Дорожка №" << track_number << endl;
		cout << "Максимальное количество людей на дорожке: " << max_people_amount << endl;
		cout << "Количество людей на дорожке: " << people_amount << endl;
		cout << "Люди на дорожке: " << endl;
		if (people_amount > 0)
		{
			for (int i = 0; i < people_amount; i++)
			{
				cout << i + 1 << ". " << peoples_ages[i] << endl;
			}
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
	int get_childrens_track_people_amount(int _track_number)
	{
		int childrens_track_people_amount = 0;
		for (int i = 0; i < childrens_tracks_amount; i++)
		{
			if (_track_number == childrens_tracks[i]->get_track_number())
			{
				childrens_track_people_amount = childrens_tracks[i]->get_people_amount();
				break;
			}
		}
		return childrens_track_people_amount;
	}
	int get_adults_track_people_amount(int _track_number)
	{
		int adults_track_people_amount = 0;
		for (int i = 0; i < adults_tracks_amount; i++)
		{
			if (_track_number == adults_tracks[i]->get_track_number())
			{
				adults_track_people_amount = adults_tracks[i]->get_people_amount();
				break;
			}
		}
		return adults_track_people_amount;
	}
	int get_childrens_track_max_people_amount(int _track_number)
	{
		int childrens_track_people_amount = 0;
		for (int i = 0; i < childrens_tracks_amount; i++)
		{
			if (_track_number == childrens_tracks[i]->get_track_number())
			{
				childrens_track_people_amount = childrens_tracks[i]->get_max_people_amount();
				break;
			}
		}
		return childrens_track_people_amount;
	}
	int get_adults_track_max_people_amount(int _track_number)
	{
		int adults_track_people_amount = 0;
		for (int i = 0; i < adults_tracks_amount; i++)
		{
			if (_track_number == adults_tracks[i]->get_track_number())
			{
				adults_track_people_amount = adults_tracks[i]->get_max_people_amount();
				break;
			}
		}
		return adults_track_people_amount;
	}
	void set_swimming_pool_number(int _settable_swimming_pool_number)
	{
		if (_settable_swimming_pool_number >= 0)
		{
			swimming_pool_number = _settable_swimming_pool_number;
		}
		else
		{
			swimming_pool_number = 0;
		}
	}
	void set_childrens_track_number(int _track_number, int _settable_track_number)
	{
		for (int i = 0; i < childrens_tracks_amount; i++)
		{
			if (_track_number == childrens_tracks[i]->get_track_number())
			{
				bool this_number_did_not_meet = true;
				for (int j = 0; j < childrens_tracks_amount; j++)
				{
					if (_settable_track_number == childrens_tracks[j]->get_track_number())
					{
						this_number_did_not_meet = false;
						break;
					}
				}
				if (this_number_did_not_meet)
				{
					childrens_tracks[i]->set_track_number(_settable_track_number);
				}
				break;
			}
		}
	}
	void set_adults_track_number(int _track_number, int _settable_track_number)
	{
		for (int i = 0; i < adults_tracks_amount; i++)
		{
			if (_track_number == adults_tracks[i]->get_track_number())
			{
				bool this_number_did_not_meet = true;
				for (int j = 0; j < adults_tracks_amount; j++)
				{
					if (_settable_track_number == adults_tracks[j]->get_track_number())
					{
						this_number_did_not_meet = false;
						break;
					}
				}
				if (this_number_did_not_meet)
				{
					adults_tracks[i]->set_track_number(_settable_track_number);
				}
				break;
			}
		}
	}
	void output_swimming_pool()
	{
		int i = 0;
		cout << "Бассейн №" << swimming_pool_number << endl;
		cout << "Количество детских дорожек: " << childrens_tracks_amount << endl;
		cout << "Количество взрослых дорожек: " << adults_tracks_amount << endl;
		cout << "Максимальная глубина: " << max_depth << endl;
		cout << "Длина: " << lenght << endl;
		cout << "Детские дорожки:" << endl;
		for (i = 0; i < childrens_tracks_amount; i++)
		{
			childrens_tracks[i]->output_track();
		}
		cout << "Взрослые дорожки" << endl;
		for (i = 0; i < adults_tracks_amount; i++)
		{
			adults_tracks[i]->output_track();
		}
	}
	void output_childrens_track(int _track_number)
	{
		for (int i = 0; i < childrens_tracks_amount; i++)
		{
			if (_track_number == childrens_tracks[i]->get_track_number())
			{
				childrens_tracks[i]->output_track();
			}
		}
	}
	void output_adults_track(int _track_number)
	{
		for (int i = 0; i < adults_tracks_amount; i++)
		{
			if (_track_number == adults_tracks[i]->get_track_number())
			{
				adults_tracks[i]->output_track();
			}
		}
	}
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
	string get_name_sport_complex() const { return name_sport_complex; }
	int get_max_swimming_pools_amount() const { return max_swimming_pools_amount; }
	int get_swimming_pools_amount() const { return swimming_pools_amount; }
	int get_childrens_track_people_amount(int _swimming_pool_number, int _track_number) const { return swimming_pools[_swimming_pool_number]->get_childrens_track_people_amount(_track_number); }
	int get_adults_track_people_amount(int _swimming_pool_number, int _track_number) const { return swimming_pools[_swimming_pool_number]->get_adults_track_people_amount(_track_number); }
	int get_childrens_track_max_people_amount(int _swimming_pool_number, int _track_number) const { return swimming_pools[_swimming_pool_number]->get_childrens_track_max_people_amount(_track_number); }
	int get_adults_track_max_people_amount(int _swimming_pool_number, int _track_number) const { return swimming_pools[_swimming_pool_number]->get_adults_track_max_people_amount(_track_number); }
	void set_name_sport_complex(string _settable_name_sport_complex)
	{
		if (_settable_name_sport_complex != "")
		{
			name_sport_complex = _settable_name_sport_complex;
		}
		else
		{
			name_sport_complex = "Не определено";
		}
	}
	void set_swimming_pool_number(int _swimming_pool_number, int _settable_swimming_pool_number)
	{
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				bool this_number_did_not_meet = true;
				for (int j = 0; j < swimming_pools_amount; j++)
				{
					if (_settable_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
					{
						this_number_did_not_meet = false;
						break;
					}
				}
				if (this_number_did_not_meet)
				{
					swimming_pools[i]->set_swimming_pool_number(_settable_swimming_pool_number);
				}
				break;
			}
		}
	}
	void set_childrens_track_number(int _swimming_pool_number, int _track_number, int _settable_track_number)
	{
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				swimming_pools[i]->set_childrens_track_number(_track_number, _settable_track_number);
				break;
			}
		}
	}
	void set_adults_track_number(int _swimming_pool_number, int _track_number, int _settable_track_number)
	{
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				swimming_pools[i]->set_adults_track_number(_track_number, _settable_track_number);
				break;
			}
		}
	}
	void output_sport_complex()
	{
		cout << "Спортивный комплекс \"" << name_sport_complex << "\"" << endl;
		cout << "Максимальное количество бассейнов: " << max_swimming_pools_amount << endl;
		cout << "Количество бассейнов: " << swimming_pools_amount << endl;
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			swimming_pools[i]->output_swimming_pool();
		}
	}
	void output_swimming_pool(int _swimming_pool_number)
	{
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				swimming_pools[i]->output_swimming_pool();
				break;
			}
		}
	}
	void output_childrens_track(int _swimming_pool_number, int _track_number)
	{
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				swimming_pools[i]->output_childrens_track(_track_number);
				break;
			}
		}
	}
	void output_adults_track(int _swimming_pool_number, int _track_number)
	{
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				swimming_pools[i]->output_adults_track(_track_number);
				break;
			}
		}
	}
	bool add_swimming_pool_by_default_constructor()
	{
		bool result = false;
		if (swimming_pools_amount < max_swimming_pools_amount)
		{
			swimming_pools[swimming_pools_amount + 1] = new swimming_pool();
			swimming_pools_amount++;
			result = true;
		}
		return result;
	}
	bool add_swimming_pool_by_constructor_with_parameters(int _swimming_pool_number, int _max_childrens_tracks_amount, int _childrens_tracks_amount, int _max_adults_tracks_amount, int _adults_tracks_amount, double _max_depth, double _lenght)
	{
		bool result = false;
		if (swimming_pools_amount < max_swimming_pools_amount)
		{
			swimming_pools[swimming_pools_amount + 1] = new swimming_pool(_swimming_pool_number, _max_childrens_tracks_amount, _childrens_tracks_amount, _max_adults_tracks_amount, _adults_tracks_amount, _max_depth, _lenght);
			swimming_pools_amount++;
			result = true;
		}
		return result;
	}
	bool add_swimming_pool_by_copy_constructor(swimming_pool& src_object)
	{
		bool result = false;
		if (swimming_pools_amount < max_swimming_pools_amount)
		{
			swimming_pools[swimming_pools_amount + 1] = new swimming_pool(src_object);
			swimming_pools_amount++;
			result = true;
		}
		return result;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	return 0;
}
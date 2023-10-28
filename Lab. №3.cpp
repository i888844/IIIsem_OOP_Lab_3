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
	void output_track()
	{
		cout << "Дорожка №" << track_number << endl;
		cout << "Максимальное количество людей на дорожке: " << max_people_amount << " ед." << endl;
		cout << "Количество людей на дорожке: " << people_amount << " ед." << endl;
		cout << "Люди на дорожке: " << endl;
		if (people_amount > 0)
		{
			for (int i = 0; i < people_amount; i++)
			{
				cout << i + 1 << ". " << peoples_ages[i] << endl;
			}
		}
	}
	void let_human_on_track(int _human_age)
	{
		peoples_ages[people_amount + 1] = _human_age;
		people_amount++;
	}
	void remove_human_from_track(int _human_number)
	{
		for (int i = _human_number; i < people_amount; i++)
		{
			peoples_ages[i] = peoples_ages[i + 1];
		}
		people_amount--;
	}
	void remove_all_humans_from_track()
	{
		for (int i = 0; i < people_amount; i++)
		{
			peoples_ages[i] = 0;
		}
		people_amount = 0;
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
		if (_max_depth >= 2.0)
		{
			max_depth = _max_depth;
		}
		else
		{
			max_depth = 5.0;
		}
		if (_lenght >= 5.0)
		{
			lenght = _lenght;
		}
		else
		{
			lenght = 25.0;
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
		cout << "Количество детских дорожек: " << childrens_tracks_amount << " ед." << endl;
		cout << "Количество взрослых дорожек: " << adults_tracks_amount << " ед." << endl;
		cout << "Максимальная глубина: " << max_depth << " м" << endl;
		cout << "Длина: " << lenght << " м" << endl;
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
	bool add_childrens_track_by_default_constructor()
	{
		bool result = false;
		if (childrens_tracks_amount < max_childrens_tracks_amount)
		{
			childrens_tracks[childrens_tracks_amount + 1] = new childrens_track();
			childrens_tracks_amount++;
			result = true;
		}
		return false;
	}
	bool add_childrens_track_by_constructor_with_parameters(int _track_number, int _max_people_amount, int _people_amount)
	{
		bool result = false;
		if (childrens_tracks_amount < max_childrens_tracks_amount)
		{
			childrens_tracks[childrens_tracks_amount + 1] = new childrens_track(_track_number, _max_people_amount, _people_amount);
			childrens_tracks_amount++;
			result = true;
		}
		return false;
	}
	bool add_childrens_track_by_copy_constructor(childrens_track& src_object)
	{
		bool result = false;
		if (childrens_tracks_amount < max_childrens_tracks_amount)
		{
			childrens_tracks[childrens_tracks_amount + 1] = new childrens_track(src_object);
			childrens_tracks_amount++;
			result = true;
		}
		return false;
	}
	bool delete_childrens_track(int _track_number)
	{
		bool result = false;
		for (int i = 0; i < childrens_tracks_amount; i++)
		{
			if (_track_number == childrens_tracks[i]->get_track_number())
			{
				delete childrens_tracks[i];
				result = true;
				break;
			}
		}
		return result;
	}
	bool add_adults_track_by_default_constructor()
	{
		bool result = false;
		if (adults_tracks_amount < max_adults_tracks_amount)
		{
			adults_tracks[adults_tracks_amount + 1] = new adults_track();
			adults_tracks_amount++;
			result = true;
		}
		return false;
	}
	bool add_adults_track_by_constructor_with_parameters(int _track_number, int _max_people_amount, int _people_amount)
	{
		bool result = false;
		if (adults_tracks_amount < max_adults_tracks_amount)
		{
			adults_tracks[adults_tracks_amount + 1] = new adults_track(_track_number, _max_people_amount, _people_amount);
			adults_tracks_amount++;
			result = true;
		}
		return false;
	}
	bool add_adults_track_by_copy_constructor(adults_track& src_object)
	{
		bool result = false;
		if (adults_tracks_amount < max_adults_tracks_amount)
		{
			adults_tracks[adults_tracks_amount + 1] = new adults_track(src_object);
			adults_tracks_amount++;
			result = true;
		}
		return false;
	}
	bool delete_adults_track(int _track_number)
	{
		bool result = false;
		for (int i = 0; i < adults_tracks_amount; i++)
		{
			if (_track_number == adults_tracks[i]->get_track_number())
			{
				delete adults_tracks[i];
				result = true;
				break;
			}
		}
		return result;
	}
	bool let_human_on_childrens_track(int _track_number, int _human_age)
	{
		bool result = false;
		for (int i = 0; i < childrens_tracks_amount; i++)
		{
			if (_track_number == childrens_tracks[i]->get_track_number())
			{
				if ((childrens_tracks[i]->get_people_amount() < childrens_tracks[i]->get_max_people_amount()) && (_human_age > 0 && _human_age < 12))
				{
					childrens_tracks[i]->let_human_on_track(_human_age);
					result = true;
				}
				break;
			}
		}
		return result;
	}
	bool remove_human_from_childrens_track(int _track_number, int _human_number)
	{
		bool result = false;
		for (int i = 0; i < childrens_tracks_amount; i++)
		{
			if (_track_number == childrens_tracks[i]->get_track_number())
			{
				childrens_tracks[i]->remove_human_from_track(_human_number);
				result = true;
				break;
			}
		}
		return result;
	}
	bool remove_all_humans_from_childrens_track(int _track_number)
	{
		bool result = false;
		for (int i = 0; i < childrens_tracks_amount; i++)
		{
			if (_track_number == childrens_tracks[i]->get_track_number())
			{
				childrens_tracks[i]->remove_all_humans_from_track();
				result = true;
				break;
			}
		}
		return result;
	}
	bool let_human_on_adults_track(int _track_number, int _human_age)
	{
		bool result = false;
		for (int i = 0; i < adults_tracks_amount; i++)
		{
			if (_track_number == adults_tracks[i]->get_track_number())
			{
				if ((adults_tracks[i]->get_people_amount() < adults_tracks[i]->get_max_people_amount()) && (_human_age >= 12))
				{
					adults_tracks[i]->let_human_on_track(_human_age);
					result = true;
				}
				break;
			}
		}
		return result;
	}
	bool remove_human_from_adults_track(int _track_number, int _human_number)
	{
		bool result = false;
		for (int i = 0; i < adults_tracks_amount; i++)
		{
			if (_track_number == adults_tracks[i]->get_track_number())
			{
				adults_tracks[i]->remove_human_from_track(_human_number);
				result = true;
				break;
			}
		}
		return result;
	}
	bool remove_all_humans_from_adults_track(int _track_number)
	{
		bool result = false;
		for (int i = 0; i < adults_tracks_amount; i++)
		{
			if (_track_number == adults_tracks[i]->get_track_number())
			{
				adults_tracks[i]->remove_all_humans_from_track();
				result = true;
				break;
			}
		}
		return result;
	}
	void remove_all_humans_from_swimming_pool()
	{
		int i = 0;
		for (i = 0; i < childrens_tracks_amount; i++)
		{
			childrens_tracks[i]->remove_all_humans_from_track();
		}
		for (i = 0; i < adults_tracks_amount; i++)
		{
			adults_tracks[i]->remove_all_humans_from_track();
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
			swimming_pools[i] = new swimming_pool(i + 1, 2, 2, 3, 3, 5.0, 25.0);
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
		cout << "Максимальное количество бассейнов: " << max_swimming_pools_amount << " ед." << endl;
		cout << "Количество бассейнов: " << swimming_pools_amount << " ед." << endl;
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
	bool delete_swimming_pool(int _swimming_pool_number)
	{
		bool result = false;
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				delete swimming_pools[i];
				result = true;
				break;
			}
		}
		return result;
	}
	bool add_childrens_track_by_default_constructor(int _swimming_pool_number)
	{
		bool result = false;
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				result = swimming_pools[i]->add_childrens_track_by_default_constructor();
				break;
			}
		}
		return result;
	}
	bool add_childrens_track_by_constructor_with_parameters(int _swimming_pool_number, int _track_number, int _max_people_amount, int _people_amount)
	{
		bool result = false;
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				result = swimming_pools[i]->add_childrens_track_by_constructor_with_parameters(_track_number, _max_people_amount, _people_amount);
				break;
			}
		}
		return result;
	}
	bool add_childrens_track_by_copy_constructor(int _swimming_pool_number, childrens_track& src_object)
	{
		bool result = false;
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				result = swimming_pools[i]->add_childrens_track_by_copy_constructor(src_object);
				break;
			}
		}
		return result;
	}
	bool delete_childrens_track(int _swimming_pool_number, int _track_number)
	{
		bool result = false;
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				result = swimming_pools[i]->delete_childrens_track(_track_number);
				break;
			}
		}
		return result;
	}
	bool add_adults_track_by_default_constructor(int _swimming_pool_number)
	{
		bool result = false;
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				result = swimming_pools[i]->add_adults_track_by_default_constructor();
				break;
			}
		}
		return result;
	}
	bool add_adults_track_by_constructor_with_parameters(int _swimming_pool_number, int _track_number, int _max_people_amount, int _people_amount)
	{
		bool result = false;
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				result = swimming_pools[i]->add_adults_track_by_constructor_with_parameters(_track_number, _max_people_amount, _people_amount);
				break;
			}
		}
		return result;
	}
	bool add_adults_track_by_copy_constructor(int _swimming_pool_number, adults_track& src_object)
	{
		bool result = false;
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				result = swimming_pools[i]->add_adults_track_by_copy_constructor(src_object);
				break;
			}
		}
		return result;
	}
	bool delete_adults_track(int _swimming_pool_number, int _track_number)
	{
		bool result = false;
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				result = swimming_pools[i]->delete_adults_track(_track_number);
				break;
			}
		}
		return result;
	}
	bool let_human_on_childrens_track(int _swimming_pool_number, int _track_number, int _human_age)
	{
		bool result = false;
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				result = swimming_pools[i]->let_human_on_childrens_track(_track_number, _human_age);
				break;
			}
		}
		return result;
	}
	bool remove_human_from_childrens_track(int _swimming_pool_number, int _track_number, int _human_number)
	{
		bool result = false;
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				result = swimming_pools[i]->remove_human_from_childrens_track(_track_number, _human_number);
				break;
			}
		}
		return result;
	}
	bool remove_all_humans_from_childrens_track(int _swimming_pool_number, int _track_number)
	{
		bool result = false;
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				result = swimming_pools[i]->remove_all_humans_from_childrens_track(_track_number);
				break;
			}
		}
		return result;
	}
	bool let_human_on_adults_track(int _swimming_pool_number, int _track_number, int _human_age)
	{
		bool result = false;
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				result = swimming_pools[i]->let_human_on_adults_track(_track_number, _human_age);
				break;
			}
		}
		return result;
	}
	bool remove_human_from_adults_track(int _swimming_pool_number, int _track_number, int _human_number)
	{
		bool result = false;
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				result = swimming_pools[i]->remove_human_from_adults_track(_track_number, _human_number);
				break;
			}
		}
		return result;
	}
	bool remove_all_humans_from_adults_track(int _swimming_pool_number, int _track_number)
	{
		bool result = false;
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				result = swimming_pools[i]->remove_all_humans_from_adults_track(_track_number);
				break;
			}
		}
		return result;
	}
	bool remove_all_humans_from_swimming_pool(int _swimming_pool_number)
	{
		bool result = false;
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			if (_swimming_pool_number == swimming_pools[i]->get_swimming_pool_number())
			{
				swimming_pools[i]->remove_all_humans_from_swimming_pool();
				result = true;
				break;
			}
		}
		return result;
	}
	void remove_all_humans_from_sport_complex()
	{
		for (int i = 0; i < swimming_pools_amount; i++)
		{
			swimming_pools[i]->remove_all_humans_from_swimming_pool();
		}
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	sport_complex a;
	int cmd = 0;
	do
	{
		cout << "Меню взаимодействия:" << endl;
		cout << "1. Вывести на экран:" << endl;
		cout << ">>> 1. Спортивный комплекс" << endl;
		cout << ">>> 2. Бассейн" << endl;
		cout << ">>> 3. Детскую дорожку" << endl;
		cout << ">>> 4. Взрослую дорожку" << endl;
		cout << "2. Изменить:" << endl;
		cout << ">>> 1. Название спортивного комплекса" << endl;
		cout << ">>> 2. Номер бассейна" << endl;
		cout << ">>> 3. Номер детской дорожки" << endl;
		cout << ">>> 4. Номер взрослой дорожки" << endl;
		cout << "3. Добавить:" << endl;
		cout << ">>> 1. Бассейн" << endl;
		cout << ">>> >>> 1. Конструктором по умолчанию" << endl;
		cout << ">>> >>> 2. Конструктором с параметрами" << endl;
		cout << ">>> >>> 3. Конструктором копии" << endl;
		cout << ">>> 2. Дорожку" << endl;
		cout << ">>> >>> 1. Конструктором по умолчанию" << endl;
		cout << ">>> >>> 2. Конструктором с параметрами" << endl;
		cout << ">>> >>> 3. Конструктором копии" << endl;
		cout << "4. Убрать: " << endl;
		cout << ">>> 1. Бассейн" << endl;
		cout << ">>> 2. Дорожку" << endl;
		cout << "5. Поместить человека:" << endl;
		cout << ">>> 1. На детскую дорожку" << endl;
		cout << ">>> 2. На взрослую дорожку" << endl;
		cout << "6. Убрать человека:" << endl;
		cout << ">>> 1. Убрать одного человека:" << endl;
		cout << ">>> >>> 1. С детской дорожки" << endl;
		cout << ">>> >>> 2. С взрослой дорожки" << endl;
		cout << ">>> 2. Убрать всех людей:" << endl;
		cout << ">>> >>> 1. С детской дорожки" << endl;
		cout << ">>> >>> 2. С взрослой дорожки" << endl;
		cout << ">>> >>> 3. С бассейна" << endl;
		cout << ">>> >>> 4. С спортивного комлекса" << endl;
		cout << "0. Завершить работу программы" << endl;
		cout << "Номер дейсвия: ";
		cin >> cmd;
		while (cmd < 0 || cmd > 6)
		{
			cout << "[Ошибка]: введён некорректный номер действия. Номер действия: ";
			cin >> cmd;
		}
		switch (cmd)
		{
			case 0:
			{
				break;
			}
			case 1:
			{
				int s_cmd = 0;
				cout << "Меню взаимодействия: Вывести на экран:" << endl;
				cout << "1. Спортивный комплекс" << endl;
				cout << "2. Бассейн" << endl;
				cout << "3. Детскую дорожку" << endl;
				cout << "4. Взрослую дорожку" << endl;
				cout << "0. Вернуться назад" << endl;
				cout << "Номер дейсвия: ";
				cin >> s_cmd;
				while (s_cmd < 0 || s_cmd > 4)
				{
					cout << "[Ошибка]: введён некорректный номер действия. Номер действия: ";
					cin >> s_cmd;
				}
				switch (s_cmd)
				{
					case 0:
					{
						break;
					}
					case 1:
					{
						cout << "Меню взаимодействия: Вывести на экран: Спортивный комплекс" << endl;

						break;
					}
					case 2:
					{
						cout << "Меню взаимодействия: Вывести на экран: Бассейн" << endl;

						break;
					}
					case 3:
					{
						cout << "Меню взаимодействия: Вывести на экран: Детскую дорожку" << endl;

						break;
					}
					case 4:
					{
						cout << "Меню взаимодействия: Вывести на экран: Взрослую дорожку" << endl;

						break;
					}
				}
				break;
			}
			case 2:
			{
				int s_cmd = 0;
				cout << "Меню взаимодействия: Изменить:" << endl;
				cout << "1. Название спортивного комплекса" << endl;
				cout << "2. Номер бассейна" << endl;
				cout << "3. Номер детской дорожки" << endl;
				cout << "4. Номер взрослой дорожки" << endl;
				cout << "Номер дейсвия: ";
				cin >> s_cmd;
				while (s_cmd < 0 || s_cmd > 4)
				{
					cout << "[Ошибка]: введён некорректный номер действия. Номер действия: ";
					cin >> s_cmd;
				}
				switch (s_cmd)
				{
					case 0:
					{
						break;
					}
					case 1:
					{
						cout << "Меню взаимодействия: Изменить: Название спортивного комплекса" << endl;

						break;
					}
					case 2:
					{
						cout << "Меню взаимодействия: Изменить: Номер бассейна" << endl;

						break;
					}
					case 3:
					{
						cout << "Меню взаимодействия: Изменить: Номер детской дорожки" << endl;

						break;
					}
					case 4:
					{
						cout << "Меню взаимодействия: Изменить: Номер взрослой дорожки" << endl;

						break;
					}
				}
				break;
			}
			case 3:
			{
				int s_cmd = 0;
				cout << "Меню взаимодействия: Добавить:" << endl;
				cout << "1. Бассейн" << endl;
				cout << ">>> 1. Конструктором по умолчанию" << endl;
				cout << ">>> 2. Конструктором с параметрами" << endl;
				cout << ">>> 3. Конструктором копии" << endl;
				cout << "2. Дорожку" << endl;
				cout << ">>> 1. Конструктором по умолчанию" << endl;
				cout << ">>> 2. Конструктором с параметрами" << endl;
				cout << ">>> 3. Конструктором копии" << endl;
				cout << "Номер дейсвия: ";
				cin >> s_cmd;
				while (s_cmd < 0 || s_cmd > 2)
				{
					cout << "[Ошибка]: введён некорректный номер действия. Номер действия: ";
					cin >> s_cmd;
				}
				switch (s_cmd)
				{
					case 0:
					{
						break;
					}
					case 1:
					{
						cout << "Меню взаимодействия: Добавить: Бассейн" << endl;
						cout << ">>> 1. Конструктором по умолчанию" << endl;
						cout << ">>> 2. Конструктором с параметрами" << endl;
						cout << ">>> 3. Конструктором копии" << endl;
						cin >> s_cmd;
						while (s_cmd < 0 || s_cmd > 3)
						{
							cout << "[Ошибка]: введён некорректный номер действия. Номер действия: ";
							cin >> s_cmd;
						}
						switch (s_cmd)
						{
							case 0:
							{
								break;
							}
							case 1:
							{
								cout << "Меню взаимодействия: Добавить: Бассейн: Конструктором по умолчанию" << endl;

								break;
							}
							case 2:
							{
								cout << "Меню взаимодействия: Добавить: Бассейн: Конструктором с параметрами" << endl;

								break;
							}
							case 3:
							{
								cout << "Меню взаимодействия: Добавить: Бассейн: Конструктором копии" << endl;

								break;
							}
						}
						break;
					}
					case 2:
					{
						cout << "Меню взаимодействия: Добавить: Дорожку" << endl;
						cout << ">>> 1. Конструктором по умолчанию" << endl;
						cout << ">>> 2. Конструктором с параметрами" << endl;
						cout << ">>> 3. Конструктором копии" << endl;
						cin >> s_cmd;
						while (s_cmd < 0 || s_cmd > 3)
						{
							cout << "[Ошибка]: введён некорректный номер действия. Номер действия: ";
							cin >> s_cmd;
						}
						switch (s_cmd)
						{
						case 0:
						{
							break;
						}
						case 1:
						{
							cout << "Меню взаимодействия: Добавить: Дорожку: Конструктором по умолчанию" << endl;

							break;
						}
						case 2:
						{
							cout << "Меню взаимодействия: Добавить: Дорожку: Конструктором с параметрами" << endl;

							break;
						}
						case 3:
						{
							cout << "Меню взаимодействия: Добавить: Дорожку: Конструктором копии" << endl;

							break;
						}
						}
						break;
					}
				}
				break;
			}
			case 4:
			{
				int s_cmd = 0;
				cout << "Меню взаимодействия: Убрать:" << endl;
				cout << "1. Бассейн" << endl;
				cout << "2. Дорожку" << endl;
				cout << "Номер дейсвия: ";
				cin >> s_cmd;
				while (s_cmd < 0 || s_cmd > 2)
				{
					cout << "[Ошибка]: введён некорректный номер действия. Номер действия: ";
					cin >> s_cmd;
				}
				switch (s_cmd)
				{
					case 0:
					{
						break;
					}
					case 1:
					{
						cout << "Меню взаимодействия: Убрать: Бассейн" << endl;

						break;
					}
					case 2:
					{
						cout << "Меню взаимодействия: Убрать: Дорожку" << endl;

						break;
					}
				}
				break;
			}
			case 5:
			{
				int s_cmd = 0;
				cout << "Меню взаимодействия: Поместить человека" << endl;
				cout << "1. На детскую дорожку" << endl;
				cout << "2. На взрослую дорожку" << endl;
				cout << "Номер дейсвия: ";
				cin >> s_cmd;
				while (s_cmd < 0 || s_cmd > 2)
				{
					cout << "[Ошибка]: введён некорректный номер действия. Номер действия: ";
					cin >> s_cmd;
				}
				switch (s_cmd)
				{
					case 0:
					{
						break;
					}
					case 1:
					{
						cout << "Меню взаимодействия: Поместить человека: На детскую дорожку" << endl;

						break;
					}
					case 2:
					{
						cout << "Меню взаимодействия: Поместить человека: На взрослую дорожку" << endl;

						break;
					}
				}
				break;
			}
			case 6:
			{
				int s_cmd = 0;
				cout << "Меню взаимодействия: Убрать человека:" << endl;
				cout << "1. Убрать одного человека:" << endl;
				cout << ">>> 1. С детской дорожки" << endl;
				cout << ">>> 2. С взрослой дорожки" << endl;
				cout << "2. Убрать всех людей:" << endl;
				cout << ">>> 1. С детской дорожки" << endl;
				cout << ">>> 2. С взрослой дорожки" << endl;
				cout << ">>> 3. С бассейна" << endl;
				cout << ">>> 4. С спортивного комлекса" << endl;
				cout << "Номер дейсвия: ";
				cin >> s_cmd;
				while (s_cmd < 0 || s_cmd > 2)
				{
					cout << "[Ошибка]: введён некорректный номер действия. Номер действия: ";
					cin >> s_cmd;
				}
				switch (s_cmd)
				{
					case 0:
					{
						break;
					}
					case 1:
					{
						cout << "Меню взаимодействия: Убрать человека: Убрать одного человека" << endl;
						cout << "1. С детской дорожки" << endl;
						cout << "2. С взрослой дорожки" << endl;
						cout << "Номер дейсвия: ";
						cin >> s_cmd;
						while (s_cmd < 0 || s_cmd > 2)
						{
							cout << "[Ошибка]: введён некорректный номер действия. Номер действия: ";
							cin >> s_cmd;
						}
						switch (s_cmd)
						{
							case 0:
							{
								break;
							}
							case 1:
							{
								cout << "Меню взаимодействия: Убрать человека: Убрать одного человека: С детской дорожки" << endl;

								break;
							}
							case 2:
							{
								cout << "Меню взаимодействия: Убрать человека: Убрать одного человека: С взрослой дорожки" << endl;

								break;
							}
						}
						break;
					}
					case 2:
					{
						cout << "Меню взаимодействия: Убрать человека: Убрать всех людей" << endl;
						cout << "1. С детской дорожки" << endl;
						cout << "2. С взрослой дорожки" << endl;
						cout << "3. С бассейна" << endl;
						cout << "4. С спортивного комлекса" << endl;
						cout << "Номер дейсвия: ";
						cin >> s_cmd;
						while (s_cmd < 0 || s_cmd > 4)
						{
							cout << "[Ошибка]: введён некорректный номер действия. Номер действия: ";
							cin >> s_cmd;
						}
						switch (s_cmd)
						{
							case 0:
							{
								break;
							}
							case 1:
							{
								cout << "Меню взаимодействия: Убрать человека: Убрать всех людей: С детской дорожки" << endl;

								break;
							}
							case 2:
							{
								cout << "Меню взаимодействия: Убрать человека: Убрать всех людей: С взрослой дорожки" << endl;

								break;
							}
							case 3:
							{
								cout << "Меню взаимодействия: Убрать человека: Убрать всех людей: С бассейна" << endl;

								break;
							}
							case 4:
							{
								cout << "Меню взаимодействия: Убрать человека: Убрать всех людей: С спортивного комплекса" << endl;

								break;
							}
						}
						break;
					}
				}
				break;
			}
		}
	} while (cmd != 0);
	return 0;
}
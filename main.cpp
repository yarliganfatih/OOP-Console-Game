#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string> 
#include <memory>
#include <vector>
#include<locale.h> 
#include <regex>

#include <sstream>
#include <iomanip>

using namespace std;

int team[2][4];
bool gover = true;

std::string pad_right(std::string const& str, size_t s)
{
	if (str.size() < s)
		return str + std::string(s - str.size(), ' ');
	else
		return str;
}

std::string pad_left(std::string const& str, size_t s)
{
	if (str.size() < s)
		return std::string(s - str.size(), ' ') + str;
	else
		return str;
}

class StringUtils {
public:
	static std::string pad_right(std::string const& str, size_t s)
	{
		if (str.size() < s)
			return str + std::string(s - str.size(), ' ');
		else
			return str;
	}

	static std::string pad_left(std::string const& str, size_t s)
	{
		if (str.size() < s)
			return std::string(s - str.size(), ' ') + str;
		else
			return str;
	}
};

class Unit {
protected:
	int HP;
	int startedHP;
	int Attack;
	int Defence;
	int Chance;
	bool isAlive;
	string type;
	string name;
	int order;

public:
	Unit(string n, string t, int order_) {
		this->isAlive = true;
		this->name = n;
		this->type = t;
		this->order = order_;
	}

	int minHP;
	int maxHP;
	int minAttack;
	int maxAttack;
	int minDefence;
	int maxDefence;
	int minChance;
	int maxChance;



	void yazdir() {
		//cout << pad_right(to_string(this->order), 2);
		cout << " => Name : " << pad_right(this->name, 15);
		cout << "Type : " << pad_right(this->type, 12);
		cout << "HP : " << pad_right(to_string(this->HP), 8);
		cout << "Attack : " << pad_right(to_string(this->Attack), 8);
		cout << "Defence : " << pad_right(to_string(this->Defence), 8);
		cout << "Chance : " << pad_right(to_string(this->Chance), 8) << endl;
	}

	void round() {
		//cout << pad_right(to_string(this->order), 2);
		if (this->isAlive == true) {
			cout << " => Name : " << pad_right(this->name, 15);
			cout << "Type : " << pad_right(this->type, 12);
			cout << "Current HP : " << pad_right(to_string(this->HP), 8) << endl;
		}
	}

	void setHp(int v) {
		this->HP = v;
	}

	void setAttack(int v) {
		this->Attack = v;
	}

	void setDefence(int v) {
		this->Defence = v;
	}

	void setChance(int v) {
		this->Chance = v;
	}

	void setisAlive(bool v) {
		this->isAlive = v;
	}

	void initializeAbilities() {
		setHp(calculateAbility(maxHP, minHP));
		setAttack(calculateAbility(maxAttack, minAttack));
		setDefence(calculateAbility(maxDefence, minDefence));
		setChance(calculateAbility(maxChance, minChance));
		startedHP = HP;
	}

	int calculateAbility(int max, int min) {
		return rand() % (max - min) + min;
	}

	string getname() { return name; }
	string gettype() { return type; }
	int getindex() { return order; }
	int getHP() { return HP; }
	int getstartedHP() { return startedHP; }
	int getAttack() { return Attack; }
	int getDefence() { return Defence; }
	int getchance() { return Chance; }
	int getisAlive() { return isAlive; }

	int getminHP() { return minHP; }
	int getmaxHP() { return maxHP; }
	int getminAttack() { return minAttack; }
	int getmaxAttack() { return maxAttack; }
	int getminDefence() { return minDefence; }
	int getmaxDefence() { return maxDefence; }
	int getminchance() { return minChance; }
	int getmaxchance() { return maxChance; }
};

class Warrior : public Unit {
public:
	Warrior(string n, int order) :Unit(n, "Warrior", order) {
		minHP = 100;
		maxHP = 250;
		minAttack = 30;
		maxAttack = 50;
		minDefence = 20;
		maxDefence = 30;
		minChance = 12;
		maxChance = 16;
		initializeAbilities();
	};
};

class Wizard : public Unit {
public:
	Wizard(string n, int order) :Unit(n, "Wizard", order) {
		minHP = 90;
		maxHP = 200;
		minAttack = 10;
		maxAttack = 30;
		minDefence = 15;
		maxDefence = 25;
		minChance = 12;
		maxChance = 16;
		initializeAbilities();
	};
};

class Defender : public Unit {
public:
	Defender(string n, int order) :Unit(n, "Defender", order) {
		minHP = 300;
		maxHP = 600;
		minAttack = 15;
		maxAttack = 35;
		minDefence = 50;
		maxDefence = 70;
		minChance = 10;
		maxChance = 13;
		initializeAbilities();
	};
};

class Healer : public Unit {
public:
	Healer(string n, int order) :Unit(n, "Healer", order) {
		minHP = 100;
		maxHP = 250;
		minAttack = 10;
		maxAttack = 30;
		minDefence = 15;
		maxDefence = 30;
		minChance = 15;
		maxChance = 23;
		initializeAbilities();
	};
};

class Arena {
public:
	string map;
	int chance;
	Arena(int x) {
		if (x == 0) {
			map = "Casual"; //does not affect the battle
			chance = 0;
		}
		else if (x == 1) {
			map = "FireSpin"; //has a chance(10%) to attack (20 pure damage) each unit on the field after each round
			chance = 10;
		}
		else if (x == 2) {
			map = "Valhalla"; //has a chance(5%) to brings the death unit back to the field with 10% of HP
			chance = 5;
		}
		else if (x == 3) {
			map = "Aurora"; //has a chance(10%) to heal(10 healing point) each unit on the field after each round
			chance = 10;
		}
		cout << "The battle will be played on : " << map << endl;
	}

	void affect(vector<shared_ptr<Unit>> list) {
		srand(time(NULL));
		int r = rand() % 100;
		if (r < chance) {
			for (int i = 0; i < 8; i++) {
				int y = i / 4;
				int z = i % 4;
				if (map == "FireSpin") {
					FireSpin(list, team[y][z]);
				}
				else if (map == "Valhalla") {
					Valhalla(list, team[y][z]);

				}
				else if (map == "Aurora") {
					Aurora(list, team[y][z]);
				}
			}
			cout << "arena performed its effected!!!!!!!!!!!!" << endl;
		}
	};

	void Casual();

	void FireSpin(vector<shared_ptr<Unit>> list, int x) {
		if (list.at(x)->getisAlive()) {
			list.at(x)->setAttack(list.at(x)->getAttack() + 20);
		}
	};

	void Valhalla(vector<shared_ptr<Unit>> list, int x) {
		if (!list.at(x)->getisAlive()) {
			list.at(x)->setisAlive(true);
			list.at(x)->setHp(list.at(x)->getstartedHP() * 0.1);
		}
	};

	void Aurora(vector<shared_ptr<Unit>> list, int x) {
		if (list.at(x)->getisAlive()) {
			list.at(x)->setHp(list.at(x)->getHP() + 10);
		}
	};
};


class CharacherCollection {
public:
	vector<string> Names = { "Volverine", "Sherman", "Pershing", "Chaffee", "Patton", "Jackson", "Hellcat", "Stuart", "Hetzer", "Tiger", "Panther", "Leopard", "Jagdtiger", "Nashorn", "Grille", "Maus", "Crusader", "Conqueror", "Tortoise", "Progetto", "Alecto", "Bulldog", "Lowe", "Stug", "Challenger", "Caernarvon", "Excelsior", "Chaffee" };
};

int inputNumber(string message)
{
	string str;
	regex regex_number("^[0-9]*$");
	do
	{
		cout << message;
		cin >> str;
	} while (!regex_match(str, regex_number));

	return stoi(str);
}

void printFighterList(vector<shared_ptr<Unit>> list) {
	for (shared_ptr<Unit> fighter : list) {

		cout << pad_left(to_string(fighter->getindex()), 2) << " => Name : " << pad_right(fighter->getname(), 15);
		cout << "Type : " << pad_right(fighter->gettype(), 12);
		cout << "HP : " << pad_right(to_string(fighter->getHP()), 8);
		cout << "Attack : " << pad_right(to_string(fighter->getAttack()), 8);
		cout << "Defence : " << pad_right(to_string(fighter->getDefence()), 8);
		cout << "Chance : " << pad_right(to_string(fighter->getchance()), 8) << endl;
	}
}

void Winner(int x) {
	gover = false;
	cout << string(52, '=') << " GAME OVER " << string(52, '=') << endl;
	cout << "||" << string(111, ' ') << "||" << endl;
	cout << "||" << string(48, ' ') << "Team " << x+1 << " Wins !!!" << string(48, ' ') << "||" << endl;
	cout << "||" << string(111, ' ') << "||" << endl;
	cout << string(115, '=') << endl << endl;
	cout << string(23, '_') << "Developed by Fatih Yarlıgan, Beste Didem Atılgan, Yunus Emre Bolgonul" << string(23, '_') << endl;
}

bool GameOver(vector<shared_ptr<Unit>> p) {
	if (p.at(team[0][0] - 1)->getisAlive() == false && p.at(team[0][1] - 1)->getisAlive() == false && p.at(team[0][2] - 1)->getisAlive() == false && p.at(team[0][3] - 1)->getisAlive() == false) {
	Winner(1);
	return false;
	}
	else if (p.at(team[1][0] - 1)->getisAlive() == false && p.at(team[1][1] - 1)->getisAlive() == false && p.at(team[1][2] - 1)->getisAlive() == false && p.at(team[1][3] - 1)->getisAlive() == false) {
	Winner(2);
	return false;
	}
	else {
		return true;
	}

};

void Attack(vector<shared_ptr<Unit>> p, int x, int y, int o) {
	double as = 100 + p.at(y)->getDefence();
	double asd = 100 / as;
	double hasar = p.at(x)->getAttack() * asd;
	p.at(y)->setHp(p.at(y)->getHP() - int(hasar));
	if (p.at(y)->getHP() < 1) {
		p.at(y)->setHp(0);
		p.at(y)->setisAlive(false);
		cout << p.at(y)->getname() << " is dead !!!" << endl;
	}
	cout << p.at(x)->getname() << " attacted to "<< p.at(y)->getname() <<" Damage : " << int(hasar) << endl;
	if (p.at(team[o][0] - 1)->getisAlive() == false && p.at(team[o][1] - 1)->getisAlive() == false && p.at(team[o][2] - 1)->getisAlive() == false && p.at(team[o][3] - 1)->getisAlive() == false) {
		Winner((o+1)%2);
	}
};

void Skill(vector<shared_ptr<Unit>> p, int t, int x, int z) {
	srand(time(NULL));
	int other = 0;
	if (t == 0) {
		other = 1;
	}
	int r = rand() % 100;
	if (r < p.at(x)->getchance()) {

		if (p.at(x)->gettype() == "Warrior") {

			cout<< p.at(x)->getname() << " used the special ability and attacked again!" << endl;
			Attack(p, x, z, other);

		} else if (p.at(x)->gettype() == "Wizard") {

			for (int i = 0; i < 4; i++) {
				if (team[other][i]-1 != z && p.at(team[other][i] - 1)->getisAlive()) {
					cout << p.at(x)->getname() << " used the special ability and attacked too!" << endl;
					Attack(p, x, team[other][i]-1, other);
				}
			}

		}
		else if (p.at(x)->gettype() == "Healer") {

			for (int i = 0; i < 4; i++) {
				if (p.at(team[t][i] - 1)->getisAlive()) {
					double plus = p.at(team[t][i] - 1)->getHP() / 5;
					p.at(team[t][i] - 1)->setHp(p.at(team[t][i] - 1)->getHP() + int(plus)); // varolan HP'sinin %20'si
					cout << p.at(x)->getname() << " used the special ability and healed " << p.at(team[t][i] - 1)->getname() << endl;
				}
			}

		}
	}
	if (r < p.at(z)->getchance()) {
		if (p.at(z)->gettype() == "Defender") {

			cout << p.at(z)->getname() << " used the special ability and " << endl;
			Attack(p, z, x, t);

		}
	}
}

int main()
{
	setlocale(LC_ALL, "Turkish");

	vector<shared_ptr<Unit>> fighters;
	{
		shared_ptr<CharacherCollection> characters = make_shared<CharacherCollection>();
		for (int i = 1; i < 8; i++) {
			shared_ptr<Warrior> d1 = make_shared<Warrior>(characters->Names[i - 1], i);
			fighters.push_back(d1);
		}

		for (int i = 8; i < 15; i++) {
			shared_ptr<Defender> d1 = make_shared<Defender>(characters->Names[i - 1], i);
			fighters.push_back(d1);
		}

		for (int i = 15; i < 22; i++) {
			shared_ptr<Wizard> d1 = make_shared<Wizard>(characters->Names[i - 1], i);
			fighters.push_back(d1);
		}

		for (int i = 22; i <= 28; i++) {
			shared_ptr<Healer> d1 = make_shared<Healer>(characters->Names[i - 1], i);
			fighters.push_back(d1);
		}
	}

	printFighterList(fighters);
	cout << string(115, '-') << endl;
	bool kontrol1 = true;
	bool control1 = false;
	while (kontrol1 == true) {
		control1 = false;
		cout << "Please select first team : ";
		team[0][0] = 0; team[0][1] = 0; team[0][2] = 0; team[0][3] = 0;
		for (int i = 0; i < 4; i++) {
			int ccin;
			cin >> ccin;
			bool exists = std::find(std::begin(team[0]), std::end(team[0]), ccin) != std::end(team[0]);
			if (!exists) {
				if (!(ccin > 29) && !(ccin<0)) {
					team[0][i] = ccin;
					if (i == 3 && control1==false) {
						kontrol1 = false;
					}
				}
				else {
					kontrol1 = true;
					team[0][0] = 0; team[0][1] = 0; team[0][2] = 0; team[0][3] = 0;
					cout << ccin << " can not use, Select again" << endl;
					control1 = true;
				}
			}
			else {
				kontrol1 = true;
				team[0][0] = 0; team[0][1] = 0; team[0][2] = 0; team[0][3] = 0;
				cout << ccin << " can not use, Select again" << endl;
				control1 = true;
			}
			//cout << team[0][0] << " " << team[0][1] << " " << team[0][2] << " " << team[0][3] << endl;
		}
	}
	cout << string(115, '-') << endl;
	bool kontrol2 = true;
	bool control2 = false;
	while (kontrol2 == true) {
		bool control2 = false;
		cout << "Please select second team : ";
		team[1][0] = 0; team[1][1] = 0; team[1][2] = 0; team[1][3] = 0;
		for (int i = 0; i < 4; i++) {
			int ccin;
			cin >> ccin;
			bool exists1 = std::find(std::begin(team[0]), std::end(team[0]), ccin) != std::end(team[0]);
			bool exists2 = std::find(std::begin(team[1]), std::end(team[1]), ccin) != std::end(team[1]);
			if (!exists1 && !exists2) { 
				if (!(ccin > 29) && !(ccin < 0)) {
					team[1][i] = ccin;
					if (i == 3 && control2 == false) {
						kontrol2 = false;
					}
				}
				else {
					kontrol2 = true;
					cout << ccin << " can not use, Select again" << endl;
					control2 = true;
				}
			}
			else {
				kontrol2 = true;
				cout << ccin << " can not use, Select again" << endl;
				control2 = true;
			}
			//cout << team[1][0] << " " << team[1][1] << " " << team[1][2] << " " << team[1][3] << endl;
		}
	}
	cout << string(115, '-') << endl;

	srand(time(NULL));
	int r = rand() % 4;
	Arena smap(r);

	cout << "Team 1 with attack order :" << endl;
	for (int i = 0; i < 4; i++) {
		cout << " " << i + 1;
		fighters.at(team[0][i] - 1)->yazdir();
	}

	cout << "Team 2 with attack order :" << endl;

	for (int i = 0; i < 4; i++) {
		cout << " " << i + 1;
		fighters.at(team[1][i] - 1)->yazdir();
	}

	cout << string(50, '-') << " BATTLE STARTS " << string(50, '-') << endl;

	int turn = rand() % 2;
	cout << "Team " << turn+1 << " starts the battle !!" << endl;
	int index = 0;
	int teamturn[2] = {0, 0};
	while (GameOver && gover) {
		index++;
		int other = 0;
		if (turn == 0) {
			other = 1;
		}
		else {
			other = 0;
		}
		cout << string(50, '=') << " ROUND "<< index << " " << string(50, '=') << endl;
		cout << "Team " << turn+1 << " :" << endl;
		for (int i = 0; i < 4; i++) {
			if (fighters.at(team[turn][i] - 1)->getisAlive() == true) {
				cout << " " << i + 1;
				fighters.at(team[turn][i] - 1)->round();
			}
		}
		cout << "Team " << other+1 << " :" << endl;
		for (int i = 0; i < 4; i++) {
			if (fighters.at(team[other][i] - 1)->getisAlive() == true) {
				cout << " " << i + 1;
				fighters.at(team[other][i] - 1)->round();
			}
		}
		for (int zi = 0; zi < 2; zi++) {
			if (GameOver) {
				if (turn == 0) {
					other = 1;
				}
				else {
					other = 0;
				}
				while (fighters.at(team[turn][teamturn[turn]] - 1)->getisAlive() == false) {
					teamturn[turn]++;
					teamturn[turn] = teamturn[turn] % 4;
				}
				cout << endl << fighters.at(team[turn][teamturn[turn]] - 1)->getname() << " will attack! Select an opponent from Team " << other + 1 << " to attack : ";
				int who;
				cin >> who;
				while (who > 4 || who < 1 || !(fighters.at(team[other][who - 1] - 1)->getisAlive())) {
					cout << "Please select again : ";
					cin >> who;
				}

				Attack(fighters, team[turn][teamturn[turn]] - 1, team[other][who - 1] - 1, other);

				Skill(fighters, turn, team[turn][teamturn[turn]] - 1, team[other][who - 1] - 1);
				teamturn[turn]++;
				teamturn[turn] = teamturn[turn] % 4;
				turn = other;
			}
		}

		smap.affect(fighters);
	}
	return 0;
}

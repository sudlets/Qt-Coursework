#ifndef PLANET_H
#define PLANET_H

#ifndef STRING_H
#define STRING_H
#endif

class Planet
{
private:
    string name;
    string Who_opening;
    int mass;
    int Year_of_opening;
public:
    Planet();
    Planet(string, int, int, string);
    Planet(const Planet&);
    ~Planet();
    string get_name(void);
    string get_Who_opening(void);
    int get_Year_of_opening(void);
    int get_mass(void);
    void in_name(string);
    void in_Who_opening(string);
    void in_Year_of_opening(int);
    void in_mass(int);
    friend istream& operator>> (istream &in, Planet &point);
};


Planet::Planet() : name("no name"),  mass(-1), Who_opening("ANNOnymous"), Year_of_opening(2205)
{
}

Planet::Planet(string name_inp, int mass_inp, int Year, string Who) : name(name_inp), mass(mass_inp), Year_of_opening(Year), Who_opening(Who)
{
}

Planet::Planet(const Planet& planet_inp) : name(planet_inp.name), mass(planet_inp.mass), Year_of_opening(planet_inp.Year_of_opening), Who_opening(planet_inp.Who_opening)
{
}

Planet::~Planet()
{
}

string Planet::get_name(void)
{
    return name;
}

string Planet::get_Who_opening(void)
{
    return Who_opening;
}

int Planet::get_Year_of_opening(void)
{
    return Year_of_opening;
}

int Planet::get_mass(void)
{
    return mass;
}

void Planet::in_name(string inp_name)
{
    name = inp_name;
}

void Planet::in_mass(int inp_mass)
{
    mass = inp_mass;
}

istream& operator>> (istream &in, Planet &point)
{
    in >> point.name;
    in >> point.mass;
    in >> point.Year_of_opening;
    in >> point.Who_opening;
}

#endif // PLANET_H

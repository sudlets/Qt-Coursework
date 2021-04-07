#ifndef BASEVECT_H
#define BASEVECT_H

class VectPlanet
{
private:
    Planet * T;
    int size;
public:
    VectPlanet();
    VectPlanet(const Planet*, unsigned int);
    VectPlanet(const VectPlanet&);
    ~VectPlanet();
    void add_planet(const Planet&);
    void add_planet(void);
    void delete_planet(int);
    void new_size(int);  // Удаляем все планеты и устанавливаем новый размер контейнера
    void add_size(int);  // Добавляем указанный размер памяти к вектору с сохранением планет
    Planet& get_planet(const int&);
    int get_size();
    Planet& operator[](const int&);

    class Iterator
    {
    private:
        Planet* cur;
    public:
        Iterator() : cur(NULL)
        {
        }
        Iterator(Planet* first) : cur(first)
        {
        }
        ~Iterator()
        {
            delete cur;
        }

        string get_name() { return cur->get_name(); }
        string get_Who_opening() { return cur->get_Who_opening(); }
        int get_Year_of_opening() { return cur->get_Year_of_opening(); }
        int get_mass() { return cur->get_mass(); }

        Planet& operator+ (int n) { return *(cur + n); }
        Planet& operator- (int n) { return *(cur - n); }

        Planet& operator++ (int) { return *cur++; }
        Planet& operator+= (int add) { return *(cur+=add); }
        Planet& operator-- (int) { return *cur--; }
        Planet& operator++ () { return *++cur; }
        Planet& operator-- () { return *--cur; }


        void operator=(Planet& _planet)
                {
                    cur->in_mass(_planet.get_mass());
                    cur->in_name(_planet.get_name());
                    cur->in_Year_of_opening(_planet.get_Year_of_opening());
                    cur->in_Who_opening(_planet.get_Who_opening());
                }

        bool operator!= (const Iterator& it) { return cur != it.cur; }
        bool operator== (const Iterator& it) { return cur == it.cur; }
        Planet& operator* () { return *cur; }
        friend ostream& operator<< (ostream &out, const Iterator planeta)
        {
            out << planeta.cur->get_name() << endl
                << planeta.cur->get_mass() << endl
                << planeta.cur->get_Year_of_opening() << endl
                << planeta.cur->get_Who_opening() << endl;
            return out;
        }

        friend istream& operator>> (istream &in, Iterator& planeta)
        {
            in >> planeta;
            return in;
        }
    };
    Iterator begin() { return T; };
    Iterator end() { return T + size; };
};

VectPlanet::VectPlanet()//: T(new Planet[1]), size(1)
{
T = new Planet[1];
size = 1;
}

VectPlanet::VectPlanet(const Planet* mass, unsigned int inp_size) : T(new Planet[inp_size]), size(inp_size)
{
    for (int i = 0; i < size; i++)
        T[i] = mass[i];
}
VectPlanet::VectPlanet(const VectPlanet& cpy) : T(new Planet[cpy.size]), size(cpy.size)
{
    for (int i = 0; i < size; i++)
        T[i] = cpy.T[i];
}
VectPlanet::~VectPlanet()
{
    delete[] T;
}

void VectPlanet::add_planet(void)
{
    size++;
    Planet *arr = new Planet[size];
    for (int i = 0; i < size - 1; i++)
        arr[i] = T[i];
    delete[] T;
    T = arr;
}

void VectPlanet::add_planet(const Planet& add_plan)
{
    size++;
    Planet *arr = new Planet[size];
    for (int i = 0; i < size - 1; i++)
        arr[i] = T[i];
    arr[size - 1] = add_plan;
    delete[] T;
    T = arr;
}
void VectPlanet::delete_planet(int numb_del_planet = -1) //номер удаляемой планеты, если не указан, то удаляется последняя в массиве
{
    if (numb_del_planet <= -1 || numb_del_planet >= size)
    {
        size -= 1;
        Planet *arr = new Planet[size];
        for (int i = 0; i < size; i++)
            arr[i] = T[i];
        delete[] T;
        T = arr;
    }
    else
    {
        Planet *arr = new Planet[size - 1];
        int i = 0;
        for (; i < numb_del_planet; i++)
            arr[i] = T[i];
        for (int j = i + 1; j < size; j++)
            arr[i] = T[j];
        size -= 1;
        delete[] T;
        T = arr;
    }
}

Planet& VectPlanet::get_planet(const int & number)
{
    if (number < size)
        return T[number];
    else
        return T[0];
}

int VectPlanet::get_size()
{
    return size;
}

Planet& VectPlanet::operator[] (const int & number)
{
    return T[number];
}

void VectPlanet::new_size(int inp)
{
    size = inp;
    delete[] T;
    Planet *arr = new Planet[size];
    T = arr;
}

void VectPlanet::add_size(int add)
{
    Planet *arr = new Planet[size + add];
    for(int i = 0; i < size; i++)
        arr[i] = T[i];
    size += add;
    delete[] T;
    T = arr;
}
#endif // BASEVECT_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>


using namespace std;


class Device
{
private:
    string name;
    string type;
public:
    Device(const string& t, const string& n) : name(n), type(t) {}
    virtual void poll()
    {
        cout << name << endl;
    }
};


class Electricity_Meter: public Device
{
public:
    Electricity_Meter(const string& type, const string& name): Device(type, name) {}
};


class Heating_Control_Block : public Device
{
public:
    Heating_Control_Block(const string& type, const string& name): Device(type, name) {}
};


class Discrete_Input_Block: public Device
{
public:
    Discrete_Input_Block(const string& type, const string& name): Device(type, name) {}
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Device*> devices;
    string type;
    string name;

    ifstream inp("text.txt");
    if (!inp.is_open())
    {
        cout << "Error" << endl;
    }


    while (inp >> type >> name)
    {
        if (type == "Electricity_Meter") 
        {
            devices.push_back(new Electricity_Meter(type, name));
        }
        else if (type == "Heating_Control_Block") 
        {
            devices.push_back(new Heating_Control_Block(type, name));
        }
        else if (type == "Discrete_Input_Block")
        {
            devices.push_back(new Discrete_Input_Block(type, name));
        }
    }

    for (auto device : devices) 
    {
        device->poll();
    }
    return 0;
}

#include <iostream> 
#include <string> 

using namespace std; 

class Mobile { // superclass
    private: string OS; 
    private: string connect_type;

    public: Mobile(string os_type, string con_type) 
    { 
        OS = os_type; 
        connect_type = con_type;  
    }

    public: void SetOS(string os) 
    { 
        OS = os; 
    } 

    public: string GetOS()
    {
        return OS;  
    }

    public: void SetConnectType(string con_type) 
    { 
        connect_type = con_type; 
    }

    public: string GetConnectType() 
    { 
        return connect_type; 
    }
}; 

int main() 
{ 
    Mobile phone1 = Mobile("Android", "Wi-Fi");
    /* 
        Задание свойств через конструктор. 
    */
    cout << phone1.GetOS() << endl; 
    cout << phone1.GetConnectType() << endl;  

    /* 
        Задание свойств через методы класса 
    */
    phone1.SetOS("iOS"); 
    phone1.SetConnectType("Mobile Ethernet"); 

    cout << phone1.GetOS() << endl; 
    cout << phone1.GetConnectType() << endl;

    return 0; 
}
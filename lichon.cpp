#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include<graphics.h>
using namespace std;
string filename = "E:\\New folder (2)\\New folder\\mvl.txt";
struct Schedule {
    int day;  
    int hour;   
    int minute; 
};

vector<Schedule> schedules;
//E:\New folder (2)\New folder
/*void hienthithongbao() {
    MessageBox(
        NULL,
        "Da den gio on tap, nhanh con me len",
        "Thong bao",
        MB_OK | MB_ICONINFORMATION
    );
}*/
void hienthithongbao() {

    int result = MessageBox(
        NULL,
        "Time to study",
        "Confirm",
         MB_OK | MB_ICONINFORMATION
        //MB_YESNO | MB_ICONQUESTION
    );

}

bool Dengioontap() {
    time_t now = time(nullptr);
    tm* localTime = localtime(&now);
    for (const auto& schedule : schedules) {
        if (localTime->tm_wday == schedule.day &&
            localTime->tm_hour == schedule.hour &&
            localTime->tm_min == schedule.minute) {
            return true;
        }
    }
    return false;
}
void addToStartup() {
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH); 

    HKEY hKey;
    const char* subKey = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";

    if (RegOpenKeyExA(HKEY_CURRENT_USER, subKey, 0, KEY_WRITE, &hKey) == ERROR_SUCCESS) {
        RegSetValueExA(hKey, "MyAppNotification", 0, REG_SZ, (const BYTE*)buffer, strlen(buffer) + 1);
        RegCloseKey(hKey);
    }
}
bool chuongtrinhdangchay() {
   // string command = "tasklist | findstr /i \"" + tenfile + "\" >nul 2>&1";
	string command = "tasklist | findstr /i \"new.exe\"";

    int result = system(command.c_str());
    return (result == 0); 
}

void docLichTuFile(const string& filename) {
    ifstream file(filename);

    Schedule schedule;
    while (file >> schedule.day >> schedule.hour >> schedule.minute) {
            schedules.push_back(schedule);
    }

    file.close();
}

int main() {HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_HIDE);
	docLichTuFile(filename);
    addToStartup();
    
    //ShowWindow(hwnd, SW_SHOW); 
    
    while (true) {
        if (Dengioontap()){
        	if(chuongtrinhdangchay()==false){
        		hienthithongbao();
            	this_thread::sleep_for(chrono::minutes(1));
			}
            
        }
        this_thread::sleep_for(chrono::seconds(10));
    }

    return 0;
}

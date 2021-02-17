#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>
#include <iostream>
int main(int argc, char **argv){
	FILE* ptr;
	ptr = fopen("log_win.txt","w");
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si,sizeof(si));
	si.cb = sizeof(si);
	while(1){
		SetConsoleCtrlHandler(0,1);
		CreateProcess(*argv,0,0,0,0,CREATE_NEW_CONSOLE,0,0,&si,&pi);
		DWORD aProcesses[1024], cbNeeded, cProcesses;
		unsigned int i;
		if (!EnumProcesses(aProcesses,sizeof(aProcesses),&cbNeeded)) return 1;
		cProcesses = cbNeeded/sizeof(DWORD);
		fprintf(ptr,"%lu\n",cProcesses);
	}
	return 0;
}

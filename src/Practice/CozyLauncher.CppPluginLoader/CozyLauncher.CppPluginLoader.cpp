// CozyLauncher.CppPluginLoader.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"

extern "C"
{
	__declspec(dllexport) int GetPluginCount()
	{
		return 1;
	}

	__declspec(dllexport) LPWSTR Init(int id)
	{
		return L"1";
	}

	__declspec(dllexport) LPWSTR Query(int id, LPWSTR query)
	{
		return nullptr; //L"2";
	}

	__declspec(dllexport) void ShowPanel(int id, wchar_t* command)
	{
		return;
	}

	__declspec(dllexport) void RunCommand(int id, wchar_t* command)
	{
		return;
	}
}

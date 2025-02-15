#define USE_IMGUI

#include "NouEngine.h"
#include "NouException.h"


int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR	lpCmdLine,
	int		cCmdShow)
{

	try
	{
		return NouEngine{}.Run();
	}
	catch (const NouException::HrException& e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const NouException::BaseException& e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e)
	{
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, "No details available" , "Unknown Exception", MB_OK | MB_ICONEXCLAMATION);

	}

	return -1;
}
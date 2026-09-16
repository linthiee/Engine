#pragma once
#ifdef BASEGAME_EXPORTS
#define BASEGAME_API __declspec(dllexport)
#else
#define BASEGAME_API __declspec(dllimport)
#endif
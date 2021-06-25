#pragma once

namespace AutumnEngine
{
	// Creating an Enum to store all possible Game States
	enum class gameState { SPLASHSCREEN, MAINMENU, INGAME, PAUSED, SETTINGS, QUIT };
	gameState m_GameState;

	class GameState
	{
		public:
			// Getters and Setters for changing and getting the current Game State
			void SetGameState(gameState gameState) { m_GameState = gameState; }
			gameState GetGameState() { return m_GameState; }
	};
}
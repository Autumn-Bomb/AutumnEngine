#pragma once

namespace AutumnEngine
{
	// Creating an Enum to store all possible Game States
	class GameState
	{
		public:
			enum class gameState { SPLASHSCREEN, MAINMENU, INGAME, PAUSED, SETTINGS, QUIT };
			gameState m_GameState;

			// Getters and Setters for changing and getting the current Game State
			void SetGameState(gameState gameState) { m_GameState = gameState; }
			gameState GetGameState() { return m_GameState; }
	};
}
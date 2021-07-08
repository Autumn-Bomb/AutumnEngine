#pragma once

namespace AutumnEngine
{
	// Creating an Enum to store all possible Game States
	class GameState
	{
		// STATE CONTROL ENUMS
		public:
			enum class gameState { SPLASHSCREEN, MAINMENU, INGAME, PAUSED, SETTINGS, QUIT };
			gameState m_GameState;

		// GETTERS AND SETTERS
		public:
			void SetGameState(gameState gameState) { m_GameState = gameState; }
			gameState GetGameState() { return m_GameState; }
	};
}
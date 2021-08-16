#pragma once
#include "../../Libraries/Json/json.hpp"

namespace AutumnEngine
{
	class SceneSerializer
	{
		public:
			SceneSerializer();
			~SceneSerializer();

		public:
			void SerializeScene(nlohmann::json& scene);
			void DeserializeScene(nlohmann::json& scene);

		private:
			nlohmann::json m_CurrentScene;
	};
}
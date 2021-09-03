#pragma once

namespace AutumnEngine
{
	class AssetManager
	{
		public:
			AssetManager();
			~AssetManager();

		public:
			template <class T>
			void LoadResource(T resource);

		private:

	};
}
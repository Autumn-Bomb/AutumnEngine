#pragma once

namespace AutumnEngine
{
	class JsonToolkit
	{
		public:
			JsonToolkit();
			~JsonToolkit();

		public:
			void SerialiseScene();
			void DeserialiseScene();

			void SerialiseObject();
			void DeserialiseObject();

			void SerialiseValue();
			void DeserialiseValue();
	};
}
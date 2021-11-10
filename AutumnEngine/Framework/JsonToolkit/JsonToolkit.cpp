#include "JsonToolkit.h"

AutumnEngine::JsonToolkit::JsonToolkit() {}
AutumnEngine::JsonToolkit::~JsonToolkit() {}

// Figure out if this is needed
void AutumnEngine::JsonToolkit::SerialiseObject() {}
void AutumnEngine::JsonToolkit::DeserialiseObject() {}

// Will be used to serialise/deserialise values to entities and their components
void AutumnEngine::JsonToolkit::SerialiseValue() {}
void AutumnEngine::JsonToolkit::DeserialiseValue() {}

// Will be used to serialise/deserialise scene graphs when a scene is loaded/unloaded
void AutumnEngine::JsonToolkit::SerialiseScene() {}
void AutumnEngine::JsonToolkit::DeserialiseScene() {}
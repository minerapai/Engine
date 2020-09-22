#include "Precompiled.h"

Rectangle::Rectangle(const std::vector<Vector2>& InVertices)
{
	Min = Vector2(INFINITY, INFINITY);
	Max = Vector2(-INFINITY, -INFINITY);

	for (auto iter = InVertices.begin(); iter != InVertices.end(); ++iter)
	{
		(*this) += *iter;
	}
}
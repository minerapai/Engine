
#include "Precompiled.h"

Circle::Circle(const std::vector<Vector2>& InVertices)
{
	// 위치 정보를 받아 중심과 반지름의 값을 구하는 로직 ( 직접 구현할 것 )

	for (auto iter = InVertices.begin(); iter != InVertices.end(); ++iter)
	{
		Center += (*iter);
	}

	Center = Center / InVertices.size();
	Radius = (*std::max_element(InVertices.begin(), InVertices.end(),
		[&](Vector2 vec1, Vector2 vec2)
		{
			return (Center - vec1).SizeSquared() < (Center - vec2).SizeSquared();
		})).Size();


		/*Radius = (*std::max_element(InVertices.begin(), InVertices.end(),
			[&](Vector2 const& InLeft, Vector2 const& InRight)
			{
				return (Center - InLeft).SizeSquared() < (Center - InRight).SizeSquared();
			}
		)).Size();*/ // 교수님
}

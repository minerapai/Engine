
#include "Precompiled.h"

Circle::Circle(const std::vector<Vector2>& InVertices)
{
	// ��ġ ������ �޾� �߽ɰ� �������� ���� ���ϴ� ���� ( ���� ������ �� )

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
		)).Size();*/ // ������
}

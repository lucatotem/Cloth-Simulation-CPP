#include "CollisionObj.h"

//----------------------------------------------------------------------------------------------------------------------
CollisionObj::CollisionObj(bool _activeObj_0, bool _activeObj_1, bool _activeObj_2,
						   float _sphereR, ngl::Vec3 _spherePos, float _cubeA, ngl::Vec3 _cubePos)
{
	m_activeObj[0] = _activeObj_0;
	m_activeObj[1] = _activeObj_1;
	m_activeObj[2] = _activeObj_2;
	m_planeY = -2.0f;
	m_sphereR = _sphereR;
	m_spherePos = _spherePos;
	m_cubeA = _cubeA;
	m_cubePos = _cubePos;
}

bool CollisionObj::collision(ngl::Vec3 _nextPos)
{
	if (m_activeObj[0])
	{
		if (_nextPos.m_y <= m_planeY)
		{
			return true;
		}
	}

	if (m_activeObj[1])
	{
		float dist = sqrt(pow(_nextPos.m_x - m_spherePos.m_x, 2) + pow(_nextPos.m_y - m_spherePos.m_y, 2) + pow(_nextPos.m_z - m_spherePos.m_z, 2));
		if (dist <= m_sphereR)
			return true;
	}

	if (m_activeObj[2])
	{
		//float dist = sqrt(pow(_nextPos.m_x - m_cubePos.m_x, 2) + pow(_nextPos.m_y - m_cubePos.m_y, 2) + pow(_nextPos.m_z - m_cubePos.m_z, 2));
		if (m_cubePos.m_x - m_cubeA/2 <= _nextPos.m_x && _nextPos.m_x <= m_cubePos.m_x + m_cubeA/2)
		{
			if (m_cubePos.m_y - m_cubeA/2 <= _nextPos.m_y && _nextPos.m_y <= m_cubePos.m_y + m_cubeA/2)
			{
				if (m_cubePos.m_z - m_cubeA/2 <= _nextPos.m_z && _nextPos.m_z <= m_cubePos.m_z + m_cubeA/2)
					return true;
			}
		}		
	}
	return false;
}
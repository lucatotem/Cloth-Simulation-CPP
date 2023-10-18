#ifndef __COLLISIONOBJ_H__
#define __COLLISIONOBJ_H__

#include <ngl/VAOPrimitives.h>
#include <ngl/VAOFactory.h>
#include <ngl/SimpleVAO.h>

//----------------------------------------------------------------------------------------------------------------------
class CollisionObj
{
public:
	CollisionObj(bool _activeObj_0, bool _activeObj_1, bool _activeObj_2,
				 float _sphereR, ngl::Vec3 _spherePos, float _cubeA, ngl::Vec3 _cubePos);
	CollisionObj() { ; }

	bool collision(ngl::Vec3);

	inline void setActiveObj_0(bool _f) { m_activeObj[0] = _f; }
	inline void setActiveObj_1(bool _s) { m_activeObj[1] = _s; }
	inline void setActiveObj_2(bool _c) { m_activeObj[2] = _c; }

	inline void setSphereR(float _r) { m_sphereR = _r; }
	inline void setSphereX(float _sphereX) { m_spherePos.m_x = _sphereX; }
	inline void setSphereY(float _sphereY) { m_spherePos.m_y = _sphereY; }
	inline void setSphereZ(float _sphereZ) { m_spherePos.m_z = _sphereZ; }

	inline void setCubeA(float _a) { m_cubeA = _a; }
	inline void setCubeX(float _cubeX) { m_cubePos.m_x = _cubeX; }
	inline void setCubeY(float _cubeY) { m_cubePos.m_y = _cubeY; }
	inline void setCubeZ(float _cubeZ) { m_cubePos.m_z = _cubeZ; }

	void reset() { ; }

	float m_planeY, m_sphereR, m_cubeA;
	ngl::Vec3 m_spherePos, m_cubePos;
	bool m_activeObj[3];
};

#endif


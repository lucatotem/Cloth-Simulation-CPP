#ifndef __CLOTHMESH_H__
#define __CLOTHMESH_H__

#include "Particle.h"
#include "RK4Spring.h"
#include "CollisionObj.h"
#include "ngl/Vec3.h"

//----------------------------------------------------------------------------------------------------------------------
class ClothMesh
{
public:
	/// @brief ctor
	//----------------------------------------------------------------------------------------------------------------------
	ClothMesh(int _width, int _height, ngl::Vec3 _startingPos, float _particleMass, 
			  float _initialSpacing, float _k, float _s, float _damping, float _timestep, CollisionObj _collObj);
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief default ctor
	//----------------------------------------------------------------------------------------------------------------------
	inline ClothMesh() {;}

	void CreateParticles();
	void CreateStretchSprings();
	void CreateShearSprings();
	void clothUpdate();
	inline std::vector<std::vector<Particle>> getMesh() const { return m_mesh; }
	inline std::vector<RK4Spring> getStretchSprings() const { return m_stretchSprings; }
	inline std::vector<RK4Spring> getShearSprings() const { return m_shearSprings; }
	inline int getWidth() const { return m_width; }
	inline int getHeight() const { return m_height; }
	inline ngl::Vec3 getStartingPos() const { return m_startingPos; }
	inline float getParticleMass() const { return m_particleMass; }
	inline float getinitialSpacing() const { return m_initialSpacing; }
	inline float getK() const { return m_k; }
	inline float getS() const { return m_s; }
	inline float getDamping() const { return m_damping; }
	inline CollisionObj getCollisionObj() const { return m_collObj; }

	inline void setWidth(int _w) { m_width = _w; reset(); }
	inline void setHeight(int _h) { m_height = _h; reset(); }
	inline void setStartingPos(ngl::Vec3 _p) { m_startingPos = _p; }
	inline void setParticleMass(float _m) { m_particleMass = _m; }
	inline void setInitialSpacing(float _s) { m_initialSpacing = _s; reset(); }
	inline void setK(float _k) { m_k = _k; }
	inline void setS(float _s) { m_s = _s; }
	inline void setDamping(float _d) { m_damping = _d; }

	inline void setActiveObj_0(bool _f) { m_collObj.setActiveObj_0(_f); reset(); }
	inline void setActiveObj_1(bool _s) { m_collObj.setActiveObj_1(_s); reset(); }
	inline void setActiveObj_2(bool _c) { m_collObj.setActiveObj_2(_c); reset(); }

	inline void setSphereR(double _sphereR) { m_collObj.setSphereR(_sphereR); }
	inline void setSphereX(double _sphereX) { m_collObj.setSphereX(_sphereX); }
	inline void setSphereY(double _sphereY) { m_collObj.setSphereY(_sphereY); }
	inline void setSphereZ(double _sphereZ) { m_collObj.setSphereZ(_sphereZ); }

	inline void setCubeA(double _cubeA) { m_collObj.setCubeA(_cubeA); }
	inline void setCubeX(double _cubeX) { m_collObj.setCubeX(_cubeX); }
	inline void setCubeY(double _cubeY) { m_collObj.setCubeY(_cubeY); }
	inline void setCubeZ(double _cubeZ) { m_collObj.setCubeZ(_cubeZ); }
	/// @brief accessor to set the integration time step (dt)
	/// @param[in] _t the time step value to use
	//----------------------------------------------------------------------------------------------------------------------
	inline void setTimeStep(float _t) { m_timestep = _t; }
	void reset();

private:
	std::vector<std::vector<Particle>> m_mesh;
	std::vector<RK4Spring> m_stretchSprings;
	std::vector<RK4Spring> m_shearSprings;
	int m_width;
	int m_height;
	ngl::Vec3 m_startingPos;
	float m_particleMass;
	float m_initialSpacing;

	float m_k;
	float m_s;
	float m_damping;

	//----------------------------------------------------------------------------------------------------------------------
	/// @brief the time step used for update default 0.1
	//----------------------------------------------------------------------------------------------------------------------
	float m_timestep;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief the current time
	//----------------------------------------------------------------------------------------------------------------------
	float m_t;
	CollisionObj m_collObj;
};

#endif

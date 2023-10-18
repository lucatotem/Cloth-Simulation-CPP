#include "ClothMesh.h"

//----------------------------------------------------------------------------------------------------------------------
ClothMesh::ClothMesh(int _width, int _height, ngl::Vec3 _startingPos, float _particleMass, float _initialSpacing, 
	float _k, float _s, float _damping, float _timestep, CollisionObj _collObj)
{
	m_width = _width;
	m_height = _height;
	m_startingPos = _startingPos;
	m_particleMass = _particleMass;
	m_initialSpacing = _initialSpacing;
	m_k = _k;
	m_s = _s;
	m_damping = _damping;

	m_t = 0.0f;
	m_timestep = _timestep;

	m_collObj = _collObj;

	CreateParticles();
	CreateStretchSprings();
	CreateShearSprings();
}

void ClothMesh::CreateParticles ()
{
	for (int i = 0; i < m_height; i++)
	{
		std::vector<Particle> _tempV;
		for (int j = 0; j < m_width; j++)
		{
			Particle *_tempP = new Particle( m_startingPos + ngl::Vec3(j * m_initialSpacing, 0.0f, 0.0f) + ngl::Vec3(0.0f, 0.0f, i * m_initialSpacing), m_particleMass);
			_tempV.push_back(*_tempP);
		}
		m_mesh.push_back(_tempV);
	}
}

void ClothMesh::CreateStretchSprings()
{
	for (int i=0; i< m_height; i++)
	{
		for (int j=0; j < m_width; j++)
		{
			if (j < m_width - 1)
			{
				m_stretchSprings.push_back(RK4Spring(&m_mesh[i][j], &m_mesh[i][j + 1], 2* m_initialSpacing, m_k, m_damping));
			}
			if (i < m_height - 1)
			{
				m_stretchSprings.push_back(RK4Spring(&m_mesh[i][j], &m_mesh[i + 1][j], 2*m_initialSpacing, m_k, m_damping));
			}
		}
	}
}

void ClothMesh::CreateShearSprings()
{
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			if (i < m_height - 1 && j < m_width - 1)
			{
				m_shearSprings.push_back(RK4Spring(&m_mesh[i][j], &m_mesh[i + 1][j + 1], 2*m_initialSpacing, m_s, m_damping));
			}
			if (i > 0 && j < m_width - 1)
			{
				m_shearSprings.push_back(RK4Spring(&m_mesh[i][j], &m_mesh[i - 1][j + 1], 2 * m_initialSpacing, m_s, m_damping));
			}
		}
	}
}

void ClothMesh::clothUpdate()
{
	// update the timestep for the next time
	m_t += m_timestep;
	for (int i = 0; i < m_stretchSprings.size(); i++)
	{
		m_stretchSprings[i].springUpdate(m_t, m_timestep);
	}

	for (int i = 0; i < m_shearSprings.size(); i++)
	{
		m_shearSprings[i].springUpdate(m_t, m_timestep);
	}
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			m_mesh[i][j].particleUpdate(m_t, m_timestep);
			if (!m_collObj.collision(m_mesh[i][j].m_nextPos)) {
				m_mesh[i][j].m_currentPos = m_mesh[i][j].m_nextPos;
				//m_mesh[i][j].getState().m_position = m_mesh[i][j].m_nextPos;
			}
			else {
				m_mesh[i][j].m_nextPos = m_mesh[i][j].m_currentPos;
				//[i][j].getState().m_position = m_mesh[i][j].m_currentPos;
			}
		}
	}
}

void ClothMesh::reset()
{

	m_t = 0;
	m_mesh.clear();
	m_shearSprings.clear();
	m_stretchSprings.clear();
	CreateParticles();
	CreateStretchSprings();
	CreateShearSprings();

	/*for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			m_mesh[i][j].reset();
			//m_mesh[i][j].m_currentPos = m_startingPos;
			//m_mesh[i][j].m_nextPos = m_startingPos;
			//m_mesh[i][j].getState().m_position = m_startingPos;
			//m_mesh[i][j].getState().m_velocity = ngl::Vec3(0.0f, 0.0f, 0.0f);
		}
	}

	for (int i = 0; i < m_stretchSprings.size(); i++)
	{
		m_stretchSprings[i].reset();
	}

	for (int i = 0; i < m_shearSprings.size(); i++)
	{
		m_shearSprings[i].reset();
	}*/
}


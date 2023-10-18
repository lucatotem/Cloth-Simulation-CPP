#include <Particle.h>
#include <QDebug>

//----------------------------------------------------------------------------------------------------------------------
/*
Particle::Particle(ngl::Vec3 _pos, ngl::Vec3 _vel, float _mass)
{
	m_state.m_position = _pos;
	m_state.m_velocity = _vel;
	m_mass = _mass;
	m_nextPos = _pos;
}*/

Particle::Particle(ngl::Vec3 _pos, float _mass)
{
	m_initialPos = _pos;
	m_currentPos = _pos;
	m_nextPos = _pos;
	m_mass = _mass;
	//m_state.m_position = _pos;
	//m_state.m_velocity = ngl::Vec3(0.0f, 0.0f, 0.0f);
}

void Particle::particleUpdate(float _t, float _timestep)
{
	// run the RK4 integrator to get the new force values
	//integrate(_t, _timestep);
	//m_nextPos += getState().m_velocity;
	m_nextPos += m_mass * ngl::Vec3(0.0f, -9.8f, 0.0f)*_timestep;
}

/*
ngl::Vec3 Particle::motionFunction(const State& _state, float _t)
{
	// in the case of the spring we don't need t mark
	// it as unused in this case
	Q_UNUSED(_t);
	return m_mass * ngl::Vec3(0.0f, -9.8f, 0.0f);
}
*/

void Particle::reset()
{
	m_currentPos = m_initialPos;
	m_nextPos = m_initialPos;
}
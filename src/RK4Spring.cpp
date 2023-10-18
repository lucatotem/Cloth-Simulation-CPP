#include "RK4Spring.h"
#include <QDebug>

//----------------------------------------------------------------------------------------------------------------------
RK4Spring::RK4Spring( Particle* _a, Particle* _b, float _length, float _coefficient, float _damping)
{
	// ctor sets the initial values
	m_a =_a;
	m_b=_b;

	m_length=_length;
	m_coefficient =_coefficient;
	m_damping=_damping;
	m_state.m_position=m_b->m_currentPos - m_a->m_currentPos;

	ngl::Vec3 distance=m_b->m_currentPos - m_a->m_currentPos;
	float length=distance.length();
	m_state.m_velocity.set(0.0f,0.0f,0.0f);
}


void RK4Spring::reset()
{
	m_state.m_position=m_b->m_currentPos-m_a->m_currentPos;
	m_state.m_velocity.set( 0.0f,0.0f,0.0f);
}

void RK4Spring::springUpdate(float _t, float _timestep)
{
	// run the RK4 integrator to get the new force values
	integrate(_t, _timestep);
	// now  apply to spring points (if they are not fixed)
	m_a->m_nextPos -= getState().m_velocity;
	m_b->m_nextPos += getState().m_velocity;
}


ngl::Vec3 RK4Spring::motionFunction(const State &_state,float _t)
{
  // in the case of the spring we don't need t mark
  // it as unused in this case
  Q_UNUSED(_t);
  /// F = -k(|x|-d)(x/|x|) - bv where
	/// k is the spring constant
	/// |x| is the distance between the two spring points
	/// d is the distance of seperation
	/// b is the coefficient of damping larger b increases the damping force
	/// v is the relative velocity between the spring points
	ngl::Vec3 distance=m_b->m_currentPos -m_a->m_currentPos;
	float length=distance.length();
	return -m_coefficient *(length-m_length)*(distance/length)-m_damping*_state.m_velocity;
}

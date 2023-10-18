#ifndef __PARTICLE_H__
#define __PARTICLE_H__

#include <AbstractRK4Integrator.h>
#include <ngl/Vec3.h>

//----------------------------------------------------------------------------------------------------------------------
class Particle //: public AbstractRK4Integrator
{
	public:
		
		//----------------------------------------------------------------------------------------------------------------------
		float m_mass;
		ngl::Vec3  m_initialPos;
		ngl::Vec3  m_currentPos;
		ngl::Vec3  m_nextPos;


		//----------------------------------------------------------------------------------------------------------------------
		/// @brief ctor
		/// @brief[in] _pos initial position
		/// @brief[in] _vel initial velocity
		/// @brief[in] _mass initial mass
		//----------------------------------------------------------------------------------------------------------------------
		//Particle(ngl::Vec3 _pos, ngl::Vec3 _vel, float _mass);

		Particle(ngl::Vec3 _pos, float _mass);

		//----------------------------------------------------------------------------------------------------------------------
		/// @brief default ctor
		//----------------------------------------------------------------------------------------------------------------------
		inline Particle() {;}

		//inline State getState() const { return m_state; }


		void particleUpdate(float _t, float _timestep);
		//ngl::Vec3 motionFunction(const State& _state, float _t);

		void reset();
};

#endif

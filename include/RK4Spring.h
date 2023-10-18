#ifndef __RK4SPRING_H__
#define __RK4SPRING_H__

#include "AbstractRK4Integrator.h"
#include "Particle.h"

//----------------------------------------------------------------------------------------------------------------------
/// @brief this class implements a simple dampped spring system using RK4 integration
/// the main motionFunction is derived from
/// http://gafferongames.com/game-physics/spring-physics/
class RK4Spring : public AbstractRK4Integrator
{
public :
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor
	/// @param[in] _a the start particle of spring point a-/\/\/\/
	/// @param[in] _b the start particle of spring point -/\/\/\/-b
	/// @param[in] _length the resting length of the spring
	/// @param[in] _coefficient a stretch or shear constant for the spring
	/// @param[in] _damping the damping factor of the spring
	//----------------------------------------------------------------------------------------------------------------------
	RK4Spring( Particle* _a, Particle* _b, float _length, float _coefficient, float _damping);
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief this method calls the integrator to calculate the spring force and updates the spring
	/// points, if the points are fixed then no update is made to the points
	//----------------------------------------------------------------------------------------------------------------------
	void springUpdate(float _t, float _timestep);
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief this is going to calculate the spring function
	/// F = -k(|x|-d)(x/|x|) - bv where
	/// k is the spring constant
	/// |x| is the distance between the two spring points
	/// d is the distance of seperation
	/// b is the coefficient of damping larger b increases the damping force
	/// v is the relative velocity between the spring points
	/// @param[in] _state the state of the spring values to calculate
	/// @param[in] _t the current time state
	/// @returns a vector of the force calculated via the RK4 integrator
	//----------------------------------------------------------------------------------------------------------------------
	ngl::Vec3 motionFunction(const State &_state,float _t );
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief mutator to set the a position of the spring
	/// @param[in] _a the value to set
	//----------------------------------------------------------------------------------------------------------------------

	//----------------------------------------------------------------------------------------------------------------------
	/// @brief mutator to set the b position of the spring
	/// @param[in] _b the value to set
	//----------------------------------------------------------------------------------------------------------------------

	//----------------------------------------------------------------------------------------------------------------------
	inline void setAParticle(const Particle& _a) { *m_a = _a;}
	//----------------------------------------------------------------------------------------------------------------------
	inline void setBParticle(const Particle& _b) { *m_b = _b;}
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief accesor for the spring a position
	/// @returns m_a the current spring position
	//----------------------------------------------------------------------------------------------------------------------
	inline ngl::Vec3 getAPosition() const {return m_a->m_currentPos;}
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief accesor for the spring b position
	/// @returns m_b the current spring position
	//----------------------------------------------------------------------------------------------------------------------
	inline ngl::Vec3 getBPosition() const {return m_b->m_currentPos;}
	//----------------------------------------------------------------------------------------------------------------------
	inline Particle getAParticle() const { return *m_a; }
	//----------------------------------------------------------------------------------------------------------------------
	inline Particle getBParticle() const { return *m_b; }
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief mutator to set the spring constant k
	/// @param[in] _k the new k value
	//----------------------------------------------------------------------------------------------------------------------
	inline void setK(float _coefficient){m_coefficient=_coefficient;}
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief mutator to set the spring resting length
	/// @param[in] _l the new resting length value
	//----------------------------------------------------------------------------------------------------------------------
	inline void setLength(float _l){m_length=_l;}
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief mutator to set the spring damping co-efficient
	/// @param[in] _d the new damping  value
	//----------------------------------------------------------------------------------------------------------------------
	inline void setDamping(float _d){m_damping=_d;}
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief re-set the simulation, this will return a and b to the initial values and
	/// re-set the time value m_t to 0
	//----------------------------------------------------------------------------------------------------------------------

	void reset();

private :
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief the spring constant from Hooke's Law
	//----------------------------------------------------------------------------------------------------------------------
	float m_coefficient;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief a damping force for the spring
	//----------------------------------------------------------------------------------------------------------------------
	float m_damping;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief the displacement of the spring from equilibrium
	//----------------------------------------------------------------------------------------------------------------------
	ngl::Vec3 m_displacement;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief relative velocity of the spring
	//----------------------------------------------------------------------------------------------------------------------
	ngl::Vec3 m_velocity;
	//----------------------------------------------------------------------------------------------------------------------
  /// @brief the start position of the spring m_a-/\/\/\-m_b
	//----------------------------------------------------------------------------------------------------------------------
	Particle* m_a;
	//----------------------------------------------------------------------------------------------------------------------
  /// @brief the end position of the spring m_a-/\/\/\-m_b
	//----------------------------------------------------------------------------------------------------------------------
	Particle* m_b;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief the length of the spring (distance of seperation) at rest
	//----------------------------------------------------------------------------------------------------------------------
	float m_length;
};


#endif

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "NGLScene.h"
#include "ClothMesh.h"
#include "CollisionObj.h"

//----------------------------------------------------------------------------------------------------------------------
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor
	/// @param[in] parent the parent window
	//----------------------------------------------------------------------------------------------------------------------
    explicit MainWindow(QWidget *parent = 0);
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief dtor
	//----------------------------------------------------------------------------------------------------------------------
	~MainWindow();

private:
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief a pointer to our user interface
	//----------------------------------------------------------------------------------------------------------------------
	Ui::MainWindow *m_ui;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief our open gl window
	//----------------------------------------------------------------------------------------------------------------------
	NGLScene *m_gl;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief our cloth mesh
	//----------------------------------------------------------------------------------------------------------------------
	CollisionObj* m_collObj;
	ClothMesh* m_mesh;

private slots :
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief slot to set the number of particles in each width column
	//----------------------------------------------------------------------------------------------------------------------
	inline void setWidth(int _width) { m_mesh->setWidth(_width); }
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief slot to set the number of particles in each height row
	//----------------------------------------------------------------------------------------------------------------------
	inline void setHeight(int _height) { m_mesh->setHeight(_height); }
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief slot to set particle mass
	//----------------------------------------------------------------------------------------------------------------------
	inline void setParticleMass(double _mass) { m_mesh->setParticleMass(_mass); }
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief slot to set initial spacing between the particles
	//----------------------------------------------------------------------------------------------------------------------
	inline void setInitialSpacing(double _spacing) { m_mesh->setInitialSpacing(_spacing); }
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief slot to set the spring stretch constant K
	//----------------------------------------------------------------------------------------------------------------------
	inline void setK(double _k){m_mesh->setK(_k);}
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief slot to set the spring shear constant S
	//----------------------------------------------------------------------------------------------------------------------
	inline void setS(double _s) { m_mesh->setS(_s); }
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief a slot to set the spring damping
	//----------------------------------------------------------------------------------------------------------------------
	inline void setDamping(double _d){m_mesh->setDamping(_d);}
	//----------------------------------------------------------------------------------------------------------------------

	//----------------------------------------------------------------------------------------------------------------------
	/// @brief slot to draw the floor plane
	//----------------------------------------------------------------------------------------------------------------------
	inline void setActiveObj_0(bool _f){m_mesh->setActiveObj_0(_f);}
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief slot to draw a collision sphere
	//----------------------------------------------------------------------------------------------------------------------
	inline void setActiveObj_1(bool _s){m_mesh->setActiveObj_1(_s);}
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief slot to draw a collision cube
	//----------------------------------------------------------------------------------------------------------------------
	inline void setActiveObj_2(bool _c) { m_mesh->setActiveObj_2(_c); }
	//----------------------------------------------------------------------------------------------------------------------

	//----------------------------------------------------------------------------------------------------------------------
	/// @brief slot to set the sphere radius R
	//----------------------------------------------------------------------------------------------------------------------
	inline void setSphereR(double _sphereR) { m_mesh->setSphereR(_sphereR); }
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief slot to set the sphere position X
	//----------------------------------------------------------------------------------------------------------------------
	inline void setSphereX(double _sphereX) { m_mesh->setSphereX(_sphereX); }
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief slot to set the sphere position Y
	//----------------------------------------------------------------------------------------------------------------------
	inline void setSphereY(double _sphereY) { m_mesh->setSphereY(_sphereY); }
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief slot to set the sphere position Z
	//----------------------------------------------------------------------------------------------------------------------
	inline void setSphereZ(double _sphereZ) { m_mesh->setSphereZ(_sphereZ); }
	//----------------------------------------------------------------------------------------------------------------------

	//----------------------------------------------------------------------------------------------------------------------
	/// @brief slot to set the cube side length A
	//----------------------------------------------------------------------------------------------------------------------
	inline void setCubeA(double _cubeA) { m_mesh->setCubeA(_cubeA); }
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief slot to set the cube position X
	//----------------------------------------------------------------------------------------------------------------------
	inline void setCubeX(double _cubeX) { m_mesh->setCubeX(_cubeX); }
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief slot to set the sphere position Y
	//----------------------------------------------------------------------------------------------------------------------
	inline void setCubeY(double _cubeY) { m_mesh->setCubeY(_cubeY); }
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief slot to set the sphere position Z
	//----------------------------------------------------------------------------------------------------------------------
	inline void setCubeZ(double _cubeZ) { m_mesh->setCubeZ(_cubeZ); }
	//----------------------------------------------------------------------------------------------------------------------

	/// @brief a slot to set the simulation dt value
	//----------------------------------------------------------------------------------------------------------------------
	inline void setDT(double _dt) { m_mesh->setTimeStep(_dt); }
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief slot to toggle the sim on and off
	//----------------------------------------------------------------------------------------------------------------------
	void startSim();
	void stopSim();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief slot to reset the simulation
	//----------------------------------------------------------------------------------------------------------------------
	void reset();
};

#endif // MAINWINDOW_H

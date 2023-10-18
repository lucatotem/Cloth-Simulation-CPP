#include "MainWindow.h"
#include "ui_MainWindow.h"

//----------------------------------------------------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), m_ui(new Ui::MainWindow)
{
	// setup the user interface
	m_ui->setupUi(this);
	// create our GL window for drawing the spring
	m_gl=new  NGLScene(m_ui->m_timerValue->value(),this);
	m_gl->stopSimTimer();
	// add the glWindow to the UI
	m_ui->s_mainWindowGridLayout->addWidget(m_gl,0,0,4,1);
	// create a new cloth mesh using the defaul ui values
	m_collObj = new CollisionObj(m_ui->m_activeObj_0->checkState(), m_ui->m_activeObj_1->checkState(), m_ui->m_activeObj_2->checkState(),
								 m_ui->m_sphereR->value(), ngl::Vec3(m_ui->m_sphereX->value(), m_ui->m_sphereY->value(), m_ui->m_sphereZ->value()),
								 m_ui->m_cubeA->value(), ngl::Vec3(m_ui->m_cubeX->value(), m_ui->m_cubeY->value(), m_ui->m_cubeZ->value()));

	//m_mesh = new ClothMesh(10, 10, ngl::Vec3(0.0f, 1.6f, 0.0f), .1f, 0.2f, 3.0f, 1.5f, 10.0f, 0.05f, *m_collObj);
	m_mesh = new ClothMesh(m_ui->m_width->value(), m_ui->m_height->value(),
						   ngl::Vec3(float(-m_ui->m_width->value()) / 2* m_ui->m_initialSpacing->value(), 1.6f, float(-m_ui->m_height->value()) / 2 * m_ui->m_initialSpacing->value()),
						   m_ui->m_particleMass->value(), m_ui->m_initialSpacing->value(),
						   m_ui->m_k->value(), m_ui->m_s->value(), m_ui->m_damping->value(), m_ui->m_dt->value(), *m_collObj);

	// now set the mesh in the GL window as we share it
	m_gl->setMesh(m_mesh);
	//m_gl->setObj(m_collObj);
	
	// now we wire up the UI components to the slots
	connect(m_ui->m_width, SIGNAL(valueChanged(int)), this, SLOT(setWidth(int)));
	connect(m_ui->m_height, SIGNAL(valueChanged(int)), this, SLOT(setHeight(int)));
	connect(m_ui->m_particleMass, SIGNAL(valueChanged(double)), this, SLOT(setParticleMass(double)));
	connect(m_ui->m_initialSpacing, SIGNAL(valueChanged(double)), this, SLOT(setInitialSpacing(double)));
	connect(m_ui->m_k, SIGNAL(valueChanged(double)), this, SLOT(setK(double)));
	connect(m_ui->m_s, SIGNAL(valueChanged(double)), this, SLOT(setS(double)));
	connect(m_ui->m_damping, SIGNAL(valueChanged(double)), this, SLOT(setDamping(double)));

	connect(m_ui->m_activeObj_0, SIGNAL(clicked(bool)), this, SLOT(setActiveObj_0(bool)));
	connect(m_ui->m_activeObj_1, SIGNAL(clicked(bool)), this, SLOT(setActiveObj_1(bool)));
	connect(m_ui->m_activeObj_2, SIGNAL(clicked(bool)), this, SLOT(setActiveObj_2(bool)));

	connect(m_ui->m_sphereR, SIGNAL(valueChanged(double)), this, SLOT(setSphereR(double)));
	connect(m_ui->m_sphereX, SIGNAL(valueChanged(double)), this, SLOT(setSphereX(double)));
	connect(m_ui->m_sphereY, SIGNAL(valueChanged(double)), this, SLOT(setSphereY(double)));
	connect(m_ui->m_sphereZ, SIGNAL(valueChanged(double)), this, SLOT(setSphereZ(double)));

	connect(m_ui->m_cubeA, SIGNAL(valueChanged(double)), this, SLOT(setCubeA(double)));
	connect(m_ui->m_cubeX, SIGNAL(valueChanged(double)), this, SLOT(setCubeX(double)));
	connect(m_ui->m_cubeY, SIGNAL(valueChanged(double)), this, SLOT(setCubeY(double)));
	connect(m_ui->m_cubeZ, SIGNAL(valueChanged(double)), this, SLOT(setCubeZ(double)));

	connect(m_ui->m_dt, SIGNAL(valueChanged(double)), this, SLOT(setDT(double)));
	connect(m_ui->m_timerValue, SIGNAL(valueChanged(int)), m_gl, SLOT(setTimerDuration(int)));
	connect(m_ui->m_startSim, SIGNAL(clicked()), this, SLOT(startSim()));
	connect(m_ui->m_stopSim, SIGNAL(clicked()), this, SLOT(stopSim()));
	connect(m_ui->m_reset, SIGNAL(clicked()), this, SLOT(reset()));
}

//----------------------------------------------------------------------------------------------------------------------
MainWindow::~MainWindow()
{
		delete[] m_mesh;
		delete m_collObj;
    delete m_ui;
}

//----------------------------------------------------------------------------------------------------------------------
void MainWindow::startSim()
{
	m_gl->startSimTimer();

}
void MainWindow::stopSim()
{
	m_gl->stopSimTimer();
}
void MainWindow::reset() {

	m_gl->stopSimTimer();
	//m_ui->m_sim->clicked();
	m_mesh->reset(); 
}

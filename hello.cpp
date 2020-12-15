// OGRE 1.12 starter sample
#include <Ogre.h>
#include <OgreApplicationContext.h>

using namespace Ogre;
using namespace OgreBites;

class MyTestApp
	: public ApplicationContext, public InputListener
{
public:
	MyTestApp();
	~MyTestApp() {}
	void setup() override;
	bool keyPressed(KeyboardEvent const & evt) override;
};

MyTestApp::MyTestApp()
	: ApplicationContext{"OgreTutorialApp"}
{}

bool MyTestApp::keyPressed(KeyboardEvent const & evt)
{
	if (evt.keysym.sym == SDLK_ESCAPE)
	{
		getRoot()->queueEndRendering();
		return true;
	}
	else
		return false;  // key not processed
}

void MyTestApp::setup()
{
	ApplicationContext::setup();
	addInputListener(this);  // register for input events

	SceneManager * scene = getRoot()->createSceneManager();
	scene->setAmbientLight(ColourValue{0.5, 0.5, 0.5});

	// register our scene with the RTSS
	RTShader::ShaderGenerator * shadergen =
		RTShader::ShaderGenerator::getSingletonPtr();
	shadergen->addSceneManager(scene);

	SceneNode * root_node = scene->getRootSceneNode();

	// without light we would just get a black screen
	Light * light = scene->createLight("MainLight");
	SceneNode * light_node = root_node->createChildSceneNode();
	light_node->setPosition(20, 80, 50);
	light_node->attachObject(light);

	// create camera so we can observe scene
	Camera * camera = scene->createCamera("MainCamera");
	camera->setNearClipDistance(5);  // specific to this sample
	camera->setAutoAspectRatio(true);
	SceneNode * camera_node = root_node->createChildSceneNode();
	camera_node->setPosition(0, 0, 140);
	camera_node->lookAt(Vector3{0, 0, -1}, Node::TS_PARENT);
	camera_node->attachObject(camera);

	getRenderWindow()->addViewport(camera);  // render into the main window

	// finally something to render
	Entity * ent = scene->createEntity("ogrehead.mesh");
	SceneNode * node = root_node->createChildSceneNode();
	node->attachObject(ent);
}

int main(int argc, char * argv[])
{
	MyTestApp app;
	app.initApp();
	app.getRoot()->startRendering();
	app.closeApp();
	return 0;
}

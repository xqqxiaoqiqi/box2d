#include "test.h"

// This test shows how to apply forces and torques to a body.
// It also shows how to use the friction joint that can be useful
// for overhead games.
class mytest : public Test
{
public:
	mytest()
	{
		{
			
			// Define the gravity vector.
			m_world->SetGravity(b2Vec2(0, -10.0f));

			// Define the ground body.
			b2BodyDef groundBodyDef;
			groundBodyDef.position.Set(0.0f, -10.0f);

			// Call the body factory which allocates memory for the ground body
			// from a pool and creates the ground box shape (also from a pool).
			// The body is also added to the world.
			b2Body* groundBody = m_world->CreateBody(&groundBodyDef);

			// Define the ground box shape.
			b2PolygonShape groundBox;

			// The extents are the half-widths of the box.
			groundBox.SetAsBox(50.0f, 10.0f);

			// Add the ground fixture to the ground body.
			groundBody->CreateFixture(&groundBox, 0.0f);

			// Define the dynamic body. We set its position and call the body factory.
			b2BodyDef bodyDef;
			bodyDef.type = b2_dynamicBody;
			bodyDef.position.Set(0.0f, 4.0f);
			bodyDef.angle = 0.2f * b2_pi;
			b2Body* body = m_world->CreateBody(&bodyDef);
			b2PolygonShape dynamicBox;
			dynamicBox.SetAsBox(1.0f, 1.0f);
			b2FixtureDef fixtureDef;
			fixtureDef.shape = &dynamicBox;
			fixtureDef.density = 1.0f;
			fixtureDef.friction = 0.3f;
			fixtureDef.restitution = 0.8f;
			body->CreateFixture(&fixtureDef);
			
			// bodyDef.position.Set(0.0f, 8.0f);
			// b2Body* body2 = m_world->CreateBody(&bodyDef);
			// fixtureDef.friction = 0.8f;
			// body2->CreateFixture(&fixtureDef);
		}
	}

	void Step(Settings& settings) override
	{
		// g_debugDraw.DrawString(5, m_textLine, "Forward (W), Turn (A) and (D)");
		// m_textLine += m_textIncrement;
		//
		// if (glfwGetKey(g_mainWindow, GLFW_KEY_W) == GLFW_PRESS)
		// {
		// 	b2Vec2 f = m_body->GetWorldVector(b2Vec2(0.0f, -50.0f));
		// 	b2Vec2 p = m_body->GetWorldPoint(b2Vec2(0.0f, 3.0f));
		// 	m_body->ApplyForce(f, p, true);
		// }
		//
		// if (glfwGetKey(g_mainWindow, GLFW_KEY_A) == GLFW_PRESS)
		// {
		// 	m_body->ApplyTorque(10.0f, true);
		// }
		//
		// if (glfwGetKey(g_mainWindow, GLFW_KEY_D) == GLFW_PRESS)
		// {
		// 	m_body->ApplyTorque(-10.0f, true);
		// }

		Test::Step(settings);
	}

	static Test* Create()
	{
		return new mytest;
	}

	b2Body* m_body;
};

static int testIndex = RegisterTest("ZQ", "Apply Force", mytest::Create);
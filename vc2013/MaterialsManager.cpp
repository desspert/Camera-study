#include "MaterialsManager.h"

MaterialManager::MaterialManager()
{
	
	
	
	
}

void Collision(std::list<shared_ptr<ObjectBase>> obj,Ray ray,Vec3f& result) {
	std::vector<float> buf;
	for (auto it : obj) {
		float t[3] = { 0.0f };
		if (it->box->intersect(ray, t)) {
			if (t[0] > 0 && t[0] <= 1) {
				buf.push_back(t[0]);
			}
			if (t[1] > 0 && t[1] <= 1) {
				buf.push_back(t[1]);
			}
		}
	}

	if (!buf.empty())
	{
		auto itr = std::min_element(buf.begin(), buf.end());
		result = ray.calcPosition(*itr);
	}
	
	

}

void MaterialManager::setup(Vec3f camera_pos) {
	light = std::make_shared<gl::Light>(gl::Light::DIRECTIONAL, 0);

	light->setAmbient(Color(1.0f, 1.0f, 1.0f));
	light->setDiffuse(Color(0.8f, 0.8f, 0.8f));
	light->setSpecular(Color(0.5f, 0.5f, 0.5f));
	light->setDirection(Vec3f(0.0f, 1.0f, -1.0f));

	glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);
	
	sphere.push_back(std::make_shared <SphereMaterial>(Vec3f(0, 0, 0), Vec3f(1, 0.1, 1), Vec3f(0, 0, 0), Vec3f(0, 0, 0), Vec3f(1000, 1000, 1000)
		, "skydome", "Skydome151004y.jpg"));
	object.push_back(std::make_shared<CubeMaterial>(Vec3f(0, 0, 0), Vec3f(1, 1, 1), Vec3f(0, 0, 0), Vec3f(0, 0, 0), "kabe", "ki.png"));
	object.push_back(std::make_shared<CubeMaterial>(Vec3f(0, -2, 0), Vec3f(50, 1, 50), Vec3f(0, 0, 0), Vec3f(0, 0, 0), "jimen", "1762.jpg"));
	object.push_back(std::make_shared<CubeMaterial>(Vec3f(40, -5, 0), Vec3f(40, 30, 40), Vec3f(0, 0, 0), Vec3f(0, 0, 0), "bill","img_9.jpg"));
	object.push_back(std::make_shared<CubeMaterial>(Vec3f(-40, -5, 0), Vec3f(40, 30, 40), Vec3f(0, 0, 0), Vec3f(0, 0, 0), "bill", "img_9.jpg"));
	object.push_back(std::make_shared<CubeMaterial>(Vec3f(0, -6, 40), Vec3f(40, 30, 40), Vec3f(0, 0, 0), Vec3f(0, 0, 0), "bill", "img_9.jpg"));
	/*cube.push_back(std::make_shared<CubeMaterial>(Vec3f(0, -1.5, 0), Vec3f(10, 1, 10), Vec3f(0, 0, 0), Vec3f(0, 1, 0), "jimen", "ki.png"));*/
	//cube.push_back(std::make_shared<CubeMaterial>(camera_pos, Vec3f(1, 1, 1), Vec3f(0, 0, 5), Vec3f(0, 1, 0)));
	object.push_back(std::make_shared<Enemy>(Vec3f(10, 1, 10), Vec3f(1, 2, 1)));
	for (auto it : object) {
		it->setup();
	}
	ak.push_back(std::make_shared<AK>(Vec3f(5,0,0),Vec3f(0, 0, 0),Vec3f(0,1,0),Vec3f(1,1,0),Vec3f(0.004,0.004,0.004),"ak", "cfn_01_b.jpg"));
	for (auto it : ak) {
		it->setup();
	}
}

void MaterialManager::update()
{
	for (auto it : ak) {
		it->setPos(CAMERA.getPos());
		it->update();
		it->fire();
		trigger = it->getTrigger();
	}
	CAMERA.getRay().setOrigin(CAMERA.getPos() + Vec3f(0,1,0));
	CAMERA.getRay().setDirection(CAMERA.getInsertPoint() * (1000,1000,1000) + Vec3f(0, 1, 0));
	
	CAMERA.setPos(Vec3f(CAMERA.getPos().x, CAMERA.getPos().y - 0.01, CAMERA.getPos().z));
	for (auto it : object) {
		CAMERA.setPos(returnBoxToBox(CAMERA.getPos(), CAMERA.getSize(), it->getPos(), it->getSize()));
		it->update();
	}
	
	for (auto it : sphere) {
		it->update();
	}
	
	
}

void MaterialManager::draw()
{
	gl::color(1, 1, 1);
	gl::enable(GL_LIGHTING);
	gl::enable(GL_NORMALIZE);
	
	light->enable();
	
	
	
	
	
	for (auto it : object) {
		it->draw();
		
		it->box->intersect(CAMERA.getRay(), &t[0]);
		
	}
	
	
	for (auto it : sphere) {
		it->draw();
	}
	for (auto it : object) {
		it->draw();
		
		for (auto weapon : ak) {
			if (it->box->intersects(CAMERA.getRay())) {
				if (weapon->getTrigger()) {
					console() << weapon->getAttackPoint() << std::endl;
				}
			}
		}

		//it->box->intersect(CAMERA.getRay(), &t[0]);
		
	}
	
	Collision(object, CAMERA.getRay(), ray_pos);
	/*for (auto it : enemy) {
		if (it->getInsert()) {
			for (auto in : enemy) {
				if (in->getInsert()) {
					if (it->getPos().x < in->getPos().x) {
						if (it->getPos().y < in->getPos().y) {
							if (it->getPos().z < in->getPos().z) {
								for (auto weapon : ak) {
									if (weapon->getTrigger()) {
										it->damage(weapon->getAttackPoint());
										console() << weapon->getAttackPoint() << std::endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}*/
	
	gl::color(0, 1, 0);
	for (auto it : object) {
		gl::drawStrokedCube(it->box->getMin() + it->box->getSize() / 2, it->box->getSize());
	}
	gl::color(1, 0, 0);
	gl::drawVector(CAMERA.getRay().getOrigin(), CAMERA.getRay().getOrigin() + CAMERA.getRay().getDirection());
	
	gl::pushModelView();
	gl::color(0, 0, 1);
	gl::drawSphere(ray_pos, 0.1f, 12);
	gl::popModelView();
	for (auto it : ak) {
		it->draw();
	}
	
}

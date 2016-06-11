#include "Enemy.h"

Enemy::Enemy(Vec3f _pos, Vec3f _size) : ObjectBase(_pos, _size) {
	hp = 100;
	insert = false;
	arrive = true;
}

void Enemy::update()
{
	if (hp >= 0) {
		arrive = false;
	}
	console() << hp << std::endl;
}
void Enemy::damage(int damage) {
	
	hp -= damage;
}

void Enemy::draw()
{
	gl::pushModelView();
	box = std::make_shared<AxisAlignedBox3f>(pos - size / 2, (pos - size / 2) + size);
	gl::drawCube(pos, size);
	gl::popModelView();
}

#include "Plate.h"

void UIPlate::update() {

}

void UIPlate::draw() {
	
		gl::pushModelView();
		gl::translate(0.0f, 0.0f, -5.0f);
		
		gl::enableAlphaBlending();

		TEX.get(name).enableAndBind();
		
		gl::drawSolidRect(Rectf(pos,end_pos));

		TEX.get(name).disable();
		gl::disableAlphaBlending();
		gl::popModelView();
	

}
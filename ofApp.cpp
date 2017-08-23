#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	/********************
	********************/
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofSetWindowShape(1280, 720);
	
	
	shader.load( "shaderVert.c", "shaderFrag.c" );

	for(int i = 0; i < 3; i++){
		fbo[i].allocate( ofGetWidth(), ofGetHeight() );
	}
	
	image[0].loadImage( "img_0.jpg" );	
	image[1].loadImage( "img_1.jpg" );	
	image[2].loadImage( "img_2.jpg" );
	
	id = 0;
	
	/********************
	********************/
	ofVec3f p[4];
	int length = 500;
	p[0] = ofVec3f(0, length);
	p[1] = ofVec3f(0, 0);
	p[2] = ofVec3f(length, length);
	p[3] = ofVec3f(length, 0);
	
	mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	for(int i = 0; i < 4; i++){
		mesh.addVertex(p[i]);
		mesh.addTexCoord(p[i]);
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);

	for(int i = 0; i < 3; i++){
		fbo[i].begin();
		ofBackground(0);
		ofSetColor( 255, 255, 255 );
		image[i].draw(0, 0, fbo[i].getWidth(), fbo[i].getHeight());
	
		fbo[i].end();
	}

	shader.begin();
	shader.setUniform1f( "id", id );
	shader.setUniformTexture( "tex_0", fbo[0].getTextureReference(), 0 ); // tex_0の参照先をtexture buffer[0]にし、同bufferに fbo[0].getTextureReference() を描き込む.
	shader.setUniformTexture( "tex_1", fbo[1].getTextureReference(), 1 ); 
	shader.setUniformTexture( "tex_2", fbo[2].getTextureReference(), 2 ); 

	ofSetColor( 255, 255, 255 );
	/********************
	textureを持つobjectのdraw()	->	GPU側のtexture buffer[0]をover drawし、shader処理をstart.
	if no texture(like "mesh" here), no over draw to texture buffer[0] and just start shader.
	********************/
	fbo[0].draw( 0, 0 );
	// mesh.draw();
	// ofDrawRectangle(0, 0, 500, 500);

	shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key){
		case '0':
		case '1':
		case '2':
			id = key - '0';
			break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

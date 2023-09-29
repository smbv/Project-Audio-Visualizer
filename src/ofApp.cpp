#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sound.loadSound("beat.wav"); //Loads a sound file (in bin/data/)
    sound.setLoop(true); // Makes the song loop indefinitely
    sound.setVolume(1); // Sets the song volume
    ofSetBackgroundColor(42, 21, 74); // Sets the Background Color

}

//--------------------------------------------------------------
void ofApp::update(){
    /* The update method is called muliple times per second
    It's in charge of updating variables and the logic of our app */
    ofSoundUpdate(); // Updates all sound players
    visualizer.updateAmplitudes(); // Updates Amplitudes for visualizer
    k += 1;
    if(replaying && k > 120){
        keyPressed(recordedKeys[i]+100);
        if(i > recordedKeys.size()){
            replaying = false;
            i = 0;
        }
            
        k = 0;
        i++;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */
    if(!playing){
        ofDrawBitmapString("Press 'p' to play some music!", ofGetWidth()/2 - 50, ofGetHeight()/2);
    }
    if(recording){
        ofDrawBitmapString("recording keys", ofGetWidth()/2 - 50, ofGetHeight()/2);
    }
    if(replaying){
        ofDrawBitmapString("replaying", ofGetWidth()/2 - 50, ofGetHeight()/2);
    }
    if(!pause){    
        amplitudes = visualizer.getAmplitudes();
    }
    if(mode == '1'){
        drawMode1(amplitudes);
    }else if(mode == '2'){
        drawMode2(amplitudes);
    }else if(mode == '3'){
        drawMode3(amplitudes);
    }
    
}
void ofApp::drawMode1(vector<float> amplitudes){
        ofFill(); // Drawn Shapes will be filled in with color
        ofSetColor(256); // This resets the color of the "brush" to white
        ofDrawBitmapString("Rectangle Height Visualizer", 0, 15);
        for(int i=0; i<64; i++){   
            ofSetColor(ofRandom(0,256),ofRandom(0,256),ofRandom(0,256)); //Randomizes colors of rectangleHeight         
            ofDrawRectangle((ofGetWidth()/64)*i, ofGetHeight() - 100, ofGetWidth()/64,  amplitudes[i]);
        }
}
void ofApp::drawMode2(vector<float> amplitudes){
        ofSetLineWidth(5); // Sets the line width
        ofNoFill(); // Only the outline of shapes will be drawn
        ofSetColor(256); // This resets the color of the "brush" to white
        ofDrawBitmapString("Circle Radius Visualizer", 0, 15);
        int bands = amplitudes.size();
        for(int i=0; i< bands; i++){
            ofSetColor((bands - i)*32 %256,18,144); // Color varies between frequencies
            ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, amplitudes[0]/(i +1));
        }
}

void ofApp::drawMode3(vector<float> amplitudes){
    ofFill();
    ofSetColor(256); // This resets the color of the "brush" to white
    ofDrawBitmapString("Rectangle Width Visualizer", 0, 15);
    for(int i=0; i<64; i++){
        ofSetColor(ofRandom(0,256),ofRandom(0,256),ofRandom(0,256)); //Randomizes color of rectangleHeight
        ofDrawRectangle(ofGetWidth(),ofGetHeight()/64*i, amplitudes[i], ofGetHeight()/64);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // This method is called automatically when any key is pressed
    
    
    if(replaying && key<'z' && key!='t'){
        return;
    }
    else if(replaying && key !='t'){
        key-=100;
    }
    
    if(recording && key!='r'){
        recordedKeys.push_back(key);
    }
    
    
    switch(key){
        case 'p':
            if(playing){
                sound.stop();
            }else{
                sound.play();
            }
            playing = !playing;
            break;

        case 'b':
            sound.loadSound("beat.wav");
            sound.setLoop(true);
            sound.play();
            break;

        case 'g':
            sound.loadSound("geesebeat.wav");
            sound.setLoop(true);
            sound.play();
            break;

        case 'c':
            sound.loadSound("pigeon-coo.wav");
            sound.setLoop(true);
            sound.play();
            break;

        case 'i':
            sound.loadSound("rock-song.wav");
            sound.setLoop(true);
            sound.play();
            break;

        case 'q':
            sound.loadSound("Barbie.mp3"); 
            sound.setLoop(true);
            sound.play();
            break;

        case 'w':
            sound.loadSound("Brave.mp3");
            sound.setLoop(true);
            sound.play();
            break;

        case 'e':
            sound.loadSound("Groovy.mp3");
            sound.setLoop(true);
            sound.play();
            break;

        case 'h':
            sound.loadSound("Frog.mp3");
            sound.setLoop(true);
            sound.play();
            break;

        case 'a':
            pause = !pause;
            break;

        case 'A':
            pause = !pause;
            if(playing){
                sound.setPaused(true);
            } 

            else{
                sound.setPaused(false);
            }

            playing = !playing;
            break;

        case 'r':
            if(!recording){
               recordedKeys.clear();
            }
            recording = !recording;

	        break;

        case 't':
           replaying = !replaying;
            
	        break;

        case '1':
            mode = '1';
            break;

        case '2':
            mode = '2';
            break;

        case '3':
            mode = '3';
            break;

        case '-':
        if(sound.getVolume() > 0){
            sound.setVolume(sound.getVolume() - 0.05);
        }
        break;

        case '=':
        if(sound.getVolume() < 1.0){
            sound.setVolume(sound.getVolume() + 0.05);
        }
        break;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
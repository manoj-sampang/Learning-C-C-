/*Create a C++ program to exemplify multiple inheritance and ambiguity
resolution in a multimedia player hierarchy. Define classes AudioPlayer,
VideoPlayer, and MediaPlayer. Both base classes have a shared attribute
contentType. Your task is to demonstrate how to handle ambiguity using
scope resolution.
AudioPlayer Class:
Ø Base class with contentType attribute and method play() prints
"Playing” contentType “content."
VideoPlayer Class:
Ø Base class with contentType attribute and method play() prints
"Playing” contentType “content."
MediaPlayer Class:
Ø Derived from AudioPlayer and VideoPlayer and method
playMedia() prints "Playing media."
Write a program that:
a. Creates a MediaPlayer instance and assigns contentType for audio
and video and demonstrates ambiguity resolution with proper
method calls.*/


#include<iostream>
using namespace std;

class AudioPlayer {
    string contentType;
public:
    string& get_contentType() {
        return contentType;
    }

    void play() {
        cout << "Playing " << contentType << " content." << endl;
    }
};

class VideoPlayer {
    string contentType;
public:
    string& get_contentType() {
        return contentType;
    }

    void play() {
        cout << "Playing " << contentType << " content." << endl;
    }
};

class MediaPlayer : protected AudioPlayer, protected VideoPlayer {
public:
    void playMedia() {
        AudioPlayer::play();    // Disambiguate play()
        VideoPlayer::play();
        cout << "Playing media." << endl;
    }

    void input() {
        string temp;

        cout << "Enter Audio content type: ";
        getline(cin, temp);
        AudioPlayer::get_contentType() = temp;
        
        cout << "Enter Video content type: ";
        getline(cin, temp);
        VideoPlayer::get_contentType() = temp;
    }
};

int main() {
    MediaPlayer M;
    M.input();

    cout << "\n--- From Derived Class ---" << endl;
    M.playMedia();

    return 0;
}

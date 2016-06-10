#pragma once
#include "cinder/audio/Context.h"
#include "cinder/audio/GainNode.h"
#include "cinder/audio/SamplePlayerNode.h"      
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include <unordered_map>
using namespace ci;
using namespace ci::app;

#define SE SoundManager::get()

class SoundManager : AppNative
{
private:
	std::unordered_map<std::string, audio::BufferRef> sound;
	audio::GainNodeRef gain;
public:
	audio::BufferPlayerNodeRef buffer_player;
	SoundManager() {};
	~SoundManager() {};
	void set(std::string name, std::string path)
	{
		if (sound.find(name) == sound.end()) {
			if (sound.find(name) == sound.end()) {
				audio::SourceFileRef source = audio::load(loadAsset(path));
				sound[name] = source->loadBuffer();
			}
		}
	}
	void setup() {
		// サウンド機能を有効にする
		audio::Context* ctx = audio::master();
		ctx->enable();
		

		
		// 再生用のノードを生成
		buffer_player = ctx->makeNode(new audio::BufferPlayerNode());

		// 音量調整用のノードを生成
		gain = ctx->makeNode(new audio::GainNode());

		// 用意したノードを連結
		buffer_player >> gain >> ctx->getOutput();
	}

	audio::BufferRef getSound(std::string name) {
		return sound[name];
	}

	

	static SoundManager& get() {
		static SoundManager se;
		return se;
	}
};
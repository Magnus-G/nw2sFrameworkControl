long audioIn = ::analogRead(inputs[11]); 

audioInToAudioOut++;

// if (audioInToAudioOut % 2 = 0) {
//   audioIn = audioIn * 2;
// }

// if (audioIn > 0) {
//   audioIn = audioIn - (audioIn / 2);
// }
//
// if (audioIn < 0) {
//   audioIn = audioIn + (audioIn / 2);
// }

outputs[0]->outputCV(audioIn); 

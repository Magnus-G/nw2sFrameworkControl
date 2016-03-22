if (digitalRead(digitalInputs[2]) == 1) {
  if (arpClockState2 == false) {
    arpClockState2 = true;
    arpTriggerIn2 = true;
  }
}

if (digitalRead(digitalInputs[2]) == 0) {
  if (arpClockState2 == true) {
    arpClockState2 = false;
  }
}

if (arpTriggerIn2) {
  arpAddition[1] = arpJumps[1][arpStep2];
  arpTriggerIn2 = false;
  arpStep2++;

  if(arpStep2 > 2) {
    arpStep2 = 0;
  }
}

if (digitalRead(digitalInputs[1]) == 1) {
  if (arpClockState == false) {
    arpClockState = true;
    arpTriggerIn = true;
  }
}

if (digitalRead(digitalInputs[1]) == 0) {
  if (arpClockState == true) {
    arpClockState = false;
  }
}

if (arpTriggerIn) {
  arpAddition[0] = arpJumps[1][arpStep];
  arpTriggerIn = false;
  arpStep++;

  if(arpStep > 3) {
    arpStep = 0;
  }
}

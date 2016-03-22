if (digitalRead(digitalInputs[3]) == 1) {
  if (arpClockState3 == false) {
    arpClockState3 = true;
    arpTriggerIn3 = true;
  }
}

if (digitalRead(digitalInputs[3]) == 0) {
  if (arpClockState3 == true) {
    arpClockState3 = false;
  }
}

if (arpTriggerIn3) {
  arpAddition[2] = arpJumps[1][arpStep3];
  arpTriggerIn3 = false;
  arpStep3++;

  if(arpStep3 > 2) {
    arpStep3 = 0;
  }
}

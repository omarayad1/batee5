#include "DigiKeyboard.h"

void setup() {
  DigiKeyboard.update();
  writeBatchFile();
}

void loop() {

}

void kprint(String s)
{
  for (int i = 0; i < s.length(); ++i)
  {
    DigiKeyboard.write(s.charAt(i));
    DigiKeyboard.update();
  }
}

void writeBatchFile()
{
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_RIGHT);
  delay(3000);
  DigiKeyboard.update();
  
  kprint("cmd.exe /T:02 /K mode CON: COLS=120 LINES=40");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.update();
  delay(3000);

  kprint("copy /Y con %USERPROFILE%\\batee5.bat");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  delay(500);

  kprint("@echo off");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  kprint(":while1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER); 
  kprint("echo batee5");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  kprint("goto :while1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.sendKeyStroke(KEY_C, MOD_CONTROL_LEFT);
  kprint("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  delay(300);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_RIGHT);
  delay(3000);
  DigiKeyboard.update();
  kprint("cmd.exe /T:02 /K mode CON: COLS=120 LINES=40");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.update();
  delay(3000);
  kprint("%USERPROFILE%\\batee5.bat");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  delay(100);
}

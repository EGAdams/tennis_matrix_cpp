#include "CppInterface.h"
#include "GAME_MODES.h"
#include "GameObject.h"
#include "GameState.h"
#include "GameTimer.h"
#include "INPUTS.h"
#include "PinInterface.h"
#include "PinState.h"
#include "Player.h"
#include "ScoreBoard.h"
#include "WebLiquidCrystal.h"

Napi::Object CppInterface::Init(Napi::Env env, Napi::Object exports) {
  Napi::Function func = DefineClass(
      env,
      "CppInterface",
      {InstanceMethod("plusOne", &CppInterface::PlusOne),
       InstanceMethod("value", &CppInterface::GetValue),
       InstanceMethod("multiply", &CppInterface::Multiply),
       InstanceMethod("gameLoop", &CppInterface::gameLoop),
    //    InstanceMethod("getPinMap", &CppInterface::getPinMap),
       InstanceMethod("digitalRead", &CppInterface::digitalRead),
       InstanceMethod("analogRead", &CppInterface::analogRead),
       InstanceMethod("digitalWrite", &CppInterface::digitalWrite)});

  Napi::FunctionReference* constructor = new Napi::FunctionReference();
  *constructor = Napi::Persistent(func);
  env.SetInstanceData(constructor);

  exports.Set("CppInterface", func);
  return exports;
}

CppInterface::CppInterface(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<CppInterface>(info) {
  Napi::Env env = info.Env();

  int length = info.Length();
  if (length <= 0 || !info[0].IsNumber()) {  // not a number?!... bail.
    Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    return;
  }

  Napi::Number value = info[0].As<Napi::Number>();
  this->value_ = value.DoubleValue();
  //   std::cout << "before pin state construction..." << std::endl;
  //   PinState* _pinState = new PinState(&_cpp_interface_pin_map);
  //   std::cout << "after pin state construction." << std::endl;

  //   GameTimer gameTimer;
  //   WebLiquidCrystal webLiquidCrystal;
  //   Player player1(1);
  //   Player player2(2);
  //   PinInterface* pinInterface = new PinInterface(_pinState);
  //   GameState gameState(&player1, &player2);
  //   ScoreBoard scoreBoard(&player1, &player2, &webLiquidCrystal);
  //   Inputs gameInputs(&player1, &player2, pinInterface, &gameState);
  //   GameModes gameModes(&player1, &player2, pinInterface, &gameState);
  //   GameObject gameObject(&player1,
  //                         &player2,
  //                         _pinState,
  //                         pinInterface,
  //                         &gameState,
  //                         &gameTimer,
  //                         &gameInputs,
  //                         &gameModes,
  //                         &scoreBoard,
  //                         &webLiquidCrystal);
  _gameObject = &gameObject;
  std::cout << "CppInterface::CppInterface()" << std::endl;
}

Napi::Value CppInterface::GetValue(const Napi::CallbackInfo& info) {
  double num = this->value_;

  return Napi::Number::New(info.Env(), num);
}

Napi::Value CppInterface::PlusOne(const Napi::CallbackInfo& info) {
  return CppInterface::GetValue(info);
}

Napi::Value CppInterface::Multiply(const Napi::CallbackInfo& info) {
  Napi::Number multiple;
  if (info.Length() <= 0 || !info[0].IsNumber()) {
    multiple = Napi::Number::New(info.Env(), 1);
  } else {
    multiple = info[0].As<Napi::Number>();
  }
  Napi::Object obj = info.Env().GetInstanceData<Napi::FunctionReference>()->New(
      {Napi::Number::New(info.Env(), this->value_ * multiple.DoubleValue())});
  return obj;
}

Napi::Value CppInterface::gameLoop(const Napi::CallbackInfo& info) {
  _gameObject->loopGame();
  return CppInterface::GetValue(info);
}

Napi::Value CppInterface::digitalRead(const Napi::CallbackInfo& info) {
  // Napi::Env env = info.Env();
  // std::cout << "digitalRead called here..." << std::endl;

  // if (info.Length() < 1) {
  //     Napi::TypeError::New(env, "Wrong number of
  //     arguments").ThrowAsJavaScriptException(); return env.Null(); }
  // std::cout << "length must be > 1" << std::endl;

  // if (!info[0].IsNumber()) {
  //     Napi::TypeError::New(env, "Wrong argument
  //     type").ThrowAsJavaScriptException(); return env.Null(); }
  // std::cout << "must be a number" << std::endl;

  // std::cout << "pin: " << 202 << " value: " <<
  // _gameObject->getPinInterface()->pinDigitalRead( 202 ) << std::endl;
  // //   std::cout << "reading pin 202: "          <<
  // _gameObject->getPinInterface()->pinDigitalRead( 202 ) << std::endl;

  // int pin_value = _gameObject->getPinInterface()->pinDigitalRead(
  // info[0].As<Napi::Number>().Int32Value() );

  // std::cout << "digitalRead returning pin_value: " << pin_value << std::endl;
  // return Napi::Number::New(info.Env(), pin_value);
  Napi::Env env = info.Env();
  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }
  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "Argument not an integer")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  double pin = info[0].As<Napi::Number>().DoubleValue();

  std::cout << "reading pin: " << pin << "..." << std::endl;
  int pin_value = _gameObject->getPinInterface()->pinDigitalRead(pin);
  std::cout << "pin: " << pin
            << " value: " << _gameObject->getPinInterface()->pinDigitalRead(pin)
            << std::endl;

  Napi::Number setValue = Napi::Number::New(env, pin_value);
  return setValue;
}

Napi::Value CppInterface::analogRead(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }
  if (!info[0].IsNumber()) {
    Napi::TypeError::New(env, "Argument type not a number")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  int pin_value = _gameObject->getPinInterface()->pinAnalogRead(
      info[0].As<Napi::Number>().Int32Value());
  return Napi::Number::New(info.Env(), pin_value);
}

Napi::Value CppInterface::digitalWrite(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() < 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }
  if (!info[0].IsNumber() || !info[1].IsNumber()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  double pin = info[0].As<Napi::Number>().DoubleValue();
  double value = info[1].As<Napi::Number>().DoubleValue();

  // std::cout << "writing " << value << " to pin " << pin << "..." << std::endl;
  _gameObject->getPinInterface()->pinDigitalWrite(pin, value);
//   std::cout << "pin: " << pin
//             << " value: " << _gameObject->getPinInterface()->pinDigitalRead(pin)
//             << std::endl;

  Napi::Number setValue = Napi::Number::New(env, pin + value);
  return setValue;
}

// Napi::Value CppInterface::getPinMap(const Napi::CallbackInfo& info) {
//   Napi::Env env = info.Env();
//   std::cout << "getPinMap called..." << std::endl;
//   Napi::Object pinMap = Napi::Object::New(env);
//   for (const std::pair<const std::string, int>& p :
//        _gameObject->getPinInterface()->getPinStateMap() /* pinState */) {
//     int key = std::stoi(p.first);
//     pinMap.Set(_translator.get_translated_constant(key), p.second);
//   }

//   return pinMap;
// }

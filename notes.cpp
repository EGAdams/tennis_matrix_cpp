/*
 * c++ notes
 */

PinInterface* goPinInt = _gameObject->getPinInterface();
std::cout << (reinterpret_cast<const char*>(std::addressof(_pinInterface)) ==
              reinterpret_cast<const char*>(std::addressof(goPinInt)))
          << std::endl;

Napi::Value GetValue(const Napi::CallbackInfo& info);
Napi::Value PlusOne(const Napi::CallbackInfo& info);
Napi::Value Multiply(const Napi::CallbackInfo& info);
Napi::Value digitalWrite(const Napi::CallbackInfo& info);
Napi::Value digitalRead(const Napi::CallbackInfo& info);
Napi::Value analogRead(const Napi::CallbackInfo& info);
Napi::Value gameLoop(const Napi::CallbackInfo& info);
Napi::Value getPinMap(const Napi::CallbackInfo& info);
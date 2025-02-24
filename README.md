## Quest Modding Template

A template for modding on quest

### How To Use

1. Clone the repo with ``` git clone --recurse-submodules https://github.com/Livku2/Quest-Modding-Template ```
2. Open the project in Android Studio
3. Change the library name in `app/src/main/cpp/CMakeLists.txt`
4. Start coding
5. Build the project
6. Copy the generated .so from `app/build/outputs/native/{debug/release}/lib{template}.so`

### Injecting the library
You have to decompile the apk, then go to smali/com/unity3d/player and open UnityPlayerActivity.smali

then go to OnCreate and add this

```java
const-string v0, "libname"

invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V
```

make sure you replace "libname" with whatever you put the project name as in CMakeLists.txt

it should look something like this

![image](https://github.com/user-attachments/assets/cecc47d5-5905-4da5-aad4-1a4b285bb363)


### Todo

- [ ] Add Input System
- [ ] Add Imgui Support
- [ ] Examples

### Credit

- [Dobby](https://github.com/jmpews/Dobby) - Hooking library
- [KittyMemory](https://github.com/MJx0/KittyMemory) - Android, IOS runtime code patching library
- [Aimar](https://github.com/aimardcr) - Made il2cpp api

- [BryanGIG](https://github.com/BryanGIG/Android-Native-Mod) - Made Original Template
